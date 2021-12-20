 /* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "QtGit/mainWindow.hpp"

#include "logController.hpp"
#include "logModel.hpp"

#include "cppgit2/repository.hpp"

#include <QFileDialog>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlFileSelector>
#include <QUrl>

using namespace qtgit;

struct mainWindow_t::privateData_t
{
    logController_t controller;
    QQmlApplicationEngine engine;
    QUrl qmlPath;
    cppgit2::repository repository;
    QFileDialog repoDialog;
};

mainWindow_t::~mainWindow_t() = default;

mainWindow_t::mainWindow_t (QString qmlPath_, QObject *const parent_) : QObject (parent_)
{
    m_d = std::make_unique<mainWindow_t::privateData_t>();
    m_d->qmlPath = QUrl(qmlPath_);
    qmlRegisterSingletonInstance<qtgit::mainWindow_t>("com.test.MainWindow", 1, 0, "MainWindow", this);

    m_d->repoDialog.setFileMode (QFileDialog::Directory);
    m_d->repoDialog.setOption (QFileDialog::ShowDirsOnly);
    m_d->repoDialog.setHidden (true);
    connect (&m_d->repoDialog, &QFileDialog::fileSelected, this, &mainWindow_t::loadFolder);
}

bool mainWindow_t::init()
{
    m_d->engine.load(m_d->qmlPath);

    if (m_d->engine.rootObjects().isEmpty())
        return false;

    //m_d->engine.rootContext ()->setContextProperty (QStringLiteral ("MainWindow_t"), this);

    auto root = m_d->engine.rootObjects ().at (0);
    //connect (root, SIGNAL(loadGitFolder(QString)), this, SLOT(handleLoadFolder(QString)));
    //connect (this, SIGNAL(onError()), root, SLOT(handleErrorMessage()));

    return true;
}

void
mainWindow_t::loadFolder (QString path_)
{
    auto rootDir = QDir(path_);
    if (rootDir.exists ())
    {
        auto gitDir = QDir(path_+ "/.git");
        if (gitDir.exists ())
            m_d->controller.loadPath (path_);
        else {
            emit createNewRepo (path_);
            qInfo("Handle load folder");
        }
    } else {
        qInfo("Folder does not exists");
    }



//    qDebug("Path_ %s", path_.toStdString ().c_str ());
//    m_d->repository = cppgit2::repository::open(path_.toStdString ());
//    m_d->controller.loadPath (m_d->repository);

}

void
mainWindow_t::openRepoPathDialog ()
{
    m_d->repoDialog.show ();
}

void
mainWindow_t::branchOut (QString id_)
{
    qInfo("Branch %s", id_.toStdString ().c_str ());
    emit reportError("zoeira mano");
}
void
mainWindow_t::cherryPick (QString id_)
{
qInfo("Cherry %s", id_.toStdString ().c_str ());
}
void
mainWindow_t::revertCommit (QString id_)
{
qInfo("Revert %s", id_.toStdString ().c_str ());
}

void mainWindow_t::createNewRepository (QString name_, QString url_, bool genReadme_, bool genLicense_, bool genIgnore_)
{
    qInfo("create new repo");
}

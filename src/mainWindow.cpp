/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "QtGit/mainWindow.hpp"

#include "logController.hpp"
#include "logModel.hpp"

#include "cppgit2/repository.hpp"

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
};

mainWindow_t::~mainWindow_t() = default;

mainWindow_t::mainWindow_t (QString qmlPath_, QObject *const parent_) : QObject (parent_)
{
    m_d = std::make_unique<mainWindow_t::privateData_t>();
    m_d->qmlPath = QUrl(qmlPath_);
    qmlRegisterSingletonInstance<qtgit::logModel_t>("com.test.LogModel", 1, 0, "GitLogModel", m_d->controller.model());
}

bool mainWindow_t::init()
{
    m_d->engine.load(m_d->qmlPath);

    if (m_d->engine.rootObjects().isEmpty())
        return false;

    auto root = m_d->engine.rootObjects ().at (0);
    connect (root, SIGNAL(loadGitFolder(QString)), this, SLOT(handleLoadFolder(QString)));

    return true;
}

void mainWindow_t::handleLoadFolder(QString path_)
{
//    qDebug("Path_ %s", path_.toStdString ().c_str ());
//    m_d->repository = cppgit2::repository::open(path_.toStdString ());
//    m_d->controller.loadPath (m_d->repository);
    m_d->controller.loadPath (path_);
}



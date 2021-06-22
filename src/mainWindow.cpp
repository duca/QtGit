/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "QtGit/mainWindow.hpp"

#include "logController.hpp"
#include "logModel.hpp"

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlFileSelector>
#include <QUrl>

using namespace qtgit;

struct mainWindow_t::privateData_t
{
    logController_t controller;
    logModel_t model;
    QQmlApplicationEngine engine;
    QUrl qmlPath;
};

mainWindow_t::~mainWindow_t() = default;

mainWindow_t::mainWindow_t (QString qmlPath_, QObject *const parent_) : QObject (parent_)
{
    m_d = std::make_unique<mainWindow_t::privateData_t>();
    qmlRegisterSingletonInstance<qtgit::logModel_t>("com.test.LogModel", 1, 0, "GitLogModel", &m_d->model);

    qtgit::logModel_t::logItem_t item;
    item.id = "1weqwsadsa4wr423r2sadfcsdf";
    item.description = "sdfsdfsdfrrgrgtrh---------------+++++---g";
    item.userEmail = "duca@github.com";
    item.userName = "duca";
    item.date = "12/12/12";

    m_d->model.appendCommit (item);
    m_d->model.appendCommit (item);
    m_d->model.appendCommit (item);
    m_d->model.appendCommit (item);

    m_d->qmlPath = QUrl(qmlPath_);
}

bool mainWindow_t::init()
{
    m_d->engine.load(m_d->qmlPath);
    return m_d->engine.rootObjects().isEmpty();
}



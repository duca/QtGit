/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "logController.hpp"
#include "logModel.hpp"

#include "QtQuick/QQuickView"
#include <QQmlContext>

using namespace qtgit;

struct logController_t::privateData_t
{
    QQuickView view;
    qtgit::logModel_t model;
};

logController_t::~logController_t () = default;

logController_t::logController_t(QObject *const parent_) : QObject (parent_)
{
	qRegisterMetaType<logModel_t>();
    m_d = std::make_unique<logController_t::privateData_t>();

    qtgit::logModel_t::logItem_t item;
    item.id = "1weqwsadsa4wr423r2sadfcsdf";
    item.description = "teste";
    item.userEmail = "duca@github.com";
    item.userName = "duca";
    item.date = "12/12/12";
    m_d->model.appendCommit (item);
    m_d->model.appendCommit (item);
    m_d->model.appendCommit (item);
    m_d->model.appendCommit (item);

    m_d->view.rootContext ()->setContextProperty ("GitLogModel", &m_d->model);
    m_d->view.setSource (QUrl("qrc:/qml/GitLogView.qml"));
}

void logController_t::show ()
{
    m_d->view.show ();
}

bool logController_t::init (cppgit2::repository const& repo_)
{
	return false;
}

void logController_t::handleUpdateLog () const
{
}


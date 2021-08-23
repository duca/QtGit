/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "logController.hpp"
#include "logModel.hpp"

#include "cppgit2/repository.hpp"
using namespace cppgit2;

#include "QtQuick/QQuickView"
#include <QQmlContext>
#include <QSharedPointer>
#include <QDateTime>
#include <QDir>
#include <QString>

using namespace qtgit;

struct logController_t::privateData_t
{
    QQuickView view;
    qtgit::logModel_t model;
};

logController_t::~logController_t () = default;

logController_t::logController_t(QObject *const parent_) : QObject (parent_)
{	
    m_d = std::make_unique<logController_t::privateData_t>();
}

//void logController_t::loadPath(cppgit2::repository& repo_)
void logController_t::loadPath(QString repo_)
{
    m_d->model.clear ();

    QList<qtgit::logModel_t::logItem_t> commits;

    auto repo = cppgit2::repository::open(repo_.toStdString ());

    repo.for_each_commit ([&commits](cppgit2::commit const& c_){
        qtgit::logModel_t::logItem_t item;
        item.id = QString::fromStdString (c_.id().to_hex_string (8));
        item.userName = QString::fromStdString(c_.committer ().name ());
        item.userEmail = QString::fromStdString(c_.committer ().email ());
        item.summary = QString::fromStdString(c_.summary ());
        item.type = "Commit";
        item.date = QDateTime::fromMSecsSinceEpoch (c_.time (), Qt::LocalTime, c_.time_offset () * 60).toString ();
        commits.emplaceBack(std::move(item));
    });

    repo.for_each_tag([&commits, &repo](std::string const &name_, cppgit2::oid const &id_){
        qtgit::logModel_t::logItem_t item;
        item.id = QString::fromStdString (id_.to_hex_string (8));
        item.summary = QString::fromStdString(name_);
        item.type = "Tag";
        commits.emplaceBack(std::move(item));
    });

    m_d->model.appendCommits (std::move(commits));
}

logModel_t* logController_t::model ()
{
    return &m_d->model;
}

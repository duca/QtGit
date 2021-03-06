/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include "logModel.hpp"

#include "cppgit2/repository.hpp"
#include <QString>

#include <QObject>
#include <QSharedPointer>

namespace qtgit {

class logController_t : public QObject
{
    Q_OBJECT
public:

    explicit logController_t(QObject *const parent_ = nullptr);
	virtual ~logController_t ();

    void loadPath (QString repo_);
    //void loadPath (cppgit2::repository& repo_);

    void show ();

    logModel_t* model ();

signals:
    void onLogReport (logModel_t const &commits_) const;

private:
	struct privateData_t;
	std::unique_ptr<privateData_t> m_d;
};

}

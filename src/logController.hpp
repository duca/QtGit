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

/**
 * @brief The logController_t class that process commits of a given repository
 */
class logController_t : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief logController_t constructor
     * @param parent_ QObject pointer
     */
    explicit logController_t(QObject *const parent_ = nullptr);

    ~logController_t () override;

    /**
     * @brief loadPath - reads all the commits in a repository path
     * @param repo_ path
     */
    void loadPath (QString repo_);

    /**
     * @brief model address. Used to connect C++ code with QML
     * @return model address
     */
    logModel_t* model ();

signals:
    /**
     * @brief onError - report error messages
     * @param error_ message
     */
    void onError (QString error_) const;

private:
	struct privateData_t;
	std::unique_ptr<privateData_t> m_d;
};

}

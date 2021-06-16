/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include "cppgit2/repository.hpp"
#include <QString>

#include <QObject>
#include <QSharedPointer>

class logController_t : public QObject
{
    Q_OBJECT

    explicit logController_t(QObject *const parent_);

    bool init (cppgit2::repository const& repo_);

    void handleUpdateLog () const;

signals:
    void
};

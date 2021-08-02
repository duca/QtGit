/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <QObject>
#include <memory>

namespace qtgit {

class mainWindow_t : public QObject
{
    Q_OBJECT

public:
    explicit mainWindow_t(QString qmlPath_, QObject *parent_ = nullptr);
    ~mainWindow_t();

    bool init();

public slots:
    void handleLoadFolder (QString path_);
    void handleOpenRepoPathDialog ();

private:
    struct privateData_t;
    std::unique_ptr<privateData_t> m_d;    
};

}

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <QObject>
#include <QString>
#include <memory>

namespace qtgit {

class mainWindow_t : public QObject
{
    Q_OBJECT

public:
    explicit mainWindow_t(QString qmlPath_, QObject *parent_ = nullptr);
    ~mainWindow_t();

    bool init();

    Q_INVOKABLE void loadFolder (QString path_);
    Q_INVOKABLE void openRepoPathDialog ();
    Q_INVOKABLE void branchOut (QString id_);
    Q_INVOKABLE void cherryPick (QString id_);
    Q_INVOKABLE void revertCommit (QString id_);
    Q_INVOKABLE void createNewRepository (
        QString name_, QString url_, bool genReadme_, bool genLicense_, bool genIgnore_);

signals:
    void createNewRepo(QString path_) const;
    void reportError (QString message_) const;

private:
    struct privateData_t;
    std::unique_ptr<privateData_t> m_d;    
};

}

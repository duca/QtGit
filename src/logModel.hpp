/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <QObject>
#include <QString>
#include <QAbstractListModel>

namespace qtgit {

class logModel_t : public QAbstractListModel
{
	Q_OBJECT

public:
	enum logModelRole {
        idRole = Qt::DisplayRole,
        longIdRole,
        summaryRole,
		userNameRole,
		userEmailRole,
        commitDateRole,
        bodyRole
	};
	Q_ENUM (logModelRole);

	struct logItem_t {
		QString id;
        QString summary;
		QString userName;
		QString userEmail;
		QString date;
        QString body;
	};

	virtual ~logModel_t ();

	explicit logModel_t (QObject *const parent_ = nullptr);
	logModel_t (logModel_t const &other_);
    logModel_t (logModel_t &&other_) noexcept;

	int rowCount (const QModelIndex & = QModelIndex()) const override;

    QVariant data (const QModelIndex &index_, int role_ = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames () const override;

    Q_INVOKABLE bool removeRows(int row_, int count_, const QModelIndex &parent_ = QModelIndex()) override;

    Q_INVOKABLE QVariantMap get (int row_) const;

    void appendCommit (logItem_t &&item_);

    QList<logItem_t> allCommits () const;
    void clear ();

private:
    QList<logItem_t> m_commits;
};
}

Q_DECLARE_METATYPE(qtgit::logModel_t)

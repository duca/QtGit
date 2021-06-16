/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once


#include <QObject>
#include <QString>
#include <qnamespace.h>
#include <qobjectdefs.h>

namespace qtgit {

class logModel_t : public QAbstractListModel
{
	Q_OBJECT

public:
	enum logModelRole {
		idRole = Qt::DisplayRole,
		descriptionRole = Qt::DisplayRole,
		userNameRole,
		userEmailRole,
		commitDateRole
	};

	struct logItem_t {
		QString id;
		QString description;
		QString userName;
		QString userEmail;
		QString date;
	};

	explicit logModel_t (QObject *const parent_ = nullptr);

	int rowCount (const QModelIndex & = QModelIndex()) override const;
	QVariant data (const QModelIndex &index_, int role_ = Qt::DisplayRole) override const;
	QHash<int, QByteArray> roleNames () override const;
	Q_INVOKABLE QVariantMap get (int row_) const;

	logModel_t (logModel_t &&other_) noexcept;

	void appendCommit (logItem_t const& item_);

	QList<logItem_t> allCommits () const;

private:
	QList<logItem_t> m_commits;
};
}

Q_DECLARE_METATYPE(qtgit::logModel_t)

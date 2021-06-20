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
		descriptionRole,
		userNameRole,
		userEmailRole,
		commitDateRole
	};
	Q_ENUM (logModelRole);

	struct logItem_t {
		QString id;
		QString description;
		QString userName;
		QString userEmail;
		QString date;
	};

	virtual ~logModel_t ();

	explicit logModel_t (QObject *const parent_ = nullptr);

	logModel_t (logModel_t const &other_);

	int rowCount (const QModelIndex & = QModelIndex()) const override;
	QVariant data (const QModelIndex &index_, int role_ = Qt::DisplayRole) const override;
	QHash<int, QByteArray> roleNames () const override;
	Q_INVOKABLE QVariantMap get (int row_) const;

	logModel_t (logModel_t &&other_) noexcept;

	Q_INVOKABLE void appendCommit (logItem_t const& item_);

	QList<logItem_t> allCommits () const;

private:
	QList<logItem_t> m_commits;
};
}

Q_DECLARE_METATYPE(qtgit::logModel_t)

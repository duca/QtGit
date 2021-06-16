/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
#include "logModel.hpp"

using namespace qtgit;

logModel_t::logItem_t (QObject *const parent_) : QAbstractListModel (parent_)
{
}

int logModel_t::rowCount() const
{
	return m_commits.count();
}

QVariant logModel_t::data(const QModelIndex &index_, int role_) const
{
	if (index.row() < rowCount())
		switch (role) {
		case idRole: return m_commits.at(index_.row()).id;
		case descriptionRole: return m_commits.at(index_.row()).description;
		case userNameRole: return m_commits.at(index_.row()).userName;
		case userEmailRole: return m_commits.at(index_.row()).userEmail;
		case commitDateRole: return m_commits.at(index_.row()).date;
		default: return QVariant();
		}
	return QVariant();
}

QHash<int, QByteArray> logModel_t::roleNames() const
{
	static const QHash<int, QByteArray> roles {
		{idRole, "id"},
		{descriptionRole, "description"},
		{userNameRole, "userName"},
		{userEmailRole, "userEmail"},
		{commitDateRole, "commitDate"}
	};
	return roles;
}

QVariantMap logModel_t::get(int row_) const
{
	if (int row_ >= rowCount())
		return QVariantMap();

	const logItem_t item = m_commits.value(row);
	return { {"id", item.id}, {"description", item.description}, {"userName", item.userName},
			 {"userEmail", item.userEmail}, {"commitDate", item.date}};
}

void logModel_t::appendCommit(const logItem_t &item_)
{
	int row = 0;

	while (row < rowCount() && item_.id > m_commits.at(row).id)
		row++;

	beginInsertRows(QModelIndex(), row, row);
	m_commits.insert(item_);
	endInsertRows();
}

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
#include "logModel.hpp"

using namespace qtgit;

namespace {
auto constexpr shortHashLen = 6; ///< lenght of the short hash view
}

logModel_t::~logModel_t () = default;

logModel_t::logModel_t (QObject *const parent_) : QAbstractListModel (parent_)
{
}
logModel_t::logModel_t (logModel_t const &other_)
{
	m_commits = other_.allCommits ();
}

QVariant logModel_t::data(const QModelIndex &index_, int role_) const
{
	if (index_.row() < rowCount())
		switch (role_) {
        case idRole:
        {
            auto id = m_commits.at(index_.row()).id;
            return id.chopped (id.length () - shortHashLen);
        }
        case longIdRole: return m_commits.at(index_.row ()).id;
		case descriptionRole: return m_commits.at(index_.row()).description;
		case userNameRole: return m_commits.at(index_.row()).userName;
		case userEmailRole: return m_commits.at(index_.row()).userEmail;
		case commitDateRole: return m_commits.at(index_.row()).date;
		default: return QVariant();
		}
	return QVariant();
}

logModel_t::logModel_t(logModel_t &&other_) noexcept
{
	m_commits.swap(other_.m_commits);
}

QHash<int, QByteArray> logModel_t::roleNames() const
{
	static const QHash<int, QByteArray> roles {
		{idRole, "commitId"},
        {longIdRole, "longCommitId"},
		{descriptionRole, "description"},
		{userNameRole, "userName"},
		{userEmailRole, "userEmail"},
		{commitDateRole, "commitDate"}
	};
	return roles;
}

QVariantMap logModel_t::get(int row_) const
{
	if (row_ >= rowCount())
		return QVariantMap();

	const logItem_t item = m_commits.value(row_);
    return {{"commitId", item.id.chopped (item.id.length () - shortHashLen)},
        {"longCommitId", item.id},
        {"description", item.description},
        {"userName", item.userName},
        {"userEmail", item.userEmail},
        {"commitDate", item.date}};
}

void logModel_t::appendCommit(const logItem_t &item_)
{
	int row = 0;

	while (row < rowCount() && item_.id > m_commits.at(row).id)
		row++;

	beginInsertRows(QModelIndex(), row, row);
	m_commits.append(item_);
	endInsertRows();
}

int logModel_t::rowCount(QModelIndex const&) const
{
	return m_commits.count();
}

QList<logModel_t::logItem_t> logModel_t::allCommits() const
{
	return m_commits;
}

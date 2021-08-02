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

            if (id.length () <= shortHashLen)
                return id;
            return id.chopped (id.length () - shortHashLen);
        }
        case longIdRole: return m_commits.at(index_.row ()).id;
        case summaryRole: return m_commits.at(index_.row()).summary;
        case userNameRole: return m_commits.at(index_.row()).userName;
        case userEmailRole: return m_commits.at(index_.row()).userEmail;
        case commitDateRole: return m_commits.at(index_.row()).date;
        case bodyRole: return m_commits.at(index_.row()).body;
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
        {summaryRole, "summary"},
        {userNameRole, "userName"},
        {userEmailRole, "userEmail"},
        {commitDateRole, "commitDate"},
        {bodyRole, "body"}
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
        {"summary", item.summary},
        {"userName", item.userName},
        {"userEmail", item.userEmail},
        {"commitDate", item.date},
        {"body", item.body}};
}

void logModel_t::appendCommits(QList<logItem_t> &&items_)
{
    int const len = items_.length ();

    if (len == 0)
    {
        qDebug("%s: zero length list", __PRETTY_FUNCTION__);
        return;
    }

    beginInsertRows(QModelIndex(), rowCount (), rowCount () + len);
    m_commits.append(items_);
    endInsertRows ();
}

int logModel_t::rowCount(QModelIndex const&) const
{
    return m_commits.count();
}

QList<logModel_t::logItem_t> logModel_t::allCommits() const
{
    return m_commits;
}

void logModel_t::clear()
{
    beginResetModel ();
    m_commits.clear();
    endResetModel ();
}

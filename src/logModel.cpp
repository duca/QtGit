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

void logModel_t::appendCommit(logItem_t &&item_)
{
    int const row = rowCount()-1;
    beginInsertRows(QModelIndex(),row, row);
    m_commits.append(item_);
    qDebug ("%s %s", item_.summary.toStdString ().c_str (), item_.id.toStdString ().c_str ());
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

bool logModel_t::removeRows(int row_, int count_, const QModelIndex &parent_)
{
    if (m_commits.count () == 0)
        return false;

    int last = row_ + count_;

    if (last > (m_commits.count ()-1))
        last = m_commits.count ()-1;

    beginRemoveRows(parent_, row_, count_);
    m_commits.erase(m_commits.begin()+row_, m_commits.begin()+last);
    endRemoveRows();

    return true;
}

void logModel_t::clear()
{
    removeRows(0, rowCount (), QModelIndex());
}

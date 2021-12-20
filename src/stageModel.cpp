/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
#include "stageModel.hpp"

using namespace qtgit;

namespace {
auto constexpr shortHashLen = 6; ///< lenght of the short hash view
}

stageModel_t::~stageModel_t () = default;

stageModel_t::stageModel_t (QObject *const parent_) : QAbstractListModel (parent_) {}
stageModel_t::stageModel_t (stageModel_t const &other_)
{
    m_items = other_.m_items;
}

QVariant
stageModel_t::data (const QModelIndex &index_, int role_) const
{
    if (index_.row () < rowCount ()) {
        switch (role_) {
        case fileNameRole:
            return m_items.at (index_.row ()).fileName;
        case pathRole:
            return m_items.at (index_.row ()).path;
        case diffRole:
            return m_items.at (index_.row ()).diff;
        case isStagedRole:
            return m_items.at (index_.row ()).isStaged;
        case isDirRole:
            return m_items.at (index_.row ()).isDirectory;
        case isNewRole:
            return m_items.at (index_.row ()).isNew;
        default:
            break;
        }
    }

    return "unknown";
}

stageModel_t::stageModel_t (stageModel_t &&other_) noexcept
{
    m_items.swap (other_.m_items);
}

QHash<int, QByteArray>
stageModel_t::roleNames () const
{
    static const QHash<int, QByteArray> roles {{fileNameRole, "fileName"},
                                               {pathRole, "path"},
                                               {diffRole, "diff"},
                                               {isStagedRole, "isStaged"},
                                               {isDirRole, "isDir"},
                                               {isNewRole, "isNew"}};
    return roles;
}

QVariantMap
stageModel_t::get (int row_) const
{
    if (row_ >= rowCount ())
        return QVariantMap ();

    const fileItems_t item = m_items.value (row_);
    return {
        {"fileName", item.fileName},
        {"path", item.path},
        {"diff", item.diff},
        {"isStaged", item.isStaged},
        {"isDirectory", item.isDirectory},
        {"isNew", item.isNew},
    };
}

bool
stageModel_t::setData (QModelIndex const &index_, QVariant const &value_, int role_)
{
    auto index = index_.row ();
    if (index >= rowCount ())
        return false;

    auto const roleName = roleNames ()[role_];

    return false;
}

void
stageModel_t::insertItem (fileItems_t const &items_)
{
    beginInsertRows (QModelIndex (), rowCount (), rowCount ());
    m_items.append (items_);
    endInsertRows ();
}

int
stageModel_t::rowCount (QModelIndex const &) const
{
    return m_items.count ();
}

void
stageModel_t::clear ()
{
    beginResetModel ();
    m_items.clear ();
    endResetModel ();
}

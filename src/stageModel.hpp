/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <QAbstractListModel>
#include <QObject>
#include <QString>

namespace qtgit {

/**
 * @brief The stageModel_t class used to store commit data
 */
class stageModel_t : public QAbstractListModel {
    Q_OBJECT

public:
    /**
     * @brief model roles used by the view/model mechanism
     */
    enum logModelRole {
        fileNameRole,
        pathRole,
        diffRole,
        isStagedRole,
        isDirRole,
        isNewRole,
    };
    Q_ENUM (logModelRole);

    /**
     * @brief commit item data
     */
    struct fileItems_t {
        QString fileName;
        QString path;
        QString diff;
        bool isStaged;
        bool isDirectory;
        bool isNew;
    };

    ~stageModel_t () override;

    /**
     * @brief stageModel_t constructor
     * @param parent_ QObject
     */
    explicit stageModel_t (QObject *const parent_ = nullptr);

    /**
     * @brief stageModel_t copy constructor
     * @param other_ instance
     */
    stageModel_t (stageModel_t const &other_);

    /**
     * @brief stageModel_t move construtor
     * @param other_ instance
     */
    stageModel_t (stageModel_t &&other_) noexcept;

    /**
     * @brief Reimplementation of the rowCount method. Returns the number of rows
     * @return number of rows
     */
    int rowCount (const QModelIndex & = QModelIndex ()) const override;

    /**
     * @brief Reimplementation of the data accessor method
     * @param index_ current index_
     * @param role_ which piece of data (role in the view/model jargon
     * @return data
     */
    QVariant data (const QModelIndex &index_, int role_ = Qt::DisplayRole) const override;

    /**
     * @brief setData
     * @param index_
     * @param value_
     * @param role_
     * @return
     */
    Q_INVOKABLE bool setData (QModelIndex const &index_,
                              QVariant const &value_,
                              int role_ = Qt::EditRole) override;

    /**
     * @brief Reimplementation of the roleNames method. Returns the roles of the model (i.e. components)
     * @return role names
     */
    QHash<int, QByteArray> roleNames () const override;

    /**
     * @brief Reimplementation of the get method. Gets the complete dataset of a given row
     * @param row_ of the required data
     * @return data
     */
    Q_INVOKABLE QVariantMap get (int row_) const;

    /**
     * @brief appendCommits - append a list of commits to the internal data structure
     * @param items_ list of commits
     */
    void insertItem (fileItems_t const &items_);

    /**
     * @brief Resets the model
     */
    void clear ();

private:
    /**
     * @brief m_commits - the complete list of commits
     */
    QList<fileItems_t> m_items;
};
} // namespace qtgit

Q_DECLARE_METATYPE (qtgit::stageModel_t)

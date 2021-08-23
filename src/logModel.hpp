/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <QObject>
#include <QString>
#include <QAbstractListModel>

namespace qtgit {

/**
 * @brief The logModel_t class used to store commit data
 */
class logModel_t : public QAbstractListModel
{
	Q_OBJECT

public:

    /**
     * @brief model roles used by the view/model mechanism
     */
	enum logModelRole {
        idRole = Qt::DisplayRole,
        longIdRole,
        summaryRole,
		userNameRole,
		userEmailRole,
        commitDateRole,
        typeRole,
	};
	Q_ENUM (logModelRole);

    /**
     * @brief commit item data
     */
	struct logItem_t {
		QString id;
        QString summary;
		QString userName;
		QString userEmail;
		QString date;
        QString type;
	};

    ~logModel_t () override;

    /**
     * @brief logModel_t constructor
     * @param parent_ QObject
     */
	explicit logModel_t (QObject *const parent_ = nullptr);

    /**
     * @brief logModel_t copy constructor
     * @param other_ instance
     */
    logModel_t (logModel_t const &other_);

    /**
     * @brief logModel_t move construtor
     * @param other_ instance
     */
    logModel_t (logModel_t &&other_) noexcept;

    /**
     * @brief Reimplementation of the rowCount method. Returns the number of rows
     * @return number of rows
     */
	int rowCount (const QModelIndex & = QModelIndex()) const override;


    /**
     * @brief Reimplementation of the data accessor method
     * @param index_ current index_
     * @param role_ which piece of data (role in the view/model jargon
     * @return data
     */
    QVariant data (const QModelIndex &index_, int role_ = Qt::DisplayRole) const override;


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
    void appendCommits (QList<logItem_t> &&items_);

    /**
     * @brief allCommits - returns the list of commits
     * @return list of commits
     */
    QList<logItem_t> allCommits () const;

    /**
     * @brief Resets the model
     */
    void clear ();

private:

    /**
     * @brief m_commits - the complete list of commits
     */
    QList<logItem_t> m_commits;
};
}

Q_DECLARE_METATYPE(qtgit::logModel_t)

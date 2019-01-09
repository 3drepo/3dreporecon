/**
*  Copyright (C) 2017 3D Repo Ltd
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Affero General Public License as
*  published by the Free Software Foundation, either version 3 of the
*  License, or (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Affero General Public License for more details.
*
*  You should have received a copy of the GNU Affero General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QFileInfo>
#include <QDebug>
#include <QPoint>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "repo_model_item.h"
#include "repo_node.h"
#include "repo_csv_parser.h"
#include "repo_json_parser.h"
#include "repo_db_abstract.h"

namespace repo
{

class RepoModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:

    RepoModel();

    ~RepoModel();

    Q_INVOKABLE void populate();

public :

    virtual QVariant data(const QModelIndex &proxyIndex,
                          int role = Qt::UserRole + 1) const;

    Q_INVOKABLE QVariant data(int row, const QString &roleName) const;

    //! See http://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
    QHash<int, QByteArray> roleNames() const;

    QList<RepoNode> nodes() const;

    QList<QVariant> toList() const;

    Q_INVOKABLE QUuid appendRow(int x, int y);

    Q_INVOKABLE QUuid appendRow(RepoModelItem *item);

    Q_INVOKABLE bool removeRow(int proxyRow, const QModelIndex &proxyParentIndex = QModelIndex());

    Q_INVOKABLE bool setData(RepoModelItem *item, const QVariant &value, int role = Qt::UserRole + 1);

    Q_INVOKABLE bool setData(const QModelIndex &proxyIndex, const QVariant &value, int role = Qt::UserRole + 1);

    Q_INVOKABLE bool setData(int row, const QVariant &value, const QVariant &roleName);

    Q_INVOKABLE bool setData(const QUuid &id, const QVariant &value, const QVariant &roleName);

    Q_INVOKABLE bool setImage(int row, const QUrl &fileUrl);

    Q_INVOKABLE int role(const QVariant &roleName) const;

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

    Q_INVOKABLE void filter(const QString &filter);

    Q_INVOKABLE RepoModelItem* item(int proxyRow, const QModelIndex &proxyParentIndex = QModelIndex()) const;

    Q_INVOKABLE RepoModelItem* item(const QUuid &id) const;

    /**
     * Returns links as a list of end points given current proxy row.
     *
     * @brief links
     * @param proxyRow
     * @return
     */
    Q_INVOKABLE QList<QObject *> links(const RepoModelItem *item) const;

    //! Overloaded function
    Q_INVOKABLE QList<QObject *> links(int proxyRow) const;

    //! Overloaded function
    Q_INVOKABLE QList<QObject *> links(const QUuid &id) const;

    Q_INVOKABLE void addLink(const QUuid &id1, const QUuid &id2);

private :

    QStandardItemModel *model; //! Source model

    //! Roles associated with items in the model
    static QHash<int, QByteArray> roles;

    QString _filter;

    QHash<QUuid, RepoModelItem *> itemsByID;

    QFileInfo jsonFile;

    RepoDBAbstract &db;
};

}

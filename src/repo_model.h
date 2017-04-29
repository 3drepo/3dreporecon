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

#include "repo_model_item.h"
#include "repo_node.h"
#include "repo_csv_parser.h"

namespace repo
{

class RepoModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:

    RepoModel();

    ~RepoModel();

    void populate();

public :

    //! See http://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
    QHash<int, QByteArray> roleNames() const;

    QList<RepoNode> nodes() const;

    Q_INVOKABLE void addNode(int x, int y);

    Q_INVOKABLE bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::UserRole + 1);

    Q_INVOKABLE bool setData(int row, const QVariant &value, const QVariant &roleName);

    Q_INVOKABLE int role(const QVariant &roleName) const;

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

    Q_INVOKABLE void filter(const QString &filter);

private :

    QStandardItemModel *model; //! Source model

    //! Roles associated with items in the model
    static QHash<int, QByteArray> roles;

    QString _filter;
};

}

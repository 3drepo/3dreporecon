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

namespace repo
{

class RepoModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:

    RepoModel();

    ~RepoModel();

public :

    //! See http://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
    QHash<int, QByteArray> roleNames() const;

private :

    QStandardItemModel *model; //! Source model

    //! Roles associated with items in the model
    static QHash<int, QByteArray> roles;
};

}
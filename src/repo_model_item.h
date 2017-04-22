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

#include <QString>
#include <QStandardItem>

#include "repo_node.h"
#include "repo_node_company.h"
#include "repo_node_person.h"
#include "repo_node_project.h"

namespace repo
{

class RepoModelItem : public QStandardItem
{

public :

    enum ItemRole {

        //-------
        // Node
        //-------
        ID = Qt::UserRole + 1,
        Name,
        Type,
        Image,
        X,
        Y,

        //-------
        // Person
        //-------
        FirstName,
        LastName,
        JobTitle,
        LinkedIn,
        Email
    };

public:

    RepoModelItem(const RepoNode &node);

    QVariant data(int role = Qt::UserRole + 1) const;

    void setData(const QVariant &value, int role = Qt::UserRole + 1);

    RepoNode getNode() { return node; }

private :

    RepoNode node;
};

}

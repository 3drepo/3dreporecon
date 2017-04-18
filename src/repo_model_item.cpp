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

#include "repo_model_item.h"

using namespace repo;

RepoModelItem::RepoModelItem(const RepoNode &node)
    : node(node)
{

}

QVariant RepoModelItem::data(int role) const
{
    QVariant data;
    switch (role) {
    case ID:
        data = node.id();
        break;
    case Name:
        data = node.name();
        break;
    case Type:
        data = node.type();
        break;
    case Image:
        data = node.image();
        break;
    case Point:
        data = node.point();
        break;
    case FirstName:
        data = ((RepoNodePerson) node).firstName();
        break;
    case LastName:
        data = ((RepoNodePerson) node).lastName();
        break;
    case JobTitle:
        data = ((RepoNodePerson) node).jobTitle();
        break;
    case LinkedIn:
        data = ((RepoNodePerson) node).linkedIn();
        break;
    case Email:
        data = ((RepoNodePerson) node).email();
        break;
    }

    return data;
}

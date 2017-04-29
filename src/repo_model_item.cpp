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
    case X:
        data = node.x();
        break;
    case Y:
        data = node.y();
        break;
    case FirstName:
        data = ((RepoNodePerson) node).firstName();
        break;
    case LastName:
        data = ((RepoNodePerson) node).lastName();
        break;
    case FullName :
        data = this->data(FirstName).toString() + " " + this->data(LastName).toString();
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

void RepoModelItem::setData(const QVariant &value, int role)
{
    switch (role)
    {
    case X:
        node.setX(value.toInt());
        break;
    case Y:
        node.setY(value.toInt());
        break;
    }
}

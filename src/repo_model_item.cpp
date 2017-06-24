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
    case Id:
        data = node.id();
        break;
    case Name:
        data = node.name();
        break;
    case Type:
        data = node.type();
        break;
    case Image:
    {
        QImage image = node.image();
        if (!image.isNull())
            data = node.image();
        break;
    }
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
    case Links:
        data = node.links();
        break;
    }
    return data;
}

void RepoModelItem::setData(const QVariant &value, int role)
{
    switch (role)
    {
    case FirstName:
    {
        RepoNodePerson::setFirstName(node, value.toString());
        break;
    }
    case JobTitle:
    {
        RepoNodePerson::setJobTitle(node, value.toString());
        break;
    }
    case Name:
    {
        node.setName(value.toString());
        break;
    }
    case Image:
    {
        QImage image = value.value<QImage>();
        node.setImage(image);
        break;
    }
    case X:
        if (data(role) != value)
        {
            node.setX(value.toDouble());
            emit xChanged();
        }
        break;
    case Y:
        if (data(role) != value)
        {
            node.setY(value.toDouble());
            emit yChanged();
        }
        break;
    case Links:
        node.setLinks(value.toList());
        break;
    }
}

double RepoModelItem::getX() const
{
    return data(X).toDouble();
}

double RepoModelItem::getY() const
{
    return data(Y).toDouble();
}

void RepoModelItem::setX(double x)
{
    setData(x,X);
}

void RepoModelItem::setY(double y)
{
    setData(y,Y);
}
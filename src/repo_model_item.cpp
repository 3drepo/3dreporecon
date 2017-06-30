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

RepoModelItem::RepoModelItem(RepoNode *node)
    : node(node)
{}

RepoModelItem::~RepoModelItem()
{
    if (node)
        delete node;
}


QVariant RepoModelItem::data(int role) const
{
    QVariant data;
    if (node)
    {
        switch (role) {
        case Id:
            data = node->id();
            break;
        case Name:
            data = node->name();
            break;
        case Notes:
            data = node->notes();
            break;
        case Type:
            data = node->type();
            break;
        case Image:
        {
            QImage image = node->image();
            if (!image.isNull())
                data = node->image();
            break;
        }
        case X:
            data = node->x();
            break;
        case Y:
            data = node->y();
            break;
        case JobTitle:
            data = ((RepoNodePerson*) node)->jobTitle();
            break;
        case LinkedIn:
            data = ((RepoNodePerson*) node)->linkedIn();
            break;
        case Email:
            data = ((RepoNodePerson*) node)->email();
            break;
        case Organisation:
            data = ((RepoNodePerson*) node)->organisation();
            break;
        case Mobile:
            data = ((RepoNodePerson*) node)->mobile();
            break;
        case Work:
            data = ((RepoNodePerson*) node)->work();
            break;
        case Links:
            data = node->links();
            break;
        }
    }
    return data;
}

void RepoModelItem::setData(const QVariant &value, int role)
{
    if (node)
    {
        switch (role)
        {
        case JobTitle:
        {
            ((RepoNodePerson*)node)->setJobTitle(value.toString());
            break;
        }
        case Email:
        {
            ((RepoNodePerson*)node)->setEmail(value.toString());
            break;
        }
        case Name:
        {
            node->setName(value.toString());
            break;
        }
        case Notes:
            node->setNotes(value.toString());
            break;
        case Image:
        {
            QImage image = value.value<QImage>();
            node->setImage(image);
            break;
        }
        case X:
            if (data(role) != value)
            {
                node->setX(value.toDouble());
                emit xChanged();
            }
            break;
        case Y:
            if (data(role) != value)
            {
                node->setY(value.toDouble());
                emit yChanged();
            }
            break;
        case Organisation:
            ((RepoNodePerson*) node)->setOrganisation(value.toString());
            break;
        case Mobile:
            ((RepoNodePerson*) node)->setMobile(value.toString());
            break;
        case Work:
            ((RepoNodePerson*) node)->setWork(value.toString());
            break;
        case Links:
            node->setLinks(value.toList());
            break;
        }
    }
}

double RepoModelItem::getX() const
{
    double x;
    if (node)
        x = data(X).toDouble();
    return x;
}

double RepoModelItem::getY() const
{
    double y;
    if (node)
        y = data(Y).toDouble();
    return y;
}

void RepoModelItem::setX(double x)
{
    setData(x, X);
}

void RepoModelItem::setY(double y)
{
    setData(y, Y);
}

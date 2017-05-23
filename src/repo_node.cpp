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

#include "repo_node.h"

using namespace repo;

RepoNode::RepoNode(const QMap<QString, QVariant> &map)
    : QMap<QString, QVariant>(map)
{}

RepoNode::RepoNode(const RepoNode &node)
    : QMap<QString, QVariant>(node)
{}

QUuid RepoNode::id() const
{
    return value("_id").toUuid();
}

void RepoNode::setId()
{
    setId(QUuid::createUuid());
}

void RepoNode::setId(const QUuid &id)
{
    insert("_id", id);
}

QString RepoNode::name() const
{
    return value("name").toString();
}

QString RepoNode::type() const
{
    return value("type").toString();
}

QImage RepoNode::image() const
{
    //value("image").toByteArray()
    //    return QImage(
    qDebug() << "qrc:/resources/alvise.jpg";
    return QImage();
}

double RepoNode::x() const
{
    return value("x").toDouble();
}

double RepoNode::y() const
{
    return value("y").toDouble();
}

void RepoNode::setX(double x)
{
    insert("x", x);
}

void RepoNode::setY(double y)
{
    insert("y", y);
}

QList<QVariant> RepoNode::links() const
{
    return value("links").toList();
}

void RepoNode::setLinks(QList<QVariant> &links)
{
    insert("links", links);
}

//void RepoNode::addLink(const QUuid &id)
//{
//    QList<QVariant> links = this->links();
//    if (!links.contains(id))
//    {
//        links.append(id);
//        setLinks(links);
//    }
//}

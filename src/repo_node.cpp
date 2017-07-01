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

void RepoNode::setName(const QString &name)
{
    insert("name", name);
}

QString RepoNode::notes() const
{
    return value("notes").toString();
}

void RepoNode::setNotes(const QString &notes)
{
    insert("notes", notes);
}

QString RepoNode::type() const
{
    return value("type").toString();
}

QImage RepoNode::image() const
{
    QImage image;
    QByteArray encoded = value("image").toString().toLatin1();
    if (!encoded.isEmpty())
        image.loadFromData(QByteArray::fromBase64(encoded), "PNG");
    return image;
}

void RepoNode::setImage(const QImage &image)
{
    QByteArray data;
    QBuffer buffer(&data);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
    insert("image", QString::fromLatin1(data.toBase64()));
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

float RepoNode::percentage() const
{
    return value("percentage").toFloat();
}

void RepoNode::setPercentage(float percentage)
{
    insert("percentage", percentage);
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

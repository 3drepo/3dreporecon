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
#include <iostream>

using namespace repo;

RepoNode::RepoNode(const QMap<QString, QVariant> &map)
    : QMap<QString, QVariant>(map)
{}

RepoNode::RepoNode(const RepoNode &node)
    : QMap<QString, QVariant>(node)
{}

QString RepoNode::id() const
{
    return value("_id").toString();
}

void RepoNode::setId()
{
    setId(QUuid::createUuid().toString());
}

void RepoNode::setId(const QString &id)
{
    insert("_id", id);
}

QString RepoNode::user() const
{
    return value("user").toString();
}

void RepoNode::setUser(const QString &user)
{
    insert("user", user);
}

QMap<QString, QVariant> RepoNode::customData() const
{
    return value("customData").toMap();
}

QMap<QString, QVariant> RepoNode::billing() const
{
    return customData().value("billing").toMap();
}

QMap<QString, QVariant> RepoNode::subscriptions() const
{
    return billing().value("subscriptions").toMap();
}
QMap<QString, QVariant> RepoNode::enterprise() const
{
    return subscriptions().value("enterprise").toMap();
}


QString RepoNode::email() const
{
    return customData().value("email").toString();
}

//void RepoNode::setEmail(const QString &email)
//{
////    ((QMap<QString, QVariant>) value("customData")).insert("email", email);
////    customData().insert("email", email);
//}

QString RepoNode::firstName() const
{
    return customData().value("firstName").toString();
}

QString RepoNode::lastName() const
{
    return customData().value("lastName").toString();
}

bool RepoNode::hereEnabled() const
{
    return customData().value("hereEnabled").toBool();
}

void RepoNode::setHereEnabled(bool on)
{
     QMap<QString, QVariant> cd = customData();
     cd.insert("hereEnabled", on);
     insert("customData", cd);
}

QDateTime RepoNode::lastLoginAt() const
{
    return customData().value("lastLoginAt").toDateTime();
}

QDateTime RepoNode::createdAt() const
{
    return customData().value("createdAt").toDateTime();
}

bool RepoNode::mailListOptOut() const
{
    return customData().value("mailListOptOut").toBool();
}

bool RepoNode::vrEnabled() const
{
    return customData().value("vrEnabled").toBool();
}

void RepoNode::setVrEnabled(bool on)
{
     QMap<QString, QVariant> cd = customData();
     cd.insert("vrEnabled", on);
     insert("customData", cd);
}

QImage RepoNode::avatar() const
{
    QImage avatar;
    QByteArray encoded = customData().value("avatar").toMap().value("data").toMap().value("$binary").toByteArray();
    if (!encoded.isEmpty()) {
        avatar.loadFromData(QByteArray::fromBase64(encoded));
        avatar = avatar.scaled(200, 200,Qt::KeepAspectRatio);
    }
    return avatar;
}

qulonglong RepoNode::enterpriseData() const
{
    qulonglong data = enterprise().value("data").toULongLong();
    return data;
}

void RepoNode::setEnterpriseData(qulonglong data)
{
    QMap<QString, QVariant> cd = customData();
    QMap<QString, QVariant> b = billing();
    QMap<QString, QVariant> s = subscriptions();
    QMap<QString, QVariant> e = enterprise();
    e.insert("data", data);
    s.insert("enterprise", e);
    b.insert("subscriptions",s);
    cd.insert("billing", b);
    this->insert("customData", cd);
}

QDateTime RepoNode::enterpriseExpiryDate() const
{
    QDateTime dt;
    QString dateValue = enterprise().value("expiryDate").toMap().value("$date").toString();
    if (!dateValue.isNull())
        dt = QDateTime::fromMSecsSinceEpoch(dateValue.toLongLong());
    return dt;
}

//QString RepoNode::notes() const
//{
//    return value("notes").toString();
//}

//void RepoNode::setNotes(const QString &notes)
//{
//    insert("notes", notes);
//}

//QString RepoNode::type() const
//{
//    return value("type").toString();
//}



//void RepoNode::setImage(const QImage &image)
//{
//    QByteArray data;
//    QBuffer buffer(&data);
//    buffer.open(QIODevice::WriteOnly);
//    image.save(&buffer, "PNG");
//    insert("image", QString::fromLatin1(data.toBase64()));
//}

//double RepoNode::x() const
//{
//    return value("x").toDouble();
//}

//double RepoNode::y() const
//{
//    return value("y").toDouble();
//}

//void RepoNode::setX(double x)
//{
//    insert("x", x);
//}

//void RepoNode::setY(double y)
//{
//    insert("y", y);
//}

//QList<QVariant> RepoNode::links() const
//{
//    return value("links").toList();
//}

//void RepoNode::setLinks(QList<QVariant> &links)
//{
//    insert("links", links);
//}

//float RepoNode::percentage() const
//{
//    return value("percentage").toFloat();
//}

//void RepoNode::setPercentage(float percentage)
//{
//    insert("percentage", percentage);
//}

//void RepoNode::addLink(const QUuid &id)
//{
//    QList<QVariant> links = this->links();
//    if (!links.contains(id))
//    {
//        links.append(id);
//        setLinks(links);
//    }
//}

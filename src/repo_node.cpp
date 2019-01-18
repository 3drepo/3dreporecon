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
    return value(RepoNodeSchema::_ID).toString();
}

void RepoNode::setId()
{
    setId(QUuid::createUuid().toString());
}

void RepoNode::setId(const QString &id)
{
    insert(RepoNodeSchema::_ID, id);
}

QString RepoNode::user() const
{
    return value(RepoNodeSchema::USER).toString();
}

void RepoNode::setUser(const QString &user)
{
    insert(RepoNodeSchema::USER, user);
}

QMap<QString, QVariant> RepoNode::customData() const
{
    return value(RepoNodeSchema::CUSTOM_DATA).toMap();
}

QMap<QString, QVariant> RepoNode::billing() const
{
    return customData().value(RepoNodeSchema::BILLING).toMap();
}

QMap<QString, QVariant> RepoNode::subscriptions() const
{
    return billing().value(RepoNodeSchema::SUBSCRIPTIONS).toMap();
}
QMap<QString, QVariant> RepoNode::enterprise() const
{
    return subscriptions().value(RepoNodeSchema::ENTERPRISE).toMap();
}

QMap<QString, QVariant> RepoNode::discretionary() const
{
    return subscriptions().value(RepoNodeSchema::DISCRETIONARY).toMap();
}

QString RepoNode::email() const
{
    return customData().value(RepoNodeSchema::EMAIL).toString();
}

//void RepoNode::setEmail(const QString &email)
//{
////    ((QMap<QString, QVariant>) value("customData")).insert("email", email);
////    customData().insert("email", email);
//}

QString RepoNode::firstName() const
{
    return customData().value(RepoNodeSchema::FIRST_NAME).toString();
}

QString RepoNode::lastName() const
{
    return customData().value(RepoNodeSchema::LAST_NAME).toString();
}

bool RepoNode::hereEnabled() const
{
    return customData().value(RepoNodeSchema::HERE_ENABLED).toBool();
}

void RepoNode::setHereEnabled(bool on)
{
     QMap<QString, QVariant> cd = customData();
     cd.insert(RepoNodeSchema::HERE_ENABLED, on);
     insert(RepoNodeSchema::CUSTOM_DATA, cd);
}

QDateTime RepoNode::lastLoginAt() const
{
    return customData().value(RepoNodeSchema::LAST_LOGIN_AT).toDateTime();
}

QDateTime RepoNode::createdAt() const
{
    return customData().value(RepoNodeSchema::CREATED_AT).toDateTime();
}

bool RepoNode::mailListOptOut() const
{
    return customData().value(RepoNodeSchema::MAIL_LIST_OPT_OUT).toBool();
}

bool RepoNode::vrEnabled() const
{
    return customData().value(RepoNodeSchema::VR_ENABLED).toBool();
}

void RepoNode::setVrEnabled(bool on)
{
     QMap<QString, QVariant> cd = customData();
     cd.insert(RepoNodeSchema::VR_ENABLED, on);
     insert(RepoNodeSchema::CUSTOM_DATA, cd);
}

QImage RepoNode::avatar() const
{
    QImage avatar;
    QByteArray encoded = customData().value(RepoNodeSchema::AVATAR).toMap().value(RepoNodeSchema::DATA).toMap().value(RepoNodeSchema::$BINARY).toByteArray();
    if (!encoded.isEmpty()) {
        avatar.loadFromData(QByteArray::fromBase64(encoded));
        avatar = avatar.scaled(200, 200,Qt::KeepAspectRatio);
    }
    return avatar;
}

qulonglong RepoNode::enterpriseData() const
{
    qulonglong data = enterprise().value(RepoNodeSchema::DATA).toULongLong();
    return data;
}

void RepoNode::setEnterpriseData(qulonglong data)
{
    QMap<QString, QVariant> cd = customData();
    QMap<QString, QVariant> b = billing();
    QMap<QString, QVariant> s = subscriptions();
    QMap<QString, QVariant> e = enterprise();
    e.insert(RepoNodeSchema::DATA, data);
    s.insert(RepoNodeSchema::ENTERPRISE, e);
    b.insert(RepoNodeSchema::SUBSCRIPTIONS,s);
    cd.insert(RepoNodeSchema::BILLING, b);
    this->insert(RepoNodeSchema::CUSTOM_DATA, cd);
}

QDateTime RepoNode::enterpriseExpiryDate() const
{
    QDateTime dt;
    QString dateValue = enterprise().value(RepoNodeSchema::EXPIRY_DATE).toMap().value(RepoNodeSchema::$DATE).toString();
    if (!dateValue.isNull())
        dt = QDateTime::fromMSecsSinceEpoch(dateValue.toLongLong());
    return dt;
}

QString RepoNode::enterpriseCollaborators() const
{
    return enterprise().value(RepoNodeSchema::COLLABORATORS).toString();
}

void RepoNode::setEnterpriseCollaborators(const QString str)
{
    QMap<QString, QVariant> cd = customData();
    QMap<QString, QVariant> b = billing();
    QMap<QString, QVariant> s = subscriptions();
    QMap<QString, QVariant> e = enterprise();

    e.insert(RepoNodeSchema::COLLABORATORS, str);

    s.insert(RepoNodeSchema::ENTERPRISE, e);
    b.insert(RepoNodeSchema::SUBSCRIPTIONS,s);
    cd.insert(RepoNodeSchema::BILLING, b);
    this->insert(RepoNodeSchema::CUSTOM_DATA, cd);
}

void RepoNode::setEnterpriseCollaborators(int count)
{
    QMap<QString, QVariant> cd = customData();
    QMap<QString, QVariant> b = billing();
    QMap<QString, QVariant> s = subscriptions();
    QMap<QString, QVariant> e = enterprise();

    e.insert(RepoNodeSchema::COLLABORATORS, count);

    s.insert(RepoNodeSchema::ENTERPRISE, e);
    b.insert(RepoNodeSchema::SUBSCRIPTIONS,s);
    cd.insert(RepoNodeSchema::BILLING, b);
    this->insert(RepoNodeSchema::CUSTOM_DATA, cd);
}

qulonglong RepoNode::discretionaryData() const
{
    qulonglong data = discretionary().value(RepoNodeSchema::DATA).toULongLong();
    return data;
}

void RepoNode::setDiscretionaryData(qulonglong data)
{
    QMap<QString, QVariant> cd = customData();
    QMap<QString, QVariant> b = billing();
    QMap<QString, QVariant> s = subscriptions();
    QMap<QString, QVariant> d = discretionary();

    d.insert(RepoNodeSchema::DATA, data);

    s.insert(RepoNodeSchema::DISCRETIONARY, d);
    b.insert(RepoNodeSchema::SUBSCRIPTIONS,s);
    cd.insert(RepoNodeSchema::BILLING, b);
    this->insert(RepoNodeSchema::CUSTOM_DATA, cd);
}

QDateTime RepoNode::discretionaryExpiryDate() const
{
    QDateTime dt;
    QString dateValue = discretionary().value(RepoNodeSchema::EXPIRY_DATE).toMap().value(RepoNodeSchema::$DATE).toString();
    if (!dateValue.isNull())
        dt = QDateTime::fromMSecsSinceEpoch(dateValue.toLongLong());
    return dt;
}


QString RepoNode::discretionaryCollaborators() const
{
    return discretionary().value(RepoNodeSchema::COLLABORATORS).toString();
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

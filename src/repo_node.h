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

#include <QMap>
#include <QVariant>
#include <QString>
#include <QImage>
#include <QUuid>
#include <QDebug>
#include <QList>
#include <QBuffer>
#include <QDateTime>

#include <iostream>

namespace repo
{

class RepoNode : public QMap<QString, QVariant>
{

public:

    RepoNode() : QMap<QString, QVariant>() {}

    RepoNode(const QMap<QString, QVariant> &map);

    RepoNode(const RepoNode &node);

    QString id() const;

    void setId();

    void setId(const QString &id);

    QString user() const;

    void setUser(const QString &user);

    QString email() const;

//    void setEmail(const QString &email);

    QString firstName() const;

    QString lastName() const;

    bool hereEnabled() const;

    void setHereEnabled(bool on);

    QDateTime lastLoginAt() const;

    QDateTime createdAt() const;

    bool mailListOptOut() const;

    bool vrEnabled() const;

    void setVrEnabled(bool on);

    QImage avatar() const;

    //! Returns enterprise account data allocation in MiB
    qulonglong enterpriseData() const;

    void setEnterpriseData(qulonglong data);

    QDateTime enterpriseExpiryDate() const;

private :

    QMap<QString, QVariant> customData() const;

    QMap<QString, QVariant> billing() const;

    QMap<QString, QVariant> subscriptions() const;

    QMap<QString, QVariant> enterprise() const;


//    QString notes() const;

//    void setNotes(const QString &notes);

//    QString type() const;



//    void setImage(const QImage &image);

//    double x() const;

//    double y() const;

//    void setX(double x);

//    void setY(double y);

//    QList<QVariant> links() const;

//    void setLinks(QList<QVariant> &links);

//    float percentage() const;

//    void setPercentage(float percentage);

//    void addLink(const QUuid &id);
};

}

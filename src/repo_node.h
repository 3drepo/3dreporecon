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

namespace repo
{

class RepoNode : public QMap<QString, QVariant>
{

public:

    RepoNode() : QMap<QString, QVariant>() {}

    RepoNode(const QMap<QString, QVariant> &map);

    RepoNode(const RepoNode &node);

    QUuid id() const;

    void setId();

    void setId(const QUuid &id);

    QString name() const;

    void setName(const QString &name);

    QString notes() const;

    void setNotes(const QString &notes);

    QString type() const;

    QImage image() const;

    void setImage(const QImage &image);

    double x() const;

    double y() const;

    void setX(double x);

    void setY(double y);

    QList<QVariant> links() const;

    void setLinks(QList<QVariant> &links);

//    void addLink(const QUuid &id);
};

}

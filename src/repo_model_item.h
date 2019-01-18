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

#include <QString>
#include <QStandardItem>
#include <QLocale>
#include <QDebug>
#include <QtMath>

#include "repo_node.h"
#include "repo_node_company.h"
#include "repo_node_person.h"
#include "repo_node_project.h"

namespace repo
{

class RepoModelItem : public QObject, public QStandardItem
{

public :

    Q_OBJECT

    Q_PROPERTY(QUuid id READ getId)
//    Q_PROPERTY(double x READ getX NOTIFY xChanged)
//    Q_PROPERTY(double y READ getY NOTIFY yChanged)


public :

    enum ItemRole {

        //-------
        // Node
        //-------
        Id = Qt::UserRole + 1,
        User,
        Email,
        FirstName,
        LastName,
        Name,
        HereEnabled,
        LastLoginAt,
        CreatedAt,
        MailListOptOut,
        VrEnabled,
        Image,
        EnterpriseData,
        EnterpriseExpiryDate
        /*,
        Notes,
        Type,
        Image,
        X,
        Y,
        Percentage,

        //-------
        // Person
        //-------
        JobTitle,
        LinkedIn,
        Email,
        Links,
        Organisation,
        Mobile,
        Work*/
    };

public:

    RepoModelItem(RepoNode *node = nullptr);
    ~RepoModelItem();

    QVariant data(int role = Qt::UserRole + 1) const;

    void setData(const QVariant &value, int role = Qt::UserRole + 1);

    RepoNode* getNode() { return node; }

    QUuid getId() const;

    QString megabytesToString(quint64 megabytes) const;

    //! Takes input in form of "12 GB" for instance. Must contain space!
    quint64 stringToMegabytes(const QString str) const;

//    double getX() const;
//    double getY() const;

//signals:

//    void xChanged();
//    void yChanged();

private :

    RepoNode *node;
};

}

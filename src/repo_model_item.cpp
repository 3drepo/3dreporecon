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
        case User:
            data = node->user();
            break;
        case Email:
            data = node->email();
            break;
        case FirstName:
            data = node->firstName();
            break;
        case LastName:
            data = node->lastName();
            break;
        case Name:
            data = node->firstName() + " " + node->lastName();
            break;
        case HereEnabled :
            data = node->hereEnabled();
            break;
        case LastLoginAt:
            data = node->lastLoginAt();
            break;
        case CreatedAt:
            data = node->createdAt();
            break;
        case MailListOptOut:
            data = node->mailListOptOut();
            break;
        case VrEnabled:
            data = node->vrEnabled();
            break;
        case Image:
        {
            QImage avatar = node->avatar();
            if (!avatar.isNull())
                data = node->avatar();
            break;
        }
        case Enterprise:
            data = !node->enterprise().isEmpty();
            break;
        case EnterpriseData:
            data = megabytesToString(static_cast<quint64>(node->enterpriseData()));
            break;
        case EnterpriseExpiryDate:
            data = node->enterpriseExpiryDate();
            break;
        case EnterpriseCollaborators:
            data = node->enterpriseCollaborators();
            break;
        case Discretionary:
            data = !node->discretionary().isEmpty();
            break;
        case DiscretionaryData:
            data = megabytesToString(static_cast<quint64>(node->discretionaryData()));
            break;
        case DiscretionaryExpiryDate:
            data = node->discretionaryExpiryDate();
            break;
        case DiscretionaryCollaborators:
            data = node->discretionaryCollaborators();
            break;
            //        case Notes:
            //            data = node->notes();
            //            break;
            //        case Type:
            //            data = node->type();
            //            break;

            //        case X:
            //            data = node->x();
            //            break;
            //        case Y:
            //            data = node->y();
            //            break;
            //        case Percentage:
            //            data = node->percentage();
            //            break;
            //        case JobTitle:
            //            data = ((RepoNodePerson*) node)->jobTitle();
            //            break;
            //        case LinkedIn:
            //            data = ((RepoNodePerson*) node)->linkedIn();
            //            break;
            //        case Email:
            //            data = ((RepoNodePerson*) node)->email();
            //            break;
            //        case Organisation:
            //            data = ((RepoNodePerson*) node)->organisation();
            //            break;
            //        case Mobile:
            //            data = ((RepoNodePerson*) node)->mobile();
            //            break;
            //        case Work:
            //            data = ((RepoNodePerson*) node)->work();
            //            break;
            //        case Links:
            //            data = node->links();
            //            break;
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
        //        case JobTitle:
        //        {
        //            ((RepoNodePerson*)node)->setJobTitle(value.toString());
        //            break;
        //        }
        //        case Email:
        //        {
        //            ((RepoNodePerson*)node)->setEmail(value.toString());
        //            break;
        //        }
        case User:
            node->setUser(value.toString());
            break;
        case HereEnabled:
            node->setHereEnabled(value.toBool());
            break;
        case VrEnabled:
            node->setVrEnabled(value.toBool());
            break;
        case EnterpriseData:
            node->setEnterpriseData(stringToMegabytes(value.toString()));
            break;
            //        case Notes:
            //            node->setNotes(value.toString());
            //            break;
            //        case Image:
            //        {
            //            QImage image = value.value<QImage>();
            //            node->setImage(image);
            //            break;
            //        }
            //        case X:
            //            if (data(role) != value)
            //            {
            //                node->setX(value.toDouble());
            //                emit xChanged();
            //            }
            //            break;
            //        case Y:
            //            if (data(role) != value)
            //            {
            //                node->setY(value.toDouble());
            //                emit yChanged();
            //            }
            //            break;
            //        case Percentage:
            //            node->setPercentage(value.toFloat());
            //            break;
            //        case Organisation:
            //            ((RepoNodePerson*) node)->setOrganisation(value.toString());
            //            break;
            //        case Mobile:
            //            ((RepoNodePerson*) node)->setMobile(value.toString());
            //            break;
            //        case Work:
            //            ((RepoNodePerson*) node)->setWork(value.toString());
            //            break;
            //        case Links:
            ////            node->setLinks(value.toList());
            //            break;
        }
    }
}

QUuid RepoModelItem::getId() const
{
    QUuid id;
    if (node)
        id = data(Id).toUuid();
    return id;
}

QString RepoModelItem::megabytesToString(quint64 megabytes) const
{
    QString mega;
    if (megabytes > 0)
        mega = QLocale::system().formattedDataSize((quint64) megabytes * qPow(1024, 2),
                                                   0,
                                                   QLocale::DataSizeTraditionalFormat);
    return mega;
}

quint64 RepoModelItem::stringToMegabytes(const QString str) const
{
    Q_ASSERT(str.contains(" "));
    QStringList split = str.split(" ");
    const static QStringList extension = {"bytes", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB" };
    return (split[0].toULongLong() * qPow(1024, extension.indexOf(QRegExp(split[1], Qt::CaseSensitivity::CaseInsensitive)))) / qPow(1024, 2);
}

//double RepoModelItem::getX() const
//{
//    double x;
//    if (node)
//        x = data(X).toDouble();
//    return x;
//}

//double RepoModelItem::getY() const
//{
//    double y;
//    if (node)
//        y = data(Y).toDouble();
//    return y;
//}

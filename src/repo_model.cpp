/**
*  Copyright (C) 2018 3D Repo Ltd
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

#include "repo_model.h"
#include "repo_db_mongo.h"

using namespace repo;

QHash<int, QByteArray> RepoModel::roles = {
    {RepoModelItem::Id, "id"},
    {RepoModelItem::User, "user"},
    {RepoModelItem::Email, "email"},
    {RepoModelItem::FirstName, "firstName"},
    {RepoModelItem::LastName, "lastName"},
    {RepoModelItem::Name, "name"},
    {RepoModelItem::HereEnabled, "hereEnabled"},
    {RepoModelItem::LastLoginAt, "lastLoginAt"},
    {RepoModelItem::CreatedAt, "createdAt"},
    {RepoModelItem::MailListOptOut, "mailListOptOut"},
    {RepoModelItem::VrEnabled, "vrEnabled"},
    {RepoModelItem::Image, "image"},
    {RepoModelItem::Enterprise, "enterprise"},
    {RepoModelItem::EnterpriseData, "enterpriseData"},
    {RepoModelItem::EnterpriseExpiryDate, "enterpriseExpiryDate"},
    {RepoModelItem::EnterpriseCollaborators, "enterpriseCollaborators"},
    {RepoModelItem::Discretionary, "discretionary"},
    {RepoModelItem::DiscretionaryData, "discretionaryData"},
    {RepoModelItem::DiscretionaryExpiryDate, "discretionaryExpiryDate"},
    {RepoModelItem::DiscretionaryCollaborators, "discretionaryCollaborators"}


//    {RepoModelItem::Notes, "notes"},
//    {RepoModelItem::Type, "type"},
//    {RepoModelItem::Image, "image"},
//    {RepoModelItem::X, "x"},
//    {RepoModelItem::Y, "y"},
//    {RepoModelItem::Percentage, "percentage"},
//    {RepoModelItem::JobTitle, "jobTitle"},
//    {RepoModelItem::LinkedIn, "linkedIn"},
//    {RepoModelItem::Email, "email"},
//    {RepoModelItem::Organisation, "organisation"},
//    {RepoModelItem::Mobile, "mobile"},
//    {RepoModelItem::Work, "work"},
//    {RepoModelItem::Links, "links"}
};

RepoModel::RepoModel()
    : QSortFilterProxyModel()
    , model(new QStandardItemModel())
    , db(RepoDBMongo::instance())
   // , jsonFile("c:\\Users\\jozef\\workspace\\3DRepo\\3dreporecon\\resources\\nodes.json")
{
    setDynamicSortFilter(true);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setSourceModel(model);
}

RepoModel::~RepoModel()
{
   // RepoJsonParser::write(this->toList(), jsonFile.absoluteFilePath());
    delete model;
}

void RepoModel::populate()
{   
    model->clear();
    for (QVariant node : db.fetchData())
        appendRow(new RepoModelItem(new (RepoNode)(node.toMap())));
}

QVariant RepoModel::data(const QModelIndex &proxyIndex, int role) const
{
    QVariant data;
//    if (role == RepoModelItem::Links)
//    {
//        QList<QObject *> links = this->links(this->item(proxyIndex.row()));
//        data.setValue(links);
//    }
//    else
//    {
        data = QSortFilterProxyModel::data(proxyIndex, role);
//    }
    return data;
}

QVariant RepoModel::data(int row, const QString &roleName) const
{
    return data(index(row, 0), role(roleName));
}

QHash<int, QByteArray> RepoModel::roleNames() const
{
    return roles;
}

QList<RepoNode> RepoModel::nodes() const
{
    QList<RepoNode> nodes;
    for (int i = 0; i < model->rowCount(); ++i)
    {
        RepoModelItem *item = static_cast<RepoModelItem*>(model->item(i));
        if (item)
            nodes.append(*(item->getNode()));
    }
    return nodes;
}

QList<QVariant> RepoModel::toList() const
{
    QList<QVariant> nodes;
    for (int i = 0; i < model->rowCount(); ++i)
    {
        RepoModelItem *item = static_cast<RepoModelItem*>(model->item(i));
        if (item)
            nodes.append(*(item->getNode()));
    }
    return nodes;
}

QUuid RepoModel::appendRow(int x, int y)
{
    RepoNode *node = new RepoNode();
    node->setId();
//    node->setX(x);
//    node->setY(y);
    return appendRow(new RepoModelItem(node));
}

QUuid RepoModel::appendRow(RepoModelItem *item)
{
    model->appendRow(item);
    QUuid id = item->data(RepoModelItem::Id).toUuid();
    itemsByID.insert(id, item);
    return id;
}

bool RepoModel::removeRow(int proxyRow, const QModelIndex &proxyParentIndex)
{    
    RepoModelItem* item = this->item(proxyRow, proxyParentIndex);
    bool success = false;
//    if (item)
//    {
//        for (QVariant id : item->data(RepoModelItem::Links).toList())
//        {
//            RepoModelItem* linkedItem = itemsByID[id.toUuid()];
//            if (linkedItem)
//            {
//                QList<QVariant> links = linkedItem->data(RepoModelItem::Links).toList();
//                links.removeAll(item->data(RepoModelItem::Id));
//                this->setData(linkedItem, links, RepoModelItem::Links);
//            }
//        }
//        this->setData(item, QList<QVariant>(), RepoModelItem::Links);
//        itemsByID.remove(item->data(RepoModelItem::Id).toUuid());
//        success = model->removeRow(model->indexFromItem(item).row());
//        item = nullptr; // item has been deleted by removeRow
//    }
    return success;
}

bool RepoModel::setData(RepoModelItem *item, const QVariant &value, int role)
{
    bool success = false;
    if ((success = (item != nullptr)))
    {
        if ((success = (value != item->data(role))))
        {
            item->setData(value, role);
            QModelIndex index = this->mapFromSource(model->indexFromItem(item));
            emit dataChanged(index, index, QVector<int>() << role);

            if (role == RepoModelItem::VrEnabled)
                db.update(item->data(RepoModelItem::Id), value, RepoDBAbstract::VrEnabled);
            else if (role == RepoModelItem::HereEnabled)
                db.update(item->data(RepoModelItem::Id), value, RepoDBAbstract::HereEnabled);
        }
    }
    return success;
}

bool RepoModel::setData(const QModelIndex &proxyIndex, const QVariant &value, int role)
{
    return setData(static_cast<RepoModelItem*>(model->itemFromIndex(mapToSource(proxyIndex))), value, role);
}

bool RepoModel::setData(int row, const QVariant &value, const QVariant &roleName)
{
    return setData(index(row, 0), value, role(roleName));
}

bool RepoModel::setData(const QUuid &id, const QVariant &value, const QVariant &roleName)
{
    return setData(this->item(id), value, role(roleName));
}

bool RepoModel::setImage(int row, const QUrl &fileUrl)
{
    QImage image(fileUrl.toLocalFile());
    return setData(row, image, "image");
}

int RepoModel::role(const QVariant &roleName) const
{
    return roles.key(roleName.toByteArray(), -1);
}

bool RepoModel::filterAcceptsRow(int sourceRow, const QModelIndex &) const
{
    bool accept = false;
    RepoModelItem *item = static_cast<RepoModelItem*>(model->item(sourceRow));
    if (item != nullptr)
    {
        QString comparator = filterCaseSensitivity() == Qt::CaseInsensitive
                ? _filter.toLower()
                : _filter;
        QString name = filterCaseSensitivity() == Qt::CaseInsensitive
                ? item->data(RepoModelItem::Name).toString().toLower()
                : item->data(RepoModelItem::Name).toString();
        QString email = filterCaseSensitivity() == Qt::CaseInsensitive
                ? item->data(RepoModelItem::Email).toString().toLower()
                : item->data(RepoModelItem::Email).toString();

        accept = name.contains(comparator) || email.contains(comparator);
    }
    return accept;
}

void RepoModel::filter(const QString &filter)
{
    _filter = filter;
    invalidateFilter();
}

RepoModelItem* RepoModel::item(int proxyRow, const QModelIndex &proxyParentIndex) const
{
    return static_cast<RepoModelItem*>(model->itemFromIndex(mapToSource(index(proxyRow, 0, proxyParentIndex))));
}

RepoModelItem* RepoModel::item(const QUuid &id) const
{
    return itemsByID[id];
}

QList<QObject *> RepoModel::links(const RepoModelItem* item) const
{
    QList<QObject *> endPoints;
//    if (item)
//    {
//        QList<QVariant> links = item->data(RepoModelItem::Links).toList();
//        for (QVariant l : links)
//        {
//            if (RepoModelItem *endItem = this->item(l.toUuid()))
//            {
//                endPoints.append(endItem);
//            }
//        }
//    }
    return endPoints;
}

QList<QObject *> RepoModel::links(int proxyRow) const
{
    return links(this->item(proxyRow));
}

QList<QObject *> RepoModel::links(const QUuid &id) const
{
    return links(item(id));
}

void RepoModel::addLink(const QUuid &id1, const QUuid &id2)
{
//    RepoModelItem *item1 = itemsByID[id1];
//    RepoModelItem *item2 = itemsByID[id2];

//    if (item1 && item2)
//    {
//        QList<QVariant> links1 = item1->data(RepoModelItem::Links).toList();
//        if (!links1.contains(id2))
//        {
//            links1.append(id2);
//            this->setData(item1, links1, RepoModelItem::Links);
//        }

//        QList<QVariant> links2 = item2->data(RepoModelItem::Links).toList();
//        if (!links2.contains(id1))
//        {
//            links2.append(id1);
//            this->setData(item2, links2, RepoModelItem::Links);
//        }
//    }
}

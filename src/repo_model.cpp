#include "repo_model.h"

using namespace repo;

QHash<int, QByteArray> RepoModel::roles = {
    {RepoModelItem::ID,  "id"},
    {RepoModelItem::Name, "name"},
    {RepoModelItem::Type, "type"},
    {RepoModelItem::Image, "image"},
    {RepoModelItem::X, "x"},
    {RepoModelItem::Y, "y"},
    {RepoModelItem::FirstName, "firstName"},
    {RepoModelItem::LastName, "lastName"},
    {RepoModelItem::JobTitle, "jobTitle"},
    {RepoModelItem::LinkedIn, "linkedIn"},
    {RepoModelItem::Email, "email"}
};

RepoModel::RepoModel()
    : QSortFilterProxyModel()
    , model(new QStandardItemModel())
{
    setDynamicSortFilter(true);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setSourceModel(model);

    populate();
}

RepoModel::~RepoModel()
{
    QFileInfo file("c:\\Users\\jozef\\workspace\\3DRepo\\3dreporecon\\resources\\nodes.csv");
    RepoCSVParser::write(nodes(), file.absoluteFilePath());

    delete model;
}

void RepoModel::populate()
{
    QFileInfo file("c:\\Users\\jozef\\workspace\\3DRepo\\3dreporecon\\resources\\nodes.csv");
    QList<RepoNode> nodes = RepoCSVParser::read(file.absoluteFilePath());

    for (RepoNode node : nodes)
    {
        appendRow(new RepoModelItem(node));
    }
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
        RepoModelItem *item = (RepoModelItem *) (model->item(i));
        if (item)
            nodes.append(item->getNode());
    }
    return nodes;
}

QUuid RepoModel::appendRow(int x, int y)
{
    RepoNode node;
    node.setId();
    node.setX(x);
    node.setY(y);
    return appendRow(new RepoModelItem(node));
}

QUuid RepoModel::appendRow(RepoModelItem *item)
{
    model->appendRow(item);
    QUuid id = item->data(RepoModelItem::ID).toUuid();
    itemsByID.insert(id, item);
    return id;
}

bool RepoModel::removeRow(int proxyRow, const QModelIndex &)
{    
    RepoModelItem* item = this->item(proxyRow);
    bool success = false;
    if (item)
    {
        itemsByID.remove(item->data(RepoModelItem::ID).toUuid());
        success = model->removeRow(model->indexFromItem(item).row());
    }
    // TODO: make sure all links are deleted as well
    return success;
}

bool RepoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool success;
    RepoModelItem *item = (RepoModelItem*) model->itemFromIndex(mapToSource(index));
    if (success = (item != NULL))
    {
        item->setData(value, role);
        emit dataChanged(index, index, QVector<int>() << role);
    }
    return success;
}

bool RepoModel::setData(int row, const QVariant &value, const QVariant &roleName)
{
    return setData(index(row, 0), value, role(roleName));
}

int RepoModel::role(const QVariant &roleName) const
{
    return roles.key(roleName.toByteArray(), -1);
}

bool RepoModel::filterAcceptsRow(int sourceRow, const QModelIndex &) const
{
    bool accept = false;
    RepoModelItem *item = (RepoModelItem*) model->item(sourceRow);
    if (item != NULL)
    {
        QString comparator = filterCaseSensitivity() == Qt::CaseInsensitive
                ? _filter.toLower()
                : _filter;
        QString fullName = filterCaseSensitivity() == Qt::CaseInsensitive
                ? item->data(RepoModelItem::FullName).toString().toLower()
                : item->data(RepoModelItem::FullName).toString();
        accept = fullName.contains(comparator);
    }
    return accept;
}

void RepoModel::filter(const QString &filter)
{
    _filter = filter;
    invalidateFilter();
}


RepoModelItem* RepoModel::item(int proxyRow) const
{
    return (RepoModelItem*) model->itemFromIndex(mapToSource(index(proxyRow, 0)));
}

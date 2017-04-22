#include "repo_model.h"

using namespace repo;

QHash<int, QByteArray> RepoModel::roles = {
    {RepoModelItem::ItemRole::ID,  "id"},
    {RepoModelItem::ItemRole::Name, "name"},
    {RepoModelItem::ItemRole::Type, "type"},
    {RepoModelItem::ItemRole::Image, "image"},
    {RepoModelItem::ItemRole::X, "x"},
    {RepoModelItem::ItemRole::Y, "y"},
    {RepoModelItem::ItemRole::FirstName, "firstName"},
    {RepoModelItem::ItemRole::LastName, "lastName"},
    {RepoModelItem::ItemRole::JobTitle, "jobTitle"},
    {RepoModelItem::ItemRole::LinkedIn, "linkedIn"},
    {RepoModelItem::ItemRole::Email, "email"}
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

    //    emit beginInsertRows(QModelIndex(), 0, nodes.size());
    for (RepoNode node : nodes)
    {
        model->appendRow(new RepoModelItem(node));
    }
    //    emit endInsertRows();
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

void RepoModel::addNode(int x, int y)
{
    RepoNode node;
    node.setX(x);
    node.setY(y);
    model->appendRow(new RepoModelItem(node));
}

bool RepoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool success;
    RepoModelItem *item = (RepoModelItem*) model->itemFromIndex(mapToSource(index));
    if (success = (item != NULL))
    {
        item->setData(value, role);
//        emit dataChanged(index, index, QVector<int>() << role);
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

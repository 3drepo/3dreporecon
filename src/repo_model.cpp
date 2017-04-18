#include "repo_model.h"

using namespace repo;

QHash<int, QByteArray> RepoModel::roles = {
    {RepoModelItem::ItemRoles::ID,  "id"},
    {RepoModelItem::ItemRoles::Name, "name"},
    {RepoModelItem::ItemRoles::Type, "type"},
    {RepoModelItem::ItemRoles::Image, "image"},
    {RepoModelItem::ItemRoles::Point, "point"},
    {RepoModelItem::ItemRoles::FirstName, "firstName"},
    {RepoModelItem::ItemRoles::LastName, "lastName"},
    {RepoModelItem::ItemRoles::JobTitle, "jobTitle"},
    {RepoModelItem::ItemRoles::LinkedIn, "linkedIn"},
    {RepoModelItem::ItemRoles::Email, "email"}
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
    emit beginInsertRows(QModelIndex(), 0, 0);

    QFileInfo file("c:\\Users\\jozef\\workspace\\3DRepo\\3dreporecon\\resources\\nodes.csv");
    QList<RepoNode> nodes = RepoCSVParser::read(file.absoluteFilePath());
    for (RepoNode node : nodes)
    {
        model->appendRow(new RepoModelItem(node));
    }

    emit endInsertRows();
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

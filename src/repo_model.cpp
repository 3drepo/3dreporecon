#include "repo_model.h"

using namespace repo;

RepoModel::RepoModel()
    : QSortFilterProxyModel()
    , model(new QStandardItemModel())
{
    setDynamicSortFilter(true);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setSourceModel(model);
}

RepoModel::~RepoModel()
{
    delete model;
}

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

#include "repo_model_image_provider.h"

using namespace repo;

RepoModelImageProvider::RepoModelImageProvider(RepoModel *model)
    : QQuickImageProvider(QQuickImageProvider::Image/*,
                          QQmlImageProviderBase::ForceAsynchronousImageLoading*/)
    , model(model)
{}

QImage RepoModelImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QImage image;
    int width = requestedSize.width() > 0 ? requestedSize.width() : 32;
    int height = requestedSize.height() > 0 ? requestedSize.height() : 32;

    // ID comes in as %7Bf77cf295-1817-48aa-aaef-a9f627c5edfa%7D
    // where "%7B" corresponds to "{" and "%7D" to "}"

    QString str(id);
    str.remove(0, 3); // remove "%7B"
    str.remove(36, 3); // remove "%7D"
    RepoModelItem *item = model->item(QUuid(str));
    if (item)
    {
//        image = item->data(RepoModelItem::Image).value<QImage>();
//        image = image.scaled(width, height);
    }
    *size = QSize(width, height);
    return image;
}

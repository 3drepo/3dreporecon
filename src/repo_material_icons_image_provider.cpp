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

#include "repo_material_icons_image_provider.h"

#include <iostream>

using namespace repo;

QPixmap RepoMaterialIconsImageProvider::requestPixmap(
        const QString &id,
        QSize *size,
        const QSize & requestedSize)
{
    QPixmap pixmap;

    int width = requestedSize.width() > 0 ? requestedSize.width() : 32;
    int height = requestedSize.height() > 0 ? requestedSize.height() : 32;

    if (id == "menu")
        pixmap = RepoMaterialIcons::getMenuIcon().pixmap(width, height);
    else if (id == "moreVert")
        pixmap = RepoMaterialIcons::getMoreVertIcon().pixmap(width, height);
    else if (id == "people")
        pixmap = RepoMaterialIcons::getPeopleIcon().pixmap(width, height);
    else if (id == "accountCircle")
        pixmap = RepoMaterialIcons::getAccountCircleIcon().pixmap(width, height);
    else if (id == "business")
        pixmap = RepoMaterialIcons::getBusinessIcon().pixmap(width, height);

    *size = QSize(width, height);
    return pixmap;
}


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

    QStringList iconInstructions = id.split("/");
    QString icon = iconInstructions[0];
    QColor color("white");
    if (iconInstructions.length() == 2)
    {
        color = QColor(iconInstructions[1]);
    }

    int width = requestedSize.width() > 0 ? requestedSize.width() : 32;
    int height = requestedSize.height() > 0 ? requestedSize.height() : 32;

    if (icon == "menu")
        pixmap = RepoMaterialIcons::getMenuIcon(color).pixmap(width, height);
    else if (icon == "moreVert")
        pixmap = RepoMaterialIcons::getMoreVertIcon(color).pixmap(width, height);
    else if (icon == "add")
        pixmap = RepoMaterialIcons::getAddIcon(color).pixmap(width, height);
    else if (icon == "person")
        pixmap = RepoMaterialIcons::getPersonIcon(color).pixmap(width, height);
    else if (icon == "people")
        pixmap = RepoMaterialIcons::getPeopleIcon(color).pixmap(width, height);
    else if (icon == "accountCircle")
        pixmap = RepoMaterialIcons::getAccountCircleIcon(color).pixmap(width, height);
    else if (icon == "business")
        pixmap = RepoMaterialIcons::getBusinessIcon(color).pixmap(width, height);
    else if (icon == "arrowBack")
        pixmap = RepoMaterialIcons::getArrowBackIcon(color).pixmap(width, height);
    else if (icon == "notificationsNone")
        pixmap = RepoMaterialIcons::getNotificationsNoneIcon().pixmap(width, height);
    else if (icon == "clear")
        pixmap = RepoMaterialIcons::getClearIcon(color).pixmap(width, height);
    else if (icon == "search")
        pixmap = RepoMaterialIcons::getSearchIcon(color).pixmap(width, height);
    else if (icon == "assignment")
        pixmap = RepoMaterialIcons::getAssignmentIcon(color).pixmap(width, height);

    *size = QSize(width, height);
    return pixmap;
}


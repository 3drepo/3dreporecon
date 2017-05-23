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

#include <QQuickPaintedItem>
#include <QBrush>
#include <QPoint>
#include <QPainter>
#include <QUuid>

namespace repo
{

class RepoModelItemPainter : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QUuid uuid READ getUuid WRITE setUuid NOTIFY uuidChanged)

public:

    RepoModelItemPainter(QQuickItem *parent = 0);

    void paint(QPainter *painter);

    QUuid getUuid() const;

    void setUuid(const QUuid &uuid);

signals :

    void uuidChanged();

private :

    QUuid _uuid;

};

}

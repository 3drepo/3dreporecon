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
#include <QLine>
#include <QPainter>

namespace repo
{

class RepoModelItemLinkPainter : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(int x1 READ getX1 WRITE setX1 NOTIFY x1Changed)
    Q_PROPERTY(int y1 READ getY1 WRITE setY1 NOTIFY y1Changed)
    Q_PROPERTY(int x2 READ getX2 WRITE setX2 NOTIFY x2Changed)
    Q_PROPERTY(int y2 READ getY2 WRITE setY2 NOTIFY y2Changed)

public:

    RepoModelItemLinkPainter(QQuickItem *parent = 0);

    Q_INVOKABLE void paint(QPainter *painter);

    Q_INVOKABLE int getX1() const;
    Q_INVOKABLE void setX1(int x1);
    Q_INVOKABLE int getY1() const;
    Q_INVOKABLE void setY1(int y1);

    Q_INVOKABLE int getX2() const;
    Q_INVOKABLE void setX2(int x2);
    Q_INVOKABLE int getY2() const;
    Q_INVOKABLE void setY2(int y2);

signals :

    void x1Changed();
    void y1Changed();
    void x2Changed();
    void y2Changed();

private :

    // Start point of the line in world coords
    int _x1;
    int _y1;

    // End point of the line in world coords
    int _x2;
    int _y2;

    // Line in local coordinates
    QLine line;

    QPen pen;
    int lineThickness;
};

}

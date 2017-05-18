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

#include "repo_model_item_link_painter.h"

using namespace repo;

RepoModelItemLinkPainter::RepoModelItemLinkPainter(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{  
    pen.setWidth(10);
    pen.setColor(Qt::blue);
}

void RepoModelItemLinkPainter::paint(QPainter *painter)
{
    int startX, startY, endX, endY;

    if (_x1 < _x2)
    {
        startX = 0;
        endX = _x2 - _x1;
    }
    else
    {
        startX = _x1 - _x2;
        endX = 0;
    }

    if (_y1 < _y2)
    {
        startY = 0;
        endY = _y2 - _y1;
    }
    else
    {
        startY = _y1 - _y2;
        endY = 0;
    }

    int w = boundingRect().width();
    int h = boundingRect().height();

    painter->setRenderHint(QPainter::Antialiasing);

    painter->setPen(pen);
    painter->drawLine(startX, startY, endX, endY);

    painter->drawRect(0, 0, w, h);
}


int RepoModelItemLinkPainter::getX1() const
{
    return _x1;
}

void RepoModelItemLinkPainter::setX1(int x1)
{
    if (_x1 != x1)
    {
        _x1 = x1;
        emit x1Changed();
    }
}

int RepoModelItemLinkPainter::getY1() const
{
    return _y1;
}

void RepoModelItemLinkPainter::setY1(int y1)
{
    if (_y1 != y1)
    {
        _y1 = y1;
        emit y2Changed();
    }
}

int RepoModelItemLinkPainter::getX2() const
{
    return _x2;
}

void RepoModelItemLinkPainter::setX2(int x2)
{
    if (_x2 != x2)
    {
        _x2 = x2;
        emit x2Changed();
    }
}

int RepoModelItemLinkPainter::getY2() const
{
    return _y2;
}

void RepoModelItemLinkPainter::setY2(int y2)
{
    if (_y2 != y2)
    {
        _y2 = y2;
        emit y2Changed();
    }
}

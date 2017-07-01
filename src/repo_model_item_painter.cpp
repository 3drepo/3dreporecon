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

#include "repo_model_item_painter.h"

#include "repo_material_icons.h"

using namespace repo;

RepoModelItemPainter::RepoModelItemPainter(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , _rimColor(Qt::blue)
    , _backgroundColor(QColor("#081028"))
    , _foregroundColor(Qt::blue)
    , _support(0.5)
{}

void RepoModelItemPainter::paint(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing);

    int w = boundingRect().width();
    int h = boundingRect().height();

    int border = w * 0.06;
    int gap = w * 0.08;
    int innerCircle = border + gap;
    int icon = w * 0.07;

    // Inner filled circle
    painter->setPen(Qt::NoPen);
    painter->setBrush(_backgroundColor);
    painter->drawEllipse(0, 0, w, h);

    // Outter rim border
    QPen p;
//    p.setWidth(border);
//    p.setColor(getSupportColor(_support)); //_rimColor);
//    painter->setPen(p);
//    painter->drawArc(border, border,
//                     w - 2 * border,
//                     h - 2 * border,
//                     0, 5760);

    if (_image.isNull())
    {
        // Icon
        painter->setFont(RepoMaterialIcons::getInstance().getFont(w - 2 * icon));
        painter->setPen(_foregroundColor);//QColor("#081028"));
        painter->drawText(QRectF(icon, icon, w - 2 * icon, h - 2 * icon),QChar(0xE853), // QChar(0xE7FD),
                          QTextOption(Qt::AlignCenter | Qt::AlignVCenter));
    }
    else
    {
        QPainterPath path;
        path.addEllipse(innerCircle, innerCircle, w - 2 * innerCircle, h - 2 * innerCircle);
        painter->setClipPath(path);
        painter->drawImage(boundingRect(), _image);
    }
}

QUuid RepoModelItemPainter::getUuid() const
{
    return _uuid;
}

void RepoModelItemPainter::setUuid(const QUuid &uuid)
{
    if (_uuid != uuid)
    {
        _uuid = uuid;
        emit uuidChanged();
    }
}

QImage RepoModelItemPainter::getImage() const
{
    return _image;
}

void RepoModelItemPainter::setImage(const QImage &image)
{
    if (_image != image)
    {
        _image = image;
        this->update(boundingRect().toRect());
        emit imageChanged();
    }
}

QColor RepoModelItemPainter::getRimColor() const
{
    return _rimColor;
}

void RepoModelItemPainter::setRimColor(const QColor &color)
{
    if (_rimColor != color)
    {
        _rimColor = color;
        this->update(boundingRect().toRect());
        emit rimColorChanged();
    }
}

QColor RepoModelItemPainter::getBackgroundColor() const
{
    return _backgroundColor;
}

void RepoModelItemPainter::setBackgroundColor(const QColor &color)
{
    if (_backgroundColor != color)
    {
        _backgroundColor = color;
        this->update(boundingRect().toRect());
        emit backgroundColorChanged();
    }
}

QColor RepoModelItemPainter::getForegroundColor() const
{
    return _foregroundColor;
}

void RepoModelItemPainter::setForegroundColor(const QColor &color)
{
    if (_foregroundColor != color)
    {
        _foregroundColor = color;
        this->update(boundingRect().toRect());
        emit foregroundColorChanged();
    }
}

float RepoModelItemPainter::getSupport() const
{
    return _support;
}

void RepoModelItemPainter::setSupport(float support)
{
    if (_support != support)
    {
        _support = support;
        this->update(boundingRect().toRect());
        emit supportChanged();
    }
}


QColor RepoModelItemPainter::getSupportColor(float support)
{
    int r = 255;
    int g = 255;
    if (support < 0.5)
        g = (support * 2 * 255);
    else
        r = ((1 - support) * 2 ) * 255;
    return QColor(r, g, (1 - support) * 128);
}

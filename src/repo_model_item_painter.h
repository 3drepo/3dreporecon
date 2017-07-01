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
#include <QTime>

namespace repo
{

class RepoModelItemPainter : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QUuid uuid READ getUuid WRITE setUuid NOTIFY uuidChanged)

    Q_PROPERTY(QImage image READ getImage WRITE setImage NOTIFY imageChanged)

    Q_PROPERTY(QColor rimColor READ getRimColor WRITE setRimColor NOTIFY rimColorChanged)

    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)

    Q_PROPERTY(QColor foregroundColor READ getForegroundColor WRITE setForegroundColor NOTIFY foregroundColorChanged)

    Q_PROPERTY(float support READ getSupport WRITE setSupport NOTIFY supportChanged)

public:

    RepoModelItemPainter(QQuickItem *parent = 0);

    void paint(QPainter *painter);

    QUuid getUuid() const;
    void setUuid(const QUuid &uuid);

    QImage getImage() const;
    void setImage(const QImage &image);

    QColor getRimColor() const;
    void setRimColor(const QColor &color);

    QColor getBackgroundColor() const;
    void setBackgroundColor(const QColor &color);

    QColor getForegroundColor() const;
    void setForegroundColor(const QColor &color);

    float getSupport() const;
    void setSupport(float support);

    Q_INVOKABLE static QColor getSupportColor(float support);

signals :

    void uuidChanged();

    void imageChanged();

    void rimColorChanged();

    void backgroundColorChanged();

    void foregroundColorChanged();

    void supportChanged();

private :

    QUuid _uuid;

    QImage _image;

    QColor _rimColor;

    QColor _backgroundColor;

    QColor _foregroundColor;

    float _support;

};

}

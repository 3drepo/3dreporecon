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

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "repo_material_icons_image_provider.h"
#include "repo_model.h"
#include "repo_model_item_painter.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<repo::RepoModel>("repo", 1, 0, "RepoModel");
    qmlRegisterType<repo::RepoModelItemPainter>("repo", 1, 0, "RepoModelItemPainter");

    QGuiApplication::setApplicationName("3D Repo Recon");
    QGuiApplication::setOrganizationName("3D Repo");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("materialicons"), new repo::RepoMaterialIconsImageProvider);
    engine.load(QUrl(QLatin1String("qrc:/src/main.qml")));

    return app.exec();
}

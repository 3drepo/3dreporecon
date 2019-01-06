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
#include <QQmlContext>

#include <QWindow>

#include "repo_material_icons_image_provider.h"
#include "repo_model.h"
#include "repo_model_image_provider.h"
#include "repo_model.h"
#include "repo_model_item_painter.h"
#include "repo_model_item_link_painter.h"
#include "repo_unity.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<repo::RepoModel>("repo", 1, 0, "RepoModel");
    qmlRegisterType<repo::RepoModelItem>("repo", 1, 0, "RepoModelItem");
    qmlRegisterType<repo::RepoModelItemPainter>("repo", 1, 0, "RepoModelItemPainter");
    qmlRegisterType<repo::RepoModelItemLinkPainter>("repo", 1, 0, "RepoModelItemLinkPainter");
    qmlRegisterType<RepoUnity>("repo", 1, 0, "RepoUnity");

    QGuiApplication::setApplicationName("3D Repo Recon");
    QGuiApplication::setOrganizationName("3D Repo");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    repo::RepoModel model;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("repoModel", &model);
    engine.addImageProvider(QLatin1String("materialicons"), new repo::RepoMaterialIconsImageProvider);
    engine.addImageProvider(QLatin1String("modelimages"), new repo::RepoModelImageProvider(&model));   

    engine.load(QUrl(QLatin1String("qrc:/src/main.qml")));



    WId wid;
    QObject* m_rootObject = engine.rootObjects().first();
    if(m_rootObject) {
        QWindow *window = qobject_cast<QWindow *>(m_rootObject);
        if(window) {
            wid = window->winId();
//            RepoUnity * u = new RepoUnity(wid);
            RepoUnity::wid = wid;
            qDebug() << wid;
        }
    }

    return app.exec();
}

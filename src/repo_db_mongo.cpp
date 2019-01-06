/**
*  Copyright (C) 2019 3D Repo Ltd
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

#include "repo_db_mongo.h"

#include <iostream>

#include <QDebug>
#include <QString>
#include <QJsonDocument>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/string/view_or_value.hpp>
#include <mongocxx/collection.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/stdx/optional.hpp>
#include <mongocxx/exception/logic_error.hpp>
#include <mongocxx/exception/bulk_write_exception.hpp>

using namespace repo;

void RepoDBMongo::connect(const QString &host,
                                 uint16_t port,
                                 const QString &username,
                                 const QString &password)
{
    std::string address = "mongodb://" +
            username.toStdString() + ":" +
            password.toStdString() + "@" +
            host.toStdString() + ":" +
            std::to_string(port) + "/?authSource=admin";
    connection = mongocxx::client{mongocxx::uri{address}};
}

QList<QVariant> RepoDBMongo::fetchData()
{
    QList<QVariant> list;
    mongocxx::v_noabi::cursor cursor = connection["admin"]["system.users"].find({});
    for (auto&& doc : cursor) {
        QString jsonString = QString::fromStdString(bsoncxx::to_json(doc));
        QJsonDocument document = QJsonDocument::fromJson(jsonString.toUtf8());
        list.append(document.toVariant());
    }
    return list;
}

QString RepoDBMongo::update(const QVariant &id, const QVariant &value, const Field &field)
{
    QString error;
    try {

        // Filter to find the document by (in this case by the supplied _id)
        bsoncxx::document::view_or_value filterDocument = bsoncxx::builder::stream::document{}
                                                  << "_id" << id.toString().toStdString()
                                                  << bsoncxx::builder::stream::finalize;

        // Document to update
        auto builder = bsoncxx::builder::stream::document{};
        builder << "$set" << bsoncxx::builder::stream::open_document;
        switch(field)
        {
            case VrEnabled:
                builder << "customData.vrEnabled" << value.toBool();
            break;
        case HereEnabled:
                builder << "customData.hereEnabled" << value.toBool();
            break;
        }
        builder << bsoncxx::builder::stream::close_document;
        bsoncxx::document::view_or_value updateDocument = builder << bsoncxx::builder::stream::finalize;

        // Execute the update using the filter and the update documents
        connection["admin"]["system.users"].update_one(
                    filterDocument,
                    updateDocument);

    } catch (mongocxx::logic_error e1) {
        // if the update is invalid
        error = QString::fromStdString(std::string(e1.what()));
        qDebug(e1.what());
    } catch (mongocxx::bulk_write_exception e2) {
        // if the operation fails
        error = QString::fromStdString(std::string(e2.what()));
        qDebug(e2.what());
    }
    return error;
}


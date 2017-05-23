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

#include "repo_json_parser.h"

using namespace repo;

QList<QVariant> RepoJsonParser::read(const QString &filepath)
{
    QList<QVariant> list;
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    QJsonDocument doc = QJsonDocument::fromJson(in.readAll().toUtf8());
    file.close();

    if (doc.isArray())
        list = doc.toVariant().toList();
    else
        list.append(doc.toVariant());

    return list;
}

void RepoJsonParser::write(const QList<QVariant> &list,
                           const QString &filepath,
                           QJsonDocument::JsonFormat format)
{
    QFile file(filepath);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);
    out << QJsonDocument::fromVariant(list).toJson(format);
    file.close();
}

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

#include "repo_csv_parser.h"

using namespace repo;

QList<RepoNode> RepoCSVParser::read(const QString &filepath, const QString &delimiter)
{
    QList<RepoNode> nodes;
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    QStringList header = in.readLine().split(delimiter);

    while (!in.atEnd())
    {
        QStringList line = in.readLine().split(delimiter);
        RepoNode node;
        for (int i = 0; i < header.size() && i < line.size(); ++i)
        {
            node.insert(header.at(i), line.at(i));
        }

        if (!node.isEmpty())
            nodes.append(node);
    }
    file.close();
    return nodes;
}

void RepoCSVParser::write(const QList<RepoNode> &nodes,
                          const QString &filepath,
                          const QString &delimiter)
{
    QFile file(filepath);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);

    // Extract and write header first
    QList<QString> header;
    for (RepoNode node : nodes)
    {
        for (QString key : node.keys())
        {
            if (!header.contains(key))
            {
                header.append(key);
                out << key << delimiter;
            }
        }
    }
    out << "\n";

    // Extract and write individual rows
    for (RepoNode node : nodes)
    {
        for (QString key : header)
        {
            if (node.contains(key))
            {
                out << node.value(key).toString();
            }
            out << delimiter;
        }
        out << "\n";
    }

    file.close();
}

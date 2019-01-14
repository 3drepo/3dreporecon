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

#pragma once

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "repo_db_abstract.h"

#include <QString>
#include <QList>
#include <QVariant>

namespace repo
{

class RepoDBMongo : public RepoDBAbstract
{

    Q_OBJECT

public:

    Q_INVOKABLE static RepoDBMongo& instance()
    {
        static RepoDBMongo instance;
        static mongocxx::instance inst{};
        return instance;
    }

public:

    Q_INVOKABLE virtual void connect(const QString &hostPort = "localhost:27017",
                         const QString &username = QString(),
                         const QString &password = QString());

    Q_INVOKABLE virtual QList<QVariant> fetchData() const;

    //! Returns error message or empty string if no error.
    Q_INVOKABLE virtual QString update(const QVariant &id, const QVariant &value, const Field &field);

private:

    mongocxx::client connection;

};

}


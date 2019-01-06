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

#include <QList>
#include <QVariant>

namespace repo {

class RepoDBAbstract
{

public:

    enum Field {
        VrEnabled,
        HereEnabled
    };

//    virtual RepoDBAbstract& instance() = 0;
//    {
//        static RepoDBAbstract instance;
//        return instance;
//    }

    RepoDBAbstract(RepoDBAbstract const&) = delete;
    void operator=(RepoDBAbstract const&) = delete;

protected:
    RepoDBAbstract() {}
    virtual ~RepoDBAbstract() {}

public:

    virtual void connect(const QString &host = "localhost",
                         uint16_t port = 0,
                         const QString &username = QString(),
                         const QString &password = QString()) = 0;

    virtual QList<QVariant> fetchData() = 0;

    //! Returns error message or empty string if no error.
    virtual QString update(const QVariant &id, const QVariant &value, const Field &field) = 0;

};
}

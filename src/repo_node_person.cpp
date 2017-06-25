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

#include "repo_node_person.h"

using namespace repo;

QString RepoNodePerson::jobTitle() const
{
    return value("jobTitle").toString();
}

void RepoNodePerson::setJobTitle(const QString &jobTitle)
{
    insert("jobTitle", jobTitle);
}

QUrl RepoNodePerson::linkedIn() const
{
    return value("linkedIn").toUrl();
}

void RepoNodePerson::setLinkedIn(const QUrl &linkedIn)
{
    insert("linkedIn", linkedIn.toString());
}

QString RepoNodePerson::email() const
{
    return value("email").toString();
}

void RepoNodePerson::setEmail(const QString &email)
{
    insert("email", email);
}

QString RepoNodePerson::organisation() const
{
    return value("organisation").toString();
}

void RepoNodePerson::setOrganisation(const QString &organisation)
{
    insert("organisation", organisation);
}

QString RepoNodePerson::mobile() const
{
    return value("mobile").toString();
}

void RepoNodePerson::setMobile(const QString &mobile)
{
    insert("mobile", mobile);
}

QString RepoNodePerson::work() const
{
    return value("work").toString();
}

void RepoNodePerson::setWork(const QString &work)
{
    insert("work", work);
}

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

#include <QString>
#include <QUrl>

#include "repo_node.h"

namespace repo
{

class RepoNodePerson : public RepoNode
{

public :

    RepoNodePerson(const RepoNode &node) : RepoNode(node) {}

public:

    QString jobTitle() const;

    void setJobTitle(const QString &jobTitle);

    QUrl linkedIn() const;

    void setLinkedIn(const QUrl &linkedIn);

    QString email() const;

    void setEmail(const QString &email);

    QString organisation() const;

    void setOrganisation(const QString &organisation);

    QString mobile() const;

    void setMobile(const QString &mobile);

    QString work() const;

    void setWork(const QString &work);
};

}


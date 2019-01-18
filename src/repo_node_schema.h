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

#include <QString>

namespace repo {

struct RepoNodeSchema {
    static const QString _ID;
    static const QString USER;
    static const QString CUSTOM_DATA;
    static const QString BILLING;
    static const QString SUBSCRIPTIONS;
    static const QString ENTERPRISE;
    static const QString DISCRETIONARY;
    static const QString EMAIL;
    static const QString FIRST_NAME;
    static const QString LAST_NAME;
    static const QString HERE_ENABLED;
    static const QString LAST_LOGIN_AT;
    static const QString CREATED_AT;
    static const QString MAIL_LIST_OPT_OUT;
    static const QString VR_ENABLED;
    static const QString AVATAR;
    static const QString DATA;
    static const QString $BINARY;
    static const QString EXPIRY_DATE;
    static const QString $DATE;
    static const QString COLLABORATORS;
    static const QString UNLIMITED;
};

}

#  Copyright (C) 2018 3D Repo Ltd
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Affero General Public License as
#  published by the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Affero General Public License for more details.
#
#  You should have received a copy of the GNU Affero General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#===============================================================================
# CHANGE THESE TO YOUR LIBRARY DIRECTORIES IF YOU ARE NOT USING ENV. VARIABLES
# BOOSTDIR = $$(BOOST_ROOT)
BOOSTDIR = "C:/local/boost_1_60_0/"
#BOOST_LIB_DIR = $$(BOOST_LIBRARYDIR)
# MONGOCXXDIR = $$(MONGOCXX_ROOT)
MONGOCXXDIR = "C:/local/mongo-cxx-driver/"

# EDIT THESE IF YOU ARE A WINDOWS USER
BOOST_VERS = 1_60
COMPILER = vc140

#================================== BOOST ======================================
!isEmpty(BOOSTDIR) {
    INCLUDEPATH += $${BOOSTDIR}
    DEPENDPATH += $${BOOSTDIR}
} else {
    error(Cannot find BOOST library. Please ensure the environment variables BOOST_ROOT is set.)
}

#============================= MONGOCXX DRIVER ================================
!isEmpty(MONGOCXXDIR) {
    MONGOCXX_LIB_DIR = $${MONGOCXXDIR}/lib
    MONGOCXX_INC_DIR = $${MONGOCXXDIR}/include/mongocxx/v_noabi/
    BSONCXX_INC_DIR = $${MONGOCXXDIR}/include/bsoncxx/v_noabi/

    win32:CONFIG(release, debug|release):MONGOCXXLIB = -lmongocxx
    else:win32:CONFIG(debug, debug|release):MONGOCXXLIB = -lmongocxx #-gd
    else:unix|macx:MONGOCXXLIB = -lmongocxx

    win32:CONFIG(release, debug|release):BSONCXXLIB = -lbsoncxx
    else:win32:CONFIG(debug, debug|release):BSONCXXLIB = -lbsoncxx #-gd
    else:unix|macx:BSONCXXLIB = -lbsoncxx

    LIBS += \
        -L$${MONGOCXX_LIB_DIR} $${MONGOCXXLIB} \
        -L$${MONGOCXX_LIB_DIR} $${BSONCXXLIB} \

    INCLUDEPATH += \
        $${MONGOCXX_INC_DIR} \
        $${BSONCXX_INC_DIR}

    DEPENDPATH += \
        $${MONGOCXX_INC_DIR} \
        $${BSONCXX_INC_DIR} \

} else {
    error(Cannot find mongocxx installation (non-legacy). Please ensure the environment variable MONGOCXX_ROOT is set)
}


#  Copyright (C) 2017 3D Repo Ltd
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

HEADERS += \
    $$PWD/src/repo_material_icons.h \
    $$PWD/src/repo_material_icons_image_provider.h \
    $$PWD/src/repo_node.h \
    $$PWD/src/repo_node_person.h \
    $$PWD/src/repo_node_project.h \
    $$PWD/src/repo_node_company.h \
    $$PWD/src/repo_model.h \
    $$PWD/src/repo_model_item.h \
    $$PWD/src/repo_csv_parser.h \
    $$PWD/src/repo_model_item_painter.h \
    $$PWD/src/repo_model_item_link_painter.h \
    $$PWD/src/repo_json_parser.h

SOURCES +=  \
    $$PWD/src/main.cpp \
    $$PWD/src/repo_material_icons.cpp \
    $$PWD/src/repo_material_icons_image_provider.cpp \
    $$PWD/src/repo_node.cpp \
    $$PWD/src/repo_node_person.cpp \
    $$PWD/src/repo_node_project.cpp \
    $$PWD/src/repo_node_company.cpp \
    $$PWD/src/repo_model.cpp \
    $$PWD/src/repo_model_item.cpp \
    $$PWD/src/repo_csv_parser.cpp \
    $$PWD/src/repo_model_item_painter.cpp \
    $$PWD/src/repo_model_item_link_painter.cpp \
    $$PWD/src/repo_json_parser.cpp

FORMS += 

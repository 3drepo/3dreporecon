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

import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import repo 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Dialogs 1.0

ColumnLayout {

    property string collaborators
    width: parent.width
    spacing: 0

    Label {
        text: qsTr("Collaborators")
        color: collaboratorsComboBox.focus ? Material.accent : Material.color(Material.Grey)
    }

    ComboBox {
        anchors.topMargin: 0
        id: collaboratorsComboBox
        editable: true
        Layout.preferredWidth: parent.width
        validator: RegExpValidator { regExp: /([0-9]+|unlimited)/ }

        model: ListModel {
            id: dataModel
            ListElement { text: "5" }
            ListElement { text: "10" }
            ListElement { text: "20" }
            ListElement { text: "50" }
            ListElement { text: "100" }
            ListElement { text: "500" }
            ListElement { text: "unlimited" }
        }

        onAccepted: {
            if (find(currentText) === -1) {
                dataModel.append({text: editText})
                currentIndex = find(editText)
            }
        }

        Component.onCompleted: {
            if (collaborators) {
                if (find(collaborators) === -1) {
                    dataModel.append({text: collaborators})
                }
                currentIndex = find(collaborators);
            }
        }
    }
}


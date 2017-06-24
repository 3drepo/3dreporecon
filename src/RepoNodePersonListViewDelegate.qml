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

import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import repo 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

import QtQuick.Dialogs 1.0

Item {


   width: nodePersonListView.width
   height: nodePersonListView.height

    RepoNodeImage {
        id: img
        anchors.horizontalCenter: parent.horizontalCenter
        sourceSize.width: 200
        sourceSize.height: 200
        anchors.topMargin: 100
        anchors.top: parent.top
    }

    Grid {
        id: grid
        columns: 1
        anchors.top: img.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        spacing: 10
        width: parent.width - 60

        TextField {
            id: nameField
            width: parent.width
            placeholderText: qsTr("Name")
            text: firstName
            font.pointSize: 12
//            anchors.horizontalCenter: parent.horizontalCenter
            onTextChanged: {
                repoModel.setData(index, text, "firstName")
            }
        }

        TextField {
            text: jobTitle
            //        horizontalAlignment: TextInput.AlignHCenter
            placeholderText: qsTr("Job Title")
            width: parent.width
            anchors.topMargin: 2
            font.pointSize: 10
            color: "grey"
            onTextChanged: {
                repoModel.setData(index, text, "jobTitle")
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        visible: false
        nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
        }
        onRejected: {
            console.log("Canceled")
        }
    }

}

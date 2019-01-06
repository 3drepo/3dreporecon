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
import QtQuick.Controls.Material 2.2

import QtQuick.Dialogs 1.0

Flickable {
    width: nodePersonListView.width
    height: nodePersonListView.height
    contentHeight: img.height + grid.height + 60


    RepoModelItemPainter {
        id: img
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 200
        Binding on image {
            when: model.image !== "undefined"
            value: model.image
        }
        focus: false
        backgroundColor: "transparent"
        foregroundColor: "#ddd"
        Dial {
            id: dial
            width: 290
            height: 290
            value: percentage
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            onValueChanged: {
                img.percentage = value
                repoModel.setData(index, value, "percentage")
            }
            snapMode: Dial.SnapAlways
            stepSize: 0.2
            Material.accent: img.getPercentageColor(value)


            background: Rectangle {
                color: "transparent"
                radius: width / 2
                border.color: img.getPercentageColor(dial.value)
                border.width: 0
            }
        }

        MouseArea {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width: 100
            height: 100
            onClicked: fileDialog.open()
            propagateComposedEvents: true
        }

    }



    Grid {
        id: grid
        columns: 1
        anchors.top: img.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalItemAlignment: Grid.AlignHCenter
        anchors.topMargin: 10
        anchors.bottomMargin: 80
        //spacing: 10
        width: parent.width

        TextField {
            id: nameField
            width: parent.width - 30
            placeholderText: qsTr("Name")
            text: name
            enabled: false
            font.pointSize: 12
            onTextChanged: {
                repoModel.setData(index, text, "name")
            }
        }

        TextField {
            placeholderText: qsTr("Username")
            text: user
            enabled: false
            width: parent.width - 30
            anchors.topMargin: 2
            font.pointSize: 10
            // see http://www.qtcentre.org/threads/65095-How-to-elide-text-in-TextEdit
            onTextChanged: {
                repoModel.setData(index, text, "user")
            }
        }

        TextField {
            text: email
            placeholderText: qsTr("Email")
            enabled: false
            width: parent.width - 30
            anchors.topMargin: 2
            onTextChanged: {
                repoModel.setData(index, text, "email")
            }
        }

        SwitchDelegate {
            text: qsTr("Virtual reality")
            checked: vrEnabled
            width: parent.width
            height: 50
            anchors.topMargin: 2
            onCheckedChanged: {
                repoModel.setData(index, checked, "vrEnabled")
            }
        }

        SwitchDelegate {
            text: qsTr("HERE maps")
            checked: hereEnabled
            width: parent.width
            onCheckedChanged: {
                repoModel.setData(index, checked, "hereEnabled")
            }
        }


        GroupBox {
            width: parent.width

            background: Rectangle {
                border.width: 0
            }

            label: SwitchDelegate {
                id: discretionaryAccountCheckbox
                width: parent.width
                checked: true
                text: qsTr("Discretionary account")
            }

            ColumnLayout {
                anchors.fill: parent
                enabled: discretionaryAccountCheckbox.checked
                TextField { placeholderText: "Collaborators";  Layout.preferredWidth: parent.width }
                TextField { placeholderText: qsTr("Data"); Layout.preferredWidth: parent.width}
                TextField { placeholderText: qsTr("Expiry date"); Layout.preferredWidth: parent.width }
            }
        }




    }
    ScrollIndicator.vertical: ScrollIndicator { }
    //    }

    //        MouseArea {

    //            anchors.fill: parent
    //            onClicked: nodePersonListView.currentIndex = index
    //    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        visible: false
        nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        onAccepted: {
            repoModel.setImage(index, fileDialog.fileUrl)

        }
        onRejected: {
            console.log("Canceled")
        }
    }

}

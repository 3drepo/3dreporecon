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

//    Rectangle {
//    color: Material.primary
//    width: nodePersonListView.width


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
            //            value: percentage
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            onValueChanged: {
                img.percentage = value
                repoModel.setData(index, value, "percentage")
            }
            snapMode: Dial.SnapAlways
            stepSize: 0.1
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
        width: parent.width

        Text { text: name; font.pointSize: 12}

        Item { height: 4; width: 1}

        Text { text: email; font.pointSize: 10; color: Material.color(Material.Grey) }

        Item { height: 30; width: 1}


        Rectangle {
            implicitHeight: 1
            color: Material.color(Material.Grey, Material.Shade300)
            width: parent.width
        }

        SwitchDelegate {
            text: qsTr("Virtual reality")
            checked: vrEnabled
            width: parent.width
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
            id: discretionaryAccountGroupBox

            width: parent.width
            clip: true
            Behavior on height { NumberAnimation { duration: 100 } }
            height: discretionaryAccountCheckbox.checked ? RepoInputCollaborators.height : discretionaryAccountCheckbox.height
            background: Rectangle {
                border.width: 0
            }
            label: SwitchDelegate {
                id: discretionaryAccountCheckbox
                width: parent.width
                checked: discretionary
                text: qsTr("Discretionary account")
            }
            ColumnLayout {
                id: discretionaryAccountContents
                anchors.fill: parent
                anchors.leftMargin: 20
                anchors.rightMargin: 3
                spacing: 15
                enabled: discretionaryAccountCheckbox.checked
                RepoInputCollaborators { collaborators: discretionaryCollaborators; Layout.preferredWidth: parent.width }
                RepoInputDataSize { dataSize: discretionaryData; Layout.preferredWidth: parent.width }
                RepoInputCalendar { calendar.selectedDate: discretionaryExpiryDate; Layout.preferredWidth: parent.width }
            }
        }


        GroupBox {
            id: enterpriseAccountGroupBox

            width: parent.width
            clip: true
            Behavior on height { NumberAnimation { duration: 100 } }
            height: enterpriseAccountCheckbox.checked ? RepoInputCollaborators.height : enterpriseAccountCheckbox.height
            background: Rectangle {
                border.width: 0
            }
            label: SwitchDelegate {
                id: enterpriseAccountCheckbox
                width: parent.width
                text: qsTr("Enterprise account")
                checked: enterprise
            }
            ColumnLayout {
                id: enterpriseAccountContents
                spacing: 15
                anchors.fill: parent
                anchors.leftMargin: 20
                anchors.rightMargin: 3
                enabled: enterpriseAccountCheckbox.checked
                RepoInputCollaborators { collaborators: enterpriseCollaborators; Layout.preferredWidth: parent.width }
                RepoInputDataSize { dataSize: enterpriseData; Layout.preferredWidth: parent.width }
                RepoInputCalendar {
                    //                    Component.onCompleted: {
                    //                        if (enterpriseExpiryDate.month)
                    //                            calendar.selectedDate = enterpriseExpiryDate
                    //                    }
                    calendar.selectedDate : enterpriseExpiryDate
                    Layout.preferredWidth: parent.width
                }
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

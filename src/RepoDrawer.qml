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
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.1
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

Drawer {
    id: drawer
    width: 300
    height: window.height

    ListView {
        id: menuListView
        focus: true
        currentIndex: -1
        anchors.fill: parent

        header: Rectangle {
            width: parent.width
            height: 84
            z: 2

            ToolButton {
                id: backButton
                anchors.left: parent.left
                anchors.leftMargin: 4
                implicitWidth: 84
                implicitHeight: 84

                onClicked: drawer.close()

                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "image://materialicons/arrowBack"
                    sourceSize.width: 32
                    sourceSize.height: 32

                    ColorOverlay {
                        anchors.fill: parent
                        source: parent
                        color: "#FF000000"
                    }
                }
            }

            Image {
                id: repoLogo
                anchors.left: backButton.right
                anchors.leftMargin: 12
                anchors.top: parent.top
                anchors.topMargin: 28
                source: "qrc:/resources/3D-Repo_white.svg"
                fillMode: Image.PreserveAspectFit
                antialiasing: true

                ColorOverlay {
                    anchors.fill: parent
                    source: parent
                    color: "#FF000000"
                }
            }
        }


        delegate: ItemDelegate {
            width: parent.width
            highlighted: ListView.isCurrentItem
            height: 60

            Image {
                id: menuIcon
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.verticalCenter: parent.verticalCenter

                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: model.icon
                sourceSize.width: 32
                sourceSize.height: 32

                ColorOverlay {
                    id: menuIconOverlay
                    anchors.fill: parent
                    source: parent
                    color: "#FF757575"
                }
            }

            Text {
                text: model.title
                anchors.left: menuIcon.right
                anchors.leftMargin: 40
                anchors.verticalCenter: parent.verticalCenter
//                font.bold: true
                font.pointSize: 10
            }


            onClicked: {
//                listView.currentIndex = index
                drawer.close()
            }
        }

        model: ListModel {
            ListElement { title: qsTr("People"); icon: "image://materialicons/people" }
            ListElement { title: qsTr("Companies"); icon: "image://materialicons/business" }
        }

        ScrollIndicator.vertical: ScrollIndicator { }
    }
}

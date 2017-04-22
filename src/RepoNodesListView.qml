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
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.0

import repo 1.0

ListView {
    id: listView
    focus: true
    currentIndex: -1
    snapMode: ListView.SnapToItem
    clip: true

    header: Rectangle {
        width: listView.width
        height: 84
        color: "white"
        radius: 4
        z: 2

        CheckBox {
            id: headerCheckBox
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10

            onCheckedChanged: {
                console.log(listView.visible)
            }
        }

        TextField {
            id: searchField
            placeholderText: qsTr("Search")
            anchors.verticalCenter : parent.verticalCenter
            anchors.left: headerCheckBox.right
            anchors.right: searchButton.left
            topPadding: 20
            leftPadding: 10
            rightPadding: 10
            focus: true
            background: Rectangle {
                color: "transparent"
                border.width: 0
            }
            onTextChanged: {
                filterTagCode(text)
            }
        }

        ToolButton {
            id: searchButton
            anchors.right: parent.right
            anchors.verticalCenter : parent.verticalCenter
            anchors.rightMargin: 0
            implicitWidth: 84
            implicitHeight: 84

            contentItem: Image {
                Material.theme: Material.Dark
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: searchField.text.length > 0 ? "image://materialicons/clear" : "image://materialicons/search"
                sourceSize.width: 32
                sourceSize.height: 32

                ColorOverlay {
                    anchors.fill: parent
                    source: parent
                    color: "#FF757575"
                }
            }
            onClicked: {
                if (searchField.text.length > 0)
                    searchField.clear()
            }
        }

        Rectangle {
            implicitHeight: 1
            color: "#ddd"
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }
    headerPositioning: ListView.OverlayHeader // ListView.PullBackHeader


    footer: Rectangle {
        width: listView.width
        height: 84
        color: "transparent"
        z: 2

        RoundButton {
            id: createButton
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 10
            Material.background: Material.Green
            Material.theme: Material.Light
            width: 74
            height: width
            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source:  "image://materialicons/add"
            }
        }
    }
    footerPositioning: ListView.OverlayFooter // ListView.PullBackHeader

    delegate: RepoNodesListViewDelegate {
        highlighted: ListView.isCurrentItem
//        onClicked: {
//            assetListView.currentIndex = index
//        }
    }

    ScrollIndicator.vertical: ScrollIndicator {}
}

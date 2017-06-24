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
    id: nodePersonListView
    clip: true
    model: repoModel
    currentIndex: -1
    orientation: ListView.Horizontal
    snapMode: ListView.SnapToItem
    highlightFollowsCurrentItem: false

    function select(index) {
        console.log(index)
        currentIndex = index
    }


    header: Rectangle {
        width: listView.width
        height: 84
        color: "white"
        radius: 4
        z: 2

        ToolButton {
            id: personBackButton
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 0
            implicitWidth: 84
            implicitHeight: 84
            onClicked: stackView.pop()
            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "image://materialicons/arrowBack/black"
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }

        Text {
            text: "Person"
            anchors.left: personBackButton.right
            anchors.leftMargin: 4
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 10
        }

//        TextField {
//            id: searchField
//            placeholderText: qsTr("Search")
//            anchors.verticalCenter : parent.verticalCenter
//            anchors.left: personBackButton.right

//            topPadding: 20
//            leftPadding: 10
//            rightPadding: 10
////            focus: true
//            background: Rectangle {
//                color: "transparent"
//                border.width: 0
//            }
//            onTextChanged: {
//                model.filter(text)
//            }
//        }




        Rectangle {
            implicitHeight: 1
            color: "#ddd"
            anchors.top: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }
    headerPositioning: ListView.OverlayHeader // ListView.PullBackHeader

    delegate: RepoNodePersonListViewDelegate {}

}

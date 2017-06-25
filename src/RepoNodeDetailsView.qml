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

Item {
    id: repoNodeDetailsView

    Rectangle {
        id: topBar
        width: repoNodeDetailsView.width
        height: 84
        color: "white"
        radius: 4
        z: 2
        anchors.top: repoNodeDetailsView.top
        anchors.left: repoNodeDetailsView.left
        anchors.right: repoNodeDetailsView.right

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
                source: "image://materialicons/arrowBack/#FF757575"
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }

        ToolButton {
            id: deletePersonButton
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: personEmailButton.left
            anchors.rightMargin: -24
            implicitWidth: 84
            implicitHeight: 84
            onClicked:{
                //Qt.openUrlExternally("mailto:" + repoModel.data(nodePersonListView.currentIndex, "email"))
            }
            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "image://materialicons/delete/#FF757575"
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }

        ToolButton {
            id: personEmailButton
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 0
            implicitWidth: 84
            implicitHeight: 84
            onClicked:{
                Qt.openUrlExternally("mailto:" + repoModel.data(nodePersonListView.currentIndex, "email"))
            }
            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "image://materialicons/email/#FF757575"
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }

        Rectangle {
            implicitHeight: 1
            color: "#ddd"
            anchors.top: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }

    ListView {
        id: nodePersonListView
        model: repoModel
        anchors.top: topBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        currentIndex: -1
        orientation: ListView.Horizontal
        snapMode: ListView.SnapToItem
        highlightFollowsCurrentItem: true
        delegate: RepoNodePersonDelegate {}

        keyNavigationWraps: true


        onHighlightItemChanged: {
            console.log(currentItem)
        }

        onCurrentIndexChanged: {
            console.log(currentItem)
        }
    }

    function select(index) {
        nodePersonListView.currentIndex = index
    }
}

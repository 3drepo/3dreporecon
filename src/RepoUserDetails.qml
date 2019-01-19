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
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.0

import repo 1.0

ColumnLayout {
    id: repoNodeDetailsView
    spacing: 0

    Rectangle {
        z: 2
        radius: 4
        width: parent.width
        height: 84
        color: Material.primary
        RowLayout {
            height: 84
            spacing: 0
            width: parent.width
            ToolButton {
                id: personBackButton
                implicitWidth: 84
                implicitHeight: 84
                onClicked: stackView.pop()
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "image://materialicons/arrowBack/#fff"
                    sourceSize.width: 32
                    sourceSize.height: 32
                }
            }
            Label {
                id: userLabel
                color: "white"
                text: "User" //user
                font.pointSize: 14
            }
            Item { Layout.fillWidth: true }
            ToolButton {
                id: personSaveButton
                implicitWidth: 84
                implicitHeight: 84
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "image://materialicons/save/#fff"
                    sourceSize.width: 32
                    sourceSize.height: 32
                }
                onClicked:{}
            }
        }
    }
//    // Spacer item
//    Item { Layout.fillHeight: true }

//    RepoNodePersonDelegate { Layout.fillHeight: true }


    //        Rectangle {
    //            id: topBar
    //            width: repoNodeDetailsView.width




    //

    //            ToolButton {
    //                id: personEmailButton
    //                anchors.verticalCenter: parent.verticalCenter
    //                anchors.right: personSaveButton.left
    //                anchors.rightMargin: -24
    //                implicitWidth: 84
    //                implicitHeight: 84
    //                onClicked:{
    //                    Qt.openUrlExternally("mailto:" + repoModel.data(nodePersonListView.currentIndex, "email"))
    //                }
    //                contentItem: Image {
    //                    fillMode: Image.Pad
    //                    horizontalAlignment: Image.AlignHCenter
    //                    verticalAlignment: Image.AlignVCenter
    //                    source: "image://materialicons/email/#fff"
    //                    sourceSize.width: 32
    //                    sourceSize.height: 32
    //                }
    //            }



    //            Rectangle {
    //                implicitHeight: 1
    //                color: "#ddd"
    //                anchors.top: parent.bottom
    //                anchors.left: parent.left
    //                anchors.right: parent.right
    //            }
    //        }
    //    }

        ListView {
            id: nodePersonListView
            model: repoModel
            currentIndex: -1
            orientation: ListView.Horizontal
            snapMode: ListView.SnapToItem
            highlightFollowsCurrentItem: true
            delegate: RepoNodePersonDelegate {}

            keyNavigationWraps: true


            //        onHighlightItemChanged: {
            //            console.log(currentItem)
            //        }

            //        onCurrentItemChanged:
            //        {
            //            console.log(currentIndex)
            //            userLabel.text = repoModel.data(currentIndex, "user")
            //        }
        }

    function select(index) {
        //        nodePersonListView.currentIndex = index
    }
}


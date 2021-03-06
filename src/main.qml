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
import Qt.labs.settings 1.0

import repo 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 1280
    height: 720

    Settings {
        property alias x: window.x
        property alias y: window.y
        property alias width: window.width
        property alias height: window.height
    }

    title: qsTr("3D Repo Recon")

    //        background: Image {
    //            source: "qrc:/resources/bg.png"
    //            width: 1920
    //            height: 948
    //        }

    //    background: Rectangle {
    //        color: "#081028"
    //    }

    background: Rectangle {
        id: bg
        color: "#081028"

        RepoCanvas {
            id: canvas
        }

    }

    Component.onCompleted: {
        repoLoginDialog.open()

    }

    RepoUnity { id: unity; }
    RepoDialogLogin { id: repoLoginDialog }

    header: ToolBar {
        id: toolbar
        Material.foreground: "white"
        background: Rectangle {
            color: "transparent"
        }

        //        focus: true

        //        Keys.onPressed: {
        //            console.log("key")
        ////            if (event.key == Qt.ControlModifier) {

        //                canvas.activateZoom()
        //                event.accepted = true;
        ////            }
        //        }


        RowLayout {
            spacing: 16
            anchors.fill: parent

            ToolButton {
                id: menuButton
                // anchors.left: parent.left
                //anchors.leftMargin: 4
                implicitWidth: 84
                implicitHeight: 84

                //                ToolTip.visible: hovered
                //                ToolTip.text: qsTr("Menu")

                //                onClicked: drawer.open()
                onClicked: unity.runUnity()

                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "image://materialicons/menu"
                    sourceSize.width: 32
                    sourceSize.height: 32
                }
            }

            Image {
                id: repoLogo
                source: "qrc:/resources/3D-Repo_white.svg"
                fillMode: Image.PreserveAspectFit
                antialiasing: true
            }

            // Spacer item
            Item { Layout.fillWidth: true }

            //            ToolButton {
            //                anchors.rightMargin: -24
            //                implicitWidth: 84
            //                implicitHeight: 84
            //                Layout.alignment: Qt.AlignRight
            //                contentItem: Image {
            //                    fillMode: Image.Pad
            //                    horizontalAlignment: Image.AlignHCenter
            //                    verticalAlignment: Image.AlignVCenter
            //                    source: "image://materialicons/notificationsNone"
            //                    sourceSize.width: 32
            //                    sourceSize.height: 32
            //                }

            //            }

            ToolButton {
                id: profileButton
                anchors.rightMargin: 4
                implicitWidth: 84
                implicitHeight: 84

                //                ToolTip.visible: hovered
                //                ToolTip.text: qsTr("Profile")

                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "image://materialicons/accountCircle"
                    sourceSize.width: 32
                    sourceSize.height: 32
                }
                onClicked: optionsMenu.visible ?  optionsMenu.close() : optionsMenu.open()

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    y: parent.height
                    transformOrigin: Menu.TopRight

                    MenuItem { text: qsTr("Sign in"); onTriggered: repoLoginDialog.open() }
                    MenuItem { text: qsTr("Settings"); onTriggered: settingsDialog.open() }
                    MenuItem { text: qsTr("About"); onTriggered: aboutDialog.open() }
                }
            }

        }
    }

    ColumnLayout {
        id: buttonsColumn
        spacing: -24
        anchors.left: parent.left
        anchors.top: toolbar.bottom
        anchors.leftMargin: 4
        anchors.topMargin: -12

        ToolButton {
            id: peopleButton
            implicitWidth: 84
            implicitHeight: 84

            //            ToolTip.visible: hovered
            //            ToolTip.text: qsTr("People")

            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "image://materialicons/people/" + Material.accent
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }

        ToolButton {
            id: projectsButton
            implicitWidth: 84
            implicitHeight: 84

            //            ToolTip.visible: hovered
            //            ToolTip.text: qsTr("People")

            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "image://materialicons/assignment"
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }

        ToolButton {
            id: businessButton
            implicitWidth: 84
            implicitHeight: 84

            //            ToolTip.visible: hovered
            //            ToolTip.text: qsTr("Companies")

            //            ToolTip {
            //                    parent: businessButtonIcon
            //                    visible: businessButton.hovered
            //                    text: qsTr("Companies")
            //                }

            contentItem: Image {
                id: businessButtonIcon
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "image://materialicons/business"
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }
    }
    //        RoundButton {
    //            id: createButton
    //            Material.background: Material.accent
    //            Material.theme: Material.Light
    //            width: 74
    //            height: 74
    //            contentItem: Image {
    //                fillMode: Image.Pad
    //                horizontalAlignment: Image.AlignHCenter
    //                verticalAlignment: Image.AlignVCenter
    //                source: "image://materialicons/people"
    //                sourceSize.width: 32
    //                sourceSize.height: 32
    //            }
    //            onPressed : {
    //                canvas.contentItem.scale *= 0.9
    //                canvas.contentX += (canvas.width / 2) * canvas.contentItem.scale
    //                canvas.contentY += (canvas.height / 2) * canvas.contentItem.scale
    //                console.log(canvas.contentX + ", " + canvas.contentY + " s: " + canvas.contentItem.scale)
    //            }
    //        }

    Rectangle {
        id: sidePanel
        anchors.left: buttonsColumn.right
        height: parent.height
        anchors.leftMargin: 12
        width: 500
        antialiasing: true
        color: "white"
        radius: 4
        clip: true

        StackView {
            id: stackView
            anchors.fill: parent
            clip: true
            initialItem: RepoNodesListView {
                id: listView
                cacheBuffer: 1000
                highlightFollowsCurrentItem: true
                highlightMoveDuration: 200
                model: repoModel
                delegate: RepoNodesListViewDelegate {
                    highlighted: ListView.isCurrentItem
                    onClicked: {
                        listView.currentIndex = index
//                        stackView.push("qrc:/src/RepoUserDetails.qml")
                        stackView.push("qrc:/src/RepoNodeDetailsView.qml")
                        var personal = stackView.currentItem
                        personal.select(index)
                        canvas.contentX = model.x - window.width/2 - sidePanel.width/2
                        canvas.contentY = model.y - window.height/2
                    }
                }
            }
        }
    }


    RepoDrawer { id: drawer }
}

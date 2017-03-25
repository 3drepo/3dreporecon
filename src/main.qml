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

ApplicationWindow {
    id: window
    visible: true
    width: 1280
    height: 720
    title: qsTr("3D Repo Recon")

//    background: Image {
//        source: "qrc:/resources/bg.png"
//        width: 1920
//        height: 948
//    }

            background: Rectangle {
                color: "#081028"
            }


    header: ToolBar {
        id: toolbar
        Material.foreground: "white"
        background: Rectangle {
            color: "transparent"
        }

        RowLayout {
            anchors.fill: parent

            ToolButton {
                id: menuButton
                anchors.left: parent.left
                anchors.leftMargin: 4
                implicitWidth: 84
                implicitHeight: 84

                onClicked: drawer.open()

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
                anchors.left: menuButton.right
                anchors.leftMargin: 12
                source: "qrc:/resources/3D-Repo_logo.svg"
                fillMode: Image.PreserveAspectFit
                antialiasing: true
            }

            ToolButton {
                anchors.right: parent.right
                anchors.rightMargin: 4
                implicitWidth: 84
                implicitHeight: 84
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

                    MenuItem {
                        text: "Settings"
                        onTriggered: settingsDialog.open()
                    }
                    MenuItem {
                        text: "About"
                        onTriggered: aboutDialog.open()
                    }
                }
            }

        }
    }

    ColumnLayout {
        id: buttonsColumn
        spacing: -22
        anchors.left: parent.left
        anchors.leftMargin: 4
//        anchors.topMargin: -10

        ToolButton {
            id: peopleButton
            implicitWidth: 84
            implicitHeight: 84

            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "image://materialicons/people"
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }

        ToolButton {
            id: businessButton
            implicitWidth: 84
            implicitHeight: 84

            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "image://materialicons/business"
                sourceSize.width: 32
                sourceSize.height: 32
            }
        }
    }
    //    RoundButton {
    //        id: createButton
    //        Material.background: Material.accent
    //        Material.theme: Material.Light
    //        width: 74
    //        height: 74
    //        contentItem: Image {
    //            fillMode: Image.Pad
    //            horizontalAlignment: Image.AlignHCenter
    //            verticalAlignment: Image.AlignVCenter
    //            source: "image://materialicons/people"
    //            sourceSize.width: 32
    //            sourceSize.height: 32
    //        }
    //    }

    Rectangle {
        anchors.left: buttonsColumn.right
        height: parent.height
        anchors.leftMargin: 12
//        anchors.topMargin: 10
        width: 500
        antialiasing: true
        color: "white"
        radius: 4
    }


    Drawer {
        id: drawer
        width: 300
        height: window.height

        ListView {
            id: listView

            focus: true
            currentIndex: -1
            anchors.fill: parent

            delegate: ItemDelegate {
                width: parent.width
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    listView.currentIndex = index
                    stackView.push(model.source)
                    drawer.close()

                    // This needs fixing as sometimes this would not be RepoCameraPage object
                    var camera = stackView.currentItem
                    camera.tagCodeDetected.connect(relay)
                }
            }

            model: ListModel {
                ListElement { title: "Crossrail C530"; }
                ListElement { title: "Crossrail C512"; }
                ListElement { title: "Camera"; source: "qrc:/src/RepoCameraPage.qml" }
                ListElement { title: "Drawing"; source: "qrc:/src/RepoDrawing.qml" }
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }


}

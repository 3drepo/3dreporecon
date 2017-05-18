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

import QtQuick 2.0
import QtQuick 2.6
import QtQuick 2.7
import QtQuick.Controls 2.1
import QtMultimedia 5.8
import QtQuick.Dialogs 1.2

import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1
import QtQuick.Controls.Universal 2.1
import Qt.labs.settings 1.0

import repo 1.0

Flickable {
    property QtObject graphModel
    property int w: 19200
    property int h: 10800
    property RepoModelItemPainter start

    property int zoomTargetX: w/2
    property int zoomTargetY: h/2
    property int currentMouseX: w/2
    property int currentMouseY: h/2
    property bool ctrlOn: false

    id: flick
    contentWidth: w
    contentHeight: h
    width: parent.width
    height: parent.height
    flickableDirection: Flickable.HorizontalAndVerticalFlick
    pixelAligned: true

    contentX: w/2
    contentY: h/2

    // Prevent flick scrolling
    MouseArea {
        anchors.fill: parent
        onWheel: {
            wheel.accepted = true
        }
    }

    Behavior on contentX { NumberAnimation { duration: 100 } }
    Behavior on contentY { NumberAnimation { duration: 100 } }




    DropArea {
        anchors.fill: parent.fill

        // Main canvas rectangle
        Rectangle {
            id: canvas
            width: w
            height: h
            color: "transparent"
            border.color: "#081744"
            border.width: 500


            RepoModelItemLinkPainter {
                id: link
                x: 19200/2
                y: 10800/2
                width: 19200
                height: 10800
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onDoubleClicked: model.appendRow(mouseX, mouseY)
                propagateComposedEvents: true
                preventStealing: false

                onPositionChanged: {

                    link.x2 = mouseX //Qt.binding(function() { return mouseX - link.x; })
                    link.y2 = mouseY //Qt.binding(function() { return mouseY - link.y; })

                    if (link.x1 < link.x2)
                    {
                        link.x = link.x1
                        link.width = link.x2 - link.x1
                    }
                    else
                    {
                        link.x = link.x2
                        link.width = link.x1 - link.x2
                    }

                    if (link.y1 < link.y2)
                    {
                        link.y = link.y1
                        link.height = link.y2 - link.y1
                    }
                    else
                    {
                        link.y = link.y2
                        link.height = link.y1 - link.y2
                    }



                }

                onClicked: {

                    link.x = mouseX
                    link.y = mouseY

                    link.x1 = mouseX
                    link.y1 = mouseY

                    link.x2 = mouseX
                    link.y2 = mouseY

                    zoomTargetX = Math.round(mouseX)
                    zoomTargetY = Math.round(mouseY)
                }

                onWheel: {
                    if (wheel.modifiers && Qt.ControlModifier) {
                        if (canvas.scale != 0.01 || canvas.scale != 1.0) {
                            canvas.scale += (wheel.angleDelta.y / 120) * 0.1
                            canvas.scale = Math.min(canvas.scale, 1.0)
                            canvas.scale = Math.max(canvas.scale, 0.01)

                            var offsetX = Math.round((zoomTargetX - mouseX) * canvas.scale)
                            var offsetY = Math.round((zoomTargetY - mouseY) * canvas.scale)

                            flick.contentX += offsetX
                            flick.contentY += offsetY

//                            console.log(flick.contentX + ", " + flick.contentY)
                        }
                        wheel.accepted = true
                    }
                }
            }



            // Individual items to be painted
            Repeater {
                model: graphModel
                delegate: RepoModelItemPainter {
                    width: 200
                    height: 200
                    Drag.active: draggable.drag.active
                    focus: true




                    Binding on x {
                        when: x !== model.x - width/2
                        value: model.x - width/2
                    }
                    Binding on y {
                        when: y !== model.y - height/2
                        value: model.y - height/2
                    }

                    onXChanged: graphModel.setData(index, x + width/2, "x")
                    onYChanged: graphModel.setData(index, y + height/2, "y")


                    Text {
                        id: nameText
                        y: parent.height * 1.05
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: firstName + " " + lastName
                        font.pointSize: parent.width / 10
                        font.weight: Font.DemiBold
                        elide: Text.ElideRight
                        color: "blue"
                    }

                    Text {
                        text: activeFocus ? "YES" : "*"
                        color: "red"
                        font.pointSize: parent.width / 10
                        anchors.right: parent.right
                    }

                    MouseArea {
                        id: draggable
                        anchors.fill: parent
                        drag.target: parent
                        hoverEnabled: true
                        propagateComposedEvents: false
                        acceptedButtons: Qt.AllButtons

                        onClicked: {

                            console.log(start)
                            if (start)
                            {

                                // parent is end point
                                start = null
                            }
                            else
                            {
                                start = parent



                            }

                            // Delete on right click
                            if (mouse.button == Qt.RightButton)
                            {
                                // TODO: show confirmation dialog to prevent
                                // accidental deletes
                                console.log(model.id)
                                graphModel.removeRow(index)
                            }


                        }
                    }
                }
            }


        }
    }


    //        PinchArea {
    //            id: pincher
    //            anchors.fill: parent
    //            pinch.target: canvas
    //            pinch.minimumRotation: 0
    //            pinch.maximumRotation: 0
    //            pinch.minimumScale: 0.1
    //            pinch.maximumScale: 10
    //            pinch.dragAxis: Pinch.XAndYAxis
    //            //            onPinchUpdated: {
    //            //                flick.contentWidth = drawingImage.width * pincher.scale
    //            //                flick.contentHeight = drawingImage.height * pincher.scale
    //            //            }



    //        }



}

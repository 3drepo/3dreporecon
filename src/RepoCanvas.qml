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

    property int prevMouseX: w/2
    property int prevMouseY: h/2

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



            MouseArea {

                anchors.fill: parent
                hoverEnabled: true
                onDoubleClicked: model.addNode(mouseX, mouseY)
                propagateComposedEvents: true
                preventStealing: false

                onWheel: {
                    if (wheel.modifiers && Qt.ControlModifier) {
                        canvas.scale += (wheel.angleDelta.y / 120) * 0.1
                        canvas.scale = Math.min(canvas.scale, 1.0)
                        canvas.scale = Math.max(canvas.scale, 0.01)


                        if (canvas.scale != 0.01 || canvas.scale != 1.0) {


                            var offsetX = (prevMouseX - mouseX)/100
                            var offsetY = (prevMouseY - mouseY)/100


                            console.log("mouseXY: [" + mouseX + ", " + mouseY + "]")
                            console.log("prevMouseXY: [" + prevMouseX + ", " + prevMouseY + "]")
                            console.log("offsetXY: [" + offsetX + ", " + offsetY + "]")
                            console.log("contentXY: [" + flick.contentX + ", " + flick.contentY + "]")
                            console.log("")

                            prevMouseX = mouseX
                            prevMouseY = mouseY

                            flick.contentX += offsetX
                            flick.contentY += offsetY


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

                    //                    x: model.x - width/2
                    //                    y: model.y - height/2

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

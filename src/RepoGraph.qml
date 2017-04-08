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


import QtQuick 2.6
import QtQuick.Controls 2.1
import QtMultimedia 5.8
import QtQuick.Dialogs 1.2

import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1
import QtQuick.Controls.Universal 2.1
import Qt.labs.settings 1.0

Pane {
    id: pane
    padding: 0

    background: Rectangle {
        color: "#081028"
    }

    Flickable {
        id: flick
        anchors.fill: parent
        contentWidth: drawingImage.width
        contentHeight: drawingImage.height

        Rectangle {
            id: imageFrame
            width: parent.width
            height: parent.height

            Image {
                id: drawingImage
                source: "qrc:/resources/circles.svg"
                sourceSize.width: parent.width
                sourceSize.height: parent.height
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                antialiasing: true
            }


            PinchArea {
                id: pincher
                anchors.fill: parent
                pinch.target: flick
                pinch.minimumRotation: 0
                pinch.maximumRotation: 0
                pinch.minimumScale: 0.1
                pinch.maximumScale: 10
                pinch.dragAxis: Pinch.XAndYAxis
                //            onPinchUpdated: {
                //                flick.contentWidth = drawingImage.width * pincher.scale
                //                flick.contentHeight = drawingImage.height * pincher.scale
                //            }

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    drag.target: imageFrame
                    scrollGestureEnabled: false
                    onWheel: {
                        if (wheel.modifiers && Qt.ControlModifier) {
                            drawingImage.scale += (wheel.angleDelta.y / 120) * 0.1
                        }
                    }
                }

            }
        }

        ScrollIndicator.horizontal: ScrollIndicator { id: hbar; active: vbar.active }
        ScrollIndicator.vertical: ScrollIndicator { id: vbar; active: hbar.active }
    }
}

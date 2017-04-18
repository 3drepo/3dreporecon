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
import QtQuick.Controls 2.1
import QtMultimedia 5.8
import QtQuick.Dialogs 1.2

import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1
import QtQuick.Controls.Universal 2.1
import Qt.labs.settings 1.0

Flickable {
    id: flick
    anchors.fill: parent
    contentWidth: canvas.width
    contentHeight: canvas.height

    Canvas {
        id: canvas
        anchors.fill: parent
        width: 19200
        height: 10800
        renderStrategy : Canvas.Threaded
        renderTarget: Canvas.FramebufferObject
        onPaint: {
            var ctx = getContext("2d");
            ctx.fillStyle = Qt.rgba(0.03, 0.06, 0.15, 1);
            ctx.fillRect(0, 0, width, height);
        }
    }

    PinchArea {
        id: pincher
        anchors.fill: parent
        pinch.target: canvas
        pinch.minimumRotation: 0
        pinch.maximumRotation: 0
        pinch.minimumScale: 0.1
        pinch.maximumScale: 10
        pinch.dragAxis: Pinch.XAndYAxis

        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            scrollGestureEnabled: false
            onWheel: {
                if (wheel.modifiers && Qt.ControlModifier) {
                    drawingImage.scale += (wheel.angleDelta.y / 120) * 0.1
                }
            }
        }

    }
}

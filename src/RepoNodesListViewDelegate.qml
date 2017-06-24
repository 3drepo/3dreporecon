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
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import repo 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

ItemDelegate {
    id: delegateItem
    width: parent.width
    height: 100


    CheckBox {
        id: checkBox
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    // http://stackoverflow.com/questions/6090740/image-rounded-corners-in-qml
    Image {
        id: img
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: checkBox.right
        anchors.leftMargin: 10
        fillMode: Image.Pad
        horizontalAlignment: Image.AlignHCenter
        verticalAlignment: Image.AlignVCenter
        source: model.image //"qrc:/resources/alvise.jpg"    //"image://materialicons/person"
        sourceSize.width: 60
        sourceSize.height: 60
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: Item {
                width: img.width
                height: img.height
                Rectangle {
                    anchors.centerIn: parent
                    width: img.width
                    height: img.height
                    radius: Math.min(width, height)
                }
            }
        }
    }


    Column {
        anchors.left: img.right
        leftPadding: 20
        spacing: 4
        anchors.verticalCenter: parent.verticalCenter

        Text {
            id: nameText
            text: firstName + " " + lastName
            font.pointSize: 10
            width: delegateItem.width - img.width - checkBox.width - 40
            elide: Text.ElideRight
        }

        Text {
            id: jobTitleText
            text: jobTitle
            font.pointSize: 9
            color: "#999"
            width: nameText.width
            elide: Text.ElideRight
        }
    }

    //    Rectangle {
    //        implicitHeight: 1
    //        color: "#ddd"
    //        anchors.bottom: parent.bottom
    //        anchors.left: parent.left
    //        anchors.right: parent.right
    //    }
}


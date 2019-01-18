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

import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.2

ColumnLayout {

    property alias calendar: calendar
    spacing: 8

    Label {
        text: qsTr("Expiry date");
        color: expiryDateTextField.focus ? Material.accent : Material.color(Material.Grey)
    }

    TextField {
        id: expiryDateTextField
        text: Qt.formatDate(calendar.selectedDate, "dd/MM/yyyy")
        inputMask: "99/99/9999"

        Layout.preferredWidth: parent.width

        onEditingFinished: {
            var newDate = new Date();
            newDate.setDate(text.substr(0, 2));
            newDate.setMonth(text.substr(3, 2) - 1);
            newDate.setFullYear(text.substr(6, 4));
            calendar.selectedDate = newDate;
        }


        Image {
            fillMode: Image.Pad
            anchors { top: parent.top; right: parent.right; rightMargin: 4 }


            //        horizontalAlignment: Image.AlignHCenter
            //        verticalAlignment: Image.AlignVCenter
            source: "image://materialicons/calendar/#333"
            sourceSize.width: parent.height * 0.8
            sourceSize.height: parent.height * 0.8
            Layout.fillWidth: true


            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (popup.closed)
                        popup.open()
                }
            }
        }

        //    implicitWidth: container.width
        //    implicitHeight: row.height

        //    RowLayout {
        //        id: row
        //        spacing: defaultFontHeight * 0.5
        //        width: parent.width

        //        TextField {
        //            text: Qt.formatDate(calendar.selectedDate, "dd/MM/yyyy")
        //            inputMask: "99/99/9999"
        //            Layout.fillWidth: true
        //            anchors.verticalCenter: parent.verticalCenter
        //            onEditingFinished: {
        //                var newDate = new Date();
        //                newDate.setDate(text.substr(0, 2));
        //                newDate.setMonth(text.substr(3, 2) - 1);
        //                newDate.setFullYear(text.substr(6, 4));
        //                calendar.selectedDate = newDate;
        //            }
        //        }

        //        Image {
        //            id: button
        ////            source: "qrc:/icon-calendar.png"
        //            anchors.verticalCenter: parent.verticalCenter
        //            anchors.verticalCenterOffset: -1

        //            MouseArea {
        //                anchors.fill: parent
        //                onClicked: calendar.visible = true
        //            }
        //        }
        //    }

        //    Rectangle {
        //        id: focusShade
        //        parent: window.contentItem
        //        anchors.fill: parent
        //        opacity: calendar.visible ? 0.5 : 0
        //        color: "black"

        //        Behavior on opacity {
        //            NumberAnimation {
        //            }
        //        }

        //        MouseArea {
        //            anchors.fill: parent
        //            enabled: parent.opacity > 0
        //            onClicked: calendar.visible = false
        //        }
        //    }

        Popup {

            id: popup
            width: parent.width
            height: width
            y: -height
            //modal: true
            margins: 0

            contentItem: Calendar {
                id: calendar
                visible: true
                anchors.fill: parent
                focus: popup.opened
                onClicked: popup.close() //visible = false
                Keys.onBackPressed: {
                    event.accepted = true;
                    popup.close(); //visible = false;
                }

                //        style: TouchCalendarStyle {
                //        }
            }
        }
    }
}

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import "qrc:qml/Components"
import "qrc:qml/Pages"

ApplicationWindow {
    id: root
    visible: true
    width: 1024
    height: 720

    RowLayout {
        id: mainLayout
        anchors.fill: parent
        layoutDirection: Qt.LeftToRight
        spacing: 2

        SideBar {
            stackId: mainStack
        }

        MainStack {
            id: mainStack
        }
    }



}

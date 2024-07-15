import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15


ListView {
    id: likedSongs
    objectName: "likedSongs"
    anchors.fill: parent
    model: songModel


    delegate: ItemDelegate {

        width: ListView.view.width
        height:50

        Rectangle {

            width: parent.width
            height: parent.height
            border.width: 1
            border.color: "white"

            RowLayout {

                anchors.fill: parent
                spacing: 10

                Text {
                    text: model.name
                    Layout.fillWidth: true
                }

                Text {
                    text:model.author
                    Layout.fillWidth: true
                }
            }

        }
    }


}
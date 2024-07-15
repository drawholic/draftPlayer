import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:qml/Components"

Item {
    id: root
    objectName: "likedSongsButton"

    signal updateSongsList()

    property var stack
    property int pageId

    width: 40

    Button
    {
    id: control

      onClicked: function()
                {
                    if(stack)
                    {
                root.updateSongsList()
                stack.currentIndex = pageId
                    }else{
                        console.log("stackid is not defined or null, pageid: ", pageId)
                        console.log("stack: ", stack)
                    }
            }

    font.pointSize: 14

    text: "Liked songs"

    contentItem: Text
        {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "black"
            text: control.text
        }
        background: Rectangle
        {
            radius: 6
            implicitWidth: 70
            implicitHeight: 40

            color: control.down ? "#c9c9c9" : "#31363F"
            }
              
    }
}
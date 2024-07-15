import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property var stack
    property int pageId
    property string buttonText
    width: 40

    Button {
        id: control
        font.pointSize: 14
        text: buttonText
        enabled: User.isAuthenticated
        contentItem: Text {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "black"
            text: control.text
        }

        background: Rectangle {
            radius: 6
            implicitWidth: 70
            implicitHeight: 40
            color: control.down ? "#c9c9c9" : "#31363F"
        }

        onClicked: {
            if (stack)
            {
                stack.currentIndex = pageId;
            } else {
            console.error("stackId is not defined or null, pagedid: ", pageId);
        }
    }
}
}

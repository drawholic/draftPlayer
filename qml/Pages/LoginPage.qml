import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Rectangle {
    width: 200
    height: 300
    color: "#365486"
    visible: true

    

    ColumnLayout
{
    spacing: 30
    Layout.alignment: Qt.alignHCenter | Qt.alignVCenter
    anchors.centerIn: parent

        ColumnLayout
    { 
        id: usernameComponent
        Label {
            Layout.alignment: Qt.AlignHCenter
            text: "Username"
            font.pixelSize: 17
        }

        TextField
        {
            id: usernameField
        }
    }
        ColumnLayout
        {
            id: passwordComponent
            Label {
                Layout.alignment: Qt.AlignHCenter
                text: "Password"
                font.pixelSize: 17
            }
            TextField
            {
                id: passwordField
                echoMode: TextInput.Password
            }
        }
        Button
            {
                objectName: "loginButton"
                signal loginClicked(string username, string password)
                Layout.alignment: Qt.AlignHCenter
                text: "Login"
                onClicked: function(event)
                {
                    loginClicked(usernameField.text, passwordField.text)
                }
            }
    }
}

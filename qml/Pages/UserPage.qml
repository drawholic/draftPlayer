import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import "qrc:qml/Components"

Rectangle
{
color: "#222831"
Layout.fillWidth: true

ColumnLayout
{
anchors.fill: parent

Text {
    Layout.fillWidth: true
    text: "Username: " + User.username
}
// SearchComponent
// {
// Layout.fillWidth: true
// Layout.margins: 20
// Layout.minimumWidth: 200
// Layout.minimumHeight: 50

// }
}

}

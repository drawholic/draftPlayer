import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import "qrc:qml/Components/"


Rectangle {
    id: root
    required property var stackId

    Layout.fillHeight: true
    Layout.minimumWidth: 100
    Layout.maximumWidth: 100
    Layout.minimumHeight: 200
    color: "#31363F"

    ColumnLayout {

        spacing: 50
        LikedSongsButton {
            pageId: SideBar.PagesEnum.LikesPage
            Layout.alignment: Qt.AlignCenter

            stack: stackId

        }
        SideBarButton {
            stack: stackId
            buttonText: "Main"
            pageId: SideBar.PagesEnum.MainPage
        }

        SideBarButton {
            stack: stackId
            buttonText: "Search"
            pageId: SideBar.PagesEnum.SearchPage
        }
        SideBarButton {
            stack: stackId
            buttonText: "Account"
            pageId: SideBar.PagesEnum.UserPage
        }


    }

    enum PagesEnum
{
    LikesPage,
    MainPage,
    SearchPage,
    UserPage,
    LoginPage
}

}
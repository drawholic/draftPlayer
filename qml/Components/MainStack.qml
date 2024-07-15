import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import "qrc:qml/Components"
import "qrc:qml/Pages"

StackLayout {
    id: stack
    currentIndex: User.isAuthenticated ? SideBar.PagesEnum.MainPage : SideBar.PagesEnum.LoginPage
    Layout.fillWidth: true
    LikesPage {}
    MainPage {}
    SearchPage {}
    UserPage {}
    LoginPage {}
}
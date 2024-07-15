import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15



Loader
{
    required property var loginComponent
    required property var stackComponent

    id: root
    Layout.fillWidth: true
    sourceComponent: {
        if(User.isAuthenticated)
        {
            stackComponent.stack.currentIndex = 1
            return stackComponent        
        }else
        {
            return loginComponent
        }
    }
}
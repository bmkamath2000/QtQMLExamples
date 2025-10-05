import QtQuick
import com.example.backend 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Column {
        spacing : 3
        Repeater {
            model: 10
            QWaveformHistoryPanel {
                width: Window.width
                height: Window.height / 11
            }
        }
    }
}

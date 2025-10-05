import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import com.example.backend 1.0

Item {

    Column {


        Grid {
            columns: 10


            Repeater {
                model: 100

                QWaveformHistoryPanel {
                    id: line1
                    width: Window.width /10
                    height: Window.height /10

                    property real t
                    SequentialAnimation on t {
                        NumberAnimation { to: 1; duration: 2000; easing.type: Easing.InOutQuad }
                        NumberAnimation { to: 0; duration: 2000; easing.type: Easing.InOutQuad }
                        loops: Animation.Infinite
                    }

                    p2: Qt.point(t, 1 - t)
                    p3: Qt.point(1 - t, t)
                }
            }
        }
    }
}

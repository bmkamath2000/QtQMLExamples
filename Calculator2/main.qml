import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import com.example.backend 1.0
Window {
    width: 320
    height: 400
    visible: true
    title: qsTr("Calculator")

    ColumnLayout {
        id: columnVert
        anchors.centerIn: parent
        property int buttWidth: 70
        property int buttHeight: 70

        Row {
            Layout.fillWidth: true
            TextField {
                id: textBox
                text: backend!=null ? backend.digits : ""
                width: parent.width
                height: columnVert.buttHeight
            }
        }

        Row {
            Layout.fillWidth: true
            Button {
                id: button1
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("1")
                onPressed: backend.append("1")
            }
            Button {
                id: button2
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("2")
                onPressed: backend.append("2")
            }
            Button {
                id: button3
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("3")
                onPressed: backend.append("3")
            }
            Button {
                id: buttonPlus
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("+")
                onPressed: {
                    backend.operSet(1)
                }
            }
        }
        Row {
            Layout.fillWidth: true
            Button {
                id: button4
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("4")
                onPressed: backend.append("4")
            }
            Button {
                id: button5
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("5")
                onPressed: backend.append("5")
            }
            Button {
                id: button6
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("6")
                onPressed: backend.append("6")
            }
            Button {
                id: buttonMinus
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("-")
                onPressed: {
                    backend.operSet(2)
                }
            }
        }
        Row {
            Layout.fillWidth: true
            Button {
                id: button7
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("7")
                onPressed: backend.append("7")
            }
            Button {
                id: button8
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("8")
                onPressed: backend.append("8")
            }
            Button {
                id: button9
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("9")
                onPressed: backend.append("9")
            }
            Button {
                id: buttonMult
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("*")
                onPressed: {
                    backend.operSet(3)
                }
            }
        }
        Row {
            Layout.fillWidth: true
            Button {
                id: buttonClear
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("C")
                onPressed: backend.clear()
            }
            Button {
                id: button0
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("0")
                onPressed: backend.append("0")
            }
            Button {
                id: buttonDiv
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("/")
                onPressed: {
                    backend.operSet(4)
                }
            }
            Button {
                id: buttonEquals
                width: columnVert.buttWidth
                height: columnVert.buttHeight
                text: qsTr("=")
                onPressed: {
                    backend.calculate()
                }
            }
        }
    }
}

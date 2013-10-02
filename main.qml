import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    title: qsTr("FileLister")

    statusBar: StatusBar {
    RowLayout {
        Label {
            id: status
        }
    }
    }

    width: 400
    height: 600

    ColumnLayout {
        x: 10
        y: 10

        RowLayout {
            Label {
                text: qsTr("Folder:")
            }
            TextField {
                id: filename
                implicitWidth: 200
                onTextChanged: updateStatusBar()
            }
            Button {
                text: qsTr("&Browse Folder...")
                onClicked: filedialog.visible = true
            }
        }
    }

    FileDialog {
        id: filedialog
        title: qsTr("Select a file")
        selectMultiple: false
        selectFolder: true
        selectExisiting: true
        nameFilters: [ "All files (*)" ]
        selectedNameFilter: "All files (*)"
        onAccepted: {
            filename.text = folder.toString().replace("file:///", "")
        }
    }
}


#ifndef FOLDERHANDLE_H
#define FOLDERHANDLE_H

#include <QObject>
#include <QString>
#include <QList>

class FolderHandle : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QString> FileList READ FileList NOTIFY FileListChanged)
public:
    explicit FolderHandle(QObject *parent = 0);

signals:
    void FileListChanged();

public slots:
    QList<QString> FileList();
    void getFileList(QString folder);


private:
    QList<QString> fileList;

};

#endif // FOLDERHANDLE_H

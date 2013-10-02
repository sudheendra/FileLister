#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QStringList filenames READ filenames NOTIFY filenamesChanged)

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStringList filenames;
signals:
    void filenamesChanges();

private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

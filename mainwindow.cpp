#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog filedialog(this);
    filedialog.setFileMode(QFileDialog::Directory);
    QStringList dirname;
    if (filedialog.exec())
    {
        dirname = filedialog.selectedFiles();
    }
    qDebug() << "DirName: " << dirname[0];
    QDir directory(dirname.at(0));

    QStringList files = directory.entryList(QDir::Filter::Files, QDir::SortFlag::NoSort);
    qDebug() << files;
}

#include "mainwindow.h"
#include <QDebug>
#include "chatclientcore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << ChatClientCore::getString().c_str();
}

MainWindow::~MainWindow()
{
}


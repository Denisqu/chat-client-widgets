#include "mainwindow.h"
#include <QDebug>
#include "chatclientcore.h"
#include "chatwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << ChatClientCore::getString().c_str();
    auto chatWindow = new ChatWindow();
    setCentralWidget(chatWindow);
}

MainWindow::~MainWindow()
{
}


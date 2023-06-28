#include "mainwindow.h"
#include <QDebug>
#include "chatclientcore.h"
#include "chatwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto chatWindow = new ChatWindow();
    setCentralWidget(chatWindow);
}

MainWindow::~MainWindow()
{
}


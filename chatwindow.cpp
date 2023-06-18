#include "chatwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QVBoxLayout>

ChatWindow::ChatWindow(QWidget *parent)
    : QWidget(parent)
    , m_chatClient(new ChatClient(this)) // create the chat client
    , m_chatModel(new QStandardItemModel(this)) // create the model to hold the messages
    , ui()
{
    setLayout(createRootLayout());
    // the model for the messages will have 1 column
    m_chatModel->insertColumn(0);
    // set the model as the data source vor the list view
    /* TODO: ui->chatView->setModel(m_chatModel); */
    // connect the signals from the chat client to the slots in this ui
    connect(m_chatClient, &ChatClient::connected, this, &ChatWindow::connectedToServer);
    connect(m_chatClient, &ChatClient::loggedIn, this, &ChatWindow::loggedIn);
    connect(m_chatClient, &ChatClient::loginError, this, &ChatWindow::loginFailed);
    connect(m_chatClient, &ChatClient::messageReceived, this, &ChatWindow::messageReceived);
    connect(m_chatClient, &ChatClient::disconnected, this, &ChatWindow::disconnectedFromServer);
    connect(m_chatClient, &ChatClient::error, this, &ChatWindow::error);
    connect(m_chatClient, &ChatClient::userJoined, this, &ChatWindow::userJoined);
    connect(m_chatClient, &ChatClient::userLeft, this, &ChatWindow::userLeft);
    // connect the connect button to a slot that will attempt the connection
    /* TODO: connect(ui->connectButton, &QPushButton::clicked, this, &ChatWindow::attemptConnection); */
    // connect the click of the "send" button and the press of the enter while typing to the slot that sends the message
    /* TODO: connect(ui->sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
    TODO: connect(ui->messageEdit, &QLineEdit::returnPressed, this, &ChatWindow::sendMessage); */
}

ChatWindow::~ChatWindow()
{
}

void ChatWindow::attemptConnection()
{

}

void ChatWindow::connectedToServer()
{

}

void ChatWindow::attemptLogin(const QString &userName)
{

}

void ChatWindow::loggedIn()
{

}

void ChatWindow::loginFailed(const QString &reason)
{

}

void ChatWindow::messageReceived(const QString &sender, const QString &text)
{

}

void ChatWindow::sendMessage()
{

}

void ChatWindow::disconnectedFromServer()
{

}

void ChatWindow::userJoined(const QString &username)
{

}

void ChatWindow::userLeft(const QString &username)
{

}

void ChatWindow::error(QAbstractSocket::SocketError socketError)
{

}

QLayout* ChatWindow::createRootLayout()
{
    auto rootLayout = new QVBoxLayout(this);
    rootLayout->addWidget(ui.connectButton);
    rootLayout->addWidget(ui.chatView);
    auto horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->addWidget(ui.messageEdit);
    horizontalLayout->addWidget(ui.sendButton);
    rootLayout->addLayout(horizontalLayout);

    return rootLayout;
}


ChatWindow::UI::UI()
{
    connectButton = new QPushButton();
    sendButton = new QPushButton();
    chatView = new QListView();
    messageEdit = new QLineEdit();
}

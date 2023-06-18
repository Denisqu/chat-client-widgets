#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QStandardItemModel>
#include "chatclient.h"

class QLineEdit;
class QPushButton;
class QListView;

class ChatWindow : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChatWindow)
public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();
private:
    ChatClient *m_chatClient;
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;
    struct UI {
        QLineEdit* messageEdit = nullptr;
        QPushButton* sendButton = nullptr;
        QPushButton* connectButton = nullptr;
        QListView* chatView = nullptr;
        UI();
    } ui;
private slots:
    void attemptConnection();
    void connectedToServer();
    void attemptLogin(const QString &userName);
    void loggedIn();
    void loginFailed(const QString &reason);
    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    void userJoined(const QString &username);
    void userLeft(const QString &username);
    void error(QAbstractSocket::SocketError socketError);
private:
    QLayout* createRootLayout();
};

#endif // CHATWINDOW_H

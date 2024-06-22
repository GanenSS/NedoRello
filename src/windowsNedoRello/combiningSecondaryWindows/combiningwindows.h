#ifndef COMBININGWINDOWS_H
#define COMBININGWINDOWS_H

#include "firstwindow.h"
#include "registrationwindow.h"
#include "accountwindow.h"
#include "boardnedorello.h"
#include "listnedorello.h"

#include <QObject>
#include <QDebug>

class combiningWindows : public QObject
{
    Q_OBJECT
public:
    explicit combiningWindows(QObject *parent = nullptr);
    ~combiningWindows();

    struct LoginCredentials
    {
        QString login;
        QString password;
    };

    struct boardInfo
    {
        QString name;
        QString description;
        QString login;
        int idBoard;
        int userId;
    };

    struct listInfo
    {
        int idList;
        int idBoard;
        QString title;
    };

    firstWindow fstWindow;
    registrationWindow regWindow;
    accountWindow accWindow;
    boardNedoRello *board;
    listNedoRello *list;
private:
    QVector<boardNedoRello*> widgetsBoard;
    QVector<listNedoRello*> widgetsList;
private slots:
    void openFirstWindow();
    void getLoginCredentialsFirstWindow(const firstWindow::LoginCredentials& cred);
    void wrongPasswordFirstWindow();

    void openRegistrationWindow();
    void getLoginCredentialsRegistrationWindow(const registrationWindow::LoginCredentials& cred);
    void loginIsInDbRegWindow();
    void slotCreatedAccountRegistrationWindow();
    void openAccountWindow(const QString &login);

    void slotClickedButtonCreateBoard(const accountWindow::boardInfo& info);
    void createdBoard(const boardInfo& info);

    void slotRequestToCreatelist(const boardNedoRello::listInfo& info);
    void createdList(const listInfo& infoList);

    void deletingWidgets(int idBoard);

signals:
    void signalGetLoginCredentialsFirstWindow(const LoginCredentials& cred);
    void signalErrorLoginCredentialsFirstWindow();

    void signalGetLoginCredentialsRegistrationWindow(const LoginCredentials& cred);
    void signalLoginIsInDatabaseRegWindow();
    void signalCreatedAccountRegistrationWindow();

    void signalInputInAccount(const QString& login);

    void signalClickedButtonCreateBoard(const boardInfo& infoComb);
    void signalCreatedBoard(const boardInfo& infoComb);

    void signalRequestToCreatelist(const listInfo& infoList);
    void signalCreatedList(const listInfo& infoList);

};

#endif // COMBININGWINDOWS_H
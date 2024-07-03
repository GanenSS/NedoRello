#ifndef LISTDB_H
#define LISTDB_H

#include "combiningwindows.h"

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>

class passDB : public QObject
{
    Q_OBJECT
public:
    explicit passDB(QObject *parent = nullptr);
    ~passDB();

    QSqlDatabase    db;
    QSqlQuery       query;
    QSqlTableModel  *modelUser;
    QSqlTableModel  *modelBoard;
    QSqlTableModel  *modelList;
    QSqlTableModel  *modelCard;


private:
    combiningWindows     combWindows;

    const QString dbType        = "QPSQL";
    const QString dbUserName    = "postgres";
    const QString dbName        = "NedoRello";
    const QString dbPassword    = "1+Qwertis+1";

    const QString dbTableUser   = "users";
        const int idColumnUser          = 0;
        const int loginColumnUser       = 1;
        const int passwdColumnUser      = 2;

    const QString dbTableBoard  = "boards";
        const int idColumnBoard             = 0;
        const int nameColumnBoard           = 1;
        const int descriptionColumnBoard    = 2;
        const int userIdColumnBoard         = 3;

    const QString dbTableList   = "lists";
        const int idColumnList             = 0;
        const int nameColumnList           = 1;
        const int boardIdColumnList        = 2;

    const QString dbTableCard   = "cards";
        const int idColumnCard          = 0;
        const int nameColumnCard        = 1;
        const int descriptionColumnCard = 2;
        const int dateColumnCard        = 3;
        const int processColumnCard     = 4;
        const int listIdColumnCard      = 5;
        const int userIdColumnCard      = 6;

    const QString cardInProcess     = "В ПРОЦЕССЕ";
    const QString completedCard     = "ВЫПОЛНЕННО";
    const QString notCompletedCard  = "НЕ ВЫПОЛНЕННО";

public slots:
    bool    createConnection();

    void    addRowUser(const combiningWindows::LoginCredentials &cred);
    void    creatingAccount(const combiningWindows::LoginCredentials &cred);
    void    enterAccount(const combiningWindows::LoginCredentials &cred);

    int loginVerificationRequest(const QString& login);
    QString passwordVerificationRequest(const QString& login);

    QString hashPassword(const QString &password);

    void createdNewBoard(const combiningWindows::boardInfo& info);
    void addRowBoard(const combiningWindows::boardInfo& info);

    void createdNewList(const combiningWindows::listInfo& info);
    void addRowList(const combiningWindows::listInfo& info);

    void createdNewCard(const combiningWindows::cardInfo& info);
    void addRowCard(const combiningWindows::cardInfo& info);
    void cardTimeOut(const int& cardId);
    void cardClickedButtonReady(const int& idCard);
    void slotCardInProcess(const int& idCard);
};

#endif // LISTDB_H

#include "passdb.h"

passDB::passDB(QObject *parent)
    : QObject{parent}
{
    createConnection();

    connect(&combWindows, &combiningWindows::signalGetLoginCredentialsRegistrationWindow,   this, &passDB::creatingAccount);
    connect(&combWindows, &combiningWindows::signalGetLoginCredentialsFirstWindow,          this, &passDB::enterAccount);
    connect(&combWindows, &combiningWindows::signalClickedButtonCreateBoard,                this, &passDB::createdNewBoard);
    connect(&combWindows, &combiningWindows::signalRequestToCreatelist,                     this, &passDB::createdNewList);
}

passDB::~passDB()
{
    //db.commit();
    delete modelUser;
    delete modelBoard;
    delete modelList;
    delete modelCard;
    // db.close();
}

bool passDB::createConnection()
{
    db = QSqlDatabase::addDatabase(dbType);
    db.setHostName("localhost");
    db.setDatabaseName(dbName);
    db.setUserName(dbUserName);
    db.setPassword(dbPassword);

    if (!db.open())
    {
        QMessageBox::warning(0, "Ошибка БД",db.lastError().text());
        return false;
    }
    else
    {
        qDebug() << "Соединение с БД установлено!";

        query = QSqlQuery(db);

        modelUser = new QSqlTableModel(this, db);
        modelUser->setTable(dbTableUser);
        modelUser->select();

        modelBoard = new QSqlTableModel(this, db);
        modelBoard->setTable(dbTableBoard);
        modelBoard->select();

        modelList = new QSqlTableModel(this, db);
        modelList->setTable(dbTableList);
        modelList->select();

        modelCard = new QSqlTableModel(this, db);
        modelCard->setTable(dbTableCard);
        modelCard->select();

        return true;
    }
}

void passDB::addRowUser(const QString &login, const QString &password)
{
    int row = modelUser->rowCount();
    modelUser->insertRow(row);

    QModelIndex index = modelUser->index(row, idColumnUser);
    modelUser->setData(index, row);

    index = modelUser->index(row, loginColumnUser);
    modelUser->setData(index, login);

    index = modelUser->index(row, passwdColumnUser);
    modelUser->setData(index, password);
}

void passDB::creatingAccount(const combiningWindows::LoginCredentials &cred)
{
    if(loginVerificationRequest(cred.login) == 0)
    {
        emit combWindows.signalLoginIsInDatabaseRegWindow();
    }
    else if(loginVerificationRequest(cred.login) == 1)
    {
        addRowUser(cred.login, hashPassword(cred.password));
        modelUser->submitAll();
        emit combWindows.signalCreatedAccountRegistrationWindow();
    }
}

void passDB::enterAccount(const combiningWindows::LoginCredentials &cred)
{
    if(loginVerificationRequest(cred.login) == 0)
    {
        if(passwordVerificationRequest(cred.login) == hashPassword(cred.password))
        {
            QString login = cred.login;
            emit combWindows.signalInputInAccount(login);
        }
        else
        {
            emit combWindows.signalErrorLoginCredentialsFirstWindow();
        }
    }
    else
    {
        emit combWindows.signalErrorLoginCredentialsFirstWindow();
    }

}

int passDB::loginVerificationRequest(const QString &login)
{
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :login");
    query.bindValue(":login", login);

    if(query.exec())
    {   // Если запрос успешно выполнен, проверяем результат
        if(query.next())
        {
            int count = query.value(0).toInt();
            if (count > 0)
            {
                return 0;//Логин существует в базе данных
            }
            else
            {
                return 1;//Логин не существует в базе данных
            }
        }
        else
        {
            return 2;//Ошибка выполнения запроса
        }
    }
    else
    {
        return 3;//Ошибка подготовки запроса
    }
    query.finish();
}

QString passDB::passwordVerificationRequest(const QString &login)
{
    query.prepare("SELECT password_hash FROM users WHERE username = :login");
    query.bindValue(":login", login);

    if(query.exec())
    {
        if(query.next())
        {   // Если запрос успешно выполнен, проверяем результат
            QString password = query.value("password_hash").toString();
            return password;
        }
        else
        {
            qDebug() << "Пользователь не найден";
            return "";
        }
    }
    else
    {
        qDebug() << "Ошибка выполнения запроса";
        return "";
    }

    query.finish();
}

QString passDB::hashPassword(const QString &password)
{
    QByteArray passwordBytes = password.toUtf8();
    QByteArray hashedBytes = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256);
    return hashedBytes.toHex();
}

void passDB::createdNewBoard(const combiningWindows::boardInfo &info)
{
    query.prepare("SELECT id FROM Users WHERE username = :username");
    query.bindValue(":username", info.login);

    if(query.exec())
    {
        if(query.next())
        {
            combiningWindows::boardInfo infoBoard;
            infoBoard.name = info.name;
            infoBoard.description = info.description;
            infoBoard.userId = query.value(0).toInt();
            infoBoard.idBoard = modelBoard->rowCount();
            addRowBoard(infoBoard);

            emit combWindows.signalCreatedBoard(infoBoard);
        }
    }
    else
    {
        qDebug() << "Ошибка запроса: " << query.lastError().text();
    }

    query.finish();
}

void passDB::addRowBoard(const combiningWindows::boardInfo &info)
{
    int row = modelBoard->rowCount();
    modelBoard->insertRow(row);

    QModelIndex index = modelBoard->index(row, idColumnBoard);
    modelBoard->setData(index, info.idBoard);

    index = modelBoard->index(row, nameColumnBoard);
    modelBoard->setData(index, info.name);

    index = modelBoard->index(row, descriptionColumnBoard);
    modelBoard->setData(index, info.description);

    index = modelBoard->index(row, userIdColumnBoard);
    modelBoard->setData(index, info.userId);

    modelBoard->submitAll();
}

void passDB::createdNewList(const combiningWindows::listInfo &info)
{
    combiningWindows::listInfo list;
    list.idList  = modelList->rowCount();
    list.title   = info.title;
    list.idBoard = info.idBoard;

    addRowList(list);

    emit combWindows.signalCreatedList(list);
}

void passDB::addRowList(const combiningWindows::listInfo &info)
{
    int row = modelList->rowCount();
    modelList->insertRow(row);

    QModelIndex index = modelList->index(row, idColumnList);
    modelList->setData(index, info.idList);

    index = modelList->index(row, nameColumnList);
    modelList->setData(index, info.title);

    index = modelList->index(row, boardIdColumnList);
    modelList->setData(index, info.idBoard);

    modelList->submitAll();
}

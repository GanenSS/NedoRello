#include "combiningwindows.h"

combiningWindows::combiningWindows(QObject *parent)
    : QObject{parent}
{
    fstWindow.show();
    connect(&fstWindow, &firstWindow::signalClickedButtonRegistration,              this, &combiningWindows::openRegistrationWindow);
    connect(&regWindow, &registrationWindow::signalClickedButtonCancel,             this, &combiningWindows::openFirstWindow);
    connect(&fstWindow, &firstWindow::signalClickedButtonEnter,                     this, &combiningWindows::getLoginCredentialsFirstWindow);
    connect(&regWindow, &registrationWindow::signalClickedButtonSave,               this, &combiningWindows::getLoginCredentialsRegistrationWindow);
    connect(this,       &combiningWindows::signalLoginIsInDatabaseRegWindow,        this, &combiningWindows::loginIsInDbRegWindow);
    connect(this,       &combiningWindows::signalInputInAccount,                    this, &combiningWindows::openAccountWindow);
    connect(this,       &combiningWindows::signalCreatedAccountRegistrationWindow,  this, &combiningWindows::slotCreatedAccountRegistrationWindow);
    connect(&accWindow, &accountWindow::signalCreatedBoardAccountWindow,            this, &combiningWindows::slotClickedButtonCreateBoard);
    connect(this,       &combiningWindows::signalErrorLoginCredentialsFirstWindow,  this, &combiningWindows::wrongPasswordFirstWindow);
    connect(this,       &combiningWindows::signalCreatedBoard,                      this, &combiningWindows::createdBoard);

    connect(this,       &combiningWindows::signalCreatedList,                       this, &combiningWindows::createdList);


}

combiningWindows::~combiningWindows()
{
    //delete &widgetList;
}

void combiningWindows::openFirstWindow()
{
    fstWindow.show();
}

void combiningWindows::openRegistrationWindow()
{
    regWindow.show();
}

void combiningWindows::getLoginCredentialsFirstWindow(const firstWindow::LoginCredentials &cred) // Запрос на вход в аккаунт
{
    LoginCredentials combCred;
    combCred.login = cred.login;
    combCred.password = cred.password;
    emit signalGetLoginCredentialsFirstWindow(combCred);
}

void combiningWindows::getLoginCredentialsRegistrationWindow(const registrationWindow::LoginCredentials &cred) // Запрос на создание аккаунта
{
    LoginCredentials combCred;
    combCred.login = cred.login;
    combCred.password = cred.login;
    emit signalGetLoginCredentialsRegistrationWindow(combCred);
}

void combiningWindows::loginIsInDbRegWindow() // Оповищение пользователя о том, что такой логин уже существует
{
    regWindow.loginIsInDB();
}

void combiningWindows::slotCreatedAccountRegistrationWindow() //Открытие первого окна после конца регистрации
{
    regWindow.close();
    openFirstWindow();
}

void combiningWindows::slotClickedButtonCreateBoard(const accountWindow::boardInfo &info) //Запрос на создание доски
{
    boardInfo infoComb;
    infoComb.name = info.name;
    infoComb.description = info.description;
    infoComb.login = info.login;

    emit signalClickedButtonCreateBoard(infoComb);
}

void combiningWindows::createdBoard(const boardInfo &info) //Создание Доски
{
    board = new boardNedoRello;
    board->IdBoard = info.idBoard;
    qDebug() << "Board: idboard" << board->IdBoard;
    board->setNameBoard(info.name);
    board->setDescriptionBoard(info.description);
    widgetsBoard.append(board);
    board->show();

    connect(board, &boardNedoRello::signalRequestToCreatelistBoard, this, &combiningWindows::slotRequestToCreatelist);

    connect(board, &boardNedoRello::destroyedBoard, this, &combiningWindows::deletingWidgets);
}

void combiningWindows::slotRequestToCreatelist(const boardNedoRello::listInfo &info) //Запрос на создание в доске списка
{
    listInfo list;
    list.idBoard = info.idBoard;
    list.title = info.title;

    emit signalRequestToCreatelist(list);

}

void combiningWindows::createdList(const listInfo &infoList) // Создание списка
{
    list = new listNedoRello();
    list->idList = infoList.idList;
    list->idBoard = infoList.idBoard;
    list->setTitleList(infoList.title);
    widgetsList.append(list);
    board->addListInBoard(list);

}

void combiningWindows::deletingWidgets(int idBoard)
{
    for(int i = 0; i < widgetsList.length(); i++)
    {
        if(widgetsList[i]->idBoard == idBoard)
        {
            delete widgetsList[i];
            widgetsList[i] = nullptr;
            widgetsList.remove(i);
        }
    }

    for(int i = 0; i < widgetsBoard.length(); i++)
    {
        if(widgetsBoard[i]->IdBoard == idBoard)
        {
            delete widgetsBoard[i];
            widgetsBoard[i] = nullptr;
            widgetsBoard.remove(i);
        }
    }

}

void combiningWindows::openAccountWindow(const QString &login) //Открытие окна аккаунта
{
    fstWindow.close();
    accWindow.show();
    accWindow.setLogin(login);
}

void combiningWindows::wrongPasswordFirstWindow() //Сообщение о неправильном логине или пороле
{
    fstWindow.setErrorText("Неверный логин или пороль");
}
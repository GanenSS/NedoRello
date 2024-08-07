#include "combiningwindows.h"

combiningWindows::combiningWindows(QObject *parent)
    : QObject{parent}
{
    openFirstWindow();

    connect(this, &combiningWindows::signalLoginIsInDatabaseRegWindow,          this, &combiningWindows::loginIsInDbRegWindow);
    connect(this, &combiningWindows::signalInputInAccount,                      this, &combiningWindows::openAccountWindow);
    connect(this, &combiningWindows::signalCreatedAccountRegistrationWindow,    this, &combiningWindows::slotCreatedAccountRegistrationWindow);
    connect(this, &combiningWindows::signalErrorLoginCredentialsFirstWindow,    this, &combiningWindows::wrongPasswordFirstWindow);
    connect(this, &combiningWindows::signalCreatedBoard,                        this, &combiningWindows::createdBoard);
    connect(this, &combiningWindows::signalCreatedList,                         this, &combiningWindows::createdList);
    connect(this, &combiningWindows::signalCreatedCard,                         this, &combiningWindows::createdCard);
    connect(this, &combiningWindows::signalNotCompletedCard,                    this, &combiningWindows::slotNotCompletedCard);
    connect(this, &combiningWindows::signalCardCompleted,                       this, &combiningWindows::slotCompletedCard);
    connect(this, &combiningWindows::signalCardInProcess,                       this, &combiningWindows::slotCardInProcess);

}

combiningWindows::~combiningWindows()
{
}

void combiningWindows::openFirstWindow()
{
    fstWindow = new firstWindow;

    connect(fstWindow,  &firstWindow::signalClickedButtonRegistration,  this, &combiningWindows::openRegistrationWindow);
    connect(fstWindow,  &firstWindow::signalClickedButtonEnter,         this, &combiningWindows::getLoginCredentialsFirstWindow);

    fstWindow->show();
}

void combiningWindows::openRegistrationWindow()
{
    regWindow = new registrationWindow;

    connect(regWindow,  &registrationWindow::signalClickedButtonCancel, this, &combiningWindows::openFirstWindow);
    connect(regWindow,  &registrationWindow::signalClickedButtonSave,   this, &combiningWindows::getLoginCredentialsRegistrationWindow);

    regWindow->show();
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
    combCred.password = cred.password;
    emit signalGetLoginCredentialsRegistrationWindow(combCred);
}

void combiningWindows::loginIsInDbRegWindow() // Оповещение пользователя о том, что такой логин уже существует
{
    regWindow->loginIsInDB();
}

void combiningWindows::slotCreatedAccountRegistrationWindow() //Открытие первого окна после конца регистрации
{
    regWindow->closeWindow();
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
    board->setNameBoard(info.name);
    board->setDescriptionBoard(info.description);
    widgetsBoard.append(board);
    board->show();

    accWindow->userId = info.userId;

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
    list->setTitleList(infoList.title);
    widgetsList.append(list);
    list->idBoard = infoList.idBoard;
    board->addListInBoard(list);

    connect(list, &listNedoRello::signalinformationForCombining, this, &combiningWindows::slotRequestToCreateCard);

}

void combiningWindows::deletingWidgets(int idBoard)
{    
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

void combiningWindows::slotRequestToCreateCard(const listNedoRello::infoCardList &info)
{
    cardInfo card;
    card.title = info.title;
    card.description = info.description;
    card.deadLines = info.deadLines;
    card.idList = info.idList;
    card.userID = accWindow->userId;
    emit signalRequestToCreateCard(card);
}

void combiningWindows::createdCard(const cardInfo &info)
{
    cardNedoRello *card = new cardNedoRello;

    connect(card, &cardNedoRello::signalTimeOut,                            this, &combiningWindows::signalCardTimeOut);
    connect(card, &cardNedoRello::signalClickedButtonReady,                 this, &combiningWindows::signalClickedButtonReady);
    connect(card, &cardNedoRello::signalClickedButtonReadyOnCompletedCard,  this, &combiningWindows::signalClickedButtonReadyOnCompletedCard);

    card->idCard = info.idCard;
    card->setTitle(info.title);
    card->setDescription(info.description);
    card->setDeadLines(info.deadLines);
    card->setLogin(accWindow->getLogin());

    widgetsCard.append(card);

    for(int i = 0; i < widgetsList.length(); i++)
    {
        if(widgetsList[i]->idList == info.idList)
        {
            if(widgetsList[i]->counterCard != 0)
            {
                widgetsList[i]->resizeList();

                widgetsList[i]->addCardInList(card);
            }
            else
            {
                widgetsList[i]->addCardInList(card);
            }
        }
    }
}

void combiningWindows::slotNotCompletedCard(const int &cardId)
{
    for(int i = 0; i < widgetsCard.length(); i++)
    {
        if(widgetsCard[i]->idCard == cardId)
        {
            widgetsCard[i]->slotNotCompletedCard();
        }
    }
}

void combiningWindows::slotCompletedCard(const int &idCard)
{
    for(int i = 0; i < widgetsCard.length(); i++)
    {
        if(widgetsCard[i]->idCard == idCard)
        {
            widgetsCard[i]->slotCompletedCard();
        }
    }
}

void combiningWindows::slotCardInProcess(const int &idCard)
{
    for(int i = 0; i < widgetsCard.length(); i++)
    {
        if(widgetsCard[i]->idCard == idCard)
        {
            widgetsCard[i]->slotCardInProcess();
        }
    }
}

void combiningWindows::openAccountWindow(const QString &login) //Открытие окна аккаунта
{
    fstWindow->closeWindow();

    accWindow = new accountWindow;

    connect(accWindow, &accountWindow::signalCreatedBoardAccountWindow, this, &combiningWindows::slotClickedButtonCreateBoard);
    connect(accWindow, &accountWindow::signalClickedButtonExit,         this, &combiningWindows::exitFromAccaunt);

    accWindow->show();
    accWindow->setLogin(login);
}

void combiningWindows::exitFromAccaunt()
{
    accWindow->closeWindow();
    openFirstWindow();
}

void combiningWindows::wrongPasswordFirstWindow() //Сообщение о неправильном логине или пароле
{
    fstWindow->setErrorText("Неверный логин или пароль");
}

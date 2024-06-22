#include "accountwindow.h"
#include "ui_accountwindow.h"

accountWindow::accountWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::accountWindow)
{
    ui->setupUi(this);
    connect(ui->buttonCreate, &QPushButton::clicked, this, &accountWindow::openCreateBoard);
    connect(&creatBoard, &createBoard::signalClickedButtonCreate, this, &accountWindow::slotCreatedBoard);
}

accountWindow::~accountWindow()
{
    delete ui;
}

void accountWindow::setLogin(const QString &login)
{
    ui->labelLogin->setText(login);
}

void accountWindow::openCreateBoard()
{
    creatBoard.show();
}

void accountWindow::slotCreatedBoard()
{
    boardInfo info;
    info.name = creatBoard.getNameBoard();
    info.description = creatBoard.getDescriptionBoard();
    info.login = ui->labelLogin->text();
    emit signalCreatedBoardAccountWindow(info);
}

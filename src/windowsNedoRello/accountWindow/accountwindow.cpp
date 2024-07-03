#include "accountwindow.h"
#include "ui_accountwindow.h"

accountWindow::accountWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::accountWindow)
{
    ui->setupUi(this);

    setInterfaceStyle();

    connect(ui->buttonCreate, &QPushButton::clicked, this, &accountWindow::openCreateBoard);
    connect(ui->buttonExit, &QPushButton::clicked, this, &accountWindow::slotClickedButtonExit);
}

accountWindow::~accountWindow()
{
    delete ui;
}

void accountWindow::closeEvent(QCloseEvent *event)
{
    closeWindow();
}

void accountWindow::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

void accountWindow::setInterfaceStyle()
{
    this->setStyleSheet(Styles::getAccountWidgetStyle());

    ui->labelLogin->setStyleSheet(Styles::getLabelText());
    ui->labelAccountTables->setStyleSheet(Styles::getLabelText());

    ui->buttonEnter->setStyleSheet(Styles::getButtonStyle());
    ui->buttonCreate->setStyleSheet(Styles::getButtonStyle());
    ui->buttonExit->setStyleSheet(Styles::getButtonStyle());

    ui->scrollArea->setStyleSheet(Styles::getScrollAreaStyle());
}

void accountWindow::setLogin(const QString &login)
{
    ui->labelLogin->setText(login);
}

QString accountWindow::getLogin()
{
    return ui->labelLogin->text();
}

void accountWindow::openCreateBoard()
{
    creatBoard = new createBoard;

    connect(creatBoard, &createBoard::signalClickedButtonCreate, this, &accountWindow::slotCreatedBoard);

    creatBoard->show();
}

void accountWindow::slotCreatedBoard()
{
    boardInfo info;
    info.name = creatBoard->getNameBoard();
    info.description = creatBoard->getDescriptionBoard();
    info.login = ui->labelLogin->text();
    emit signalCreatedBoardAccountWindow(info);
}

void accountWindow::closeWindow()
{
    delete this;
}

void accountWindow::slotClickedButtonExit()
{
    emit signalClickedButtonExit();
}

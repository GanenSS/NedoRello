#include "firstWindow.h"
#include "ui_firstwindow.h"

firstWindow::firstWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::firstWindow)
{

    ui->setupUi(this);
    connect(ui->buttonRegistration, &QPushButton::clicked,      this, &firstWindow::slotClickedButtonRegistration);
    connect(ui->buttonRegistration, &QPushButton::clicked,      this, &firstWindow::closeWindow);
    connect(ui->buttonEnter,        &QPushButton::clicked,      this, &firstWindow::slotClickedButtonEnter);
    connect(ui->buttonVision,       &QPushButton::pressed,      this, &firstWindow::pressedButtonVision);
    connect(ui->buttonVision,       &QPushButton::released,     this, &firstWindow::releasedButtonVision);
}

firstWindow::~firstWindow()
{
    delete ui;
}

void firstWindow::slotClickedButtonRegistration()
{
    emit signalClickedButtonRegistration();
}

void firstWindow::slotClickedButtonEnter()
{
    LoginCredentials creds;
    creds.login = getLogin();
    creds.password = getPassword();
    emit signalClickedButtonEnter(creds);
}

void firstWindow::pressedButtonVision()
{
    ui->editPassword->setEchoMode(QLineEdit::Normal);
}

void firstWindow::releasedButtonVision()
{
    ui->editPassword->setEchoMode(QLineEdit::Password);
}

void firstWindow::setErrorText(const QString& ErrorMessage)
{
    ui->labelPasswordErroreMessage->setText(ErrorMessage);
}

void firstWindow::closeWindow()
{
    delete this;
}

QString firstWindow::getLogin()
{
    QString login = ui->editLogin->text();
    return login;
}

QString firstWindow::getPassword()
{
    QString password = ui->editPassword->text();
    return password;
}


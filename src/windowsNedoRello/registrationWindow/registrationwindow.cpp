#include "registrationwindow.h"
#include "ui_registrationwindow.h"

registrationWindow::registrationWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::registrationWindow)
{
    ui->setupUi(this);

    connect(ui->buttonCancel,       &QPushButton::clicked,      this, &registrationWindow::slotClickedButtonCancel);
    connect(ui->buttonCancel,       &QPushButton::clicked,      this, &registrationWindow::closeWindow);

    connect(ui->buttonSave,         &QPushButton::clicked,      this, &registrationWindow::slotClickedButtonSave);

    connect(ui->buttonFirstVision,  &QPushButton::pressed,      this, &registrationWindow::pressedFirstButtonVision);
    connect(ui->buttonFirstVision,  &QPushButton::released,     this, &registrationWindow::releasedFirstButtonVision);

    connect(ui->buttonSecondVision, &QPushButton::pressed,      this, &registrationWindow::pressedSecondButtonVision);
    connect(ui->buttonSecondVision, &QPushButton::released,     this, &registrationWindow::releasedSecondButtonVision);
    connect(ui->editSecondPassword, &QLineEdit::textChanged,    this, &registrationWindow::comparisonPassword);

}

registrationWindow::~registrationWindow()
{
    delete ui;
}

void registrationWindow::slotClickedButtonCancel()
{
    emit signalClickedButtonCancel();
}

void registrationWindow::slotClickedButtonSave()
{
    if(comparisonPassword() && getLogin() != "")
    {
        LoginCredentials cred;
        cred.login = getLogin();
        cred.password = getFirstPassword();
        emit signalClickedButtonSave(cred);
    }
    else
    {
        ui->labelErrorePasswordMessage->setText("Заполните все поля правильно");
    }
}

void registrationWindow::pressedFirstButtonVision()
{
    ui->editFirstPassword->setEchoMode(QLineEdit::Normal);
}

void registrationWindow::releasedFirstButtonVision()
{
    ui->editFirstPassword->setEchoMode(QLineEdit::Password);
}

void registrationWindow::pressedSecondButtonVision()
{
    ui->editSecondPassword->setEchoMode(QLineEdit::Normal);
}

void registrationWindow::releasedSecondButtonVision()
{
    ui->editSecondPassword->setEchoMode(QLineEdit::Password);
}

void registrationWindow::loginIsInDB()
{
    ui->labelErrorLoginMessage->setText("Такой логин уже существует");
}

bool registrationWindow::comparisonPassword()
{
    if(getFirstPassword() == getSecondPassword())
    {
        ui->labelErrorePasswordMessage->setText("");
        return true;
    }
    else
    {
        ui->labelErrorePasswordMessage->setText("Пороли не совпадают");
        return false;
    }
}

QString registrationWindow::getLogin()
{
    QString login = ui->editLogin->text();
    return login;
}

QString registrationWindow::getFirstPassword()
{
    QString password = ui->editFirstPassword->text();
    return password;
}

QString registrationWindow::getSecondPassword()
{
    QString password = ui->editSecondPassword->text();
    return password;
}

void registrationWindow::closeWindow()
{
    delete this;
}

#include "cardnedorello.h"
#include "ui_cardnedorello.h"

cardNedoRello::cardNedoRello(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardNedoRello)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDisplayFormat("hh:mm dd.MM.yyyy");
    ui->dateTimeEdit->setReadOnly(true);
    ui->dateTimeEdit->setButtonSymbols(QDateTimeEdit::NoButtons);
    ui->textBrowserDescription->setReadOnly(true);
}

cardNedoRello::~cardNedoRello()
{
    delete ui;
}

void cardNedoRello::setTitle(const QString &title)
{
    ui->labelTitle->setText(title);
}

void cardNedoRello::setDescription(const QString &description)
{
    ui->textBrowserDescription->setText(description);
}

void cardNedoRello::setDeadLines(const QDateTime &deadLines)
{
    ui->dateTimeEdit->setDateTime(deadLines);
}

void cardNedoRello::setLogin(const QString &login)
{
    ui->labelLoginUser->setText(login);
}

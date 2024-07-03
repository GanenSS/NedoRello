#include "cardnedorello.h"
#include "ui_cardnedorello.h"

cardNedoRello::cardNedoRello(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardNedoRello)
{
    ui->setupUi(this);
    setInterfaceStyle();

    connect(ui->dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &cardNedoRello::checkingTime);
    connect(ui->buttonReady, &QPushButton::clicked, this, &cardNedoRello::slotClickedButtonReady);

    ui->dateTimeEdit->setDisplayFormat("hh:mm dd.MM.yyyy");
    ui->dateTimeEdit->setReadOnly(true);
    ui->dateTimeEdit->setButtonSymbols(QDateTimeEdit::NoButtons);
    ui->textBrowserDescription->setReadOnly(true);
}

cardNedoRello::~cardNedoRello()
{
    delete ui;
}

void cardNedoRello::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

void cardNedoRello::setInterfaceStyle()
{
    this->setStyleSheet(Styles::getNormalStyle());

    ui->label->setStyleSheet(Styles::getLabelText());
    ui->labelLoginUser->setStyleSheet(Styles::getLabelText());
    ui->labelTitle->setStyleSheet(Styles::getLabelText());

    ui->buttonEdit->setStyleSheet(Styles::getButtonStyle());
    ui->buttonReady->setStyleSheet(Styles::getButtonStyle());
    ui->buttonDeleteCard->setStyleSheet(Styles::getButtonStyle());

    ui->textBrowserDescription->setStyleSheet(Styles::getTextBrowserStyle());

    ui->dateTimeEdit->setStyleSheet(Styles::getDateTimeEditStyle());
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

void cardNedoRello::checkingTime()
{
    if(resultCard == cardInProcess)
    {
        if(ui->dateTimeEdit->dateTime() < QDateTime::currentDateTime())
        {
            emit signalTimeOut(idCard);
            resultCard = notCompletedCard;
        }
        else
        {
            QTimer::singleShot(1000, this, checkingTime);
        }
    }
}

void cardNedoRello::slotNotCompletedCard()
{
    this->setStyleSheet(Styles::getNotCompletedStyle());

    resultCard = notCompletedCard;
}

void cardNedoRello::slotCompletedCard()
{
    this->setStyleSheet(Styles::getAcceptStyle());

    resultCard = completedCard;
}

void cardNedoRello::slotClickedButtonReady()
{
    if(resultCard == cardInProcess){
        emit signalClickedButtonReady(idCard);}
    else
    {
        if(resultCard == completedCard){
            emit signalClickedButtonReadyOnCompletedCard(idCard);
        }
    }
}

void cardNedoRello::slotCardInProcess()
{
    this->setStyleSheet(Styles::getNormalStyle());

    resultCard = cardInProcess;

    checkingTime();
}

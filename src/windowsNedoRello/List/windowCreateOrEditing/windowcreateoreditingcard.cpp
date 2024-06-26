#include "windowcreateoreditingcard.h"
#include "ui_windowcreateoreditingcard.h"

windowCreateOrEditingCard::windowCreateOrEditingCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowCreateOrEditingCard)
{
    ui->setupUi(this);

    connect(ui->buttonCancel, &QPushButton::clicked, this, &QWidget::close);
    connect(ui->buttonCreate, &QPushButton::clicked, this, &windowCreateOrEditingCard::clickedButtonCreate);

    ui->dateTimeDeadLines->setDisplayFormat("hh:mm dd.MM.yyyy");

    ui->dateTimeDeadLines->setDateTime(QDateTime::currentDateTime());

}

windowCreateOrEditingCard::~windowCreateOrEditingCard()
{
    delete ui;
}

void windowCreateOrEditingCard::clickedButtonCreate()
{
    if(ui->editTitleCard->text() == "")
    {
        QMessageBox::warning(0, "Придумаете вашей карточке название", "Карточка не может быть без названия.");
    }
    else
    {
        if(ui->editDesriptionCard->toPlainText() == "")
        {
            QMessageBox::warning(0, "Напишите вашей карточке описание", "Карточка не может быть без описания.");
        }
        else
        {
            if(ui->dateTimeDeadLines->dateTime() < QDateTime::currentDateTime() || ui->dateTimeDeadLines->dateTime() == QDateTime::currentDateTime())
            {
                QMessageBox::warning(0, "Введите дату и время", "Введите время за которое нужно выполнить задачу.");
            }
            else
            {
                infoCard info;
                info.title = ui->editTitleCard->text();
                info.description = ui->editDesriptionCard->toPlainText();
                info.deadLines = ui->dateTimeDeadLines->dateTime();
                emit signalclickedButtonCreate(info);
            }
        }
    }
}

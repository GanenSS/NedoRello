#include "windowcreateoreditingcard.h"
#include "ui_windowcreateoreditingcard.h"

windowCreateOrEditingCard::windowCreateOrEditingCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowCreateOrEditingCard)
{
    ui->setupUi(this);

    setInterfaceStyle();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &windowCreateOrEditingCard::closeWindow);
    connect(ui->buttonCreate, &QPushButton::clicked, this, &windowCreateOrEditingCard::clickedButtonCreate);

    ui->dateTimeDeadLines->setDisplayFormat("hh:mm dd.MM.yyyy");

    ui->dateTimeDeadLines->setDateTime(QDateTime::currentDateTime());

}

windowCreateOrEditingCard::~windowCreateOrEditingCard()
{
    delete ui;
}

void windowCreateOrEditingCard::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

void windowCreateOrEditingCard::setInterfaceStyle()
{
    ui->dateTimeDeadLines->setStyleSheet(Styles::getDateTimeEditStyle());

    ui->label->setStyleSheet(Styles::getLabelText());
    ui->labelDescriptionBoard->setStyleSheet(Styles::getLabelText());
    ui->labelNameBoard->setStyleSheet(Styles::getLabelText());

    ui->buttonCancel->setStyleSheet(Styles::getButtonStyle());
    ui->buttonCreate->setStyleSheet(Styles::getButtonStyle());

    ui->editDesriptionCard->setStyleSheet(Styles::getEditStyle());
    ui->editTitleCard->setStyleSheet(Styles::getEditStyle());
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

                closeWindow();
            }
        }
    }
}

void windowCreateOrEditingCard::closeWindow()
{
    delete this;
}

void windowCreateOrEditingCard::closeEvent(QCloseEvent *event)
{
    closeWindow();
}

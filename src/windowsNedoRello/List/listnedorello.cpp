#include "listnedorello.h"
#include "ui_listnedorello.h"

listNedoRello::listNedoRello(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::listNedoRello)
{
    ui->setupUi(this);

    connect(ui->buttonAddCard, &QPushButton::clicked, this, &listNedoRello::slotClickedButtonAddCard);
}

listNedoRello::~listNedoRello()
{
    delete ui;
}

void listNedoRello::createdList()
{
    ui->verticalLayoutForCards->addSpacerItem(spacer);
}

void listNedoRello::setTitleList(const QString &title)
{
    ui->labelTitle->setText("         "+title);
}

void listNedoRello::slotClickedButtonAddCard()
{
    createWindowCard = new windowCreateOrEditingCard;

    createWindowCard->show();

    connect(createWindowCard, &windowCreateOrEditingCard::signalclickedButtonCreate, this, &listNedoRello::informationForCombining);
}

void listNedoRello::informationForCombining(const windowCreateOrEditingCard::infoCard& info)
{
    infoCardList card;
    card.title = info.title;
    card.description = info.description;
    card.deadLines = info.deadLines;
    card.idList = idList;

    emit signalinformationForCombining(card);
}

void listNedoRello::addCardInList(QWidget *card)
{
    ui->verticalLayoutForCards->removeItem(ui->verticalSpacerForCards);
    ui->verticalLayoutForCards->addWidget(card);
    ui->verticalLayoutForCards->addItem(ui->verticalSpacerForCards);
    counterCard += 1;

    ui->verticalLayoutForCards->invalidate();
}

void listNedoRello::resizeList()
{
    this->setMaximumHeight(this->maximumHeight()+220);
    this->setMinimumHeight(this->minimumHeight()+220);
}


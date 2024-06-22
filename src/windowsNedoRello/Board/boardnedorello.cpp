#include "boardnedorello.h"
#include "ui_boardnedorello.h"

boardNedoRello::boardNedoRello(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::boardNedoRello)
{
    ui->setupUi(this);

    connect(ui->buttonDescription,  &QPushButton::clicked,                          this, &boardNedoRello::clickedButtonDescription);
    connect(ui->buttonAddList,      &QPushButton::clicked,                          this, &boardNedoRello::slotClickedButtonAddList);
    connect(&winCreatedList,        &windowCreatedList::signalClickedCreatedButton, this, &boardNedoRello::slotRequestToCreatelist);

    popUp = new PopUp();

    ui->horizontalLayoutLists->addItem(spacer);
}

boardNedoRello::~boardNedoRello()
{
    delete ui;
    delete popUp;
}

void boardNedoRello::closeEvent(QCloseEvent *event)
{
    emit destroyedBoard(IdBoard);

}

void boardNedoRello::setNameBoard(const QString &name)
{
    ui->labelTitle->setText(name);
}

void boardNedoRello::setDescriptionBoard(const QString &desc)
{
    description = desc;
}

void boardNedoRello::clickedButtonDescription()
{
    popUp->setPopupText(description);

    popUp->show();
}

void boardNedoRello::slotClickedButtonAddList()
{
    winCreatedList.show();
}

void boardNedoRello::slotRequestToCreatelist()
{
    listInfo info;
    info.idBoard = IdBoard;
    info.title = winCreatedList.getTitleList();
    emit signalRequestToCreatelistBoard(info);
}

void boardNedoRello::addListInBoard(QWidget *list)
{
    vertBoxLayoutLists = new QVBoxLayout;
    vertBoxLayoutLists->addWidget(list);

    spacerList = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vertBoxLayoutLists->addItem(spacerList);

    ui->horizontalLayoutLists->removeItem(spacer);
    ui->horizontalLayoutLists->addLayout(vertBoxLayoutLists);
    ui->horizontalLayoutLists->addItem(spacer);

    ui->horizontalLayoutLists->update();
}


#include "boardnedorello.h"
#include "ui_boardnedorello.h"

boardNedoRello::boardNedoRello(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::boardNedoRello)
{
    ui->setupUi(this);

    setInterfaceStyle();

    connect(ui->buttonDescription,  &QPushButton::clicked,                          this, &boardNedoRello::clickedButtonDescription);
    connect(ui->buttonAddList,      &QPushButton::clicked,                          this, &boardNedoRello::slotClickedButtonAddList);

    popUp = new PopUp();


    ui->horBoxLayoutLists->addItem(spacer);
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

void boardNedoRello::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

void boardNedoRello::setInterfaceStyle()
{
    ui->scrollArea->setStyleSheet(Styles::getScrollAreaStyle());

    ui->buttonAddList->setStyleSheet(Styles::getButtonStyle());
    ui->buttonDescription->setStyleSheet(Styles::getButtonStyle());
    ui->buttonSearchUser->setStyleSheet(Styles::getButtonStyle());

    ui->labelTitle->setStyleSheet(Styles::getLabelText());
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
    winCreatedList = new windowCreatedList;

    connect(winCreatedList, &windowCreatedList::signalClickedCreatedButton, this, &boardNedoRello::slotRequestToCreatelist);

    winCreatedList->show();
}

void boardNedoRello::slotRequestToCreatelist()
{
    listInfo info;
    info.idBoard = IdBoard;
    info.title = winCreatedList->getTitleList();
    emit signalRequestToCreatelistBoard(info);
}

void boardNedoRello::addListInBoard(QWidget *list)
{
    vertBoxLayoutLists = new QVBoxLayout;
    vertBoxLayoutLists->addWidget(list);
    list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    spacerList = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vertBoxLayoutLists->addItem(spacerList);

    ui->horBoxLayoutLists->removeItem(spacer);
    ui->horBoxLayoutLists->addLayout(vertBoxLayoutLists);
    ui->horBoxLayoutLists->addItem(spacer);

    ui->horBoxLayoutLists->update();
}




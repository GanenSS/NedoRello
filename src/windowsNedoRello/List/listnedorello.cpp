#include "listnedorello.h"
#include "ui_listnedorello.h"

listNedoRello::listNedoRello(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::listNedoRello)
{
    ui->setupUi(this);
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
    ui->labelTitle->setText(title);
}

int listNedoRello::getIdBoard()
{
    return idBoard;
}

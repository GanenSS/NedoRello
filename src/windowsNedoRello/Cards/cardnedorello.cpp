#include "cardnedorello.h"
#include "ui_cardnedorello.h"

cardNedoRello::cardNedoRello(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardNedoRello)
{
    ui->setupUi(this);
}

cardNedoRello::~cardNedoRello()
{
    delete ui;
}

#include "inputboard.h"
#include "ui_inputboard.h"

inputBoard::inputBoard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inputBoard)
{
    ui->setupUi(this);
}

inputBoard::~inputBoard()
{
    delete ui;
}

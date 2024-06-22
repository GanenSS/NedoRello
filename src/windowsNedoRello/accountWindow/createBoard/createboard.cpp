#include "createboard.h"
#include "ui_createboard.h"

createBoard::createBoard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::createBoard)
{
    ui->setupUi(this);
    connect(ui->buttonCreate, &QPushButton::clicked, this, &createBoard::slotClickedButtonCreate);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &QWidget::close);
    connect(&confWindow, &confirmationWindow::signalClickedButtonCreate, this, &createBoard::slotClickedButtonCreateConfirmationWindow);
}

createBoard::~createBoard()
{
    delete ui;
}

QString createBoard::getNameBoard()
{
    return ui->editNameBoard->text();
}

QString createBoard::getDescriptionBoard()
{
    return ui->editDesriptionBoard->toPlainText();
}

void createBoard::slotClickedButtonCreate()
{
    if(ui->editNameBoard->text() == "")
    {
        QMessageBox::warning(0, "Придумаете вашей доске название", "Доска не может быть без названия");
    }
    else
    {
        if(ui->editDesriptionBoard->toPlainText() == "")
        {
            QMessageBox::warning(0, "Напишите вашей доске описание", "Доска не может быть без описания");
        }
        else
        {
            confWindow.show();
        }
    }
}

void createBoard::slotClickedButtonCreateConfirmationWindow()
{
    this->close();
    emit signalClickedButtonCreate();
}

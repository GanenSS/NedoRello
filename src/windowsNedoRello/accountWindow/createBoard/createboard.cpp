#include "createboard.h"
#include "ui_createboard.h"

createBoard::createBoard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::createBoard)
{
    ui->setupUi(this);

    setInterfaceStyle();

    connect(ui->buttonCreate, &QPushButton::clicked, this, &createBoard::slotClickedButtonCreate);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &createBoard::closeWindow);
}

createBoard::~createBoard()
{
    delete ui;
}

void createBoard::closeEvent(QCloseEvent *event)
{
    closeWindow();
}

void createBoard::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

void createBoard::setInterfaceStyle()
{
    ui->buttonCreate->setStyleSheet(Styles::getButtonStyle());
    ui->buttonCancel->setStyleSheet(Styles::getButtonStyle());

    ui->labelNameBoard->setStyleSheet(Styles::getLabelText());
    ui->labelDescriptionBoard->setStyleSheet(Styles::getLabelText());

    ui->editNameBoard->setStyleSheet(Styles::getEditStyle());
    ui->editDesriptionBoard->setStyleSheet(Styles::getEditStyle());
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
            emit signalClickedButtonCreate();
            closeWindow();
        }
    }
}

void createBoard::closeWindow()
{
    delete this;
}



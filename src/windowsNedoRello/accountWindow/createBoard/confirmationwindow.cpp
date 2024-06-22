#include "confirmationwindow.h"
#include "ui_confirmationwindow.h"

confirmationWindow::confirmationWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::confirmationWindow)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &QWidget::close);
    connect(ui->buttonCreate, &QPushButton::clicked, this, &confirmationWindow::slotClickedButtonCreate);
    connect(ui->buttonCreate, &QPushButton::clicked, this, &QWidget::close);
}

confirmationWindow::~confirmationWindow()
{
    delete ui;
}

void confirmationWindow::slotClickedButtonCreate()
{
    emit signalClickedButtonCreate();
}

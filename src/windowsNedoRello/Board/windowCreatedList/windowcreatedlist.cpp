#include "windowcreatedlist.h"
#include "ui_windowcreatedlist.h"

windowCreatedList::windowCreatedList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowCreatedList)
{
    ui->setupUi(this);

    connect(ui->buttonCrated, &QPushButton::clicked, this, &windowCreatedList::slotClickedCreatedButton);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &QWidget::close);
}

windowCreatedList::~windowCreatedList()
{
    delete ui;
}

QString windowCreatedList::getTitleList()
{
    QString title = ui->editTitleList->text();
    return title;
}

void windowCreatedList::slotClickedCreatedButton()
{
    if(ui->editTitleList->text() == "")
    {
        QMessageBox::warning(0, "Поле \"Заголовок\" пустое", "Придумайте заголовок");
    }
    else
    {
        emit signalClickedCreatedButton();
        this->close();
    }

}

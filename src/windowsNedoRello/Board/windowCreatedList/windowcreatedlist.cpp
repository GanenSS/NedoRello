#include "windowcreatedlist.h"
#include "ui_windowcreatedlist.h"

windowCreatedList::windowCreatedList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windowCreatedList)
{
    ui->setupUi(this);

    setInterfaceStyle();

    connect(ui->buttonCreated, &QPushButton::clicked, this, &windowCreatedList::slotClickedCreatedButton);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &windowCreatedList::closWindow);
}

windowCreatedList::~windowCreatedList()
{
    delete ui;
}

void windowCreatedList::closeEvent(QCloseEvent *event)
{
    closWindow();
}

void windowCreatedList::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

void windowCreatedList::setInterfaceStyle()
{
    ui->buttonCreated->setStyleSheet(Styles::getButtonStyle());
    ui->buttonCancel->setStyleSheet(Styles::getButtonStyle());

    ui->label->setStyleSheet(Styles::getLabelText());

    ui->editTitleList->setStyleSheet(Styles::getEditStyle());
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
        this->closWindow();
    }

}

void windowCreatedList::closWindow()
{
    delete this;
}

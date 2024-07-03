#ifndef LISTNEDORELLO_H
#define LISTNEDORELLO_H

#include "windowcreateoreditingcard.h"
#include "styles.h"

#include <QWidget>
#include <QSpacerItem>
#include <QPainter>
#include <QStyleOption>

namespace Ui {
class listNedoRello;
}

class listNedoRello : public QWidget
{
    Q_OBJECT

public:
    explicit listNedoRello(QWidget *parent = nullptr);
    ~listNedoRello();

    struct infoCardList
    {
        QString title;
        QString description;
        QDateTime deadLines;
        int idList;
    };

    int idList;
    int idBoard;
    int counterCard = 0;
    windowCreateOrEditingCard *createWindowCard;
private:
    Ui::listNedoRello *ui;

    const int heightCard = 230;

    QSpacerItem* spacer         = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Expanding);
protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void setInterfaceStyle();
    void createdList();
    void setTitleList(const QString& title);
    void slotClickedButtonAddCard();
    void informationForCombining(const windowCreateOrEditingCard::infoCard &info);
    void addCardInList(QWidget* card);
    void resizeList();

signals:
    void signalinformationForCombining(const infoCardList &info);

};

#endif // LISTNEDORELLO_H

#ifndef BOARDNEDORELLO_H
#define BOARDNEDORELLO_H

#include "popup.h"
#include "windowcreatedlist.h"
#include "styles.h"

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QSpacerItem>

namespace Ui {
class boardNedoRello;
}

class boardNedoRello : public QWidget
{
    Q_OBJECT

public:
    explicit boardNedoRello(QWidget *parent = nullptr);
    ~boardNedoRello();

    struct listInfo
    {
        int idList;
        int idBoard;
        QString title;
    };

    int IdBoard;
private:
    Ui::boardNedoRello *ui;

    QString description;

    PopUp *popUp;

    windowCreatedList *winCreatedList;

    QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem* spacerList;
    QVBoxLayout* vertBoxLayoutLists;

protected:
    void closeEvent(QCloseEvent* event);
    void paintEvent(QPaintEvent *event);

public slots:
    void setInterfaceStyle();
    void setNameBoard(const QString& name);
    void setDescriptionBoard(const QString& desc);
    void clickedButtonDescription();

    void slotClickedButtonAddList();
    void slotRequestToCreatelist();
    void addListInBoard(QWidget *list);
signals:
    void signalClickedButtonAddList();
    void signalRequestToCreatelistBoard(const listInfo& info);
    void destroyedBoard(int idBoard);
};

#endif // BOARDNEDORELLO_H

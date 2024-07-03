#ifndef WINDOWCREATEOREDITINGCARD_H
#define WINDOWCREATEOREDITINGCARD_H

#include "styles.h"

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class windowCreateOrEditingCard;
}

class windowCreateOrEditingCard : public QWidget
{
    Q_OBJECT

public:
    explicit windowCreateOrEditingCard(QWidget *parent = nullptr);
    ~windowCreateOrEditingCard();

    struct infoCard
    {
        QString title;
        QString description;
        QDateTime deadLines;
    };

private:
    Ui::windowCreateOrEditingCard *ui;

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void setInterfaceStyle();
    void clickedButtonCreate();
    void closeWindow();
    void closeEvent(QCloseEvent* event);

signals:
    void signalclickedButtonCreate(const infoCard& info);
};

#endif // WINDOWCREATEOREDITINGCARD_H

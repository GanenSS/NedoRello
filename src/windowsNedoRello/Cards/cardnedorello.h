#ifndef CARDNEDORELLO_H
#define CARDNEDORELLO_H

#include "styles.h"

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QDateTime>
#include <QTimer>

namespace Ui {
class cardNedoRello;
}

class cardNedoRello : public QWidget
{
    Q_OBJECT

public:
    explicit cardNedoRello(QWidget *parent = nullptr);
    ~cardNedoRello();

    int idCard;
private:
    Ui::cardNedoRello *ui;

    const QString cardInProcess     = "В ПРОЦЕССЕ";
    const QString completedCard     = "ВЫПОЛНЕННО";
    const QString notCompletedCard  = "НЕ ВЫПОЛНЕННО";

    QString resultCard = "В ПРОЦЕССЕ";

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void setInterfaceStyle();
    void setTitle(const QString& title);
    void setDescription (const QString &description);
    void setDeadLines(const QDateTime& deadLines);
    void setLogin(const QString &login);
    void checkingTime();
    void slotNotCompletedCard();
    void slotCompletedCard();
    void slotClickedButtonReady();
    void slotCardInProcess();

signals:
    void signalTimeOut(const int& idCard);
    void signalClickedButtonReady(const int& idCard);
    void signalClickedButtonReadyOnCompletedCard(const int& idCard);
};

#endif // CARDNEDORELLO_H

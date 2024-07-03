#ifndef CREATEBOARD_H
#define CREATEBOARD_H

#include "styles.h"

#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include <QStyleOption>

namespace Ui {
class createBoard;
}

class createBoard : public QWidget
{
    Q_OBJECT

public:
    explicit createBoard(QWidget *parent = nullptr);
    ~createBoard();

private:
    Ui::createBoard *ui;

protected:
    void closeEvent(QCloseEvent* event);
    void paintEvent(QPaintEvent *event);

public slots:
    void setInterfaceStyle();
    QString getNameBoard();
    QString getDescriptionBoard();
    void slotClickedButtonCreate();
    void closeWindow();

signals:
    void signalClickedButtonCreate();
};

#endif // CREATEBOARD_H

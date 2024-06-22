#ifndef CREATEBOARD_H
#define CREATEBOARD_H

#include "confirmationwindow.h"

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class createBoard;
}

class createBoard : public QWidget
{
    Q_OBJECT

public:
    explicit createBoard(QWidget *parent = nullptr);
    ~createBoard();

    confirmationWindow confWindow;
private:
    Ui::createBoard *ui;

public slots:
    QString getNameBoard();
    QString getDescriptionBoard();
    void slotClickedButtonCreate();
    void slotClickedButtonCreateConfirmationWindow();

signals:
    void signalClickedButtonCreate();
};

#endif // CREATEBOARD_H

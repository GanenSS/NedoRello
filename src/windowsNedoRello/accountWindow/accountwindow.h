#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H

#include "createboard.h"
#include "inputboard.h"
#include <QWidget>

namespace Ui {
class accountWindow;
}

class accountWindow : public QWidget
{
    Q_OBJECT

public:
    explicit accountWindow(QWidget *parent = nullptr);
    ~accountWindow();

    struct boardInfo
    {
        QString name;
        QString description;
        QString login;
    };

    createBoard creatBoard;
private:
    Ui::accountWindow *ui;

public slots:
    void setLogin(const QString &login);
    void openCreateBoard();
    void slotCreatedBoard();
signals:
    void signalCreatedBoardAccountWindow(const boardInfo& info);
};

#endif // ACCOUNTWINDOW_H

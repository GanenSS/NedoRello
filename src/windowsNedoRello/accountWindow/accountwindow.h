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

    createBoard *creatBoard;

    int userId;
private:
    Ui::accountWindow *ui;

protected:
    void closeEvent(QCloseEvent* event);
public slots:
    void setLogin(const QString &login);
    QString getLogin();
    void openCreateBoard();
    void slotCreatedBoard();
    void closeWindow();
    void slotClickedButtonExit();
signals:
    void signalCreatedBoardAccountWindow(const boardInfo& info);
    void signalClickedButtonExit();
};

#endif // ACCOUNTWINDOW_H

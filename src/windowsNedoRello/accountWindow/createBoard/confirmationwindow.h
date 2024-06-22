#ifndef CONFIRMATIONWINDOW_H
#define CONFIRMATIONWINDOW_H

#include <QWidget>

namespace Ui {
class confirmationWindow;
}

class confirmationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit confirmationWindow(QWidget *parent = nullptr);
    ~confirmationWindow();

private:
    Ui::confirmationWindow *ui;

public slots:
    void slotClickedButtonCreate();
signals:
    void signalClickedButtonCreate();
};

#endif // CONFIRMATIONWINDOW_H

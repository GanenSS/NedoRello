#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include "styles.h"

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

namespace Ui {
class registrationWindow;
}

class registrationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit registrationWindow(QWidget *parent = nullptr);
    ~registrationWindow();
    Ui::registrationWindow *ui;

    struct LoginCredentials
    {
        QString login;
        QString password;
    };


protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void setInterfaceStyle();
    void slotClickedButtonCancel();
    void slotClickedButtonSave();

    void pressedFirstButtonVision();
    void releasedFirstButtonVision();

    void pressedSecondButtonVision();
    void releasedSecondButtonVision();

    void loginIsInDB();

    bool comparisonPassword();

    QString getLogin();
    QString getFirstPassword();
    QString getSecondPassword();

    void closeWindow();
signals:
    void signalClickedButtonCancel();
    void signalClickedButtonSave(const LoginCredentials& cred);


};

#endif // REGISTRATIONWINDOW_H

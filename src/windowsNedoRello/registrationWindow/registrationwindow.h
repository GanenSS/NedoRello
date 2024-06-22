#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>

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

public slots:
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

signals:
    void signalClickedButtonCancel();
    void signalClickedButtonSave(const LoginCredentials& cred);


};

#endif // REGISTRATIONWINDOW_H

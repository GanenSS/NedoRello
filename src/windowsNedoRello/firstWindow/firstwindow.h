#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QWidget>

namespace Ui {
class firstWindow;
}

class firstWindow : public QWidget
{
    Q_OBJECT
public:
    explicit firstWindow(QWidget *parent = nullptr);
    ~firstWindow();

    struct LoginCredentials
    {
        QString login;
        QString password;
    };

private:
    Ui::firstWindow *ui;

public slots:
    void    slotClickedButtonRegistration();
    void    slotClickedButtonEnter();
    void    pressedButtonVision();
    void    releasedButtonVision();
    void    setErrorText(const QString &ErrorMessage);

    QString getLogin();
    QString getPassword();


signals:
    void signalClickedButtonRegistration();
    void signalClickedButtonEnter(const LoginCredentials& cred);

};

#endif // FIRSTWINDOW_H

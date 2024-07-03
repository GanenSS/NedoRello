#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include "styles.h"

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

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

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void    setInterfaceStyle();
    void    slotClickedButtonRegistration();
    void    slotClickedButtonEnter();
    void    pressedButtonVision();
    void    releasedButtonVision();
    void    setErrorText(const QString &ErrorMessage);

    void    closeWindow();

    QString getLogin();
    QString getPassword();


signals:
    void signalClickedButtonRegistration();
    void signalClickedButtonEnter(const LoginCredentials& cred);

};

#endif // FIRSTWINDOW_H

#ifndef WINDOWCREATEDLIST_H
#define WINDOWCREATEDLIST_H

#include "styles.h"

#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include <QStyleOption>

namespace Ui {
class windowCreatedList;
}

class windowCreatedList : public QWidget
{
    Q_OBJECT

public:
    explicit windowCreatedList(QWidget *parent = nullptr);
    ~windowCreatedList();

private:
    Ui::windowCreatedList *ui;

protected:
    void closeEvent(QCloseEvent* event);
    void paintEvent(QPaintEvent *event);

public slots:
    void    setInterfaceStyle();
    QString getTitleList();
    void    slotClickedCreatedButton();
    void    closWindow();

signals:
    void signalClickedCreatedButton();
};

#endif // WINDOWCREATEDLIST_H

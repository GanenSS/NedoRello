#ifndef WINDOWCREATEDLIST_H
#define WINDOWCREATEDLIST_H

#include <QWidget>
#include <QMessageBox>

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

public slots:
    QString getTitleList();
    void    slotClickedCreatedButton();

signals:
    void signalClickedCreatedButton();
};

#endif // WINDOWCREATEDLIST_H

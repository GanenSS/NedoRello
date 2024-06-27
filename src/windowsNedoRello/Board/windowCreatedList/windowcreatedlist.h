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

protected:
    void closeEvent(QCloseEvent* event);

public slots:
    QString getTitleList();
    void    slotClickedCreatedButton();
    void    closWindow();

signals:
    void signalClickedCreatedButton();
};

#endif // WINDOWCREATEDLIST_H

#ifndef CREATEBOARD_H
#define CREATEBOARD_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class createBoard;
}

class createBoard : public QWidget
{
    Q_OBJECT

public:
    explicit createBoard(QWidget *parent = nullptr);
    ~createBoard();

private:
    Ui::createBoard *ui;

protected:
    void closeEvent(QCloseEvent* event);

public slots:
    QString getNameBoard();
    QString getDescriptionBoard();
    void slotClickedButtonCreate();
    void closeWindow();

signals:
    void signalClickedButtonCreate();
};

#endif // CREATEBOARD_H

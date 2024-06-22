#ifndef INPUTBOARD_H
#define INPUTBOARD_H

#include <QWidget>

namespace Ui {
class inputBoard;
}

class inputBoard : public QWidget
{
    Q_OBJECT

public:
    explicit inputBoard(QWidget *parent = nullptr);
    ~inputBoard();

private:
    Ui::inputBoard *ui;
};

#endif // INPUTBOARD_H

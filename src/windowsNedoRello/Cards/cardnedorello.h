#ifndef CARDNEDORELLO_H
#define CARDNEDORELLO_H

#include <QWidget>

namespace Ui {
class cardNedoRello;
}

class cardNedoRello : public QWidget
{
    Q_OBJECT

public:
    explicit cardNedoRello(QWidget *parent = nullptr);
    ~cardNedoRello();

private:
    Ui::cardNedoRello *ui;
};

#endif // CARDNEDORELLO_H

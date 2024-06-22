#ifndef LISTNEDORELLO_H
#define LISTNEDORELLO_H

#include <QWidget>
#include <QSpacerItem>

namespace Ui {
class listNedoRello;
}

class listNedoRello : public QWidget
{
    Q_OBJECT

public:
    explicit listNedoRello(QWidget *parent = nullptr);
    ~listNedoRello();

    int idBoard;
    int idList;
private:
    Ui::listNedoRello *ui;

    QSpacerItem* spacer         = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Expanding);
public slots:
    void createdList();
    void setTitleList(const QString& title);
    int  getIdBoard();
};

#endif // LISTNEDORELLO_H

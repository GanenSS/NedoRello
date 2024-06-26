#ifndef CARDNEDORELLO_H
#define CARDNEDORELLO_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class cardNedoRello;
}

class cardNedoRello : public QWidget
{
    Q_OBJECT

public:
    explicit cardNedoRello(QWidget *parent = nullptr);
    ~cardNedoRello();

    int idCard;
private:
    Ui::cardNedoRello *ui;

public slots:
    void setTitle(const QString& title);
    void setDescription (const QString &description);
    void setDeadLines(const QDateTime& deadLines);
    void setLogin(const QString &login);
};

#endif // CARDNEDORELLO_H

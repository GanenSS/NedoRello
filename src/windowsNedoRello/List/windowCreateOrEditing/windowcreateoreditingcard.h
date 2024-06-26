#ifndef WINDOWCREATEOREDITINGCARD_H
#define WINDOWCREATEOREDITINGCARD_H

#include <QWidget>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class windowCreateOrEditingCard;
}

class windowCreateOrEditingCard : public QWidget
{
    Q_OBJECT

public:
    explicit windowCreateOrEditingCard(QWidget *parent = nullptr);
    ~windowCreateOrEditingCard();

    struct infoCard
    {
        QString title;
        QString description;
        QDateTime deadLines;
    };

private:
    Ui::windowCreateOrEditingCard *ui;

public slots:
    void clickedButtonCreate();

signals:
    void signalclickedButtonCreate(const infoCard& info);
};

#endif // WINDOWCREATEOREDITINGCARD_H

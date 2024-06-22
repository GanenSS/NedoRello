#include "passdb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    passDB db;

    return a.exec();
}

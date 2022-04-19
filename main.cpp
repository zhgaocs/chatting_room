#include "client.h"
#include "server.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Server s;
    Client c1, c2;
    c1.show();
    c2.show();
    s.show();
    return a.exec();
}

#include "src/manager.h"
#include "src/login.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QFile f("qss/app.qss");
    f.open(QFile::ReadOnly);
    a.setStyleSheet(f.readAll());

    pp::manager::init();

    return a.exec();
}

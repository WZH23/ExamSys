#include "logindialog.h"
//#include "examdialog.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    auto res1 = w.exec();
    if(res1 == QDialog::Rejected)
        exit(0);
    return a.exec();
}

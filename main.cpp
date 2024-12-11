#include "logindialog.h"
#include "examdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    w.exec();
    return a.exec();
//    ExamDialog e;
//    e.show();

}

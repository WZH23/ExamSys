#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    //QT警告Slots named on_foo_bar are error prone
    //https://blog.csdn.net/weixin_43577616/article/details/120706263
private slots:
    void on_loginBtn_clicked();

    //void on_cancelBtn_clicked();

private:
    Ui::LoginDialog *ui;
};
#endif // LOGINDIALOG_H

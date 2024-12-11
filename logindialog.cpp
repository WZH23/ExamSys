#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QRegExp>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QIcon>
#include "examdialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->imageLabel->setScaledContents(true);//设置填充属性

    this->setWindowTitle("驾校科目一考试登录");

    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    this->resize(ui->imageLabel->width(), ui->imageLabel->height());//将窗口设置为图片的大小
    this->setFixedSize(this->geometry().size());//设置窗口不可修改大小

    QObject::connect(ui->cancelBtn,&QPushButton::clicked,[](){
        exit(0);
    });

    //qDebug() << QDir::currentPath() ;//打印当前路径
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

/*
qiniu666@126.com,2019good
niu_xueyuan666@163.com,niceday123
xue123_good@sina.com,beautifulgirl999
guangjia@mail.com,555sky
18229977755@qq.com,666
meiren@cn-meiya.com,888
meiyuan@0757info.com,100yearsold
*/

void LoginDialog::on_loginBtn_clicked()
{
    //QMessageBox::information(this,"提示","被调用",QMessageBox::Ok | QMessageBox::Cancel);
    QRegExp rx("^[A-Za-z0-9]+([_.][A-Za-z0-9]+)*@([A-Za-z0-9-]+.)+[A-Za-z]{2,6}$");
    auto res = rx.exactMatch(ui->accountEdit->text());
    if(!res)
    {
        QMessageBox::critical(this,"提示","匹配失败",QMessageBox::Cancel);
        ui->accountEdit->clear();//清空账号输入栏的内容
        ui->accountEdit->setFocus();//聚焦到输入框，用户不需要手动点击输入框
        return;
    }
    else
    {
        //QMessageBox::information(this,"提示","匹配成功",QMessageBox::Ok/* | QMessageBox::Cancel*/);
        QString fileName = "./account/account.txt";
        QString strAccount = ui->accountEdit->text();
        QString strPasswd = ui->passwdEdit->text();
        QString strLine;
        QStringList strList;
        qDebug() << fileName;

        QFile file(fileName);
        QTextStream stream(&file);
        auto res = file.open(QIODevice::ReadOnly | QIODevice::Text);
        if(res)
        {
            while(!stream.atEnd())
            {
                strLine = stream.readLine();
                strList = strLine.split(",");
                if(strAccount == strList[0])
                {
                    if(strPasswd == strList[1])
                    {
                        QMessageBox::information(this,"提示","欢迎登陆考试系统");
                        file.close();
                        this->close();
                        ExamDialog *e = new ExamDialog();
                        e->show();
                        return;
                    }
                    else
                    {
                        QMessageBox::information(this,"提示","账号或密码错误");
                        ui->passwdEdit->clear();
                        ui->passwdEdit->setFocus();
                        file.close();
                        return;
                    }
                }
            }
        }
        else
        {
            QMessageBox::information(this,"提示","账号数据打开失败");
            qDebug() << "res = " << res;
            return;
        }
    }
}


//void LoginDialog::on_cancelBtn_clicked()
//{
//    this->close();
//}


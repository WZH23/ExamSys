/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *imageLabel;
    QLineEdit *accountEdit;
    QLineEdit *passwdEdit;
    QPushButton *loginBtn;
    QPushButton *cancelBtn;
    QLabel *accountLabel;
    QLabel *passwdLabel;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("account/login.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LoginDialog->setWindowIcon(icon);
        imageLabel = new QLabel(LoginDialog);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(0, 0, 771, 581));
        imageLabel->setPixmap(QPixmap(QString::fromUtf8(":/account/account/login.png")));
        accountEdit = new QLineEdit(LoginDialog);
        accountEdit->setObjectName(QString::fromUtf8("accountEdit"));
        accountEdit->setGeometry(QRect(250, 200, 171, 24));
        passwdEdit = new QLineEdit(LoginDialog);
        passwdEdit->setObjectName(QString::fromUtf8("passwdEdit"));
        passwdEdit->setGeometry(QRect(250, 260, 171, 24));
        passwdEdit->setEchoMode(QLineEdit::Password);
        loginBtn = new QPushButton(LoginDialog);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(180, 350, 92, 29));
        cancelBtn = new QPushButton(LoginDialog);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(390, 350, 92, 29));
        accountLabel = new QLabel(LoginDialog);
        accountLabel->setObjectName(QString::fromUtf8("accountLabel"));
        accountLabel->setGeometry(QRect(200, 200, 31, 31));
        passwdLabel = new QLabel(LoginDialog);
        passwdLabel->setObjectName(QString::fromUtf8("passwdLabel"));
        passwdLabel->setGeometry(QRect(200, 250, 31, 31));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "LoginDialog", nullptr));
        imageLabel->setText(QString());
        loginBtn->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        cancelBtn->setText(QCoreApplication::translate("LoginDialog", "\345\217\226\346\266\210", nullptr));
        accountLabel->setText(QCoreApplication::translate("LoginDialog", "\350\264\246\345\217\267", nullptr));
        passwdLabel->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

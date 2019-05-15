/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QPushButton *Login_Button;
    QPushButton *Cancel_Button;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_Username;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_Password;
    QPushButton *testimonialButton;
    QPushButton *contactButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        textBrowser = new QTextBrowser(Login);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(80, 49, 231, 51));
        groupBox = new QGroupBox(Login);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 100, 291, 131));
        Login_Button = new QPushButton(groupBox);
        Login_Button->setObjectName(QString::fromUtf8("Login_Button"));
        Login_Button->setGeometry(QRect(40, 90, 93, 28));
        Cancel_Button = new QPushButton(groupBox);
        Cancel_Button->setObjectName(QString::fromUtf8("Cancel_Button"));
        Cancel_Button->setGeometry(QRect(160, 90, 93, 28));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 211, 57));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_Username = new QLineEdit(layoutWidget);
        lineEdit_Username->setObjectName(QString::fromUtf8("lineEdit_Username"));

        horizontalLayout_2->addWidget(lineEdit_Username);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));

        horizontalLayout->addWidget(lineEdit_Password);


        verticalLayout->addLayout(horizontalLayout);

        testimonialButton = new QPushButton(Login);
        testimonialButton->setObjectName(QString::fromUtf8("testimonialButton"));
        testimonialButton->setGeometry(QRect(300, 260, 93, 28));
        contactButton = new QPushButton(Login);
        contactButton->setObjectName(QString::fromUtf8("contactButton"));
        contactButton->setGeometry(QRect(10, 260, 93, 28));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", nullptr));
        textBrowser->setHtml(QApplication::translate("Login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600; color:#000000;\">SHAPES.IO</span></p></body></html>", nullptr));
        groupBox->setTitle(QString());
        Login_Button->setText(QApplication::translate("Login", "Login", nullptr));
        Cancel_Button->setText(QApplication::translate("Login", "Cancel", nullptr));
        label->setText(QApplication::translate("Login", "Username", nullptr));
        label_2->setText(QApplication::translate("Login", "Password", nullptr));
        testimonialButton->setText(QApplication::translate("Login", "Testimonial", nullptr));
        contactButton->setText(QApplication::translate("Login", "Contact Us", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

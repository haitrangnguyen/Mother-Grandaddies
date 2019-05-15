/********************************************************************************
** Form generated from reading UI file 'contactus.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTUS_H
#define UI_CONTACTUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactUs
{
public:
    QLineEdit *emailBox;
    QLabel *emailLabel;
    QLineEdit *messageBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendButton;
    QPushButton *discardButton;
    QLabel *logo;
    QLabel *groupName;

    void setupUi(QDialog *ContactUs)
    {
        if (ContactUs->objectName().isEmpty())
            ContactUs->setObjectName(QString::fromUtf8("ContactUs"));
        ContactUs->resize(593, 339);
        emailBox = new QLineEdit(ContactUs);
        emailBox->setObjectName(QString::fromUtf8("emailBox"));
        emailBox->setGeometry(QRect(50, 12, 331, 22));
        emailLabel = new QLabel(ContactUs);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setGeometry(QRect(10, 13, 55, 16));
        messageBox = new QLineEdit(ContactUs);
        messageBox->setObjectName(QString::fromUtf8("messageBox"));
        messageBox->setGeometry(QRect(10, 50, 371, 231));
        QFont font;
        font.setPointSize(12);
        messageBox->setFont(font);
        messageBox->setMaxLength(32769);
        messageBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        layoutWidget = new QWidget(ContactUs);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(389, 300, 195, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendButton = new QPushButton(layoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);

        discardButton = new QPushButton(layoutWidget);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));

        horizontalLayout->addWidget(discardButton);

        logo = new QLabel(ContactUs);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(387, 69, 201, 191));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy);
        logo->setPixmap(QPixmap(QString::fromUtf8("Granddaddies_Logo.png")));
        logo->setScaledContents(true);
        groupName = new QLabel(ContactUs);
        groupName->setObjectName(QString::fromUtf8("groupName"));
        groupName->setGeometry(QRect(390, 40, 231, 21));
        QFont font1;
        font1.setPointSize(14);
        groupName->setFont(font1);

        retranslateUi(ContactUs);

        QMetaObject::connectSlotsByName(ContactUs);
    } // setupUi

    void retranslateUi(QDialog *ContactUs)
    {
        ContactUs->setWindowTitle(QApplication::translate("ContactUs", "Dialog", nullptr));
        emailLabel->setText(QApplication::translate("ContactUs", "Email:", nullptr));
        messageBox->setText(QString());
        sendButton->setText(QApplication::translate("ContactUs", "Send", nullptr));
        discardButton->setText(QApplication::translate("ContactUs", "Close", nullptr));
        logo->setText(QString());
        groupName->setText(QApplication::translate("ContactUs", "The Granddaddies", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactUs: public Ui_ContactUs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTUS_H

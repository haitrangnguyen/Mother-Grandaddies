/********************************************************************************
** Form generated from reading UI file 'testimonial.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTIMONIAL_H
#define UI_TESTIMONIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Testimonial
{
public:
    QLabel *label;
    QLineEdit *testimonialBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendButton;
    QPushButton *discardButton;

    void setupUi(QDialog *Testimonial)
    {
        if (Testimonial->objectName().isEmpty())
            Testimonial->setObjectName(QString::fromUtf8("Testimonial"));
        Testimonial->resize(669, 501);
        label = new QLabel(Testimonial);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 5, 601, 30));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        testimonialBox = new QLineEdit(Testimonial);
        testimonialBox->setObjectName(QString::fromUtf8("testimonialBox"));
        testimonialBox->setGeometry(QRect(20, 41, 621, 401));
        QFont font1;
        font1.setPointSize(12);
        testimonialBox->setFont(font1);
        testimonialBox->setMaxLength(32769);
        testimonialBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        widget = new QWidget(Testimonial);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(434, 455, 195, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);

        discardButton = new QPushButton(widget);
        discardButton->setObjectName(QString::fromUtf8("discardButton"));

        horizontalLayout->addWidget(discardButton);


        retranslateUi(Testimonial);

        QMetaObject::connectSlotsByName(Testimonial);
    } // setupUi

    void retranslateUi(QDialog *Testimonial)
    {
        Testimonial->setWindowTitle(QApplication::translate("Testimonial", "Dialog", nullptr));
        label->setText(QApplication::translate("Testimonial", "Testimonial: tell us how you like our program.", nullptr));
        testimonialBox->setText(QString());
        sendButton->setText(QApplication::translate("Testimonial", "Send", nullptr));
        discardButton->setText(QApplication::translate("Testimonial", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Testimonial: public Ui_Testimonial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTIMONIAL_H

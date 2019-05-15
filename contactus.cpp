#include "contactus.h"
#include "ui_contactus.h"
#include <fstream>
#include <iostream>

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
}

ContactUs::~ContactUs()
{
    delete ui;
}

void ContactUs::on_sendButton_clicked()
 {
    std::ofstream email;
    email.open ("email.txt");
    email << ui->emailBox->text().toStdString();
    email.close();

    std::ofstream contact;
    contact.open ("contact_us.txt");
    contact << ui->messageBox->text().toStdString();
    contact.close();
    close();
}

void ContactUs::on_discardButton_clicked()
{
    close();
}

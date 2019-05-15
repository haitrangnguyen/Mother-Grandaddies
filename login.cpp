#include "login.h"
#include "ui_login.h"
#include "window.h"
#include "testimonial.h"
#include "contactus.h"
#include <string>
#include <QMessageBox>

const QString ADMIN = "admin1234";
const QString ADMIN_PASS = "password1234";

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_Login_Button_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    Window *window(nullptr);

    if(username == ADMIN && password == ADMIN_PASS)
    {
        admin = true;
        hide();
        if(window == nullptr)
        {
            window = new Window();
            window->show();
        }
    } else {
        QMessageBox::warning(this, "Login", "Username or password was incorrect.");
    }
}

void Login::on_Cancel_Button_clicked()
{
    admin = false;
    hide();
    Window *window(nullptr);
    if(window == nullptr)
    {
        window = new Window();
        window->show();
    }
}

void Login::on_lineEdit_Password_returnPressed()
{
    on_Login_Button_clicked();
}

void Login::on_testimonialButton_clicked()
{
    Testimonial *testimonial = new Testimonial();
    testimonial->show();
}

void Login::on_contactButton_clicked()
{
    ContactUs *contactUs = new ContactUs();
    contactUs->show();
}

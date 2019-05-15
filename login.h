#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_Login_Button_clicked();
    void on_Cancel_Button_clicked();
    void on_lineEdit_Password_returnPressed();

    void on_testimonialButton_clicked();

    void on_contactButton_clicked();

private:
    Ui::Login *ui{nullptr};
    bool admin;
};

#endif // LOGIN_H

#ifndef TESTIMONIAL_H
#define TESTIMONIAL_H

#include <QDialog>

namespace Ui {
class Testimonial;
}

class Testimonial : public QDialog
{
    Q_OBJECT

public:
    explicit Testimonial(QWidget *parent = nullptr);
    ~Testimonial();

private slots:
    void on_sendButton_clicked();

    void on_discardButton_clicked();

    void on_testimonialBox_returnPressed();

private:
    Ui::Testimonial *ui;
};

#endif // TESTIMONIAL_H

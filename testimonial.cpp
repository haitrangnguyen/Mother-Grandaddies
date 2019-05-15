#include "testimonial.h"
#include "ui_testimonial.h"
#include <fstream>
#include <iostream>

Testimonial::Testimonial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testimonial)
{
    ui->setupUi(this);
}

Testimonial::~Testimonial()
{
    delete ui;
}

void Testimonial::on_sendButton_clicked()
{
    std::ofstream myFile;
    myFile.open ("testimonial.txt");
    myFile << ui->testimonialBox->text().toStdString();
    myFile.close();
    close();
}

void Testimonial::on_discardButton_clicked()
{
    close();
}

void Testimonial::on_testimonialBox_returnPressed()
{
    on_sendButton_clicked();
}

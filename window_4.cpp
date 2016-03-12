#include "window_4.h"

window_4::window_4()
{

    //Label
    label_1 = new QLabel;
    label_1->setText(tr("Akku 1. Spannung:"));
    label_2 = new QLabel;
    label_2->setText(tr("Akku 2. Spannung:"));

    label_value1 = new QLabel;
    label_value2 = new QLabel;

    //Slider
    slider1 = new QSlider(Qt::Horizontal);
    slider1->setTickPosition(QSlider::TicksBothSides);
    slider1->setTickInterval(10);
    slider1->setSingleStep(1);

    slider2 = new QSlider(Qt::Horizontal);
    slider2->setTickPosition(QSlider::TicksBothSides);
    slider2->setTickInterval(10);
    slider2->setSingleStep(1);

    connect(slider1,SIGNAL(valueChanged(int)),this,SLOT(slot_value1()));
    connect(slider2,SIGNAL(valueChanged(int)),this,SLOT(slot_value2()));

    //Layout
    QGridLayout  *layout_grid = new QGridLayout;
    layout_grid->addWidget(label_1,0,0);
    layout_grid->addWidget(label_value1,0,1);
    layout_grid->addWidget(slider1,0,2);
    layout_grid->addWidget(label_2,2,0);
    layout_grid->addWidget(label_value2,2,1);
    layout_grid->addWidget(slider2,2,2);
    setLayout(layout_grid);


}

void window_4::slot_value1()
{
    double d1 = slider1->value();
    char ch1[10];
    sprintf(ch1,"%03.1fV",d1);
    QString string1 = QString(QLatin1String(ch1));
    label_value1->setText(string1);
}

void window_4::slot_value2()
{
    double d2 = slider2->value();
    char ch2[10];
    sprintf(ch2,"%03.1fV",d2);
    QString string2 = QString(QLatin1String(ch2));
    label_value2->setText(string2);
}

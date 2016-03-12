#include "window_3.h"


window_3::window_3()
{

    QPixmap pix_5;
    pix_5.load(":/BMS_5.png");
    //Create label for background
    label = new QLabel(this);
    label->setPixmap(pix_5);
    label_I = new QLabel(this);
    label_I->setText("I:");
    label_V = new QLabel(this);
    label_V->setText("V:");
    label_T = new QLabel(this);
    label_T->setText("Temperatur:");
    label_SOC = new QLabel(this);
    label_SOC->setText("SOC:");


    //Slider
    slider = new QSlider(Qt::Vertical,this);
    slider->setTickPosition(QSlider::TicksBothSides);
    slider->setTickInterval(10);
    slider->setSingleStep(1);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slider_value()));

    QVBoxLayout  *layout_vertical = new QVBoxLayout();
    layout_vertical->addWidget(label_SOC);
    layout_vertical->addWidget(label_V);
    layout_vertical->addWidget(label_I);
    layout_vertical->addWidget(label_T);

    QHBoxLayout *layout_horizontal = new QHBoxLayout(this);
    layout_horizontal->addLayout(layout_vertical);
    layout_horizontal->addWidget(label);
    layout_horizontal->addWidget(slider);
    setLayout(layout_horizontal);

}


void window_3::slider_value(){

    //Pixmap load
    QPixmap pix_0,pix_1,pix_2,pix_3,pix_4,pix_5;
    pix_0.load(":/BMS_0.png");
    pix_1.load(":/BMS_1.png");
    pix_2.load(":/BMS_2.png");
    pix_3.load(":/BMS_3.png");
    pix_4.load(":/BMS_4.png");
    pix_5.load(":/BMS_5.png");

    if(slider->value() >=0 && slider->value() <=10 )
    {
        label->setPixmap(pix_0);
    }

    if(slider->value() >10 && slider->value() <=20 )
    {
        label->setPixmap(pix_1);
    }

    if(slider->value() >20 && slider->value() <=40 )
    {
        label->setPixmap(pix_2);
    }

    if(slider->value() >40 && slider->value() <=60 )
    {
        label->setPixmap(pix_3);
    }

    if(slider->value() >60 && slider->value() <=80 )
    {
        label->setPixmap(pix_4);
    }

    if(slider->value() >80 && slider->value() <=100 )
    {
        label->setPixmap(pix_5);
    }

    //SOC String
    double s = slider->value();
    char ch1[10];
    sprintf(ch1,"%03.0f",s);
    QString string_SOC = QString(QLatin1String(ch1));
    label_SOC->setText("SOC:"+string_SOC+"%");

    //Temperatur String
    double t = slider->value()/2.2;
    char ch2[10];
    sprintf(ch2,"%03.1f",t);
    QString string_T = QString(QLatin1String(ch2));
    label_T->setText("Temperatur:"+string_T+"℃");

    //Voltage String
    double v = slider->value()*3.8;
    char ch3[10];
    sprintf(ch3,"%03.1f",v);
    QString string_V = QString(QLatin1String(ch3));
    label_V->setText("Spannung:"+string_V+"V");

    //Strom String
    double i = slider->value()/5.1;
    char ch4[10];
    sprintf(ch4,"%03.1f",i);
    QString string_I = QString(QLatin1String(ch4));
    label_I->setText("Strom:"+string_I+"A");
}


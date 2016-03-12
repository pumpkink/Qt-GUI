#include "window_2.h"
#include "qpainter.h"
//#include <QDebug>


window_2::window_2()
{
    //Background Color
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background,Qt::gray);
    this->setPalette(palette);
    //layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    //Pixmap load
    QPixmap pix;
    QImage background;
    background.load(":/background.png");
    pix.load(":/background.png");
    label =new QLabel(this);
    label->setPixmap(pix);
    label->setAlignment(Qt::AlignCenter);

    //label_2 =new QLabel(tr("000km/h"),this);
    //label_2->setAlignment(Qt::AlignCenter);

    //LCD
    lcd_speed = new QLCDNumber(this);
    lcd_speed->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    lcd_speed->setSegmentStyle(QLCDNumber::Flat);
    QPalette lcdpad = lcd_speed->palette();
    lcdpad.setColor(QPalette::Normal,QPalette::WindowText,Qt::blue);
    lcd_speed->setPalette(lcdpad);
    lcd_speed->setStyleSheet("background-color:yellow");
    lcd_speed->setDigitCount(4);

    //Slider
    slider = new QSlider(Qt::Horizontal,this);
    slider->setTickPosition(QSlider::TicksBothSides);
    slider->setTickInterval(10);
    slider->setSingleStep(1);


    layout->addWidget(label);
    layout->addWidget(lcd_speed);
    layout->addWidget(slider);




    //Index
    a=0;
    range_min=0;
    range_max=120;
    start_range=55;
    angle_min=-130;
    angle_max=130;

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slider_value()));
}

void window_2::paintEvent(QPaintEvent *)
{

}


void window_2::slider_value(){

    //Draw
    QImage background;
    background.load(":/background.png");
    label->setGeometry(0,0,background.height(),background.width());
    QPixmap pix;
    pix = pix.fromImage(background);
    QPainter painter(&pix);//create a pen
    QPixmap pix3;
    pix3.load(":/needle.png");

    painter.translate(105,99);//(105,99) als neue Urspannung

    painter.rotate(start_range);

    if(slider->value() !=125){
        a =1.2*slider->value();
        current_range =(double)a*(angle_max-angle_min)/(range_max-range_min);
        painter.rotate(current_range);

    }

    painter.drawPixmap(0,0,pix3);
    painter.translate(-105,-99);//back to (0,0)



    label->setPixmap(pix);
    //Test
    //qDebug()<<":"+QString::number(a) +"range = " +QString::number(current_range);
    double d = a;

    char ch[10];
    sprintf(ch,"%03.0fkm/h",d);
    //QString string = QString(QLatin1String(ch));
    lcd_speed->display(d);
    //label_2->setText(string);
    //qDebug()<<string;
}



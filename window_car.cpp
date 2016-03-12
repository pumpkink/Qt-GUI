#include "window_car.h"
#include <QString>
#include <QTime>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>



window_car::window_car()
{

    QPixmap pix_car;
    QImage background;
    background.load(":/car.png");
    pix_car.load(":/car.png");
    label_car = new QLabel();
    label_car->setPixmap(pix_car);
    /**********************QPushButton****************************
    *Hier sind Einstellung von Pushbutton.                       *
    *                                                       *
    *********************************************************/
    //button_brake = new QPushButton("Brake");
    //button_brake->setFont(QFont("Times",10,QFont::Bold));

    //connect(button_brake,SIGNAL(pressed()),this,SLOT(on_pushButton_pressed()));
    //connect(button_brake,SIGNAL(released()),this,SLOT(on_pushButton_released()));


    /**********************QLabel****************************
    *Hier sind Einstellung von label.                       *
    *                                                       *
    *********************************************************/

    //Current Time Label
    time_label = new QLabel();
    time_label->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    time_label->setAlignment(Qt::AlignCenter);
    time_label->setFont(QFont("System",14,QFont::Bold));


    //Stopphur Label
    stoppuhr_label = new QLabel();
    stoppuhr_label->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    stoppuhr_label->setAlignment(Qt::AlignCenter);
    stoppuhr_label->setFont(QFont("System",14,QFont::Bold));
    stoppuhr_label->setText(tr("Lionsracing Team 2015\nGUI v1.0"));


    label_VLR = new QLabel();
    label_VLR->setAlignment(Qt::AlignCenter);
    label_VLR->setFont(QFont("System",10,QFont::Bold));
    label_VLR->setText("VL Raddrehzahl");

    label_HLR = new QLabel();
    label_HLR->setAlignment(Qt::AlignCenter);
    label_HLR->setFont(QFont("System",10,QFont::Bold));
    label_HLR->setText("HL Raddrehzahl");

    label_VRR = new QLabel();
    label_VRR->setAlignment(Qt::AlignCenter);
    label_VRR->setFont(QFont("System",10,QFont::Bold));
    label_VRR->setText("VR Raddrehzahl");

    label_HRR = new QLabel();
    label_HRR->setAlignment(Qt::AlignCenter);
    label_HRR->setFont(QFont("System",10,QFont::Bold));
    label_HRR->setText("HR Raddrehzahl");


    /**********************QLCDNumber****************************
    *Hier sind Einstellung von label.                           *
    *                                                           *
    *************************************************************/
    //add LCD
    //lcd_zeit = new QLCDNumber();
    //lcd_stoppuhr = new QLCDNumber();
    lcd_VLR = new QLCDNumber();
    lcd_VRR = new QLCDNumber();
    lcd_HLR = new QLCDNumber();
    lcd_HRR = new QLCDNumber();


    /**********************Slider*****************************
    *Hier sind Einstellung von Sliders, es gibt entsprechende*
    *API Funktion als seine SLOTS, darin kann man die Value  *
    *einstellen .                                            *
    *********************************************************/

    //Vor Links als API(Drehzahl,Federweg)
    slider_VL = new QSlider(Qt::Horizontal);
    slider_VL->setTickPosition(QSlider::TicksBothSides);
    slider_VL->setTickInterval(10);
    slider_VL->setSingleStep(1);

    //Vor Rechts als API(Drehzahl,Federweg)
    slider_VR = new QSlider(Qt::Horizontal);
    slider_VR->setTickPosition(QSlider::TicksBothSides);
    slider_VR->setTickInterval(10);
    slider_VR->setSingleStep(1);

    //Hinter Links als API(Drehzahl,Federweg)
    slider_HL = new QSlider(Qt::Horizontal);
    slider_HL->setTickPosition(QSlider::TicksBothSides);
    slider_HL->setTickInterval(10);
    slider_HL->setSingleStep(1);

    //Hinter Rechts als API(Drehzahl,Federweg)
    slider_HR = new QSlider(Qt::Horizontal);
    slider_HR->setTickPosition(QSlider::TicksBothSides);
    slider_HR->setTickInterval(10);
    slider_HR->setSingleStep(1);

    //Lenkwinkel als API(slot_winkel())
    slider_winkel = new QSlider(Qt::Horizontal);
    slider_winkel->setTickPosition(QSlider::TicksBothSides);
    slider_winkel->setTickInterval(10);
    slider_winkel->setSingleStep(1);

    /**********************Slider-API*************************
    *Verbindung zwischen slider and API-Funktion,später kann *
    *man in dieser Funktions die Data von CAN Bus lesen      *
    *                                                        *
    *********************************************************/
    connect(slider_VL,SIGNAL(valueChanged(int)),this,SLOT(slot_paint()));
    connect(slider_VR,SIGNAL(valueChanged(int)),this,SLOT(slot_paint()));
    connect(slider_HL,SIGNAL(valueChanged(int)),this,SLOT(slot_paint()));
    connect(slider_HR,SIGNAL(valueChanged(int)),this,SLOT(slot_paint()));
    connect(slider_winkel,SIGNAL(valueChanged(int)),this,SLOT(slot_paint()));
    //alle slider controled by slider_winkel(for Test)
    connect(slider_winkel,SIGNAL(valueChanged(int)),slider_VL,SLOT(setValue(int)));
    connect(slider_winkel,SIGNAL(valueChanged(int)),slider_VR,SLOT(setValue(int)));
    connect(slider_winkel,SIGNAL(valueChanged(int)),slider_HL,SLOT(setValue(int)));
    connect(slider_winkel,SIGNAL(valueChanged(int)),slider_HR,SLOT(setValue(int)));
    connect(slider_VL,SIGNAL(valueChanged(int)),lcd_VLR,SLOT(display(int)));
    connect(slider_VR,SIGNAL(valueChanged(int)),lcd_VRR,SLOT(display(int)));
    connect(slider_HL,SIGNAL(valueChanged(int)),lcd_HLR,SLOT(display(int)));
    connect(slider_HR,SIGNAL(valueChanged(int)),lcd_HRR,SLOT(display(int)));

    /************************Textedit Window****************************
    *Hier sind Eigenschaft von Textedit Window                         *
    *                                                                  *
    *******************************************************************/





    /**********************QLayout********************************
    *Hier sind Einstellung von Layout.                           *
    *Es gibt 3 Layout, Links, Rechts,und Haupt                   *
    *In Links und Rechts gibt es auch Layouts                    *
    *************************************************************/
    //Left layout
    layout_l1 = new QVBoxLayout;
    layout_l1->addWidget(time_label);
    layout_l1->addWidget(slider_winkel);

    layout_l2 = new QVBoxLayout;
    layout_l2->addWidget(label_VLR);
    layout_l2->addWidget(lcd_VLR);
    layout_l2->addWidget(slider_VL);

    layout_l3 = new QVBoxLayout;
    layout_l3->addWidget(label_HLR);
    layout_l3->addWidget(lcd_HLR);
    layout_l3->addWidget(slider_HL);


    layout_verticalleft = new QVBoxLayout();
    layout_verticalleft->addLayout(layout_l1);
    layout_verticalleft->addLayout(layout_l2);
    layout_verticalleft->addLayout(layout_l3);

    //Right layout
    layout_r1 = new QVBoxLayout();
    layout_r1->addWidget(stoppuhr_label);
    layout_r1->addWidget(button_brake);

    layout_r2 = new QVBoxLayout();
    layout_r2->addWidget(label_VRR);
    layout_r2->addWidget(lcd_VRR);
    layout_r2->addWidget(slider_VR);

    layout_r3 = new QVBoxLayout();
    layout_r3->addWidget(label_HRR);
    layout_r3->addWidget(lcd_HRR);
    layout_r3->addWidget(slider_HR);

    layout_verticalright = new QVBoxLayout();
    layout_verticalright->addLayout(layout_r1);
    layout_verticalright->addLayout(layout_r2);
    layout_verticalright->addLayout(layout_r3);


    //Main layout
    layout_horizontal = new QHBoxLayout(this);
    layout_horizontal->addLayout(layout_verticalleft);
    layout_horizontal->addWidget(label_car);
    layout_horizontal->addLayout(layout_verticalright);
    setLayout(layout_horizontal);

    /**********************Initial Value********************************
    *Hier sind Initialisierung von Value                               *
    *                                                                  *
    *******************************************************************/
    //init value for lenkwinkel
    a=0;
    range_min=0;
    range_max=100;
    start_range=110;
    angle_min=-60;
    angle_max=60;


    /************************LCD Update*********************************
    *Hier sind Update von LCDs and set the Flag                        *
    *                                                                  *
    *******************************************************************/
    //update flag
    this->isflush = false;

    //lcd_zeit->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    //lcd_zeit->setDigitCount(16);


    //lcd_stoppuhr->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    //lcd_stoppuhr->setDigitCount(16);


    lcd_VLR->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    lcd_VLR->setDigitCount(4);


    lcd_VRR->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    lcd_VRR->setDigitCount(4);


    lcd_HLR->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    lcd_HLR->setDigitCount(4);


    lcd_HRR->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    lcd_HRR->setDigitCount(4);

    this->startTimer(500);//0.5s
}

//定时刷新
void window_car::timerEvent(QTimerEvent *)
{
      //current time
      isflush = !isflush;
      QString timeString = QTime::currentTime().toString("hh:mm");
      QDate date = QDate::currentDate();
      QString dateString;
      dateString = date.toString("yyyy-MM-dd");
      QString displayString = timeString + " " + dateString;

      if(!isflush){
        displayString[2] = ' ';
      }
      time_label->setText(displayString);


}

void window_car:: paintEvent(QPaintEvent*)
{

}

//Button Status
/*void window_car::on_pushButton_pressed(){

    light_status = true ;

    QImage background;
    background.load(":/car.png");
    QPixmap pix_car;
    pix_car = pix_car.fromImage(background);
    QPainter painter1(&pix_car);//create a pen on this Background
    //Draw Brakelicht
    QPoint center(150,550);
    //if Brake Button clicked
    if(light_status){
         painter1.setRenderHint(QPainter::Antialiasing,true);//反走样
         painter1.setPen(Qt::black);
         painter1.setBrush(Qt::black);
         painter1.drawRect(100,525,200,100);
         //Draw x_Axis Licht
         for(int i = 0;i < 4;i++){

         //辐射渐变center (cx, cy), radius and focal point (fx, fy).
         QRadialGradient radialGradient(center.rx(),center.ry(),10,center.rx(),center.ry());
         radialGradient.setColorAt(0.1,Qt::white);
         radialGradient.setColorAt(0.6,Qt::red);
         radialGradient.setColorAt(1,Qt::darkRed);

         painter1.setBrush(QBrush(radialGradient));//画刷
         painter1.drawEllipse(center,10,10);//画圆

         center.rx()+=50;

         if(i == 3){
             center.rx() = 150;
             center.ry() = 590;
             for(int j = 0; j < 4;j++){

                 QRadialGradient radialGradient(center.rx(),center.ry(),10,center.rx(),center.ry());
                 radialGradient.setColorAt(0.1,Qt::white);
                 radialGradient.setColorAt(0.6,Qt::red);
                 radialGradient.setColorAt(1,Qt::darkRed);

                 painter1.setBrush(QBrush(radialGradient));//画刷
                 painter1.drawEllipse(center,10,10);//画圆

                 center.rx()+=50;
             }
         }
       }
    }update();

}*/

/*void window_car::on_pushButton_released(){

    light_status = false;

    QImage background;
    background.load(":/car.png");
    QPixmap pix_car;
    pix_car = pix_car.fromImage(background);
    QPainter painter1(&pix_car);//create a pen on this Background
    //Draw Brakelicht
    QPoint center(150,550);
    if(light_status == false){
         painter1.setRenderHint(QPainter::Antialiasing,true);//反走样
         painter1.setPen(Qt::black);
         painter1.setBrush(Qt::black);
         painter1.drawRect(100,525,300,200);

         for(int i = 0;i < 4;i++){

         //辐射渐变center (cx, cy), radius and focal point (fx, fy).
         QRadialGradient radialGradient(center.rx(),center.ry(),10,center.rx(),center.ry());
         radialGradient.setColorAt(0.1,Qt::lightGray);
         radialGradient.setColorAt(0.6,Qt::gray);
         radialGradient.setColorAt(1,Qt::darkGray);

         painter1.setBrush(QBrush(radialGradient));//画刷
         painter1.drawEllipse(center,10,10);//画圆

         center.rx()+=50;

         if(i == 3){
             center.rx() = 150;
             center.ry() = 590;
             for(int j = 0; j < 4;j++){

                 QRadialGradient radialGradient(center.rx(),center.ry(),10,center.rx(),center.ry());
                 radialGradient.setColorAt(0.1,Qt::lightGray);
                 radialGradient.setColorAt(0.6,Qt::gray);
                 radialGradient.setColorAt(1,Qt::darkGray);

                 painter1.setBrush(QBrush(radialGradient));//画刷
                 painter1.drawEllipse(center,10,10);//画圆

                 center.rx()+=50;
             }
         }

        }
     }update();

}*/


void window_car::slot_paint()
{
    QImage background;
    background.load(":/car.png");
    QPixmap pix_car;
    pix_car = pix_car.fromImage(background);
    QPixmap pix_needle;
    pix_needle.load(":/needle_car.png");
    QPainter painter(&pix_car);//create a pen on this Background

    //show Angle in Text
    double d = 2*a - 140;
    char ch[10];
    sprintf(ch,"%03.1f°",d);
    QString string = QString(ch);
    painter.drawText(175,130,string);





    //Draw FWS_1
    int y_1 = slider_VL->value()*index1+y_offset;
    int height_1 =slider_VL->value()*index2;

    if(slider_VL->value()!=125)
    {
        painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter.setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linearGradient(30,200,60,300);
        linearGradient.setColorAt(1.0, Qt::green);
        linearGradient.setColorAt(0.5, Qt::yellow);
        linearGradient.setColorAt(0.3, Qt::red);
        painter.setBrush(QBrush(linearGradient));
        painter.drawRect(30,y_1,30,height_1);
        //Draw Text for Federweg Wert
        double fws1 =100-height_1;
        char ch_fws1[10];
        sprintf(ch_fws1,"%03.0fcm",fws1);
        QString string_fws1 = QString(ch_fws1);
        painter.drawText(25,320,string_fws1);
    }

    //Draw FWS_2
    int y_2 = slider_HL->value()*index1+y_offset+250;
    int height_2 =slider_HL->value()*index2;

    if(slider_HL->value()!=125)
    {
        painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter.setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linearGradient(30,450,60,550);
        linearGradient.setColorAt(1.0, Qt::red);
        linearGradient.setColorAt(0.5, Qt::yellow);
        linearGradient.setColorAt(0.3, Qt::green);
        painter.setBrush(QBrush(linearGradient));
        painter.drawRect(30,y_2,30,height_2);
        //Draw Text for Federweg Wert
        double fws2 =100-height_2;
        char ch_fws2[10];
        sprintf(ch_fws2,"%03.0fcm",fws2);
        QString string_fws2 = QString(ch_fws2);
        painter.drawText(25,570,string_fws2);
    }

    //Draw FWS_3
    int y_3 = slider_VR->value()*index1+y_offset;
    int height_3 =slider_VR->value()*index2;

    if(slider_VR->value()!=125)
    {
        painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter.setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linearGradient(280,200,310,300);
        linearGradient.setColorAt(1.0, Qt::red);
        linearGradient.setColorAt(0.5, Qt::yellow);
        linearGradient.setColorAt(0.3, Qt::green);
        painter.setBrush(QBrush(linearGradient));
        painter.drawRect(280,y_3,30,height_3);
        //Draw Text for Federweg Wert
        double fws3 = height_3;
        char ch_fws3[10];
        sprintf(ch_fws3,"%03.0fcm",fws3);
        QString string_fws3 = QString(ch_fws3);
        painter.drawText(280,320,string_fws3);
    }

    //Draw FWS_4
    int y_4 = slider_HR->value()*index1+y_offset+250;
    int height_4 =slider_HR->value()*index2;

    if(slider_HR->value()!=125)
    {
        painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter.setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linearGradient(280,450,310,550);
        linearGradient.setColorAt(1.0, Qt::red);
        linearGradient.setColorAt(0.5, Qt::yellow);
        linearGradient.setColorAt(0.3, Qt::green);
        painter.setBrush(QBrush(linearGradient));
        painter.drawRect(280,y_4,30,height_4);
        //Draw Text for Federweg Wert
        double fws4 = height_4;
        char ch_fws4[10];
        sprintf(ch_fws4,"%03.0fcm",fws4);
        QString string_fws4 = QString(ch_fws4);
        painter.drawText(280,570,string_fws4);
    }


    //Draw Gaspedal
    int y_gas = slider_winkel->value()*index1+250;
    int height_gas =slider_winkel->value();

    if(slider_winkel->value()!=125)
    {
        painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter.setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linearGradient(100,150,155,200);
        linearGradient.setColorAt(1.0, Qt::green);
        linearGradient.setColorAt(0.5, Qt::yellow);
        linearGradient.setColorAt(0.3, Qt::red);
        painter.setBrush(QBrush(linearGradient));
        painter.drawRect(100,y_gas,15,height_gas);
        //Draw Text for Gaspedal Wert
        double gaspedal =height_gas;
        char ch_gas[10];
        sprintf(ch_gas,"%03.0f%%",gaspedal);
        QString string_gas = QString(ch_gas);
        painter.drawText(35,150,"GAS:"+string_gas);
    }

    //Draw Brakepedal
    int y_brake = slider_winkel->value()*index1+250;
    int height_brake =slider_winkel->value();

    if(slider_winkel->value()!=125)
    {
        painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
        painter.setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linearGradient(215,150,230,200);
        linearGradient.setColorAt(1.0, Qt::green);
        linearGradient.setColorAt(0.5, Qt::yellow);
        linearGradient.setColorAt(0.3, Qt::red);
        painter.setBrush(QBrush(linearGradient));
        painter.drawRect(215,y_brake,15,height_brake);
        //Draw Text for Brakepedal Wert
        double brakepedal =height_brake;
        char ch_brake[10];
        sprintf(ch_brake,"%03.0f%%",brakepedal);
        QString string_brake = QString(ch_brake);
        painter.drawText(235,150,"Brake:"+string_brake);
    }
    //update();




    //Draw Lenkwinkel
    painter.translate(175,125);//(160,70) als neue Urspannung
    painter.rotate(start_range);
    if(slider_winkel->value() !=125){
        a =1.2*slider_winkel->value();
        current_range =(double)a*(angle_max-angle_min)/(range_max-range_min);
        painter.rotate(current_range);
    }
    painter.drawPixmap(0,0,pix_needle);
    painter.translate(-175,-125);//back to (0,0)

    label_car->setPixmap(pix_car);


   update();

}

//void window_car::slot_VL()
//{
//}



#include "window_stopwatch.h"
#include <QTimer>


window_stopwatch::window_stopwatch()
{
    counttemp = 0;
    secondtemp = 0;
    minutetemp = 0;
    hourtemp = 0;
    msTimer = new QTimer(this);
    lcd_stoppuhr = new QLCDNumber(this);
    lcd_stoppuhr->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
    lcd_stoppuhr->setDigitCount(11);

    //Push Button
    button_start = new QPushButton(tr("START"),this);
    button_stop = new QPushButton(tr("STOP"),this);
    button_reset = new QPushButton(tr("RESET"),this);

    connect(msTimer,SIGNAL(timeout()),this,SLOT(TimeSlot()));

    connect(button_start,SIGNAL(clicked()),this,SLOT(slot_start()));
    connect(button_stop,SIGNAL(clicked()),this,SLOT(slot_stop()));
    connect(button_reset,SIGNAL(clicked()),this,SLOT(slot_reset()));

    //Layout
    layout_h = new QHBoxLayout();
    layout_h->addWidget(button_start);
    layout_h->addWidget(button_stop);
    layout_h->addWidget(button_reset);

    layout_v = new QVBoxLayout(this);
    layout_v->addWidget(lcd_stoppuhr);
    layout_v->addLayout(layout_h);
    setLayout(layout_v);
}

void window_stopwatch::TimeSlot()
{
    counttemp += 1;
    if(counttemp==100)
        {
            counttemp=0;
            secondtemp+=1;
            if(secondtemp==60)
            {
                secondtemp=0;
                minutetemp+=1;
                if(minutetemp==60)
                {
                    minutetemp=0;
                    hourtemp+=1;
                    if(hourtemp==24)
                    {
                        hourtemp=0;
                    }
                }
             }
          }
     QString hourstr = QString::number(hourtemp);
     QString minutestr = QString::number(minutetemp);
     QString secondstr = QString::number(secondtemp);
     QString msstr = QString::number(counttemp);
     Display(hourstr,minutestr,secondstr,msstr);

}

void window_stopwatch::Display(QString hour, QString minute,QString second,QString ms)
{

    lcd_stoppuhr->display(hour+":"+minute+":"+second+":"+ms);
}


void window_stopwatch::slot_start()
{
    msTimer->start(10);//10ms

}

void window_stopwatch::slot_stop()
{
    msTimer->stop();

}

void window_stopwatch::slot_reset()
{
    QString hour_reset = "00";
    QString minute_reset = "00";
    QString second_reset = "00";
    QString ms_reset = "00";
    lcd_stoppuhr->display(hour_reset+":"+minute_reset+":"+second_reset+":"+ms_reset);
    counttemp = 0;
    secondtemp = 0;
    minutetemp = 0;
    hourtemp = 0;
}





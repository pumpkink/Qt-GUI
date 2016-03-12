#include "window_1.h"
#include <QApplication>
#include <qwidget.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <QLabel>


window_1::window_1()
{



    //Pixmap load
    QPixmap pix;
    QImage background;
    background.load(":/besch_background.png");
    pix.load(":/besch_background.png");
    label_back =new QLabel(this);
    label_back->setPixmap(pix);
    label_back->setAlignment(Qt::AlignCenter);

    label_1 = new QLabel(this);
    label_2 = new QLabel(this);
    label_3 = new QLabel(this);
    label_4 = new QLabel(this);

    //layout
    QGridLayout *layout_grid = new QGridLayout();
    layout_grid->addWidget(label_back,1,1);
    layout_grid->addWidget(label_1,1,0);
    layout_grid->addWidget(label_2,1,2);
    layout_grid->addWidget(label_3,0,1);
    layout_grid->addWidget(label_4,2,1);
    setLayout(layout_grid);


    x = 190;
    y = 124;

}

void window_1::mousePressEvent(QMouseEvent *event)
{
    mouse_status = true;

}

void window_1::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_status = false;

}

void window_1::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_status){
        x = event->pos().x();
        y = event->pos().y();
        update();
    }
}


void window_1::paintEvent(QPaintEvent *)
{
    //int center_x = 105;
    //int center_y = 138;
    //QPoint center(center_x,center_y);
    QPoint punkt(x,y);
    paint = new QPainter;
    //Start the painting
    paint->begin(this);
    paint->setPen(QPen(Qt::red,1));
    paint->setBrush(Qt::red);
    paint->drawEllipse(punkt,5,5);
    paint->end();


    double a =x - 190;
    double b =124 - y;

    char char1[10];
    char char2[10];
    sprintf(char1,"%03.0fm/s²",a);
    sprintf(char2,"%03.0fm/s²",b);
    QString string_1 = QString(char1);
    QString string_2 = QString(char2);
    label_1->setText("R:"+string_1);
    label_2->setText("L:"+string_2);
    label_3->setText("     Brake:"+string_1);
    label_4->setText("Accelerate:"+string_2);



}


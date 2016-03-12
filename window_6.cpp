#include "window_6.h"
#include <QFrame>

window_6::window_6()
{
  //Label1
  label_1_1 = new QLabel;
  label_1_1->setText(tr("Temperatur 1_1:"));
  label_1_2 = new QLabel;
  label_1_2->setText(tr("Temperatur 1_2:"));
  label_1_3 = new QLabel;
  label_1_3->setText(tr("Temperatur 1_3:"));
  label_1_4 = new QLabel;
  label_1_4->setText(tr("Temperatur 1_4:"));
  label_1_5 = new QLabel;
  label_1_5->setText(tr("Temperatur 1_5:"));
  label_1_6 = new QLabel;
  label_1_6->setText(tr("Temperatur 1_6:"));
  label_1_7 = new QLabel;
  label_1_7->setText(tr("Temperatur 1_7:"));
  label_1_8 = new QLabel;
  label_1_8->setText(tr("Temperatur 1_8:"));


  label_value1_1 = new QLabel;
  label_value1_2 = new QLabel;
  label_value1_3 = new QLabel;
  label_value1_4 = new QLabel;
  label_value1_5 = new QLabel;
  label_value1_6 = new QLabel;
  label_value1_7 = new QLabel;
  label_value1_8 = new QLabel;


  //Label2
  label_2_1 = new QLabel;
  label_2_1->setText(tr("Temperatur 2_1:"));
  label_2_2 = new QLabel;
  label_2_2->setText(tr("Temperatur 2_2:"));
  label_2_3 = new QLabel;
  label_2_3->setText(tr("Temperatur 2_3:"));
  label_2_4 = new QLabel;
  label_2_4->setText(tr("Temperatur 2_4:"));
  label_2_5 = new QLabel;
  label_2_5->setText(tr("Temperatur 2_5:"));
  label_2_6 = new QLabel;
  label_2_6->setText(tr("Temperatur 2_6:"));
  label_2_7 = new QLabel;
  label_2_7->setText(tr("Temperatur 2_7:"));
  label_2_8 = new QLabel;
  label_2_8->setText(tr("Temperatur 2_8:"));


  label_value2_1 = new QLabel;
  label_value2_2 = new QLabel;
  label_value2_3 = new QLabel;
  label_value2_4 = new QLabel;
  label_value2_5 = new QLabel;
  label_value2_6 = new QLabel;
  label_value2_7 = new QLabel;
  label_value2_8 = new QLabel;

  //Slider
  slider1 = new QSlider(Qt::Horizontal);
  slider1->setTickPosition(QSlider::TicksBothSides);
  slider1->setTickInterval(10);
  slider1->setSingleStep(1);

  slider2 = new QSlider(Qt::Horizontal);
  slider2->setTickPosition(QSlider::TicksBothSides);
  slider2->setTickInterval(10);
  slider2->setSingleStep(1);

  /*slider3 = new QSlider(Qt::Horizontal);
  slider3->setTickPosition(QSlider::TicksBothSides);
  slider3->setTickInterval(10);
  slider3->setSingleStep(1);

  slider4 = new QSlider(Qt::Horizontal);
  slider4->setTickPosition(QSlider::TicksBothSides);
  slider4->setTickInterval(10);
  slider4->setSingleStep(1);
  */

  connect(slider1,SIGNAL(valueChanged(int)),this,SLOT(slot_value1()));
  connect(slider2,SIGNAL(valueChanged(int)),this,SLOT(slot_value2()));
  //connect(slider3,SIGNAL(valueChanged(int)),this,SLOT(slot_maxvalueV()));
  //connect(slider4,SIGNAL(valueChanged(int)),this,SLOT(slot_minvalueV()));

  //Layout1
  layout_vertical_1_l = new QVBoxLayout;
  layout_vertical_1_l->addWidget(label_1_1);
  layout_vertical_1_l->addWidget(label_1_2);
  layout_vertical_1_l->addWidget(label_1_3);
  layout_vertical_1_l->addWidget(label_1_4);
  layout_vertical_1_l->addWidget(label_1_5);
  layout_vertical_1_l->addWidget(label_1_6);
  layout_vertical_1_l->addWidget(label_1_7);
  layout_vertical_1_l->addWidget(label_1_8);

  layout_vertical_1_v = new QVBoxLayout;
  layout_vertical_1_v->addWidget(label_value1_1);
  layout_vertical_1_v->addWidget(label_value1_2);
  layout_vertical_1_v->addWidget(label_value1_3);
  layout_vertical_1_v->addWidget(label_value1_4);
  layout_vertical_1_v->addWidget(label_value1_5);
  layout_vertical_1_v->addWidget(label_value1_6);
  layout_vertical_1_v->addWidget(label_value1_7);
  layout_vertical_1_v->addWidget(label_value1_8);

  layout_horizontal_1 = new QHBoxLayout;
  layout_horizontal_1->addLayout(layout_vertical_1_l);
  layout_horizontal_1->addLayout(layout_vertical_1_v);

  layout_vertical_1 = new QVBoxLayout;
  layout_vertical_1->addLayout(layout_horizontal_1);
  layout_vertical_1->addWidget(slider1);

  //Layout2
  layout_vertical_2_l = new QVBoxLayout;
  layout_vertical_2_l->addWidget(label_2_1);
  layout_vertical_2_l->addWidget(label_2_2);
  layout_vertical_2_l->addWidget(label_2_3);
  layout_vertical_2_l->addWidget(label_2_4);
  layout_vertical_2_l->addWidget(label_2_5);
  layout_vertical_2_l->addWidget(label_2_6);
  layout_vertical_2_l->addWidget(label_2_7);
  layout_vertical_2_l->addWidget(label_2_8);

  layout_vertical_2_v = new QVBoxLayout;
  layout_vertical_2_v->addWidget(label_value2_1);
  layout_vertical_2_v->addWidget(label_value2_2);
  layout_vertical_2_v->addWidget(label_value2_3);
  layout_vertical_2_v->addWidget(label_value2_4);
  layout_vertical_2_v->addWidget(label_value2_5);
  layout_vertical_2_v->addWidget(label_value2_6);
  layout_vertical_2_v->addWidget(label_value2_7);
  layout_vertical_2_v->addWidget(label_value2_8);

  layout_horizontal_2 = new QHBoxLayout;
  layout_horizontal_2->addLayout(layout_vertical_2_l);
  layout_horizontal_2->addLayout(layout_vertical_2_v);

  layout_vertical_2 = new QVBoxLayout;
  layout_vertical_2->addLayout(layout_horizontal_2);
  layout_vertical_2->addWidget(slider2);


  //Main Layout
  QLabel *vline = new QLabel;
  vline->setFrameStyle(QFrame::VLine|QFrame::Raised);
  layout_horizontal = new QHBoxLayout(this);
  layout_horizontal->addLayout(layout_vertical_1);
  layout_horizontal->addWidget(vline);
  layout_horizontal->addLayout(layout_vertical_2);
  setLayout(layout_horizontal);

}

void window_6::slot_value1()
{
  double d1 = slider1->value();
  char ch1[10];
  sprintf(ch1,"%03.1f℃",d1);
  QString string1 = QString(ch1);
  label_value1_1->setText(string1);
  label_value1_2->setText(string1);
  label_value1_3->setText(string1);
  label_value1_4->setText(string1);
  label_value1_5->setText(string1);
  label_value1_6->setText(string1);
  label_value1_7->setText(string1);
  label_value1_8->setText(string1);
}

void window_6::slot_value2()
{
  double d2 = slider2->value();
  char ch2[10];
  sprintf(ch2,"%03.1f℃",d2);
  QString string2 = QString(ch2);
  label_value2_1->setText(string2);
  label_value2_2->setText(string2);
  label_value2_3->setText(string2);
  label_value2_4->setText(string2);
  label_value2_5->setText(string2);
  label_value2_6->setText(string2);
  label_value2_7->setText(string2);
  label_value2_8->setText(string2);
}

/*void MainWindow::slot_maxvalueV()
{
  double d3 = slider3->value();
  char ch3[10];
  sprintf(ch3,"%03.1fV",d3);
  QString string3 = QString(ch3);
  label_maxvalueV->setText(string3);
}

void MainWindow::slot_minvalueV()
{
  double d4 = slider4->value();
  char ch4[10];
  sprintf(ch4,"%03.1fV",d4);
  QString string4 = QString(ch4);
  label_minvalueV->setText(string4);
}*/




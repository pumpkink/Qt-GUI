#include "window_5.h"


window_5::window_5()
{
  //Label
  label_Max_T = new QLabel;
  label_Max_T->setText(tr("Max.Temperatur:"));
  label_Min_T = new QLabel;
  label_Min_T->setText(tr("Min.Temperatur:"));
  label_Max_V = new QLabel;
  label_Max_V->setText(tr("Max.Zellspannung:"));
  label_Min_V = new QLabel;
  label_Min_V->setText(tr("Min.Zellspannung:"));


  label_maxvalueT = new QLabel;
  label_minvalueT = new QLabel;
  label_maxvalueV = new QLabel;
  label_minvalueV = new QLabel;

  //Slider
  slider1 = new QSlider(Qt::Horizontal);
  slider1->setTickPosition(QSlider::TicksBothSides);
  slider1->setTickInterval(10);
  slider1->setSingleStep(1);

  slider2 = new QSlider(Qt::Horizontal);
  slider2->setTickPosition(QSlider::TicksBothSides);
  slider2->setTickInterval(10);
  slider2->setSingleStep(1);

  slider3 = new QSlider(Qt::Horizontal);
  slider3->setTickPosition(QSlider::TicksBothSides);
  slider3->setTickInterval(10);
  slider3->setSingleStep(1);

  slider4 = new QSlider(Qt::Horizontal);
  slider4->setTickPosition(QSlider::TicksBothSides);
  slider4->setTickInterval(10);
  slider4->setSingleStep(1);

  connect(slider1,SIGNAL(valueChanged(int)),this,SLOT(slot_maxvalueT()));
  connect(slider2,SIGNAL(valueChanged(int)),this,SLOT(slot_minvalueT()));
  connect(slider3,SIGNAL(valueChanged(int)),this,SLOT(slot_maxvalueV()));
  connect(slider4,SIGNAL(valueChanged(int)),this,SLOT(slot_minvalueV()));

  //Layout
  QGridLayout  *layout_grid = new QGridLayout;
  layout_grid->addWidget(label_Max_T,0,0);
  layout_grid->addWidget(label_maxvalueT,0,1);
  layout_grid->addWidget(slider1,0,2);
  layout_grid->addWidget(label_Min_T,1,0);
  layout_grid->addWidget(label_minvalueT,1,1);
  layout_grid->addWidget(slider2,1,2);
  layout_grid->addWidget(label_Max_V,2,0);
  layout_grid->addWidget(label_maxvalueV,2,1);
  layout_grid->addWidget(slider3,2,2);
  layout_grid->addWidget(label_Min_V,3,0);
  layout_grid->addWidget(label_minvalueV,3,1);
  layout_grid->addWidget(slider4,3,2);
  setLayout(layout_grid);


}

void window_5::slot_maxvalueT()
{
  double d1 = slider1->value();
  char ch1[10];
  sprintf(ch1,"%03.1f℃",d1);
  QString string1 = QString(ch1);
  label_maxvalueT->setText(string1);
}

void window_5::slot_minvalueT()
{
  double d2 = slider2->value();
  char ch2[10];
  sprintf(ch2,"%03.1f℃",d2);
  QString string2 = QString(ch2);
  label_minvalueT->setText(string2);
}

void window_5::slot_maxvalueV()
{
  double d3 = slider3->value();
  char ch3[10];
  sprintf(ch3,"%03.1fV",d3);
  QString string3 = QString(ch3);
  label_maxvalueV->setText(string3);
}

void window_5::slot_minvalueV()
{
  double d4 = slider4->value();
  char ch4[10];
  sprintf(ch4,"%03.1fV",d4);
  QString string4 = QString(ch4);
  label_minvalueV->setText(string4);
}


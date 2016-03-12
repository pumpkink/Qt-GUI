#ifndef WINDOW_6
#define WINDOW_6

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QString>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>


class window_6 : public QWidget
{
    Q_OBJECT

public:
   window_6();

private slots:
   void slot_value1();
   void slot_value2();
   //void slot_maxvalueV();
   //void slot_minvalueV();

private:
    QLabel *label_1_1;
    QLabel *label_1_2;
    QLabel *label_1_3;
    QLabel *label_1_4;
    QLabel *label_1_5;
    QLabel *label_1_6;
    QLabel *label_1_7;
    QLabel *label_1_8;
    QLabel *label_value1_1;
    QLabel *label_value1_2;
    QLabel *label_value1_3;
    QLabel *label_value1_4;
    QLabel *label_value1_5;
    QLabel *label_value1_6;
    QLabel *label_value1_7;
    QLabel *label_value1_8;

    QLabel *label_2_1;
    QLabel *label_2_2;
    QLabel *label_2_3;
    QLabel *label_2_4;
    QLabel *label_2_5;
    QLabel *label_2_6;
    QLabel *label_2_7;
    QLabel *label_2_8;
    QLabel *label_value2_1;
    QLabel *label_value2_2;
    QLabel *label_value2_3;
    QLabel *label_value2_4;
    QLabel *label_value2_5;
    QLabel *label_value2_6;
    QLabel *label_value2_7;
    QLabel *label_value2_8;


    QVBoxLayout *layout_vertical_1_l;
    QVBoxLayout *layout_vertical_1_v;
    QVBoxLayout *layout_vertical_1;
    QHBoxLayout *layout_horizontal_1;
    QHBoxLayout *layout_horizontal;


    QVBoxLayout *layout_vertical_2_l;
    QVBoxLayout *layout_vertical_2_v;
    QVBoxLayout *layout_vertical_2;
    QHBoxLayout *layout_horizontal_2;

    QSlider *slider1;
    QSlider *slider2;
    QSlider *slider3;
    QSlider *slider4;
    QSlider *slider5;
    QSlider *slider6;
    QSlider *slider7;


};

#endif // WINDOW_6


/********Max&Min T and V **********
 *                                *
 *                                *
 * This is the Window for         *
 * Max&Min Temperatur and Voltage *
 * Value                          *
 *                                *
 *                                *
 **********************************/
#ifndef WINDOW_5
#define WINDOW_5

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QString>
#include <QGridLayout>


class window_5 : public QWidget
{
    Q_OBJECT

public:
   window_5();

private slots:
   void slot_maxvalueT();
   void slot_minvalueT();
   void slot_maxvalueV();
   void slot_minvalueV();

private:
    QLabel *label_Max_T;
    QLabel *label_Min_T;
    QLabel *label_Max_V;
    QLabel *label_Min_V;
    QLabel *label_maxvalueT;
    QLabel *label_minvalueT;
    QLabel *label_maxvalueV;
    QLabel *label_minvalueV;
    QWidget *widget;
    QGridLayout *layout_grid;
    QSlider *slider1;
    QSlider *slider2;
    QSlider *slider3;
    QSlider *slider4;

};

#endif // WINDOW_5


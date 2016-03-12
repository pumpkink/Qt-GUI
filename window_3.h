/***************BMS****************
 *                                *
 *                                *
 * This is the Window for         *
 * Batterie Manage System.        *
 *                                *
 *                                *
 **********************************/

#ifndef WINDOW_3
#define WINDOW_3

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>

class window_3 : public QWidget
{
    Q_OBJECT

public:
    window_3();

private slots:
   void slider_value();

private:
    QLabel *label;
    QLabel *label_V;
    QLabel *label_I;
    QLabel *label_T;
    QLabel *label_SOC;
    QVBoxLayout layout_vertical;
    QHBoxLayout layout_horizontal;
    QSlider *slider;

};


#endif // WINDOW_3


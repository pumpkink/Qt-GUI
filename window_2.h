/***********Speedometer************
 *                                *
 *                                *
 * This is the Window for         *
 * Speedometer.                   *
 *                                *
 *                                *
 **********************************/

#ifndef WINDOW_2
#define WINDOW_2

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QLCDNumber>



class window_2 : public QWidget
{
    Q_OBJECT

public:
    window_2();
    void paintEvent(QPaintEvent*);

private slots:
    void slider_value();

private:
    QPainter *painter;
    QSlider  *slider;
    QLCDNumber *lcd_speed;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *layout;
    int a,range_min,range_max,angle_min,angle_max;
    double start_range;
    double current_range;

};
#endif // WINDOW_2


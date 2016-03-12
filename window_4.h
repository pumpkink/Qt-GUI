/********Akku 1./2. SPannung*******
 *                                *
 *                                *
 * This is the Window for         *
 * Akku 1./2. SPannung.           *
 *                                *
 *                                *
 **********************************/
#ifndef WINDOW_4
#define WINDOW_4

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QString>
#include <QGridLayout>


class window_4 : public QWidget
{
    Q_OBJECT

public:
   window_4();

private slots:
   void slot_value1();
   void slot_value2();

private:
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_value1;
    QLabel *label_value2;
    QGridLayout *layout_grid;
    QSlider *slider1;
    QSlider *slider2;

};

#endif // WINDOW_4


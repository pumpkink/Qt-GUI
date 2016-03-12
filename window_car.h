/***********Car_Window*************
 *                                *
 *                                *
 * This is the Window for         *
 * Car_Window.                    *
 *                                *
 *                                *
 **********************************/
#ifndef WINDOW_CAR
#define WINDOW_CAR

#include <QMainWindow>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>




class window_car : public QWidget
{
    Q_OBJECT

public:
    window_car();
    void paintEvent(QPaintEvent*);


private slots:
    //void slot_VL();
    //void slot_VR();
    //void slot_HL();
    //void slot_HR();
    void slot_paint();
    //void on_pushButton_pressed();
    //void on_pushButton_released();


protected:
    void timerEvent(QTimerEvent *);
    bool isflush;

    QLCDNumber *lcd_zeit;
    QLCDNumber *lcd_stoppuhr;
    QLCDNumber *lcd_VLR;
    QLCDNumber *lcd_VRR;
    QLCDNumber *lcd_HLR;
    QLCDNumber *lcd_HRR;


    QLabel *label_car;
    QLabel *time_label;
    QLabel *label_VLR;
    QLabel *label_HLR;
    QLabel *label_VRR;
    QLabel *label_HRR;
    QLabel *stoppuhr_label;

    QSlider *slider_VL;
    QSlider *slider_VR;
    QSlider *slider_HL;
    QSlider *slider_HR;
    QSlider *slider_winkel;

    QVBoxLayout *layout_l1;
    QVBoxLayout *layout_l2;
    QVBoxLayout *layout_l3;

    QVBoxLayout *layout_r1;
    QVBoxLayout *layout_r2;
    QVBoxLayout *layout_r3;

    QVBoxLayout *layout_verticalleft;
    QVBoxLayout *layout_verticalright;

    //QHBoxLayout *layout_button;
    QHBoxLayout *layout_horizontal;

    QPushButton *button_brake;




private:
    //bool light_status;
    int a,range_min,range_max,angle_min,angle_max;
    double start_range;
    double current_range;
    enum Drawfaktor
    {
     y_offset = 300,
     index1 = -1,
     index2 = 1

    };

};

#endif // WINDOW_CAR


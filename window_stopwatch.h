#ifndef WINDOW_STOPWATCH
#define WINDOW_STOPWATCH

#include <QWidget>
#include <QLCDNumber>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>



class window_stopwatch : public QWidget
{
    Q_OBJECT

public:
    window_stopwatch();
    void StartStoppuhr();
    void StopStoppuhr();
    void ResetStoppuhr();

private slots:
    void TimeSlot();
    void slot_start();
    void slot_stop();
    void slot_reset();



private:
    int hourtemp;
    int minutetemp;
    int secondtemp;
    int counttemp;


    QTimer *msTimer;

    QLCDNumber *lcd_stoppuhr;

    QPushButton *button_start;
    QPushButton *button_stop;
    QPushButton *button_reset;

    QVBoxLayout *layout_v;
    QHBoxLayout *layout_h;

    void Display(QString,QString,QString,QString);

#endif // WINDOW_STOPWATCH


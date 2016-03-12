#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "window_1.h"
#include "window_2.h"
#include "window_3.h"
#include "window_4.h"
#include "window_5.h"
#include "window_6.h"
#include "window_car.h"


class QAction;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void open_besch();
    void open_speed();
    void open_bms();
    void open_1und2Spannung();
    void open_temperatur();
    void open_max_min();

private:
    Ui::MainWindow *ui;
    bool besch_widget;
    //int  widget1_flag;
    bool speed_widget;
    bool bms_widget;
    bool spannung1und2_widget;
    bool max_min_widget;
    bool temperatur_widget;
    window_1 *wd1;
    window_2 *wd2;
    window_3 *wd3;
    window_4 *wd4;
    window_5 *wd5;
    window_6 *wd6;
    window_car *wdcar;
    QAction *openAction_1;
    QAction *openAction_pedal;
    QAction *openAction_speed;
    QAction *openAction_besch;
    QAction *openAction_2;
    QAction *openAction_BMS;
    QAction *openAction_1und2Spanung;
    QAction *openAction_3;
    QAction *openAction_4;
    QAction *openAction_5;
    QLabel *msgLabel;
    QLabel *label_car;
};

#endif // MAINWINDOW_H


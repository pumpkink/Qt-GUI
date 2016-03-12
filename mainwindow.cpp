#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QObject>
#include <QStatusBar>
#include <QFileDialog>
#include <QColorDialog>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    //set Centralwidget
    //QPixmap pix_car;
    //QImage background;
    //background.load(":/car.png");
    //pix_car.load(":/car.png");
    //label_car = new QLabel(this);
    //label_car->setPixmap(pix_car);
    //label_car->setAlignment(Qt::AlignCenter);
    //setCentralWidget(label_car);


    //QVBoxLayout *layout = new QVBoxLayout(this);


    //parameter init
    besch_widget = false;

    //*****DockWidget*****//

    //设置主窗口
    setWindowTitle(tr("CarWindow"));
    wdcar = new window_car();
    setCentralWidget(wdcar);

    //设置停靠窗口1
    QDockWidget *dock = new QDockWidget(tr("DockWindow1"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    wd1 = new window_1();
    dock->setWidget(wd1);
    addDockWidget(Qt::LeftDockWidgetArea,dock);

    //设置停靠窗口2
    dock = new QDockWidget(tr("DockWindow2"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    wd2 = new window_2();
    dock->setWidget(wd2);
    addDockWidget(Qt::LeftDockWidgetArea,dock);

    //设置停靠窗口3
    dock =new QDockWidget(tr("DockWindow3"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    wd3 = new window_3();
    dock->setWidget(wd3);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    //设置停靠窗口7
    dock =new QDockWidget(tr("DockWindow7"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QWidget *window_4 = new QWidget();
    dock->setWidget(window_4);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    msgLabel = new QLabel;
    //将QLabel大小设置最小大小为其本身的建议大小，这样设置后，最小大小可能是变化的
    //最后设置显示规则是水平居中(HCenter)
    //接下里一行使用statusBar()函数将这个Label添加的状态栏中
    msgLabel->setMinimumSize(msgLabel->sizeHint());
    msgLabel->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(msgLabel);
    //没有下面一句，状态栏在不显示的时候是一条竖线，加了这句后，竖线消失
    //就是把QStatusBar的子组件的border设置为0，即没有边框
    //QStatusBar右下角的大小控制点可以通过setSizeGripEnabled()函数来设置是否存在
    //具体参照API文档
    statusBar()->setStyleSheet(QString("QStatusBar::item{border:0px}"));


    /*****Fahrdynamik Action*****/
    openAction_1 = new QAction(tr("&Fahrdynamik"),this);
    openAction_1->setStatusTip(tr("Open a Widget"));
    openAction_1->setIcon(QIcon(":/fahrdynamik.png"));

    openAction_pedal = new QAction(tr("&Gaspedal"),this);
    openAction_pedal->setStatusTip(tr("Gaspedal information"));
    openAction_pedal->setIcon(QIcon(":/gaspedal.png"));

    openAction_speed = new QAction(tr("&speed"),this);
    openAction_speed->setStatusTip(tr("speed information"));
    openAction_speed->setIcon(QIcon(":/speed.png"));

    openAction_besch = new QAction(tr("&Accelerate"),this);
    openAction_besch->setStatusTip(tr("a information"));
    openAction_besch->setIcon(QIcon(":/besch.png"));


    /*****Akku Action*****/
    openAction_2 = new QAction(tr("&Akku"),this);
    openAction_2->setStatusTip(tr("Akku Information"));
    openAction_2->setIcon(QIcon(":/akku.png"));

    openAction_BMS = new QAction(tr("&BMS"),this);
    openAction_BMS->setStatusTip(tr("Batterie Management System"));
    openAction_BMS->setIcon(QIcon(":/bms.png"));

    openAction_1und2Spanung = new QAction(tr("&1.and 2.Spannung"),this);
    openAction_1und2Spanung->setStatusTip(tr("1. and 2. Akkuspannung"));



    /*****Temperatur Action*****/
    openAction_3 = new QAction(tr("&Temperatur"),this);
    openAction_3->setStatusTip(tr("Temperatur Information"));
    openAction_3->setIcon(QIcon(":/temp.png"));


    /*****Zellspannung Action*****/
    openAction_4 = new QAction(tr("&Zellspannung"),this);
    openAction_4->setStatusTip(tr("Spannung Information"));
    openAction_4->setIcon(QIcon(":/spannung.png"));


    /*****Max.and Min.Value Action*****/
    openAction_5 = new QAction(tr("&Max&&Min.Wert"),this);
    openAction_5->setStatusTip(tr("Max. and Min.Temperatur and Zellspannung"));



    /*****Add Menulist to Menubar *****/
    QMenu *file_1 =menuBar()->addMenu(tr("&Fahrdynamik"));
    QMenu *file_2 =menuBar()->addMenu(tr("&Akku"));
    QMenu *file_3 =menuBar()->addMenu(tr("&Temperatur"));
    QMenu *file_4 =menuBar()->addMenu(tr("&Zellspannung"));
    QMenu *file_5 =menuBar()->addMenu(tr("&Max&&Min.Wert"));

    //在file下面添加了openAction这个动作
    file_1->addAction(openAction_pedal);
    file_1->addAction(openAction_speed);
    file_1->addAction(openAction_besch);
    file_2->addAction(openAction_BMS);
    file_2->addAction(openAction_1und2Spanung);
    file_3->addAction(openAction_3);
    file_4->addAction(openAction_4);
    file_5->addAction(openAction_5);

    /*****Add Menulist to Toolbar *****/
    QToolBar *toolBar_1 =addToolBar(tr("&Fahrdynamik"));
    QToolBar *toolBar_2 =addToolBar(tr("&Akku"));
    QToolBar *toolBar_3 =addToolBar(tr("&Temperatur"));
    QToolBar *toolBar_4 =addToolBar(tr("&Zellspannung"));

    toolBar_1->addAction(openAction_pedal);
    toolBar_1->addAction(openAction_speed);
    toolBar_1->addAction(openAction_besch);
    toolBar_2->addAction(openAction_BMS);
    toolBar_3->addAction(openAction_3);
    toolBar_4->addAction(openAction_4);



    connect(openAction_besch,SIGNAL(triggered()),this,SLOT(open_besch()));
    connect(openAction_speed,SIGNAL(triggered()),this,SLOT(open_speed()));
    connect(openAction_BMS,SIGNAL(triggered()),this,SLOT(open_bms()));
    connect(openAction_1und2Spanung,SIGNAL(triggered()),this,SLOT(open_1und2Spannung()));
    connect(openAction_3,SIGNAL(triggered()),this,SLOT(open_temperatur()));
    connect(openAction_5,SIGNAL(triggered()),this,SLOT(open_max_min()));

}

void MainWindow ::open_besch()
{
   besch_widget =true;
   if( besch_widget){
       QDockWidget *dock = new QDockWidget(tr("DockWindow1"),this);
       dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
       dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
       wd1 = new window_1();
       dock->setWidget(wd1);
       addDockWidget(Qt::LeftDockWidgetArea,dock);
   }else besch_widget = false;
}



void MainWindow ::open_speed()
{
   speed_widget =true;
   if(speed_widget){
       QDockWidget *dock = new QDockWidget(tr("DockWindow2"),this);
       dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
       dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
       wd2 = new window_2();
       dock->setWidget(wd2);
       addDockWidget(Qt::LeftDockWidgetArea,dock);
   }else speed_widget = false;
}


void MainWindow ::open_bms()
{
   bms_widget =true;
   if(bms_widget){
       QDockWidget *dock = new QDockWidget(tr("DockWindow3"),this);
       dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
       dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
       wd3 = new window_3();
       dock->setWidget(wd3);
       addDockWidget(Qt::RightDockWidgetArea,dock);
   }else bms_widget = false;
}

void MainWindow ::open_1und2Spannung()
{
   spannung1und2_widget =true;
   if(spannung1und2_widget){
       QDockWidget *dock = new QDockWidget(tr("DockWindow4"),this);
       dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
       dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
       wd4 = new window_4();
       dock->setWidget(wd4);
       addDockWidget(Qt::RightDockWidgetArea,dock);
   }else spannung1und2_widget = false;
}

void MainWindow ::open_max_min()
{
   max_min_widget =true;
   if(max_min_widget){
       QDockWidget *dock = new QDockWidget(tr("DockWindow5"),this);
       dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
       dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
       wd5 = new window_5();
       dock->setWidget(wd5);
       addDockWidget(Qt::RightDockWidgetArea,dock);
   }else max_min_widget = false;
}

void MainWindow ::open_temperatur()
{
   temperatur_widget =true;
   if(temperatur_widget){
       QDockWidget *dock = new QDockWidget(tr("DockWindow6"),this);
       dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
       dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea|Qt::TopDockWidgetArea);
       wd6 = new window_6();
       dock->setWidget(wd6);
       addDockWidget(Qt::RightDockWidgetArea,dock);
   }else temperatur_widget = false;
}




MainWindow::~MainWindow()
{
    delete ui;
}













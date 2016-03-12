/**********Beschleunigung**********
 *                                *
 *                                *
 * This is the Window for         *
 * Beschleunigung.                *
 *                                *
 *                                *
 **********************************/



#ifndef WINDOW_1
#define WINDOW_1

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QGridLayout>


class window_1 : public QWidget
{
    Q_OBJECT

public:
    window_1();
    void paintEvent(QPaintEvent*);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    QPainter *paint;
    int x ;
    int y ;
    int screenwidth;
    int screenheight;
    bool mouse_status;
    QLabel *label_back;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGridLayout *layout_grid;

};

#endif // WINDOW_1


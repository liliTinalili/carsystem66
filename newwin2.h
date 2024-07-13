#ifndef NEWWIN2_H
#define NEWWIN2_H

#include <QWidget>
#include <QTimer>
#include <QTime>

namespace Ui {
class newwin2;
}

class newwin2 : public QWidget
{
    Q_OBJECT

public:
    explicit newwin2(QWidget *parent = nullptr);
    ~newwin2();

private slots:
    void timerUpdate(void);
    void timerUpdate2();
    void timerUpdate3();


    void on_work_clicked();

    void on_rest_clicked();

private:
    Ui::newwin2 *ui;
    int count1 = 0,count2 = 0; // 计数器
    QTime startTime;   // 用于记录开始时间的 QTime 对象
    QTimer *timer2 = new QTimer(this);
    QTimer *timer3 = new QTimer(this);
    int flag=0;
    int flag2=0;
    int flag3=0;
    QString nextresttime=0;
    QString lastresttime=0;
    QDateTime currentTime1;
    QString adjustedTimeStr1=0;
    QString adjustedTimeStr;
};


#endif // NEWWIN2_H

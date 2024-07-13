#include "newwin2.h"
#include "ui_newwin2.h"
#include <QTimer>
#include <QDateTime>

newwin2::newwin2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newwin2)
{
    ui->setupUi(this);
    timerUpdate();
    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    if(flag==1&& adjustedTimeStr==nextresttime) {

    }
    timer->start(1000);
}

newwin2::~newwin2()
{
    delete ui;
}

void newwin2::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("hh:mm:ss"); // 时分秒显示

    ui->label->setText(str); // 假设在UI 中有一个名为 label 的 QLabel
}

void newwin2::timerUpdate2()
{
   // QTime currentTime = QTime::currentTime();
    //int elapsedSeconds = startTime.secsTo(currentTime); // 计算经过的秒数
    if(flag==1){
        int count=0;
        int elapsedSeconds=count1 ++;
        int elapsedSeconds2=7200*4-elapsedSeconds;

        int hours = elapsedSeconds / 3600;
        int minutes = (elapsedSeconds % 3600) / 60;
        int seconds = elapsedSeconds % 60;

        int hours2 = elapsedSeconds2 / 3600;
        int minutes2 = (elapsedSeconds2 % 3600) / 60;
        int seconds2= elapsedSeconds2 % 60;
        QString timeString = QString("%1:%2:%3")
                                 .arg(hours, 2, 10, QChar('0'))
                                 .arg(minutes, 2, 10, QChar('0'))
                                 .arg(seconds, 2, 10, QChar('0'));
        QString timeString2 = QString("%1:%2:%3")
                                  .arg(hours2, 2, 10, QChar('0'))
                                  .arg(minutes2, 2, 10, QChar('0'))
                                  .arg(seconds2, 2, 10, QChar('0'));

        ui->workremain->setText("work remain  "+timeString2); // 假设在 UI 中有一个名为 label_2 的 QLabel 来显示时间
        ui->worktotal->setText("work total  "+timeString);
    }
    //ui->countLabel->setText(QString::number(count)); // 假设在 UI 中有一个名为 countLabel 的 QLabel
}
void newwin2::timerUpdate3()
{
    // QTime currentTime = QTime::currentTime();
    //int elapsedSeconds = startTime.secsTo(currentTime); // 计算经过的秒数

    if(flag==2){
        int elapsedSeconds=count2 ++;
        int elapsedSeconds2=3600-elapsedSeconds;

        int hours = elapsedSeconds / 3600;
        int minutes = (elapsedSeconds % 3600) / 60;
        int seconds = elapsedSeconds % 60;

        int hours2 = elapsedSeconds2 / 3600;
        int minutes2 = (elapsedSeconds2 % 3600) / 60;
        int seconds2= elapsedSeconds2 % 60;
        QString timeString = QString("%1:%2:%3")
                                 .arg(hours, 2, 10, QChar('0'))
                                 .arg(minutes, 2, 10, QChar('0'))
                                 .arg(seconds, 2, 10, QChar('0'));

        QString timeString2 = QString("%1:%2:%3")
                                  .arg(hours2, 2, 10, QChar('0'))
                                  .arg(minutes2, 2, 10, QChar('0'))
                                  .arg(seconds2, 2, 10, QChar('0'));

        ui->restremain->setText("rest remain  "+timeString2); // 假设您在 UI 中有一个名为 label_2 的 QLabel 来显示时间
        ui->resttotal->setText("rest total  "+timeString);
    }
    //ui->countLabel->setText(QString::number(count)); // 假设您在 UI 中有一个名为 countLabel 的 QLabel
}

void newwin2::on_work_clicked()
{   flag=1;
    count2=0;
    int elapsedSeconds=count2 ++;
    int elapsedSeconds2=3600-elapsedSeconds;

    int hours = elapsedSeconds / 3600;
    int minutes = (elapsedSeconds % 3600) / 60;
    int seconds = elapsedSeconds % 60;

    int hours2 = elapsedSeconds2 / 3600;
    int minutes2 = (elapsedSeconds2 % 3600) / 60;
    int seconds2= elapsedSeconds2 % 60;
    QString timeString = QString("%1:%2:%3")
                             .arg(hours, 2, 10, QChar('0'))
                             .arg(minutes, 2, 10, QChar('0'))
                             .arg(seconds, 2, 10, QChar('0'));

    QString timeString2 = QString("%1:%2:%3")
                              .arg(hours2, 2, 10, QChar('0'))
                              .arg(minutes2, 2, 10, QChar('0'))
                              .arg(seconds2, 2, 10, QChar('0'));

    ui->restremain->setText("rest remain  "+timeString2); // 假设您在 UI 中有一个名为 label_2 的 QLabel 来显示时间
    ui->resttotal->setText("rest total  "+timeString);

    lastresttime=adjustedTimeStr1;
    currentTime1 = QDateTime::currentDateTime();
    adjustedTimeStr1 = currentTime1.toString("hh:mm:ss");



    QDateTime currentTime = QDateTime::currentDateTime();
    QDateTime adjustedTime = currentTime.addSecs(2 * 3600);// 增加2小时

    adjustedTimeStr = adjustedTime.toString("hh:mm:ss");
    nextresttime=adjustedTimeStr;
    ui->nextresttime->setText("next rest time"+nextresttime);
    ui->lastresttime->setText("last rest time"+lastresttime);



    //startTime = QTime::currentTime(); // 记录开始时间
    if(flag2==0)
    {
        connect(timer2, SIGNAL(timeout()), this, SLOT(timerUpdate2()));
        timer2->start(1000);
        flag2=1;
    }

}

void newwin2::on_rest_clicked()
{   flag=2;



   if(flag3==0)
    {
        connect(timer3, SIGNAL(timeout()), this, SLOT(timerUpdate3()));
        timer3->start(1000);
        flag3=1;
    }


}


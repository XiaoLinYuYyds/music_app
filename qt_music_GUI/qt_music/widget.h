#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette> //画刷头文件
#include <QListWidget>
#include <QFileDialog>  //弹出窗口
#include <QDebug>
#include <QProcess>

#include <QLabel>   //用标签插入gif图片
#include <QMovie>   //用于显示gif动图
#include <QListWidgetItem>//用于播放列表单击和双击
#include <QTimer>
#include <QSettings>

namespace Ui {
class Widget;
}

/************类函数（class）***********/
class Widget : public QWidget
{
    Q_OBJECT

public:     //公有的
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:     //公有的
     void memberInit();  //控件的初始化
     void playerInit(); //播放初始化
     void playMusic();  //播放音乐，第一次点击播放控件时执行
     void showCurPlaySongName();//显示当前正在播放的歌曲名字
     void loaPlayListSong();    //加载已经保存的歌曲
public: //公有的
    typedef enum                    //定义一个枚举类型
    {
        ListPlay        = 0,        //顺序播放
        SingleSongOnce  = 1,        //单曲一次播放
        SingleSongLoop  = 2,        //单曲循环播放
        PlayListLoop    = 3,        //列表循环播放
        RandomPlay      = 4,        //随机播放
    }PlsyModel;

private slots:  //私有的控件,slots表示槽函数
    void on_ScanSongBtn_clicked();

    void on_PlayPauseBtn_clicked();
    void doProcessErrorSlot(QProcess::ProcessError);
    void on_horizontalSlider_2_sliderMoved(int position);

    void on_NetxBtn_clicked();

    void on_SongListWidget_currentRowChanged(int currentRow);

    void on_SongListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_ShowListBtn_clicked();

    void doProcessReadyReadSlot();  //进程有数据可读的槽函数
    void doProcessReadStandardOutputSlot();//读取标准输出的槽函数
    void doProcessFinished(int );          //播放结束触发的槽函数
    void doTimeoutSlot(); //超时对应slot
    void on_PrveBtn_clicked();

    void on_ProgresshorizontalSlider_sliderMoved(int position);

    void on_ProgresshorizontalSlider_sliderReleased();

    void on_ModeComboBox_currentIndexChanged(int index);

private:    //私有的
    Ui::Widget *ui;
    QPalette palette;
    QListWidget *showPlayList;
    QFileInfoList infoList;
    QStringList playListString;     //播放列表
    QProcess    *playerProcess;     //播放音乐进程

    int     playIndex;              //定义一个全局变量，当前播放歌曲索引
    bool    playStat;               //定义一个bool类型的歌曲播放状态变量;播放状态　true,正在播放　flase ..
    bool    playBtnStat;            //播放按钮控件的状态
    bool    showSongList;           //显示歌曲列表

    QTimer *timer;                  //定时发送获取当前播放时间

    QString timePos;               //歌曲播放总时间
    QString timeLength;            //歌曲播放的当前时间

    QMovie *movie;                  //播放时显示第一个GIF动图的变量
    QMovie *movie1;                 //播放时显示第一个GIF动图的变量

    int tlength;                    //歌曲总时间，以秒为单位
    int moveSliderVal;              //拖动后播放进度条的值
    PlsyModel playmode;             //播放模式

    QSettings *configIniWrite;      //配置文件写指针
    QSettings *configIniRead;       //配置文件读指针
    QSettings *configIniＤelete;       //配置文件删除指针
};

#endif // WIDGET_H

#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
#if 0
    //****音乐背景gif****
    //    QLabel *ww=new QLabel(this);
    //    setCentralWidget(ww);
    //    ww->setAutoFillBackground(1);
    //    QMovie *pic=new QMovie("/home/ljt/work/QT-projet/qt_music_GUI/qt_music/image/音乐背景动漫跳舞2.gif");
    //    ww->setMovie(pic);
    //    pic->start();
#endif
    memberInit();
    playerInit();
}

Widget::~Widget()
{
    delete ui;
}


/**********************控件初始化，控件名字自己定义的**************************************/
void Widget::memberInit()
{

    //音乐播放时控件（BeiJinSong）和控件（label_5）的动图
//    QMovie *movie = new QMovie("/home/ljt/work/QT-projet/qt_music_GUI/qt_music/image/音乐小人街舞.gif");  //显示gif
//    ui->BeiJinSong->setMovie(movie);
//    movie->start();

//    QMovie *movie1 = new QMovie("/home/ljt/work/QT-projet/qt_music_GUI/qt_music/image/音乐音节跳动.gif");  //显示gif
//    ui->label_5->setMovie(movie1);
//    movie1->start();

    //其他控件的图标显示
    ui->ScanSongBtn->setIconSize(QSize(60,60));                        //设置扫描歌曲控件大小
    ui->ScanSongBtn->setIcon(QIcon(QPixmap(":/image/扫描歌曲1.png")));  //设置扫描歌曲控件的图标
    ui->ShowListBtn->setIconSize(QSize(60,60));                        //设置播放器列表控件大小
    ui->ShowListBtn->setIcon(QIcon(QPixmap(":/image/播放器列表.png")));  //设置播放器列表控件的图标
    ui->QuitBtn->setIconSize(QSize(60,60));                             //设置播放器退出控件大小
    ui->QuitBtn->setIcon(QIcon(QPixmap(":/image/关机.png")));             //设置播放器退出控件的图标

//    ui->PrveBtn->setIconSize(QSize(60,60));                            //设置播放器上一首控件大小
//    ui->PrveBtn->setIcon(QIcon(QPixmap(":/image/上一首1.png")));        //设置播放器上一首控件的图标
//    ui->PlayPauseBtn->setIconSize(QSize(60,60));                       //设置播放器播放控件大小
//    ui->PlayPauseBtn->setIcon(QIcon(QPixmap(":/image/播放.png")));      //设置播放器播放控件的图标
//    ui->NetxBtn->setIconSize(QSize(60,60));                            //设置播放器下一首控件大小
//    ui->NetxBtn->setIcon(QIcon(QPixmap(":/image/下一首1.png")));        //设置播放器下一首控件的图标

    /******************************************背景图片设置***************************************/
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/image/播放器背景图.png")));    //设置播放器背景图片
    this->setPalette(palette);
    this->setAutoFillBackground(true);

//    QMovie *movie2 = new QMovie("/home/ljt/work/QT-projet/qt_music_GUI/qt_music/image/音乐播放动图.gif");  //显示gif
//    //ui->setupUi(this);
//    //QWidget->setMovie(movie1);
//    movie2->start();

//    /*******************设置音乐播放动图为透明************/
//    ui->BeiJinSong->setStyleSheet("background: transparent;"
//                                "border: 1px solid gray;"
//                                "border-radius:6px;"
//                                "color: #000000;"
//                                "font:16px;"
//                                "min-width: 4em;"
//                               );

    /*******************设置返回按钮为透明************/
    ui->BackBtn->setStyleSheet("background: transparent;"
                                "border: 1px solid gray;"
                                "border-radius:6px;"
                                "color: #000000;"
                                "font:16px;"
                                "min-width: 4em;"
                               );
    /*******************设置退出按钮为透明************/
    ui->QuitBtn->setStyleSheet("background: transparent;"
                                "border: 1px solid gray;"
                                "border-radius:6px;"
                                "color: #000000;"
                                "font:16px;"
                                "min-width: 4em;"
                               );
    /*******************设置扫描播放歌曲按钮为透明************/
    ui->ScanSongBtn->setStyleSheet("background: transparent;"
                                    "border: 1px solid gray;"
                                    "border-radius:6px;"
                                    "color: #000000;"           //颜色
                                    "font:16px;"                //像素
                                    "min-width: 4em;"
                                   );
    /*******************设置播放列表控件（ShowListBtn）按钮为透明*************/
    ui->ShowListBtn->setStyleSheet("background: transparent;"
                                    "border: 1px solid gray;"
                                    "border-radius:6px;"
                                    "color: #000000;"
                                    "font:16px;"
                                    "min-width: 4em;"
                                   );
    /*******************设置播放列表按钮为透明************/
    ui->ModeComboBox->setStyleSheet("background: transparent;"
                                    "border: 1px solid gray;"
                                    "border-radius:6px;"
                                    "color: #000000;"
                                    "font:16px;"
                                    "min-width: 4em;"
                                   );
    /*******************设置播放列表图为透明************/
    ui->SongListWidget->setStyleSheet("background: transparent;"
                                            "border: 1px solid gray;"
                                            "border-radius:6px;"
                                            "color: #000000;"
                                            "font:16px;"
                                            "min-width: 4em;"
                                           );

    showSongList = true;    //显示歌曲列表

//添加播放模式到ModeComboBox控件
    ui->ModeComboBox->addItem(QIcon(QPixmap(":/image/xunhuan/顺序播放.png")),"顺序播放");       //显示图标和播放模式
    ui->ModeComboBox->addItem(QIcon(QPixmap(":/image/xunhuan/单曲一次.png")),"单曲一次");       //显示图标和播放模式
    ui->ModeComboBox->addItem(QIcon(QPixmap(":/image/xunhuan/单曲循环 (2).png")),"单曲循环");   //显示图标和播放模式
    ui->ModeComboBox->addItem(QIcon(QPixmap(":/image/xunhuan/列表循环.png")),"列表播放");       //显示图标和播放模式
    ui->ModeComboBox->addItem(QIcon(QPixmap(":/image/xunhuan/随机播放.png")),"随机播放");       //显示图标和播放模式

    //QLisrWidget示例,播放列表显示控件（listwidget）歌曲内容显示,方法１
#if 0//
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText("周传雄 - 黄昏.mp3");                       //显示歌名
    newItem->setIcon(QIcon(QPixmap(":/image/音乐图标-32.png")));//显示歌曲小图片
    ui->SongListWidget->insertItem(0,newItem);                  //加入播放列表显示控件里面

    QListWidgetItem *newItem1 = new QListWidgetItem;
    newItem1->setText("Twins - 下一站天后.mp3"); //显示歌名
    newItem1->setIcon(QIcon(QPixmap(":/image/音乐图标-32.png")));//显示歌曲小图片
    ui->SongListWidget->insertItem(0,newItem1);//加入播放列表显示控件里面

    QListWidgetItem *newItem2 = new QListWidgetItem;
    newItem2->setText("许嵩 - 清明雨上.mp3");
    newItem2->setIcon(QIcon(QPixmap(":/image/音乐图标-32.png")));
    ui->SongListWidget->insertItem(0,newItem2);

    QListWidgetItem *newItem3 = new QListWidgetItem;
    newItem3->setText("张韶涵 - 欧若拉 (Live).mp3");
    newItem3->setIcon(QIcon(QPixmap(":/image/音乐图标-32.png")));
    ui->SongListWidget->insertItem(0,newItem3);

    QListWidgetItem *newItem4 = new QListWidgetItem;
    newItem4->setText("周传雄 - 黄昏.mp3");
    newItem4->setIcon(QIcon(QPixmap(":/image/音乐图标-32.png")));
    ui->SongListWidget->insertItem(0,newItem4);

    QListWidgetItem *newItem5 = new QListWidgetItem;
    newItem5->setText("许嵩 - 玫瑰花的葬礼.mp3");
    newItem5->setIcon(QIcon(QPixmap(":/image/音乐图标-32.png")));
    ui->SongListWidget->insertItem(0,newItem5);
#endif
//    QIcon scanIcon(QPixmap(":/music/resource/player/player_icon/open.png"));
//    QIcon palyIcon(QPixmap(":/music/resource/player/player_icon/list.png"));
//    QIcon sequenceIcon(QPixmap(":/music/resource/player/player_icon/列表循环.png"));
//    QIcon onceIcon(QPixmap(":/music/resource/player/player_icon/单曲循环.png"));
//    QIcon rangeIcon(QPixmap(":/music/resource/player/player_icon/随机播放.png"));
//    QIcon onceSignle(QPixmap(":/music/resource/player/player_icon/单曲一次.png"));
//    QIcon stepPlay(QPixmap(":/music/resource/player/player_icon/顺序播放.png"));
//    ui->playModelCbox->addItem(stepPlay,"顺序播放");
//    ui->playModelCbox->addItem(onceSignle,"单曲一次");
//    ui->playModelCbox->addItem(onceIcon,"单曲循环");
//    ui->playModelCbox->addItem(sequenceIcon,"循环播放");
//    ui->playModelCbox->addItem(rangeIcon,"随机播放");
    //音量滑条的范围 40~100 声音的范围(测试 40 以上有声音)
//    ui->volumeSlider->setRange(0,100);
//    //设置音量滑条的初始值为 70
    //    ui->volumeSlider->setValue(50);
}

/*********播放初始化*************/
void Widget::playerInit()
{
    playerProcess = new QProcess(this);
    connect(playerProcess,SIGNAL(error(QProcess::ProcessError)),this,SLOT(doProcessErrorSlot(QProcess::ProcessError)));
    //读取所有输出
    //    connect(playerProcess,SIGNAL(readyRead()),this,SLOT(doProcessReadyReadSlot()));
    //读取标准输出
    connect(playerProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(doProcessReadStandardOutputSlot()));
    playStat = false;   //false：正在播放;歌曲播放状态
    playBtnStat = false;//false：正在播放;播放按钮控件的状态，功能:变换图标

    //播放结束信号
    connect(playerProcess,SIGNAL(finished(int)),this,SLOT(doProcessFinished(int )));

    //创建定时器－－定时器的主要功能，就是用于定时获取当前播放歌曲的时间，然后进行转换为当前的播放时
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(doTimeoutSlot()));

    playmode = ListPlay;    //等于顺序播放

}

/***************************************音乐播放函数********************************************/
void Widget::playMusic()
{
    playerProcess->close();//清除
    //当播放按钮按下，就触发播放动图跳动
    movie = new QMovie("/home/ljt/work/QT-projet/qt_music_GUI/qt_music/image/音乐小人街舞.gif");  //显示gif，需要写全部的地址
    ui->BeiJinSong->setMovie(movie);    //把歌曲移到（BeiJinSong）控件上面显示
    movie->start(); //启动

    movie1 = new QMovie("/home/ljt/work/QT-projet/qt_music_GUI/qt_music/image/音乐音节跳动.gif");  //显示gif
    ui->label_5->setMovie(movie1);  //把歌曲移到（label_5）控件上面显示
    movie1->start();    //启动

    //播放音乐歌曲
    QString program = "/usr/bin/mplayer";   //需要执行的命令，就是mplayer的地址
    QStringList arguments;
    arguments.clear();  //先清除
    arguments << "-slave" << "-quiet";  //命令带的参数
    //方式１
//    arguments << "/home/ljt/work/QT-projet/qt_music_GUI/qt_music/Ｍusic/许嵩 - 清明雨上.mp3";//播放的歌曲需要路径，这种方式是播放固定的歌曲
    //方式2
    arguments <<playListString.at(playIndex);//播放的歌曲需要路径，当at(0)时就是播放第一首，这是第二种方法;(playIndex)为全局变量在.h定义了。

    playerProcess->start(program,arguments); //启动进程

    //开始播放时的音量大小
    playerProcess->write("volume 80 1");
    ui->horizontalSlider_2->setVisible(80);

    playStat = true;//播放完，就重新赋值，true：停止播放状态
    playerProcess->write("pause\n");//暂停播放
    ui->PlayPauseBtn->setStyleSheet("border-image: url(:/image/暂停1.png);"); //显示暂停状态图标

    showCurPlaySongName();//显示当前正在播放的歌曲的名字

    playerProcess->write("get_time_length\n");//发送获取的歌曲总时长的命令
    timer->start(200);                        //启动定时器，发送获取当前播放时间命令

//            movie ->stop();//歌曲播放结束，然后就停止播放GIF动图
//            movie1 ->stop();//歌曲播放结束，然后就停止播放GIF动图


}


/****************************显示当前正在播放的歌曲的名字********************************************/
void Widget::showCurPlaySongName()
{
    QString songName="正在播放:" + ui->SongListWidget->item(playIndex)->text();//获取播放列表里面的歌曲名
    ui->CurPlaySongname->setText(songName);
}
/**************************************加载已经保存的歌曲*********************************************/
void Widget::loaPlayListSong()
{

}

/**************************************扫描歌曲然后歌曲显示在播放列表*********************************************/
void Widget::on_ScanSongBtn_clicked()
{

    //获取音乐文件的路径
    QString fiLeNameDir = QFileDialog::getExistingDirectory(this,"选择音乐文件","/home/ljt/work/QT-projet/qt_music_GUI/qt_music/Ｍusic");
    if(fiLeNameDir.isEmpty())   //获取失败如果为空，就返回空
    {
        return;
    }
    qDebug() << fiLeNameDir;    //用qDebug()函数调试输出(fiLeNameDir)歌曲存放的路径

     QDir dir(fiLeNameDir);     //定义一个（QDir）目录的变量存放歌曲路径
     QStringList formatList;
     formatList << "*.mp3" << "*.mp4" << "*.wma";   //获取后缀名.mp3 .mp4这些的文件

     infoList = dir.entryInfoList(formatList);
     if(infoList.isEmpty())
    {
        return;
    }
    //显示列表显示歌名的时候，前面加显示图标，显示图标的位置
    QIcon musicMap(QPixmap(":/image/音乐图标-32.png")); //显示音乐的小图标
    for(int i = 0; i < infoList.count(); i++)
    {
       playListString << infoList[i].filePath();    //播放的列表
       QListWidgetItem  *songNAmeList = new QListWidgetItem(musicMap,infoList[i].fileName());
       songNAmeList->setSizeHint(QSize(400,40));
       ui->SongListWidget->addItem(songNAmeList);   //显示在播放列表控件（SongListWidget）上面
    }
    ui->SongListWidget->setCurrentRow(0);           //从第一行开始显示
}

/*
**有个bug，就是如果播放列表没有歌曲，点击播放控件就会退出，bug还没修复好
**修复步骤：可以在点击之前先扫描获取一下播放列表有没有歌曲，如果没有就弹出
**一个music error 提示
*/
/*************************************播放歌曲控件，用进程播放歌曲**************************************/
void Widget::on_PlayPauseBtn_clicked()
{
    if(playBtnStat == false){   //如果播放按钮按下状态为false：正在播放，就调用一次;这个是按钮的状态
        if(playStat == false){  //如果按下歌曲播放状态为false：正在播放，就调用一次;这个是音乐播放的状态
            playMusic();        //音乐播放函数
        }else{                  //否则playStat为true，就停止播放，就显示播放按钮的图标为播放
            timer->start();     //开启定时器，播放时间和播放进度条继续动
            movie->start();     //歌曲播放时就启动播放第一个GIF动图
            movie1->start();    //歌曲播放时就启动播放第二个GIF动图
            playerProcess->write("pause\n");//继续播放音乐
            ui->PlayPauseBtn->setStyleSheet("border-image: url(:/image/播放.png);");//显示播放图标
        }

    }else{  //如果播放按钮按下不为false：正在播放;就为true暂停播放
        timer->stop();  //停止定时器，播放时间和播放进度条暂停运作
        movie->stop();  //歌曲播放暂停，然后就停止播放第一个GIF动图
        movie1->stop(); //歌曲播放暂停，然后就停止播放第二个GIF动图
        playerProcess->write("pause\n");//暂停播放音乐
        ui->PlayPauseBtn->setStyleSheet("border-image: url(:/image/暂停1.png);"); //显示暂停状态图标
    }

    playBtnStat = !playBtnStat;//取反，结果不是false（正在播放），就是true（暂停播放）
}

void Widget::doProcessErrorSlot(QProcess::ProcessError error)
{
    qDebug() << error;  //测试，输出error（错误）
}

/*********************声音存在一个bug，咋个bug就是音量要在百分之四十以上才可以听到*****************/
/***************************设置音量进度条控件（playerProcess）的音量大小**********************/
void Widget::on_horizontalSlider_2_sliderMoved(int position)    //滑动模式
{
    //设置音量，命令　volume 100 1
    QString cmd=QString("volume %1 1\n").arg(position); //cmd为系统的cmd编译命令
    //qDebug()<<cmd;
    playerProcess->write(cmd.toLatin1().data());    //写入cmd转换成(char *)后的数据到音量进度条控件
}

/*****************************************************************************************************
*                           上一首控件(PrveBtn)
*功能:可以达到重复一直按上一首，等上一首到第一行的时候再按上一首就会跳到最后一行
******************************************************************************************************/
void Widget::on_PrveBtn_clicked()
{
    int songCounts1 = ui->SongListWidget->count();//songCounts1:这个是播放列表中歌曲的所有行数
    if( (playIndex > 0)&&(playIndex<songCounts1))
    {
        playIndex--;//播放列表中播放歌曲索引,注意：playIndex这个是从0开始计数
        playMusic();//播放函数
        ui->SongListWidget->setCurrentRow(playIndex);//往播放列表添加行的显示，当上一首时光标也跟在移动到上一首
    }
    else
        //if(playIndex <= 0)//如果播放列表中播放歌曲索引大于播放列表总行数
    {
        playIndex = songCounts1 - 1;//播放列表中播放歌曲索引赋值为songCounts1,然后从最后一行重新开始
        playMusic();//播放函数
        ui->SongListWidget->setCurrentRow(playIndex);//往播放列表添加行的显示，当上一首时光标也跟在移动到上一首
    }

    movie->start();     //歌曲播放时就启动播放第一个GIF动图
    movie1->start();    //歌曲播放时就启动播放第二个GIF动图

    playerProcess->write("pause\n");//继续播放音乐
    ui->PlayPauseBtn->setStyleSheet("border-image: url(:/image/播放.png);");//显示播放图标
    qDebug()<<"songCounts1=" <<songCounts1;
}
/***************************************************************************************************
*                            下一首控件(NetxBtn)
*功能:可以达到重复一直按下一首，等下一首到最后一行的时候再按下一首就会跳到第一行
****************************************************************************************************/
void Widget::on_NetxBtn_clicked()
{
  int songCounts = ui->SongListWidget->count();//songCounts1:这个是播放列表中歌曲的所有行数

  if(playIndex<songCounts-1)//如果播放列表中播放歌曲索引小于播放列表总行数
  {
      if(playmode == ListPlay){//如果(playmode)播放模式等于(ListPlay)顺序播放，就按照播放列表依次播放


          playMusic();//播放函数
          ui->SongListWidget->setCurrentRow(playIndex);//往播放列表添加行的显示，当下一首时光标也跟在移动到下一首
          playIndex++;//播放列表中播放歌曲索引,注意：playIndex这个是从0开始计数，所以上面判断需要减1,不然会超出范围会造成死机退出
      }else if(playmode == RandomPlay){//否则，如果(playmode)播放模式等于(RandomPlay)随机播放，就按照随机数播放

          QDateTime now = QDateTime::currentDateTime();
          QDateTime xmas(QDate(now.date().year(),12,25),QTime(0,0));
          //获取一个随机数
          qsrand(now.secsTo(xmas));
          playIndex = qrand() % songCounts;
          playMusic();//播放函数
          ui->SongListWidget->setCurrentRow(playIndex);//往播放列表添加行的显示，当下一首随机数时光标也跟在移动到下一首随机数
      }else if(playmode == SingleSongLoop){//否则，如果(playmode)播放模式等于(SingleSongLoop)单曲循环播放，就按照单曲一直循环播放              

              playIndex = playIndex;//当前播放歌曲索引等于当前播放歌曲索引，达到重复播放当前歌曲
              playMusic();//播放函数
              ui->SongListWidget->setCurrentRow(playIndex);//往播放列表添加行的显示，当下一首时光标也跟在移动到下一首,不操作时就一直播放这一首。

      }else if(playmode == SingleSongOnce){//否则，如果(playmode)播放模式等于(SingleSongOnce)单曲一次播放，就按照播放一次

              playMusic();//播放函数
              ui->SongListWidget->setCurrentRow(playIndex);//往播放列表添加行的显示，当下一首时光标也跟在移动到下一首,播放一次。
              //点击播放的时候，可以继续以当前的内容进行播放
              playStat = false;
              playerProcess->close();//结束进程，然后歌曲结束播放，原因：使用进程播放歌曲所以要结束进程达到结束全部播放

      }else if(playmode == PlayListLoop){//否则，如果(playmode)播放模式等于(PlayListLoop)列表循环播放，就按照列表播放一直循环

          if(playIndex==songCounts)
          {
              playIndex = 0;
          }
          if(playIndex<songCounts)
          {
              playMusic();//播放函数
              ui->SongListWidget->setCurrentRow(playIndex);//往播放列表添加行的显示，当下一首时光标也跟在移动到下一首,播放一次。
              playIndex++;
          }

      }

  }
  else
      //if(playIndex == songCounts)//如果播放列表中播放歌曲索引大于播放列表总行数
  {
      playIndex=0;//播放列表中播放歌曲索引赋值为0,然后从第一行重新开始
      playMusic();//播放函数
      ui->SongListWidget->setCurrentRow(playIndex);//往播放列表添加行的显示，当下一首时光标也跟在移动到下一首
  }

  movie->start();     //歌曲播放时就启动播放第一个GIF动图
  movie1->start();    //歌曲播放时就启动播放第二个GIF动图

  playerProcess->write("pause\n");//继续播放音乐
  ui->PlayPauseBtn->setStyleSheet("border-image: url(:/image/播放.png);");//显示播放图标
}

/***********************播放列表控件（SongListWidget）********************************/
/****************功能：选中播放列表的歌单，然后点击播放控件，就可以播放该歌曲;单击****************/
void Widget::on_SongListWidget_currentRowChanged(int currentRow)
{
    playIndex = currentRow; //播放列表的歌单（currentRow）赋值给当前播放歌曲索引（playIndex）
    playStat = false;   //false：正在播放;歌曲的状态
     playBtnStat = false; //播放按钮状态false：正在播放
}
/***********************功能：播放列表的双击播放*******************************/
void Widget::on_SongListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    playMusic();//播放函数
    playBtnStat = true; //播放按钮状态为停止播放
}

/************************************显示列表控件****************************************/
void Widget::on_ShowListBtn_clicked()
{
    showSongList = !showSongList;
    if(showSongList == false)
    {
        ui->SongListWidget->hide();
    }
    else
    {
        ui->SongListWidget->show();
    }
}

/************设置播放的时间变化和获取歌曲总时间****************************　****************/
/************进程有数据可读******************/
void Widget::doProcessReadyReadSlot()
{
    QByteArray readBuf = playerProcess->readAll();//数据可读
    QString str=QString(readBuf);

}
void Widget::doProcessReadStandardOutputSlot()
{
    QByteArray readBuf = playerProcess->readAll();//数据可读
    QString str=QString(readBuf);
    //获取播放总时间
    if(str.contains("ANS_LENGTH"))//在str里面寻找是否有ANS_LENGTH
    {
        //获取时间总长度
        str.remove("\n");  //删除字符串里面的\n
        str.remove("\r");  //删除字符串里面的\r
        str.remove("ANS_LENGTH="); //删除字符串里面的ANS_LENGTH=
        //qDebug() << "str = " << str;
        int t = str.toDouble();
        int m = t / 60; //得到分
        int s = t % 60; //得到秒
        tlength = m * 60 + s;
        //qDebug() << "tlength" << tlength;
        //设置播放器进度条的总数值
        ui->ProgresshorizontalSlider->setMinimum(0);
        ui->ProgresshorizontalSlider->setMaximum(tlength);
        ui->ProgresshorizontalSlider->setSingleStep(1);
        //QString timeLength;
        timeLength.sprintf("%02d:%02d",m,s);
        ui->CurPlaySongtime_2->setText(timeLength);//右边总时间显示
    }
    //获取当前播放时间
    if(str.contains("ANS_TIME_POSITION"))//在str里面寻找是否有ANS_TIME_POSITION
    {
        //获取时间总长度
        str.remove("\n");  //删除字符串里面的\n
        str.remove("\r");  //删除字符串里面的\r
        double t = QString(str.split("=").at(1)).toDouble();
        int m=t/60;
        int s=(int)(t+0.5)%60;  //四舍五入，防止少时间
        //QString timePos;
        timePos.sprintf("%02d:%02d",m,s);
        ui->CurPlaySongtime->setText(timePos);  //左边当前时间显示
        int now = (m * 60 + s);
        //double slider=now*100/tlength;
        //设置播放进度条当前滑条的值
        ui->ProgresshorizontalSlider->setValue(now);


    }
    if(timePos == timeLength){//如果当前播放时间timePos等于歌曲总时间timeLength就执行下面语句
        movie ->stop();//歌曲播放结束，然后就停止播放GIF动图
        movie1 ->stop();//歌曲播放结束，然后就停止播放GIF动图
    }
}

/**************************************************************************
 *                  播放结束信号
 * 功能：获取到播放结束信号，结束之后就自动跳到下一首播放，每次播放的时候都会先判断是否符合
 *      下面的播放模式条件
***************************************************************************/
void Widget::doProcessFinished(int f)
{
    //一进来就关闭定时器
    timer->stop();//定时器关闭
    playStat = false;
    //更新播放暂停按钮的状态
    switch(playBtnStat)
    {
        case true:
            ui->PlayPauseBtn->setStyleSheet("border-image: url(:/image/暂停1.png);");
             break;
        case false:
            ui->PlayPauseBtn->setStyleSheet("border-image: url(:/image/播放.png);");
        break;
    }

    if(ui->ProgresshorizontalSlider->value() != ui->ProgresshorizontalSlider->maximum())
    {
        return;//返回空
    }
    //如果if语句不成立，则说明，一首歌曲播放完成，而不是播放到一半点击下一首
    //qDebug()<<"一首歌曲播放完成.....";
    switch(playmode)//播放模式
    {
     case ListPlay://顺序播放
        if(playIndex == playListString.count()-1)
        {
            ui->ProgresshorizontalSlider->setValue(0);
            playBtnStat = false;
            ui->CurPlaySongname->setText("无歌曲");
            //当前时间和总时间清零
            ui->CurPlaySongtime->setText("00:00");
            ui->CurPlaySongtime_2->setText("00:00");
            //如果点击播放，默认播放第一首歌曲
            playIndex = 0;
            //设置播放列表中当前光标显示为第几行播放，相当于显示那首歌在播放
            ui->SongListWidget->setCurrentRow(playIndex);
            return;
        }
        playIndex++;//播放索引++，相当于下一首，就是把playIndex的值传给播放函数
        playMusic();//播放歌曲函数
        //设置播放列表中当前光标显示为第几行播放，相当于显示那首歌在播放
        ui->SongListWidget->setCurrentRow(playIndex);
        break;//播放到最后一首完成就结束播放

    case SingleSongOnce://单曲一次
         //播放当前播放的内容，播放完成就结束播放
         ui->ProgresshorizontalSlider->setValue(0);
         ui->CurPlaySongname->setText("无歌曲");
         //当前时间和总时间清零
         ui->CurPlaySongtime->setText("00:00");
         ui->CurPlaySongtime_2->setText("00:00");
         //点击播放的时候，可以继续以当前的内容进行播放
         playStat = false;
         playerProcess->close();//结束进程，然后歌曲结束播放，原因：使用进程播放歌曲所以要结束进程达到结束全部播放
         return;//结束

    case SingleSongLoop://单曲循环
         //播放当前播放的内容，播放完成就结束播放
         ui->ProgresshorizontalSlider->setValue(0);
         ui->CurPlaySongname->setText("无歌曲");
         //当前时间和总时间清零
         ui->CurPlaySongtime->setText("00:00");
         ui->CurPlaySongtime_2->setText("00:00");
         playIndex = playIndex;
         playMusic();//播放歌曲函数
         break;

    case PlayListLoop://列表播放;又叫循环播放
        //播放当前播放的内容，播放完成就结束播放
        ui->ProgresshorizontalSlider->setValue(0);
        ui->CurPlaySongname->setText("无歌曲");
        //当前时间和总时间清零
        ui->CurPlaySongtime->setText("00:00");
        ui->CurPlaySongtime_2->setText("00:00");
         if(playIndex == playListString.count()-1)//如果当前播放歌曲索引等等于播放列表里面所有歌曲的最后一首时，减１是因为当前播放歌曲索引是从0开始计数
         {
             playIndex = 0;//就把当前播放歌曲索引赋值为０，然后从第一首歌重新开始播放
         }
         //设置播放列表中当前光标显示为第几行播放，相当于显示那首歌在播放
         ui->SongListWidget->setCurrentRow(playIndex);
         playMusic();//播放歌曲函数
         playIndex++;//当前播放歌曲索引++
         break;//结束本次的条件

    case RandomPlay://随机播放

         //播放当前播放的内容，播放完成就结束播放
         ui->ProgresshorizontalSlider->setValue(0);
         ui->CurPlaySongname->setText("无歌曲");
         //当前时间和总时间清零
         ui->CurPlaySongtime->setText("00:00");
         ui->CurPlaySongtime_2->setText("00:00");
         qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));//获取时间因子
         playIndex = qrand() % (playListString.count()-1);  //求于播放列表的歌曲总行数，也就是相当于歌曲的数量
         playMusic();//播放函数
         //设置播放列表中当前光标显示为第几行播放，相当于显示那首歌在播放
         ui->SongListWidget->setCurrentRow(playIndex);
         break;//结束本次循环或者是结束本次的语句，跳出判断

    }
}

/*****************************************************定时器*******************************************************/
void Widget::doTimeoutSlot()
{
    //获取当前播放的位置，以秒为单位
    playerProcess->write("get_time_pos\n");//“get_time_pos”是获取播放的百分比命令，注意：写入命令以字符串的形式写入时后面必须跟“\n”

}

/************************播放进度条控件(ProgresshorizontalSlider)***********************/
//设置播放进度条当前滑条拖动的槽,功能：实现滑动播放进度条控件(ProgresshorizontalSlider)加快播放
void Widget::on_ProgresshorizontalSlider_sliderMoved(int position)
{
    timer->stop();
    moveSliderVal= position;
}
//设置播放进度条当前滑条松开的槽,功能：实现滑动播放进度条控件(ProgresshorizontalSlider)松开后就播放
void Widget::on_ProgresshorizontalSlider_sliderReleased()
{
    int per = moveSliderVal * 100 / tlength;//定义一个变量存放
    //注意：写入命令以字符串的形式写入时后面必须跟“\n”
    QString cmd = QString("seek %1 1\n").arg(per);//"seek %1 1"是设置进度条命令，％１是设置进度条的大小　%1-%100;
    playerProcess->write(cmd.toLatin1().data());//转成char *型的数据
    timer->start();
}

/**********************播放模式控件，有五种比如：顺序播放等**************************************/
void Widget::on_ModeComboBox_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            //顺序播放
            playmode = ListPlay;break;
        case 1:
            //单曲一次
            playmode = SingleSongOnce;break;
        case 2:
            //单曲循环
            playmode = SingleSongLoop;break;
        case 3:
            //列表播放
            playmode = PlayListLoop;break;
        case 4:
            //随机播放
            playmode = RandomPlay;break;
    }
}

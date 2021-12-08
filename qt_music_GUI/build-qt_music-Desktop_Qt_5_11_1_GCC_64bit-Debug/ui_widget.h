/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_5;
    QLabel *BeiJinSong;
    QListWidget *SongListWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *CurPlaySongname;
    QSlider *ProgresshorizontalSlider;
    QHBoxLayout *horizontalLayout_5;
    QLabel *CurPlaySongtime;
    QSpacerItem *horizontalSpacer_6;
    QLabel *CurPlaySongtime_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *PrveBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *PlayPauseBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *NetxBtn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Voice;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *ModeComboBox;
    QPushButton *ScanSongBtn;
    QPushButton *ShowListBtn;
    QPushButton *BackBtn;
    QPushButton *QuitBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1024, 600);
        Widget->setMinimumSize(QSize(1024, 600));
        Widget->setMaximumSize(QSize(1024, 600));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 190, 520, 180));
        label_5->setMinimumSize(QSize(200, 180));
        label_5->setMaximumSize(QSize(16777215, 130));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\237\263\344\271\220\351\237\263\350\212\202\350\267\263\345\212\250.gif);"));
        BeiJinSong = new QLabel(Widget);
        BeiJinSong->setObjectName(QStringLiteral("BeiJinSong"));
        BeiJinSong->setGeometry(QRect(0, 0, 520, 180));
        BeiJinSong->setMinimumSize(QSize(200, 180));
        BeiJinSong->setMaximumSize(QSize(16777215, 180));
        BeiJinSong->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\351\237\263\344\271\220\345\260\217\344\272\272\350\241\227\350\210\236.gif);"));
        SongListWidget = new QListWidget(Widget);
        SongListWidget->setObjectName(QStringLiteral("SongListWidget"));
        SongListWidget->setEnabled(true);
        SongListWidget->setGeometry(QRect(520, 0, 501, 380));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SongListWidget->sizePolicy().hasHeightForWidth());
        SongListWidget->setSizePolicy(sizePolicy);
        SongListWidget->setMinimumSize(QSize(0, 380));
        SongListWidget->setMaximumSize(QSize(600, 350));
        SongListWidget->setSizeIncrement(QSize(200, 350));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 380, 1021, 221));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        CurPlaySongname = new QLabel(layoutWidget);
        CurPlaySongname->setObjectName(QStringLiteral("CurPlaySongname"));

        verticalLayout_3->addWidget(CurPlaySongname);

        ProgresshorizontalSlider = new QSlider(layoutWidget);
        ProgresshorizontalSlider->setObjectName(QStringLiteral("ProgresshorizontalSlider"));
        ProgresshorizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(ProgresshorizontalSlider);


        verticalLayout->addLayout(verticalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        CurPlaySongtime = new QLabel(layoutWidget);
        CurPlaySongtime->setObjectName(QStringLiteral("CurPlaySongtime"));

        horizontalLayout_5->addWidget(CurPlaySongtime);

        horizontalSpacer_6 = new QSpacerItem(55, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        CurPlaySongtime_2 = new QLabel(layoutWidget);
        CurPlaySongtime_2->setObjectName(QStringLiteral("CurPlaySongtime_2"));

        horizontalLayout_5->addWidget(CurPlaySongtime_2);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PrveBtn = new QPushButton(layoutWidget);
        PrveBtn->setObjectName(QStringLiteral("PrveBtn"));
        PrveBtn->setMinimumSize(QSize(60, 60));
        PrveBtn->setMaximumSize(QSize(60, 60));
        PrveBtn->setSizeIncrement(QSize(60, 60));
        PrveBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\344\270\212\344\270\200\351\246\2263.png);"));

        horizontalLayout->addWidget(PrveBtn);

        horizontalSpacer_2 = new QSpacerItem(28, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        PlayPauseBtn = new QPushButton(layoutWidget);
        PlayPauseBtn->setObjectName(QStringLiteral("PlayPauseBtn"));
        PlayPauseBtn->setMinimumSize(QSize(60, 60));
        PlayPauseBtn->setMaximumSize(QSize(60, 60));
        PlayPauseBtn->setSizeIncrement(QSize(60, 60));
        PlayPauseBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\346\232\202\345\201\2341.png);"));

        horizontalLayout->addWidget(PlayPauseBtn);

        horizontalSpacer_3 = new QSpacerItem(18, 54, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        NetxBtn = new QPushButton(layoutWidget);
        NetxBtn->setObjectName(QStringLiteral("NetxBtn"));
        NetxBtn->setMinimumSize(QSize(60, 60));
        NetxBtn->setMaximumSize(QSize(60, 60));
        NetxBtn->setSizeIncrement(QSize(60, 60));
        NetxBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\344\270\213\344\270\200\351\246\2263.png);"));

        horizontalLayout->addWidget(NetxBtn);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(58, 53, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Voice = new QPushButton(layoutWidget);
        Voice->setObjectName(QStringLiteral("Voice"));
        Voice->setMinimumSize(QSize(40, 40));
        Voice->setMaximumSize(QSize(40, 40));
        Voice->setSizeIncrement(QSize(40, 40));
        Voice->setStyleSheet(QString::fromUtf8("border-image: url(:/image/\345\243\260\351\237\2632.png);"));

        horizontalLayout_3->addWidget(Voice);

        horizontalSlider_2 = new QSlider(layoutWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ModeComboBox = new QComboBox(layoutWidget);
        ModeComboBox->setObjectName(QStringLiteral("ModeComboBox"));
        ModeComboBox->setMinimumSize(QSize(0, 60));
        ModeComboBox->setMaximumSize(QSize(16777215, 60));
        ModeComboBox->setSizeIncrement(QSize(0, 0));

        horizontalLayout_2->addWidget(ModeComboBox);

        ScanSongBtn = new QPushButton(layoutWidget);
        ScanSongBtn->setObjectName(QStringLiteral("ScanSongBtn"));
        ScanSongBtn->setMinimumSize(QSize(0, 60));
        ScanSongBtn->setMaximumSize(QSize(16777215, 60));
        ScanSongBtn->setSizeIncrement(QSize(0, 0));
        ScanSongBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(ScanSongBtn);

        ShowListBtn = new QPushButton(layoutWidget);
        ShowListBtn->setObjectName(QStringLiteral("ShowListBtn"));
        ShowListBtn->setMinimumSize(QSize(0, 60));
        ShowListBtn->setMaximumSize(QSize(16777215, 60));
        ShowListBtn->setSizeIncrement(QSize(0, 0));
        ShowListBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(ShowListBtn);

        BackBtn = new QPushButton(layoutWidget);
        BackBtn->setObjectName(QStringLiteral("BackBtn"));
        BackBtn->setMinimumSize(QSize(0, 60));
        BackBtn->setMaximumSize(QSize(16777215, 60));
        BackBtn->setSizeIncrement(QSize(0, 0));

        horizontalLayout_2->addWidget(BackBtn);

        QuitBtn = new QPushButton(layoutWidget);
        QuitBtn->setObjectName(QStringLiteral("QuitBtn"));
        QuitBtn->setMinimumSize(QSize(0, 60));
        QuitBtn->setMaximumSize(QSize(16777215, 60));
        QuitBtn->setSizeIncrement(QSize(0, 0));
        QuitBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(QuitBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label_5->setText(QString());
        BeiJinSong->setText(QString());
        CurPlaySongname->setText(QApplication::translate("Widget", "\346\227\240\346\255\214\346\233\262", nullptr));
        CurPlaySongtime->setText(QApplication::translate("Widget", "00:00", nullptr));
        CurPlaySongtime_2->setText(QApplication::translate("Widget", "00:00", nullptr));
        PrveBtn->setText(QString());
        PlayPauseBtn->setText(QString());
        NetxBtn->setText(QString());
        Voice->setText(QString());
        ScanSongBtn->setText(QApplication::translate("Widget", "\346\211\253\346\217\217\346\255\214\346\233\262", nullptr));
        ShowListBtn->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\345\210\227\350\241\250", nullptr));
        BackBtn->setText(QApplication::translate("Widget", "\350\277\224\345\233\236", nullptr));
        QuitBtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

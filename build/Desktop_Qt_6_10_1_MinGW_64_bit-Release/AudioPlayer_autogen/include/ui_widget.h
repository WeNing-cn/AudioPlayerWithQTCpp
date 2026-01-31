/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *ALL;
    QWidget *INF;
    QHBoxLayout *Infor;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QCheckBox *RandomPlay;
    QPushButton *FullScreen;
    QWidget *VideoBox;
    QVBoxLayout *verticalLayout;
    QVideoWidget *videoWidget;
    QWidget *PRO;
    QHBoxLayout *Pro;
    QHBoxLayout *ProgressControler;
    QLabel *Progess;
    QSlider *ProgressSilder;
    QLabel *label;
    QLabel *Sound;
    QSlider *SoundSilder;
    QLabel *label_2;
    QWidget *BASIC;
    QHBoxLayout *Bas;
    QHBoxLayout *BasicController;
    QPushButton *Front;
    QPushButton *StartStop;
    QPushButton *Next;
    QSpacerItem *horizontalSpacer;
    QComboBox *Speed;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(398, 136);
        ALL = new QVBoxLayout(Widget);
        ALL->setObjectName("ALL");
        INF = new QWidget(Widget);
        INF->setObjectName("INF");
        INF->setMaximumSize(QSize(16777215, 35));
        Infor = new QHBoxLayout(INF);
        Infor->setObjectName("Infor");
        label_3 = new QLabel(INF);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));

        Infor->addWidget(label_3);

        label_5 = new QLabel(INF);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setMaximumSize(QSize(60, 16777215));

        Infor->addWidget(label_5);

        label_4 = new QLabel(INF);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setMaximumSize(QSize(80, 16777215));

        Infor->addWidget(label_4);

        label_6 = new QLabel(INF);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(30, 0));
        label_6->setMaximumSize(QSize(60, 16777215));

        Infor->addWidget(label_6);

        RandomPlay = new QCheckBox(INF);
        RandomPlay->setObjectName("RandomPlay");
        RandomPlay->setMaximumSize(QSize(70, 16777215));

        Infor->addWidget(RandomPlay);

        FullScreen = new QPushButton(INF);
        FullScreen->setObjectName("FullScreen");
        FullScreen->setMinimumSize(QSize(0, 20));
        FullScreen->setMaximumSize(QSize(16777215, 16777215));

        Infor->addWidget(FullScreen);


        ALL->addWidget(INF);

        VideoBox = new QWidget(Widget);
        VideoBox->setObjectName("VideoBox");
        verticalLayout = new QVBoxLayout(VideoBox);
        verticalLayout->setObjectName("verticalLayout");
        videoWidget = new QVideoWidget(VideoBox);
        videoWidget->setObjectName("videoWidget");
        videoWidget->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(videoWidget);


        ALL->addWidget(VideoBox);

        PRO = new QWidget(Widget);
        PRO->setObjectName("PRO");
        PRO->setMaximumSize(QSize(16777215, 30));
        Pro = new QHBoxLayout(PRO);
        Pro->setObjectName("Pro");
        ProgressControler = new QHBoxLayout();
        ProgressControler->setObjectName("ProgressControler");
        Progess = new QLabel(PRO);
        Progess->setObjectName("Progess");

        ProgressControler->addWidget(Progess);

        ProgressSilder = new QSlider(PRO);
        ProgressSilder->setObjectName("ProgressSilder");
        ProgressSilder->setOrientation(Qt::Orientation::Horizontal);

        ProgressControler->addWidget(ProgressSilder);

        label = new QLabel(PRO);
        label->setObjectName("label");

        ProgressControler->addWidget(label);

        Sound = new QLabel(PRO);
        Sound->setObjectName("Sound");

        ProgressControler->addWidget(Sound);

        SoundSilder = new QSlider(PRO);
        SoundSilder->setObjectName("SoundSilder");
        SoundSilder->setOrientation(Qt::Orientation::Horizontal);

        ProgressControler->addWidget(SoundSilder);

        label_2 = new QLabel(PRO);
        label_2->setObjectName("label_2");

        ProgressControler->addWidget(label_2);


        Pro->addLayout(ProgressControler);


        ALL->addWidget(PRO);

        BASIC = new QWidget(Widget);
        BASIC->setObjectName("BASIC");
        BASIC->setMaximumSize(QSize(16777215, 50));
        Bas = new QHBoxLayout(BASIC);
        Bas->setObjectName("Bas");
        BasicController = new QHBoxLayout();
        BasicController->setObjectName("BasicController");
        BasicController->setContentsMargins(10, 5, 10, 3);
        Front = new QPushButton(BASIC);
        Front->setObjectName("Front");
        Front->setMaximumSize(QSize(60, 16777215));

        BasicController->addWidget(Front);

        StartStop = new QPushButton(BASIC);
        StartStop->setObjectName("StartStop");
        StartStop->setMaximumSize(QSize(70, 200));

        BasicController->addWidget(StartStop);

        Next = new QPushButton(BASIC);
        Next->setObjectName("Next");
        Next->setMaximumSize(QSize(60, 16777215));

        BasicController->addWidget(Next);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        BasicController->addItem(horizontalSpacer);

        Speed = new QComboBox(BASIC);
        Speed->addItem(QString());
        Speed->addItem(QString());
        Speed->addItem(QString());
        Speed->addItem(QString());
        Speed->addItem(QString());
        Speed->addItem(QString());
        Speed->addItem(QString());
        Speed->addItem(QString());
        Speed->setObjectName("Speed");

        BasicController->addWidget(Speed);

        pushButton = new QPushButton(BASIC);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(150, 16777215));

        BasicController->addWidget(pushButton);


        Bas->addLayout(BasicController);


        ALL->addWidget(BASIC);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\351\237\263\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\222\255\346\224\276:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "example.mp3", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\222\255\346\224\276\350\267\257\345\276\204:", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "example/c/user/\351\237\263\344\271\220", nullptr));
        RandomPlay->setText(QCoreApplication::translate("Widget", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));
        FullScreen->setText(QCoreApplication::translate("Widget", "\345\205\250\345\261\217", nullptr));
        Progess->setText(QCoreApplication::translate("Widget", "  \350\277\233\345\272\246:", nullptr));
        label->setText(QCoreApplication::translate("Widget", "0/0", nullptr));
        Sound->setText(QCoreApplication::translate("Widget", "  \351\237\263\351\207\217:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "50 %", nullptr));
        Front->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
        StartStop->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
        Next->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", nullptr));
        Speed->setItemText(0, QCoreApplication::translate("Widget", "1x", nullptr));
        Speed->setItemText(1, QCoreApplication::translate("Widget", "1.25x", nullptr));
        Speed->setItemText(2, QCoreApplication::translate("Widget", "0.75x", nullptr));
        Speed->setItemText(3, QCoreApplication::translate("Widget", "1.50x", nullptr));
        Speed->setItemText(4, QCoreApplication::translate("Widget", "0.5x", nullptr));
        Speed->setItemText(5, QCoreApplication::translate("Widget", "1.75x", nullptr));
        Speed->setItemText(6, QCoreApplication::translate("Widget", "0.25x", nullptr));
        Speed->setItemText(7, QCoreApplication::translate("Widget", "2x", nullptr));

        pushButton->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\351\237\263\350\247\206\351\242\221\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

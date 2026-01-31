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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
    QWidget *layoutWidget;
    QVBoxLayout *ALL;
    QHBoxLayout *Infor;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *Pro;
    QHBoxLayout *ProgressControler;
    QLabel *Progess;
    QSlider *ProgressSilder;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *Sou;
    QHBoxLayout *SoundControler;
    QLabel *Sound;
    QSlider *SoundSilder;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *Bas;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *BasicController;
    QPushButton *Front;
    QPushButton *StartStop;
    QPushButton *Next;
    QPushButton *pushButton;
    QCheckBox *RandomPlay;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(412, 140);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 411, 138));
        ALL = new QVBoxLayout(layoutWidget);
        ALL->setObjectName("ALL");
        ALL->setContentsMargins(0, 0, 0, 0);
        Infor = new QHBoxLayout();
        Infor->setObjectName("Infor");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Infor->addItem(horizontalSpacer);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        Infor->addWidget(label_3);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        Infor->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Infor->addItem(horizontalSpacer_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        Infor->addWidget(label_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        Infor->addWidget(label_6);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Infor->addItem(horizontalSpacer_10);


        ALL->addLayout(Infor);

        Pro = new QHBoxLayout();
        Pro->setObjectName("Pro");
        ProgressControler = new QHBoxLayout();
        ProgressControler->setObjectName("ProgressControler");
        Progess = new QLabel(layoutWidget);
        Progess->setObjectName("Progess");

        ProgressControler->addWidget(Progess);

        ProgressSilder = new QSlider(layoutWidget);
        ProgressSilder->setObjectName("ProgressSilder");
        ProgressSilder->setMinimumSize(QSize(300, 0));
        ProgressSilder->setOrientation(Qt::Orientation::Horizontal);

        ProgressControler->addWidget(ProgressSilder);


        Pro->addLayout(ProgressControler);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Pro->addItem(horizontalSpacer_7);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        Pro->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Pro->addItem(horizontalSpacer_5);


        ALL->addLayout(Pro);

        Sou = new QHBoxLayout();
        Sou->setObjectName("Sou");
        SoundControler = new QHBoxLayout();
        SoundControler->setObjectName("SoundControler");
        SoundControler->setContentsMargins(0, -1, -1, -1);
        Sound = new QLabel(layoutWidget);
        Sound->setObjectName("Sound");

        SoundControler->addWidget(Sound);

        SoundSilder = new QSlider(layoutWidget);
        SoundSilder->setObjectName("SoundSilder");
        SoundSilder->setMinimumSize(QSize(300, 0));
        SoundSilder->setOrientation(Qt::Orientation::Horizontal);

        SoundControler->addWidget(SoundSilder);


        Sou->addLayout(SoundControler);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Sou->addItem(horizontalSpacer_8);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        Sou->addWidget(label_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Sou->addItem(horizontalSpacer_6);


        ALL->addLayout(Sou);

        Bas = new QHBoxLayout();
        Bas->setObjectName("Bas");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Bas->addItem(horizontalSpacer_3);

        BasicController = new QHBoxLayout();
        BasicController->setObjectName("BasicController");
        BasicController->setContentsMargins(10, 5, 10, 3);
        Front = new QPushButton(layoutWidget);
        Front->setObjectName("Front");
        Front->setMaximumSize(QSize(60, 16777215));

        BasicController->addWidget(Front);

        StartStop = new QPushButton(layoutWidget);
        StartStop->setObjectName("StartStop");
        StartStop->setMaximumSize(QSize(70, 200));

        BasicController->addWidget(StartStop);

        Next = new QPushButton(layoutWidget);
        Next->setObjectName("Next");
        Next->setMaximumSize(QSize(60, 16777215));

        BasicController->addWidget(Next);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(150, 16777215));

        BasicController->addWidget(pushButton);

        RandomPlay = new QCheckBox(layoutWidget);
        RandomPlay->setObjectName("RandomPlay");
        RandomPlay->setMaximumSize(QSize(70, 16777215));

        BasicController->addWidget(RandomPlay);


        Bas->addLayout(BasicController);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Bas->addItem(horizontalSpacer_4);


        ALL->addLayout(Bas);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\351\237\263\351\242\221\346\222\255\346\224\276\345\231\250", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\222\255\346\224\276:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "example.mp3", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\222\255\346\224\276\350\267\257\345\276\204:", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "example/c/user/\351\237\263\344\271\220", nullptr));
        Progess->setText(QCoreApplication::translate("Widget", "  \350\277\233\345\272\246:", nullptr));
        label->setText(QCoreApplication::translate("Widget", "0/0", nullptr));
        Sound->setText(QCoreApplication::translate("Widget", "  \351\237\263\351\207\217:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "50 %", nullptr));
        Front->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
        StartStop->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
        Next->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\351\237\263\351\242\221\346\226\207\344\273\266", nullptr));
        RandomPlay->setText(QCoreApplication::translate("Widget", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

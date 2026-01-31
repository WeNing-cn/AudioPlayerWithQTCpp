#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    
    // 检查命令行参数，打开指定的音频文件
    if (argc > 1) {
        QString filePath = QString::fromLocal8Bit(argv[1]);
        w.openFile(filePath);
    }
    
    w.show();
    return a.exec();
}

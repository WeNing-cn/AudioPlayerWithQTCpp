/**
 * 文件名：widget.h
 * 功能：音频播放器主界面对象定义
 * 创建时间：2026-01-31
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
class QMediaPlayer;
class QAudioOutput;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    /**
     * 构造函数
     * @param parent 父窗口指针
     */
    Widget(QWidget *parent = nullptr);
    
    /**
     * 析构函数
     */
    ~Widget();

private slots:
    /**
     * 选择音频文件按钮点击事件
     */
    void on_pushButton_clicked();
    
    /**
     * 进度条操作事件
     * @param action 操作类型
     */
    void on_ProgressSilder_actionTriggered(int action);
    
    /**
     * 音量条操作事件
     * @param action 操作类型
     */
    void on_SoundSilder_actionTriggered(int action);
    
    /**
     * 上一首按钮点击事件
     */
    void on_Front_clicked();
    
    /**
     * 播放/暂停按钮点击事件
     */
    void on_StartStop_clicked();
    
    /**
     * 下一首按钮点击事件
     */
    void on_Next_clicked();
    
    /**
     * 随机播放复选框状态改变事件
     * @param arg1 复选框状态
     */
    void on_RandomPlay_checkStateChanged(const Qt::CheckState &arg1);
    
    /**
     * 更新播放进度
     */
    void updateProgress();
    
    /**
     * 播放指定索引的音频文件
     * @param index 音频文件索引
     */
    void playAt(int index);
    
    /**
     * 播放下一首
     */
    void playNext();
    
    /**
     * 播放上一首
     */
    void playPrevious();

private:
    Ui::Widget *ui;              // UI界面指针
    QMediaPlayer *player;        // 媒体播放器指针
    QAudioOutput *audioOutput;    // 音频输出指针
    QStringList playlist;         // 播放列表
    int currentIndex;             // 当前播放索引
    int previousIndex;            // 上一首播放索引
    bool isRandomPlay;           // 是否随机播放
};
#endif // WIDGET_H

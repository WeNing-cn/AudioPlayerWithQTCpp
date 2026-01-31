/**
 * 文件名：widget.cpp
 * 功能：音频播放器主界面实现
 * 创建时间：2026-01-31
 */

#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDir>
#include <QTime>
#include <QDebug>
#include <QRandomGenerator>
#include <QSettings>
#include <QFile>
#include <QFileInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , player(new QMediaPlayer(this))
    , audioOutput(new QAudioOutput(this))
    , currentIndex(-1)
    , previousIndex(-1)
    , isRandomPlay(false)
    , lastOpenDir(QDir::homePath())
{
    ui->setupUi(this);
    
    // 设置音频输出
    player->setAudioOutput(audioOutput);
    
    // 设置进度条和音量条的范围
    ui->ProgressSilder->setRange(0, 100);
    ui->SoundSilder->setRange(0, 100);
    ui->SoundSilder->setValue(50); // 默认音量50%
    
    // 设置初始音量
    audioOutput->setVolume(0.5);
    
    // 连接信号和槽
    connect(player, &QMediaPlayer::positionChanged, this, &Widget::updateProgress);
    connect(player, &QMediaPlayer::durationChanged, this, [=](qint64 duration) {
        ui->ProgressSilder->setMaximum(duration);
    });
    connect(ui->ProgressSilder, &QSlider::sliderMoved, this, [=](int position) {
        player->setPosition(position);
    });
    connect(ui->SoundSilder, &QSlider::valueChanged, this, [=](int value) {
        audioOutput->setVolume(value / 100.0);
        ui->label_2->setText(QString("%1 %").arg(value));
    });
    connect(ui->SoundSilder, &QSlider::sliderMoved, this, [=](int value) {
        audioOutput->setVolume(value / 100.0);
        ui->label_2->setText(QString("%1 %").arg(value));
    });
    
    // 连接播放器状态变化信号，自动播放下一首
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia && playlist.size() > 0) {
            playNext();
        }
    });
    
    // 加载配置文件
    loadSettings();
}

Widget::~Widget()
{
    // 保存配置文件
    saveSettings();
    
    delete ui;
}

void Widget::openFile(const QString &filePath)
{
    // 检查文件是否存在
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists()) {
        return;
    }
    
    // 获取文件的绝对路径
    QString absoluteFilePath = fileInfo.absoluteFilePath();
    
    // 清空当前播放列表
    playlist.clear();
    
    // 获取文件所在目录
    QString dirPath = fileInfo.absolutePath();
    lastOpenDir = dirPath;
    
    // 支持的音频文件扩展名
    QStringList audioExtensions = {"*.mp3", "*.wav", "*.ogg", "*.flac"};
    
    // 扫描目录下的所有音频文件
    QDir dir(dirPath);
    for (const QString &extension : audioExtensions) {
        QStringList audioFiles = dir.entryList({extension}, QDir::Files);
        for (const QString &audioFile : audioFiles) {
            QString fullPath = dir.absoluteFilePath(audioFile);
            playlist.append(fullPath);
        }
    }
    
    // 重置索引
    currentIndex = -1;
    previousIndex = -1;
    
    // 如果播放列表不为空
    if (!playlist.isEmpty()) {
        // 查找该文件在播放列表中的索引
        int playIndex = -1;
        for (int i = 0; i < playlist.size(); ++i) {
            if (QFileInfo(playlist[i]).absoluteFilePath() == absoluteFilePath) {
                playIndex = i;
                break;
            }
        }
        
        // 如果找到该文件，则从该索引开始播放；否则播放第一首
        if (playIndex != -1) {
            playAt(playIndex);
        } else {
            // 如果找不到，尝试直接添加该文件到播放列表并播放
            playlist.append(absoluteFilePath);
            playAt(playlist.size() - 1);
        }
    }
}

void Widget::on_pushButton_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(
        this,                    // 父窗口
        tr("选择音频文件"),        // 对话框标题
        lastOpenDir,             // 初始目录
        tr("音频文件 (*.mp3 *.wav *.ogg *.flac);;所有文件 (*.*)"));  // 文件过滤器

    if (!fileNames.isEmpty()) {
        // 清空当前播放列表
        playlist.clear();
        
        // 存储已处理的目录，避免重复扫描
        QSet<QString> processedDirs;
        
        // 支持的音频文件扩展名
        QStringList audioExtensions = {"*.mp3", "*.wav", "*.ogg", "*.flac"};
        
        // 处理每个选择的文件
        for (const QString &fileName : fileNames) {
            // 获取文件所在目录
            QFileInfo fileInfo(fileName);
            QString dirPath = fileInfo.absolutePath();
            
            // 如果该目录尚未处理过
            if (!processedDirs.contains(dirPath)) {
                // 标记为已处理
                processedDirs.insert(dirPath);
                
                // 扫描目录下的所有音频文件
                QDir dir(dirPath);
                for (const QString &extension : audioExtensions) {
                    QStringList audioFiles = dir.entryList({extension}, QDir::Files);
                    for (const QString &audioFile : audioFiles) {
                        QString fullPath = dir.absoluteFilePath(audioFile);
                        playlist.append(fullPath);
                    }
                }
            }
        }
        
        // 重置索引
        currentIndex = -1;
        previousIndex = -1;
        
        // 如果播放列表不为空
        if (!playlist.isEmpty()) {
            // 获取用户选择的第一个文件的完整路径
            QString firstSelectedFile = fileNames.first();
            
            // 更新上次打开的目录路径
            QFileInfo fileInfo(firstSelectedFile);
            lastOpenDir = fileInfo.absolutePath();
            
            // 查找该文件在播放列表中的索引
            int playIndex = playlist.indexOf(firstSelectedFile);
            
            // 如果找到该文件，则从该索引开始播放；否则播放第一首
            if (playIndex != -1) {
                playAt(playIndex);
            } else {
                playAt(0);
            }
        }
    }
}


void Widget::on_ProgressSilder_actionTriggered(int action)
{
    // 当用户点击或拖动进度条时，设置播放位置
    player->setPosition(ui->ProgressSilder->value());
}


void Widget::on_SoundSilder_actionTriggered(int action)
{
    // 当用户操作音量条时，设置音量
    int volume = ui->SoundSilder->value();
    audioOutput->setVolume(volume / 100.0);
    ui->label_2->setText(QString("%1 %").arg(volume));
}


void Widget::on_Front_clicked()
{
    // 播放上一首
    playPrevious();
}


void Widget::on_StartStop_clicked()
{
    // 根据当前播放状态切换播放/暂停
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
    } else {
        player->play();
    }
}


void Widget::on_Next_clicked()
{
    // 播放下一首
    playNext();
}


void Widget::on_RandomPlay_checkStateChanged(const Qt::CheckState &arg1)
{
    // 设置随机播放模式
    isRandomPlay = (arg1 == Qt::Checked);
}


void Widget::updateProgress()
{
    // 更新进度条位置
    ui->ProgressSilder->setValue(player->position());
    
    // 更新时间显示
    QTime currentTime(0, 0, 0);
    QTime durationTime(0, 0, 0);
    currentTime = currentTime.addMSecs(player->position());
    durationTime = durationTime.addMSecs(player->duration());
    
    ui->label->setText(QString("%1/%2").arg(currentTime.toString("mm:ss")).arg(durationTime.toString("mm:ss")));
}


void Widget::playAt(int index)
{
    if (index < 0 || index >= playlist.size()) {
        return;
    }
    
    // 存储当前索引为上一首
    if (currentIndex != -1) {
        previousIndex = currentIndex;
    }
    
    currentIndex = index;
    QString fileName = playlist[index];
    
    // 更新当前播放信息
    QFileInfo fileInfo(fileName);
    ui->label_5->setText(fileInfo.fileName());
    
    // 只显示上级目录
    QString parentPath = fileInfo.absolutePath();
    QDir dir(parentPath);
    ui->label_6->setText(dir.dirName());
    
    // 设置播放源并播放
    player->setSource(QUrl::fromLocalFile(fileName));
    player->play();
}


void Widget::playNext()
{
    if (playlist.isEmpty()) {
        return;
    }
    
    int nextIndex;
    if (currentIndex == -1) {
        // 如果还没有播放过任何歌曲，从第一首开始
        nextIndex = 0;
    } else if (isRandomPlay) {
        // 随机播放，避免重复播放同一首
        do {
            nextIndex = QRandomGenerator::global()->bounded(playlist.size());
        } while (nextIndex == currentIndex && playlist.size() > 1);
    } else {
        // 顺序播放，循环列表
        nextIndex = (currentIndex + 1) % playlist.size();
    }
    
    playAt(nextIndex);
}


void Widget::playPrevious()
{
    if (playlist.isEmpty()) {
        return;
    }
    
    int prevIndex;
    if (previousIndex != -1) {
        // 如果有上一首记录，播放上一首
        prevIndex = previousIndex;
    } else if (currentIndex == -1) {
        // 如果还没有播放过任何歌曲，从最后一首开始
        prevIndex = playlist.size() - 1;
    } else {
        // 否则播放播放列表中的上一首（循环）
        prevIndex = (currentIndex - 1 + playlist.size()) % playlist.size();
    }
    
    playAt(prevIndex);
}


void Widget::saveSettings()
{
    QSettings settings("AudioP.ini", QSettings::IniFormat);
    
    // 保存当前播放的歌曲路径
    if (currentIndex >= 0 && currentIndex < playlist.size()) {
        settings.setValue("CurrentSong", playlist[currentIndex]);
    } else {
        settings.setValue("CurrentSong", "");
    }
    
    // 保存播放进度（毫秒）
    settings.setValue("Position", player->position());
    
    // 保存音量大小（0-100）
    settings.setValue("Volume", ui->SoundSilder->value());
    
    // 保存是否随机播放
    settings.setValue("RandomPlay", isRandomPlay);
    
    // 保存上次打开的目录路径
    if (currentIndex >= 0 && currentIndex < playlist.size()) {
        QFileInfo fileInfo(playlist[currentIndex]);
        settings.setValue("LastOpenDir", fileInfo.absolutePath());
    }
    
    // 保存播放列表
    settings.beginWriteArray("Playlist");
    for (int i = 0; i < playlist.size(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("Song", playlist[i]);
    }
    settings.endArray();
    
    settings.sync();
}


void Widget::loadSettings()
{
    QSettings settings("AudioP.ini", QSettings::IniFormat);
    
    // 读取播放列表
    int playlistSize = settings.beginReadArray("Playlist");
    playlist.clear();
    for (int i = 0; i < playlistSize; ++i) {
        settings.setArrayIndex(i);
        QString songPath = settings.value("Song").toString();
        
        // 检查文件是否存在
        if (QFile::exists(songPath)) {
            playlist.append(songPath);
        } else {
            qWarning() << "文件不存在，已跳过：" << songPath;
        }
    }
    settings.endArray();
    
    // 读取当前播放的歌曲路径
    QString currentSong = settings.value("CurrentSong", "").toString();
    
    // 读取播放进度
    qint64 position = settings.value("Position", 0).toLongLong();
    
    // 读取音量大小
    int volume = settings.value("Volume", 50).toInt();
    
    // 读取是否随机播放
    isRandomPlay = settings.value("RandomPlay", false).toBool();
    
    // 读取上次打开的目录路径
    QString lastDir = settings.value("LastOpenDir", QDir::homePath()).toString();
    if (!lastDir.isEmpty()) {
        lastOpenDir = lastDir;
    }
    
    // 设置音量
    ui->SoundSilder->setValue(volume);
    audioOutput->setVolume(volume / 100.0);
    ui->label_2->setText(QString("%1 %").arg(volume));
    
    // 设置随机播放复选框状态
    ui->RandomPlay->setChecked(isRandomPlay);
    
    // 如果有播放列表且当前歌曲存在，则加载
    if (!playlist.isEmpty() && !currentSong.isEmpty()) {
        // 检查当前歌曲是否存在
        if (QFile::exists(currentSong)) {
            // 查找当前歌曲在播放列表中的索引
            currentIndex = playlist.indexOf(currentSong);
            
            if (currentIndex != -1) {
                // 设置播放源
                player->setSource(QUrl::fromLocalFile(currentSong));
                
                // 更新显示信息
                QFileInfo fileInfo(currentSong);
                ui->label_5->setText(fileInfo.fileName());
                QString parentPath = fileInfo.absolutePath();
                QDir dir(parentPath);
                ui->label_6->setText(dir.dirName());
                
                // 设置播放位置
                player->setPosition(position);
                
                // 不自动播放，等待用户点击播放按钮
                previousIndex = -1;
            }
        } else {
            qWarning() << "当前歌曲文件不存在：" << currentSong;
            currentIndex = -1;
        }
    }
}

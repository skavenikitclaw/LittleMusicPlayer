#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QMediaPlaylist>
#include <QStringList>
#include <QDir>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool IsPlay = false;

    QString MusicPath = QCoreApplication::applicationDirPath();     //获取程序所在文件夹路径

    QMediaPlaylist *PlayerList;
    QMediaPlayer *Player;
    QStringList fileList;

private slots:
    void init();
    void addItem(QString name);
    QStringList getFileNames(const QString &path);

    void slotCurrentMusic();
    void slotButtonStart();
    void slotButtonLast();
    void slotButtonNext();
    void on_VedioSlider_sliderMoved(int position);
};
#endif // MAINWINDOW_H

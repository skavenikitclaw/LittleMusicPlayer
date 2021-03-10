#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->ButtonPlay,&QPushButton::clicked,this,&MainWindow::slotButtonStart);     //点击促发开始键
    connect(ui->ButtonLast,&QPushButton::clicked,this,&MainWindow::slotButtonLast);
    connect(ui->ButtonNext,&QPushButton::clicked,this,&MainWindow::slotButtonNext);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::init()
{
    PlayerList = new QMediaPlaylist;
    Player = new QMediaPlayer;

    fileList = getFileNames(this->MusicPath);    //获取该路径的MP3
    //qDebug()<<"ALL MUSIC FILE : \n "<<fileList;
    for(int i=0;i<fileList.size();i++)
    {
        QString fileName = fileList.at(i);
        addItem(fileName);
        PlayerList->addMedia(QUrl::fromLocalFile(MusicPath+"\\"+fileName));
    }
    Player->setVolume(0);
    PlayerList->setCurrentIndex(0);
    Player->setPlaylist(PlayerList);     //获取播放列表

    slotCurrentMusic();
    connect(Player,&QMediaPlayer::currentMediaChanged,this,&MainWindow::slotCurrentMusic);

}


QStringList MainWindow::getFileNames(const QString &path)
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.mp3";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    return files;
}

void MainWindow::slotCurrentMusic()
{
    int index = PlayerList->currentIndex();
    QString MusicName = fileList.at(index);
    ui->CurrentMusic->setText(MusicName);
}

void MainWindow::slotButtonStart()
{
    if(!IsPlay)
    {
        IsPlay = true;
        ui->ButtonPlay->setIcon(QIcon(":/pause.ico"));
        Player->play();
    }
    else
    {
        IsPlay = false;
        ui->ButtonPlay->setIcon(QIcon(":/play.ico"));
        Player->pause();
    }
}

void MainWindow::slotButtonLast()
{
    PlayerList->previous();
    PlayerList->previousIndex();
}

void MainWindow::slotButtonNext()
{
    PlayerList->next();
    PlayerList->nextIndex();
}

void MainWindow::addItem(QString name)
{
    int count = ui->TableList->rowCount();
    ui->TableList->setRowCount(count+1);

    QTableWidgetItem *itemName = new QTableWidgetItem(name);
    ui->TableList->setItem(count,0,itemName);
}


void MainWindow::on_VedioSlider_sliderMoved(int position)
{
    Player->setVolume(position);
}

#include "lyrics.h"

Lyrics::Lyrics()
{

}

bool Lyrics::readLyricsFile(QString lyricsPath)
{
    QFile file(lyricsPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line="";
    while((line=file.readLine())>0){
        //qDebug()<<line;
        analysisLyricsFile(line);//解析歌词文件内容
    }
    return true;
}

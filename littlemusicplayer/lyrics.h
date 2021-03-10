#ifndef LYRICS_H
#define LYRICS_H

#include <QWidget>
#include <QFile>

class Lyrics
{
public:
    Lyrics();
};

bool Lyrics::readLyricsFile(QString lyricsPath);

#endif // LYRICS_H

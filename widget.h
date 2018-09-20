#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QFile>
#include <QDebug>

//歌曲元素相关

#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/taglib.h>
#include <taglib/tpropertymap.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_openFileBtn_clicked();    

    void on_pButton_clicked();

private:
    Ui::Widget *ui;
    QMediaPlayer *player;
    QString songPath;
    QString songName;
    bool playFlag;
};

#endif // WIDGET_H

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(":/img/back.jpeg").scaled(this->size(),
                     Qt::IgnoreAspectRatio,
                     Qt::SmoothTransformation)));//设置窗体背景
    this->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openFileBtn_clicked()
{
    songPath = QFileDialog::getOpenFileName(this,"open a music","/Users/zorro/Music/","*.mp3");
    songName = songPath;
    songName = songName.mid(songName.lastIndexOf("/")+1);//mid QString字符串截取，得到歌曲名
    songName = songName.mid(0,songName.lastIndexOf("."));

    ui->songLabel->setText(songName);
    ui->songLabel->setStyleSheet("color:#ffffff");//设置歌曲名颜色为白色
    ui->playBtn->setText("pauss");
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile(songPath));
    player->play();
    playFlag = false;
}

void Widget::on_playBtn_clicked()
{
    if(playFlag)
    {
        playFlag = false;
        ui->playBtn->setText("pauss");
        player->play();
    }
    else
    {
        playFlag = true;
        ui->playBtn->setText("play");
        player->pause();
    }
}

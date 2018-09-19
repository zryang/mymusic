#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openFileBtn_clicked()
{
    songPath = QFileDialog::getOpenFileName(this,"open a music","/","*.mp3");
    songName = songPath;
    songName.replace("/Users/zorro/Music/","");
    songName.replace(".mp3","");

    //setLabel
    ui->songLabel->setText(songName);
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

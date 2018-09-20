#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    showFullScreen();//设置全屏，是设置背景的全屏，还是要在ui中增大ui面积
    this->setAutoFillBackground(true);//设置背景
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(":/img/back.jpeg").scaled(this->size(),
                     Qt::IgnoreAspectRatio,
                     Qt::SmoothTransformation)));//设置窗体背景
    this->setPalette(palette);
    ui->groupBox->setVisible(true);
    ui->groupBox_2->setVisible(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openFileBtn_clicked()
{
    songPath = QFileDialog::getOpenFileName(this,"open a music","/Users/zorro/Music/","*.mp3");
    //获取文件的名称以得到歌曲名
    songName = songPath;
    qDebug() << songName;

    //使用taglib要在pro中添加INCLUDEPATH 和 LIBPATH
    TagLib::FileRef file(songName.toStdString().c_str());
    songName = QString::fromWCharArray(file.tag()->title().toCWString());
    qDebug() << songName;
//    songName = songName.mid(songName.lastIndexOf("/")+1);//mid QString字符串截取，得到歌曲名
//    songName = songName.mid(0,songName.lastIndexOf("."));

    ui->songLabel->setText(songName);
    ui->songLabel->setStyleSheet("color:#ffffff");//设置歌曲名颜色为白色
    ui->playBtn->setText("pauss");
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile(songPath));
    player->play();
    playFlag = false;
    ui->groupBox->setVisible(false);
    ui->groupBox_2->setVisible(true);
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

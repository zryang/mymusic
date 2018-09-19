#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QFileDialog>

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

    void on_playBtn_clicked();

private:
    Ui::Widget *ui;
    QMediaPlayer *player;
    QString songPath;
    QString songName;
    bool playFlag;
};

#endif // WIDGET_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <opencv.hpp>
using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_boxFilterSlider_sliderMoved(int position);

    void on_meanBlurSlider_sliderMoved(int position);

    void on_gaussianBlurSlider_sliderMoved(int position);

    void on_medianBlurSlider_sliderMoved(int position);

    void on_bilateralFilyerSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QString imageFileName;
    String srcImageFile;
};

#endif // MAINWINDOW_H

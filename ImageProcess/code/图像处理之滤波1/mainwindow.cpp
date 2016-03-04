#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <opencv.hpp>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
using namespace  cv;
using namespace  std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("图像处理之滤波1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    imageFileName = QFileDialog::getOpenFileName(this, tr("选择图像"),
                    QDir::currentPath()
                    , tr("Images (*.jpg *.png *.xpm)"));
    if(imageFileName.isEmpty()){
        QMessageBox::warning(this,"未选择文件","请选择图片！");
        return;
    }
    srcImageFile = imageFileName.toStdString();
    //qDebug()<<srcImageFile;
    Mat srcImage =  imread(srcImageFile, 1);
    imshow("1", srcImage);
}


void MainWindow::on_boxFilterSlider_sliderMoved(int position)
{
    Mat srcImage =  imread(srcImageFile, 1);
    Mat dstImage;
    int value = 2 * (int)(position/10) + 1;
    ui->boxSizeLable->setNum(value);

    if(ui->boxButton->isChecked()) {
        boxFilter(srcImage, dstImage, -1, Size(value, value));
        imshow("box",dstImage);
    }

}

void MainWindow::on_meanBlurSlider_sliderMoved(int position)
{
    Mat srcImage =  imread(srcImageFile, 1);
    Mat dstImage;
    int value = 2 * (int)(position/10) + 1;
    ui->meanValueLabel->setNum(value);

    if(ui->meanButton->isChecked()) {
        blur(srcImage, dstImage, Size(value, value),Point(-1,-1));
        imshow("meanBlur",dstImage);
    }
}

void MainWindow::on_gaussianBlurSlider_sliderMoved(int position)
{
    Mat srcImage =  imread(srcImageFile, 1);
    Mat dstImage;
    int value = 2 * (int)(position/10) + 1;
    ui->gaussLabel->setNum(value);

    if(ui->meanButton->isChecked()) {
        GaussianBlur(srcImage, dstImage, Size(value, value),0,0);
        imshow("gaussianBlur",dstImage);
    }
}

void MainWindow::on_medianBlurSlider_sliderMoved(int position)
{
    Mat srcImage =  imread(srcImageFile, 1);
    Mat dstImage;
    int value = 2 * (int)(position/10) + 1;
    ui->medianLabel->setNum(value);

    if(ui->meanButton->isChecked()) {
        medianBlur(srcImage, dstImage, value);
        imshow("medianBlur",dstImage);
    }
}

void MainWindow::on_bilateralFilyerSlider_sliderMoved(int position)
{
    Mat srcImage =  imread(srcImageFile, 1);
    Mat dstImage;
    int value = 2 * (int)(position/10) + 1;
    ui->bilaterLabel ->setNum(value);

    if(ui->meanButton->isChecked()) {
        bilateralFilter(srcImage, dstImage, value, value*2,value/2);
        imshow("bilateralFilter",dstImage);
    }
}

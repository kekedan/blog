#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MatToQImage.h"
#include <opencv.hpp>
#include <QFileDialog>
#include <QMessageBox>
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("图像滤波之腐蚀与膨胀");
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
    ui->imageFileLabel->setText(imageFileName);
    Mat srcImage =  imread(srcImageFile, 1);
    imshow("src", srcImage);
}

void MainWindow::on_erodeSlider_sliderMoved(int position)
{
    Mat srcImage =  imread(srcImageFile, 1);
    Mat dstImage;
    int value = 2 * (int)(position/10) + 1;
    ui->erodeSizeLabel->setNum(value);
    Mat element = getStructuringElement(MORPH_RECT,Size(value,value));
    erode(srcImage,dstImage,element);
    imshow("erode",dstImage);

}

void MainWindow::on_dialteSlider_sliderMoved(int position)
{
    Mat srcImage =  imread(srcImageFile, 1);
    Mat dstImage;
    int value = 2 * (int)(position/10) + 1;
    ui->dilateSizeLabel->setNum(value);
    Mat element = getStructuringElement(MORPH_RECT,Size(value,value));
    dilate(srcImage,dstImage,element);
    imshow("dilate",dstImage);

}

void MainWindow::on_negativeSlider_sliderMoved(int position)
{
    Mat srcImage =  imread(srcImageFile, 1);

    Mat dstImage,dstImage1,dstImage2;
    int value = 2 * (int)(position/10) + 1;
    ui->SizeLabel->setNum(value);
    Mat element = getStructuringElement(MORPH_RECT,Size(value,value));
    erode(srcImage,dstImage1,element);
    dilate(srcImage,dstImage2,element);
    dstImage=dstImage2-dstImage1;
    imshow("dilate-erode",dstImage);


}

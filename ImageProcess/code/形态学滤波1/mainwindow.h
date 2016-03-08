#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv.hpp>
#include <QString>
using namespace  std;

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

    void on_erodeSlider_sliderMoved(int position);

    void on_dialteSlider_sliderMoved(int position);

    void on_negativeSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QString imageFileName;
    string srcImageFile;
};

#endif // MAINWINDOW_H

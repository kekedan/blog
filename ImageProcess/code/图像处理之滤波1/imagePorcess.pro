#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T21:50:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imagePorcess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
INCLUDEPATH+=D:\opencv249\opencv\build\include\
              D:\opencv249\opencv\build\include\opencv\
             D:\opencv249\opencv\build\include\opencv2\

LIBS+=  D:\opencv249\opencvQT\lib\libopencv_calib3d249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_contrib249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_core249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_features2d249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_flann249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_gpu249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_highgui249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_imgproc249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_legacy249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_ml249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_objdetect249.dll.a\
        D:\opencv249\opencvQT\lib\libopencv_video249.dll.a

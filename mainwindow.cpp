#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalSliderRed->setMinimum(0);
    ui->horizontalSliderRed->setMaximum(RGB_VALUE_MAX);

    ui->horizontalSliderGreen->setMinimum(0);
    ui->horizontalSliderGreen->setMaximum(RGB_VALUE_MAX);

    ui->horizontalSliderBlue->setMinimum(0);
    ui->horizontalSliderBlue->setMaximum(RGB_VALUE_MAX);

    connect(ui->horizontalSliderRed, &QSlider::valueChanged, this,
            &MainWindow::onColorChanged);
    connect(ui->horizontalSliderGreen, &QSlider::valueChanged, this,
            &MainWindow::onColorChanged);
    connect(ui->horizontalSliderBlue, &QSlider::valueChanged, this,
            &MainWindow::onColorChanged);

    onColorChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onColorChanged()
{

    QColor selectedColor(ui->horizontalSliderRed->value(),
                         ui->horizontalSliderGreen->value(),
                         ui->horizontalSliderBlue->value());

    QPixmap colorMap(64, 64);
    colorMap.fill(selectedColor);
    ui->colorLabel->setPixmap(colorMap);
}

void MainWindow::on_spinBoxRed_valueChanged(int arg1)
{
    ui->horizontalSliderRed->setValue(arg1);

}


void MainWindow::on_spinBoxGreen_valueChanged(int arg1)
{

    ui->horizontalSliderGreen->setValue(arg1);

}


void MainWindow::on_spinBoxBlue_valueChanged(int arg1)
{

    ui->horizontalSliderBlue->setValue(arg1);

}


void MainWindow::on_horizontalSliderRed_valueChanged(int value)
{

    ui->spinBoxRed->setValue(value);
}


void MainWindow::on_horizontalSliderGreen_valueChanged(int value)
{

    ui->spinBoxGreen->setValue(value);
}


void MainWindow::on_horizontalSliderBlue_valueChanged(int value)
{

    ui->spinBoxBlue->setValue(value);
}


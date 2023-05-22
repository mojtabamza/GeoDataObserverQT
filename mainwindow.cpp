#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLCDNumber(GeoData_t& geoData) {
    ui->lcdNumberPoint->display(geoData.pointObj.pIndex);
    ui->lcdNumberLine->display(geoData.lineObj.lIndex);
    ui->lcdNumberArea->display(geoData.areaObj.aIndex);
}

void MainWindow::updateStatusBar(string& status) {
    ui->label_status->setText(QString::fromStdString(status));
}

void MainWindow::refreshStatusBar(void) {
    ui->label_status->setText(QString::fromStdString("----------------------------------------"));
}


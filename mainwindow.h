#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "geoData.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateLCDNumber(GeoData_t& geoData);
    void updateStatusBar(string& status);
    void refreshStatusBar(void);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

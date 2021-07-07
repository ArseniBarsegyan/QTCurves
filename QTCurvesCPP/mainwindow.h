#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnHypoCycloid_clicked();

    void on_btnAstroid_clicked();

    void on_btnHuygensCycloid_clicked();

    void on_btnCycloid_clicked();

    void on_btnLine_clicked();

    void on_spinScale_valueChanged(double arg1);

    void on_spinInterval_valueChanged(double arg1);

    void on_spinStepCount_valueChanged(int arg1);

    void on_btnBackground_clicked();

    void on_btnLineColor_clicked();

    void on_btnCircle_clicked();

    void on_btnEllipse_clicked();

    void on_btnFancy_clicked();

    void on_btnStarfish_clicked();

    void on_btnCloud_clicked();

    void on_btnInvertedCloud_clicked();

private:
    void update_ui();

private:
    Ui::MainWindow *ui;
};
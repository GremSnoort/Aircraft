#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtMath>

#include "inputwidget.h"
#include "outputwidget.h"
#include "integral.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CreateLayout();

    void SetParameters();

    float heading = 0.0f;
    float airspeed_on_ascent = 0.0f;
    float ascent_rate = 0.0f;
    float rise_time = 0.0f;
    float airspeed_on_descent = 0.0f;
    float descent_rate = 0.0f;
    float wind_to = 0.0f;       

    QScopedPointer<InputWidget> input_;
    QScopedPointer<OutputWidget> output_;
    QScopedPointer<QPushButton> calculate_res;    

public slots:
    void CalculateResult();

};

#endif // MAINWINDOW_H

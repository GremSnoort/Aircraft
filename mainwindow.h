#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QValidator>
#include <QtMath>

#include "parser.h"

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
    QString wind_function = "";

    QScopedPointer<QLabel> l_heading;//1. направление полёта
    QScopedPointer<QLabel> l_airspeed_on_ascent;//2. горизонтальная компонента вектора скорости при взлёте
    QScopedPointer<QLabel> l_ascent_rate;//3. вертикальная компонента вектора скорости при взлёте
    QScopedPointer<QLabel> l_rise_time;//4. время подъёма
    QScopedPointer<QLabel> l_airspeed_on_descent;//5. горизонтальная компонента вектора скорости при падении
    QScopedPointer<QLabel> l_descent_rate;//6. вертикальная компонента вектора скорости при падении
    QScopedPointer<QLabel> l_wind_from;//7. направление, откуда дует ветер
    QScopedPointer<QLabel> l_Wt;//8. функция ветра

    QScopedPointer<QLineEdit> data_heading;//1
    QScopedPointer<QLineEdit> data_airspeed_on_ascent;//2
    QScopedPointer<QLineEdit> data_ascent_rate;//3
    QScopedPointer<QLineEdit> data_rise_time;//4
    QScopedPointer<QLineEdit> data_airspeed_on_descent;//5
    QScopedPointer<QLineEdit> data_descent_rate;//6
    QScopedPointer<QLineEdit> data_wind_from;//7
    QScopedPointer<QLineEdit> data_Wt;//8

    QScopedPointer<QPushButton> calculate_res;

    QScopedPointer<QLabel> l_UP_North_South;
    QScopedPointer<QLabel> l_UP_East_West;
    QScopedPointer<QLabel> l_fall_time;
    QScopedPointer<QLabel> l_DOWN_North_South;
    QScopedPointer<QLabel> l_DOWN_East_West;

public slots:
    void CalculateResult();

};

#endif // MAINWINDOW_H

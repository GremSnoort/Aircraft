#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QScopedPointer>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QValidator>
#include <QComboBox>
#include <QSlider>

#include "aircraftdatatypes.h"

class InputWidget : public QWidget {
    Q_OBJECT
public:
    explicit InputWidget(QWidget* parent = nullptr);

    void CreateLayout();

    d_in GetInput(d_in in);

    QScopedPointer<QLabel> l_heading;//1. направление полёта
    QScopedPointer<QLabel> l_airspeed_on_ascent;//2. горизонтальная компонента вектора скорости при взлёте
    QScopedPointer<QLabel> l_ascent_rate;//3. вертикальная компонента вектора скорости при взлёте
    QScopedPointer<QLabel> l_rise_time;//4. время подъёма
    QScopedPointer<QLabel> l_airspeed_on_descent;//5. горизонтальная компонента вектора скорости при падении
    QScopedPointer<QLabel> l_descent_rate;//6. вертикальная компонента вектора скорости при падении
    QScopedPointer<QLabel> l_wind_from;//7. направление, откуда дует ветер
    QScopedPointer<QLabel> l_Wt;//8. функция ветра

    QScopedPointer<QLabel> l_ask_for_integral_var;
    QScopedPointer<QLabel> l_step;

    QScopedPointer<QLineEdit> d_heading;//1
    QScopedPointer<QLineEdit> d_airspeed_on_ascent;//2
    QScopedPointer<QLineEdit> d_ascent_rate;//3
    QScopedPointer<QLineEdit> d_rise_time;//4
    QScopedPointer<QLineEdit> d_airspeed_on_descent;//5
    QScopedPointer<QLineEdit> d_descent_rate;//6
    QScopedPointer<QLineEdit> d_wind_from;//7
    QScopedPointer<QLineEdit> d_Wt;//8

    QScopedPointer<QComboBox> b_ask_for_integral_var;
    QScopedPointer<QSlider> s_step;

signals:

public slots:
    void ChangePrecision(int pos);
};

#endif // INPUTWIDGET_H

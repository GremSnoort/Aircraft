#include "inputwidget.h"

InputWidget::InputWidget(QWidget *parent)
    : QWidget(parent)

    , l_heading(new QLabel("1. Heading: ", this))
    , l_airspeed_on_ascent(new QLabel("2. Airspeed on ascent: ", this))
    , l_ascent_rate(new QLabel("3. Ascent rate: ", this))
    , l_rise_time(new QLabel("4. Rise time: ", this))
    , l_airspeed_on_descent(new QLabel("5. Airspeed on descent: ", this))
    , l_descent_rate(new QLabel("6. Descent rate: ", this))
    , l_wind_from(new QLabel("7. Wind from: ", this))
    , l_Wt(new QLabel("W(t) = ", this))

    , d_heading(new QLineEdit(this))
    , d_airspeed_on_ascent(new QLineEdit(this))
    , d_ascent_rate(new QLineEdit(this))
    , d_rise_time(new QLineEdit(this))
    , d_airspeed_on_descent(new QLineEdit(this))
    , d_descent_rate(new QLineEdit(this))
    , d_wind_from(new QLineEdit(this))
    , d_Wt(new QLineEdit(this))
{
    CreateLayout();
}

void InputWidget::CreateLayout()
{
    QGridLayout* layout = new QGridLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->setColumnMinimumWidth(1, 50);
    layout->setColumnStretch(1, 1);

    layout->addWidget(l_heading.data(), 0, 0);
    layout->addWidget(d_heading.data(), 0, 1);

    layout->addWidget(l_airspeed_on_ascent.data(), 1, 0);
    layout->addWidget(d_airspeed_on_ascent.data(), 1, 1);

    layout->addWidget(l_ascent_rate.data(), 2, 0);
    layout->addWidget(d_ascent_rate.data(), 2, 1);

    layout->addWidget(l_rise_time.data(), 3, 0);
    layout->addWidget(d_rise_time.data(), 3, 1);

    layout->addWidget(l_airspeed_on_descent.data(), 4, 0);
    layout->addWidget(d_airspeed_on_descent.data(), 4, 1);

    layout->addWidget(l_descent_rate.data(), 5, 0);
    layout->addWidget(d_descent_rate.data(), 5, 1);

    layout->addWidget(l_wind_from.data(), 6, 0);
    layout->addWidget(d_wind_from.data(), 6, 1);

    layout->addWidget(l_Wt.data(), 7, 0);
    layout->addWidget(d_Wt.data(), 7, 1);

    layout->addWidget(spacer);

    setLayout(layout);

    QValidator* validator = new QDoubleValidator(this);
    d_heading.data()->setValidator(validator);
    d_airspeed_on_ascent.data()->setValidator(validator);
    d_ascent_rate.data()->setValidator(validator);
    d_rise_time.data()->setValidator(validator);
    d_airspeed_on_descent.data()->setValidator(validator);
    d_descent_rate.data()->setValidator(validator);
    d_wind_from.data()->setValidator(validator);
}

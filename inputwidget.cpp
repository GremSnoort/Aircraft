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

    , l_ask_for_integral_var(new QLabel("How to integrate? ", this))
    , l_step(new QLabel("Step of integrating: 0.1", this))

    , d_heading(new QLineEdit(this))
    , d_airspeed_on_ascent(new QLineEdit(this))
    , d_ascent_rate(new QLineEdit(this))
    , d_rise_time(new QLineEdit(this))
    , d_airspeed_on_descent(new QLineEdit(this))
    , d_descent_rate(new QLineEdit(this))
    , d_wind_from(new QLineEdit(this))
    , d_Wt(new QLineEdit(this))

    , b_ask_for_integral_var(new QComboBox(this))
    , s_step(new QSlider(Qt::Horizontal, this))
{
    CreateLayout();
    connect(s_step.data(), &QSlider::sliderMoved, this, &InputWidget::ChangePrecision);
}

void InputWidget::ChangePrecision(int pos)
{
    double d = pos;
    l_step.data()->setText(QString(tr("Step of integrating: %1").arg(d/10000)));
}

d_in InputWidget::GetInput(d_in in)
{
    in.heading = d_heading.data()->text().toFloat();
    in.airspeed_on_ascent = d_airspeed_on_ascent.data()->text().toFloat();
    in.ascent_rate = d_ascent_rate.data()->text().toFloat();
    in.rise_time = d_rise_time.data()->text().toFloat();
    in.airspeed_on_descent = d_airspeed_on_descent.data()->text().toFloat();
    in.descent_rate = d_descent_rate.data()->text().toFloat();
    in.wind_to = d_wind_from.data()->text().toFloat() + 180;
    in.wind_function = d_Wt.data()->text();
    in.step = s_step.data()->value();
    in.step/=10000;

    return in;
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

    layout->addWidget(l_ask_for_integral_var.data(), 8, 0);
    layout->addWidget(b_ask_for_integral_var.data(), 8, 1);
    b_ask_for_integral_var.data()->addItem("Formula of the central rectangles #1");
    b_ask_for_integral_var.data()->addItem("Trapezoid formula");
    b_ask_for_integral_var.data()->addItem("Formula of the central rectangles #2");

    layout->addWidget(l_step.data(), 9, 0);
    layout->addWidget(s_step.data(), 9, 1);
    s_step.data()->setRange(1, 1000);
    s_step.data()->setValue(10000);

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

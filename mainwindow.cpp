#include "mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , input_(new InputWidget(this))
    , output_(new OutputWidget(this))
    , calculate_res(new QPushButton("Calculate", this))    
{    
    setFixedSize(400, 500);
    CreateLayout();
    connect(calculate_res.data(), SIGNAL(clicked(bool)), this, SLOT(CalculateResult()));
}

MainWindow::~MainWindow(){}

void MainWindow::CalculateResult()
{
    SetParameters();

    double UP_North_South = airspeed_on_ascent * rise_time * cos(heading*M_PI/180);
    double UP_East_West = airspeed_on_ascent * rise_time * sin(heading*M_PI/180);
    double fall_time = 0.0f;
    if(descent_rate!=0)
        fall_time = ascent_rate * rise_time / descent_rate;
    double DOWN_North_South = airspeed_on_descent * fall_time * cos(heading*M_PI/180);
    double DOWN_East_West = airspeed_on_descent * fall_time * sin(heading*M_PI/180);

    double INTEGRAL = Integral::CalculateIntegral(rise_time, rise_time+fall_time);
    double WIND_North_South = INTEGRAL * cos(wind_to*M_PI/180);
    double WIND_East_West = INTEGRAL * sin(wind_to*M_PI/180);

    output_.data()->l_UP_North_South.data()->setText(QString(tr("North-South UP: %1").arg(UP_North_South)));
    output_.data()->l_UP_East_West.data()->setText(QString(tr("East-West UP: %1").arg(UP_East_West)));
    output_.data()->l_fall_time.data()->setText(QString(tr("Fall time: %1").arg(fall_time)));
    output_.data()->l_DOWN_North_South.data()->setText(QString(tr("North-South DOWN: %1").arg(DOWN_North_South)));
    output_.data()->l_DOWN_East_West.data()->setText(QString(tr("East-West DOWN: %1").arg(DOWN_East_West)));

    output_.data()->l_Integral.data()->setText(QString(tr("Integral: %1").arg(INTEGRAL)));
    output_.data()->l_WIND_North_South.data()->setText(QString(tr("North-South WIND: %1").arg(WIND_North_South)));
    output_.data()->l_WIND_East_West.data()->setText(QString(tr("East-West WIND: %1").arg(WIND_East_West)));
}

void MainWindow::SetParameters()
{
    heading = input_.data()->d_heading.data()->text().toFloat();
    airspeed_on_ascent = input_.data()->d_airspeed_on_ascent.data()->text().toFloat();
    ascent_rate = input_.data()->d_ascent_rate.data()->text().toFloat();
    rise_time = input_.data()->d_rise_time.data()->text().toFloat();
    airspeed_on_descent = input_.data()->d_airspeed_on_descent.data()->text().toFloat();
    descent_rate = input_.data()->d_descent_rate.data()->text().toFloat();
    wind_to = input_.data()->d_wind_from.data()->text().toFloat() + 180;
    Integral::wind_function = input_.data()->d_Wt.data()->text();
}

void MainWindow::CreateLayout()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(input_.data());
    layout->addWidget(calculate_res.data());
    layout->addWidget(output_.data());

    layout->addWidget(spacer);

    setLayout(layout);
}

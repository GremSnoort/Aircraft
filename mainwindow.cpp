#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , l_heading(new QLabel("1. Heading: ", this))
    , l_airspeed_on_ascent(new QLabel("2. Airspeed on ascent: ", this))
    , l_ascent_rate(new QLabel("3. Ascent rate: ", this))
    , l_rise_time(new QLabel("4. Rise time: ", this))
    , l_airspeed_on_descent(new QLabel("5. Airspeed on descent: ", this))
    , l_descent_rate(new QLabel("6. Descent rate: ", this))
    , l_wind_from(new QLabel("7. Wind from: ", this))

    , data_heading(new QLineEdit(this))
    , data_airspeed_on_ascent(new QLineEdit(this))
    , data_ascent_rate(new QLineEdit(this))
    , data_rise_time(new QLineEdit(this))
    , data_airspeed_on_descent(new QLineEdit(this))
    , data_descent_rate(new QLineEdit(this))
    , data_wind_from(new QLineEdit(this))

    , calculate_res(new QPushButton("Calculate", this))

    , l_UP_North_South(new QLabel("UP North-South: ", this))
    , l_UP_East_West(new QLabel("UP East-West: ", this))
    , l_fall_time(new QLabel("Fall time: ", this))
    , l_DOWN_North_South(new QLabel("DOWN North-South: ", this))
    , l_DOWN_East_West(new QLabel("DOWN East-West: ", this))
{    
    setFixedSize(320, 400);
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

    l_UP_North_South.data()->setText(QString(tr("UP North-South: %1").arg(UP_North_South)));
    l_UP_East_West.data()->setText(QString(tr("UP East-West: %1").arg(UP_East_West)));
    l_fall_time.data()->setText(QString(tr("Fall time: %1").arg(fall_time)));
    l_DOWN_North_South.data()->setText(QString(tr("DOWN North-South: %1").arg(DOWN_North_South)));
    l_DOWN_East_West.data()->setText(QString(tr("DOWN East-West: %1").arg(DOWN_East_West)));
}

void MainWindow::SetParameters()
{
    heading = data_heading.data()->text().toFloat();
    airspeed_on_ascent = data_airspeed_on_ascent.data()->text().toFloat();
    ascent_rate = data_ascent_rate.data()->text().toFloat();
    rise_time = data_rise_time.data()->text().toFloat();
    airspeed_on_descent = data_airspeed_on_descent.data()->text().toFloat();
    descent_rate = data_descent_rate.data()->text().toFloat();
    wind_to = data_wind_from.data()->text().toFloat() + 180;
}

void MainWindow::CreateLayout()
{
    QGridLayout* layout = new QGridLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->setColumnMinimumWidth(1, 50);
    layout->setColumnStretch(1, 1);

    layout->addWidget(l_heading.data(), 0, 0);
    layout->addWidget(data_heading.data(), 0, 1);

    layout->addWidget(l_airspeed_on_ascent.data(), 1, 0);
    layout->addWidget(data_airspeed_on_ascent.data(), 1, 1);

    layout->addWidget(l_ascent_rate.data(), 2, 0);
    layout->addWidget(data_ascent_rate.data(), 2, 1);

    layout->addWidget(l_rise_time.data(), 3, 0);
    layout->addWidget(data_rise_time.data(), 3, 1);

    layout->addWidget(l_airspeed_on_descent.data(), 4, 0);
    layout->addWidget(data_airspeed_on_descent.data(), 4, 1);

    layout->addWidget(l_descent_rate.data(), 5, 0);
    layout->addWidget(data_descent_rate.data(), 5, 1);

    layout->addWidget(l_wind_from.data(), 6, 0);
    layout->addWidget(data_wind_from.data(), 6, 1);

    layout->addWidget(calculate_res.data(), 7, 1);

    layout->addWidget(l_UP_North_South.data(), 8, 1);
    layout->addWidget(l_UP_East_West.data(), 9, 1);
    layout->addWidget(l_fall_time.data(), 10, 1);
    layout->addWidget(l_DOWN_North_South.data(), 11, 1);
    layout->addWidget(l_DOWN_East_West.data(), 12, 1);

    layout->addWidget(spacer);

    setLayout(layout);

    QValidator* validator = new QDoubleValidator(this);
    data_heading.data()->setValidator(validator);
    data_airspeed_on_ascent.data()->setValidator(validator);
    data_ascent_rate.data()->setValidator(validator);
    data_rise_time.data()->setValidator(validator);
    data_airspeed_on_descent.data()->setValidator(validator);
    data_descent_rate.data()->setValidator(validator);
    data_wind_from.data()->setValidator(validator);
}

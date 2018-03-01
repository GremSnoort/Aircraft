#include "mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , input_(new InputWidget(this))
    , output_(new OutputWidget(this))
    , calculate_res(new QPushButton("Calculate", this))    
{    
    setFixedSize(400, 580);
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/Pics/kompass.jpeg"));
    CreateLayout();
    connect(calculate_res.data(), SIGNAL(clicked(bool)), this, SLOT(CalculateResult()));
}

MainWindow::~MainWindow(){}

void MainWindow::CalculateResult()
{
    in = input_.data()->GetInput(in);

    out.up_north_south = in.airspeed_on_ascent * in.rise_time * cos(in.heading*M_PI/180);
    out.up_east_west = in.airspeed_on_ascent * in.rise_time * sin(in.heading*M_PI/180);

    if(in.descent_rate!=0)
        out.fall_time = in.ascent_rate * in.rise_time / in.descent_rate;

    out.down_north_south = in.airspeed_on_descent * out.fall_time * cos(in.heading*M_PI/180);
    out.down_east_west = in.airspeed_on_descent * out.fall_time * sin(in.heading*M_PI/180);

    out.integral = Integral::CalculateIntegral(in.rise_time, in.rise_time + out.fall_time, input_.data()->b_ask_for_integral_var.data()->currentIndex(), in.wind_function);

    out.wind_north_south = out.integral * cos(in.wind_to*M_PI/180);
    out.wind_east_west = out.integral * sin(in.wind_to*M_PI/180);

    out.final_north_south = out.up_north_south + out.down_north_south + out.wind_north_south;
    out.final_east_west = out.up_east_west + out.down_east_west + out.wind_east_west;

    out.value = sqrt(out.final_north_south * out.final_north_south + out.final_east_west * out.final_east_west);

    if(out.final_north_south>0 && out.final_east_west>=0)//I четверть
        out.destination = abs(atan(out.final_east_west/out.final_north_south))* 180.0 / M_PI;
    if(out.final_north_south>=0 && out.final_east_west<0)//II четверть
        out.destination = 270 + abs((atan(out.final_north_south/out.final_east_west))* 180.0 / M_PI);
    if(out.final_north_south<0 && out.final_east_west<=0)//III четверть
        out.destination = 180 + abs((atan(out.final_east_west/out.final_north_south))* 180.0 / M_PI);
    if(out.final_north_south<=0 && out.final_east_west>0)//IV четверть
        out.destination = 90 + abs((atan(out.final_north_south/out.final_east_west))* 180.0 / M_PI);

    output_.data()->SetOutput(out);
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

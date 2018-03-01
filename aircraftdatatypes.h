#ifndef AIRCRAFTDATATYPES_H
#define AIRCRAFTDATATYPES_H

#include <QtCore>

struct d_in
{
    d_in(){}

    double heading = 0.0f;
    double airspeed_on_ascent = 0.0f;
    double ascent_rate = 0.0f;
    double rise_time = 0.0f;
    double airspeed_on_descent = 0.0f;
    double descent_rate = 0.0f;
    double wind_to = 0.0f;
    QString wind_function = "";
};
Q_DECLARE_METATYPE(d_in)

struct d_out
{
    d_out(){}

    double up_north_south = 0.0f;
    double up_east_west = 0.0f;
    double fall_time = 0.0f;
    double down_north_south = 0.0f;
    double down_east_west = 0.0f;
    double integral = 0.0f;
    double wind_north_south = 0.0f;
    double wind_east_west = 0.0f;
    double final_north_south = 0.0f;
    double final_east_west = 0.0f;

    double value = 0.0f;
    double destination = 0.0f;
};
Q_DECLARE_METATYPE(d_out)

#endif // AIRCRAFTDATATYPES_H

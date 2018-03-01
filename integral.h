#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <QObject>
#include <QString>
#include <sstream>

#include "tinyexpr-master/tinyexpr.h"

class Integral
{
public:
    Integral();

    static QString ChangeTtoValue(QString ss, QString wf);

    static long double Function(long double t, QString wind_function);

    static long double CalculateIntegral(long double a, long double b, int var, double precision, QString wind_function);

    static long double CalculateIntegral_1(long double a, long double n, long double h, QString wind_function);
    static long double CalculateIntegral_2(long double a, long double b, long double n, long double h, QString wind_function);
    static long double CalculateIntegral_3(long double a, long double b, long double n, long double h, QString wind_function);
};

#endif // INTEGRAL_H

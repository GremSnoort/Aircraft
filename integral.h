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

    static long double Function(long double t);
    static long double CalculateIntegral(long double a, long double b);

    static QString wind_function;
};

#endif // INTEGRAL_H

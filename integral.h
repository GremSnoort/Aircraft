#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <QObject>

class Integral
{
public:
    Integral();

    static double Function(double t);
    static double CalculateIntegral(double a, double b);


};

#endif // INTEGRAL_H

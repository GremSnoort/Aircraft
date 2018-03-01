#include "integral.h"

Integral::Integral(){}

QString Integral::ChangeTtoValue(QString ss, QString wf)
{
    if(wf.indexOf('t', 0)!=-1)
        wf =    wf.mid(0, wf.indexOf('t', 0))
                + ss
                + wf.mid(wf.indexOf('t', 0)+1);
    if(wf.indexOf('t', 0)!=-1)
        wf = Integral::ChangeTtoValue(ss, wf);

    return wf;
}

long double Integral::Function(long double t, QString wind_function)
{    
    std::stringstream ss;
    ss<<t;
    QString wf = wind_function;
    wf = Integral::ChangeTtoValue(QString::fromStdString(ss.str()), wf);

    return te_interp(wf.toStdString().c_str(), 0);
}

long double Integral::CalculateIntegral(long double a, long double b, int var, QString wind_function)
{
    long double h = 0.001;// задаём шаг интегрирования!!!
    long double n; // задаём число разбиений n
    n = (b - a) / h;

    switch (var) {
    case 0:
        return CalculateIntegral_1(a, n, h, wind_function);
        break;
    case 1:
        return CalculateIntegral_2(a, b, n, h, wind_function);
        break;
    case 2:
        return CalculateIntegral_3(a, b, n, h, wind_function);
        break;
    default:
        break;
    }

    return 0;
}

long double Integral::CalculateIntegral_1(long double a, long double n, long double h, QString wind_function)
{    
    // вычисляем интеграл по формуле центральных прямугольников
    long double integral = 0.0;
    for(int i = 1; i <= n; i++)
        integral = integral + h * Integral::Function(a + h * (i - 0.5), wind_function);

    return integral;
}

long double Integral::CalculateIntegral_2(long double a, long double b, long double n, long double h, QString wind_function)
{
    // вычисляем интеграл по формуле трапеций
    long double integral = h * (Function(a, wind_function) + Function(b, wind_function)) / 2.0;
    for(int i = 1; i <= n-1; i++)
        integral += h * Function(a + h * i, wind_function);

    return integral;
}

long double Integral::CalculateIntegral_3(long double a, long double b, long double n, long double h, QString wind_function)
{
    // вычисляем интеграл по формуле центральных прямугольников
    long double integral = h * (Function(a, wind_function) + Function(b, wind_function)) / 6.0;
    for(int i = 1; i <= n; i++)
        integral = integral + 4.0 / 6.0 * h * Function(a + h * (i - 0.5), wind_function);
    for(int i = 1; i <= n-1; i++)
        integral = integral + 2.0 / 6.0 * h * Function(a + h * i, wind_function);

    return integral;
}

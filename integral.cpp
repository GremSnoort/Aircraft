#include "integral.h"

QString Integral::wind_function = "";

Integral::Integral(){}

long double Integral::Function(long double t)
{    
    std::stringstream ss;
    ss<<t;
    QString wf = Integral::wind_function;
    while(wf.indexOf('t', 0)!=-1)
    {
        wf =    Integral::wind_function.mid(0, Integral::wind_function.indexOf('t', 0))
                + QString::fromStdString(ss.str())
                + Integral::wind_function.mid(Integral::wind_function.indexOf('t', 0)+1);
    }

    return te_interp(wf.toStdString().c_str(), 0);
                     //toLocal8Bit().data(), 0);
}

long double Integral::CalculateIntegral(long double a, long double b)
{
    int i; // счётчик
    long double integral; // здесь будет интеграл
    long double h = 0.001;// задаём шаг интегрирования
    long double n; // задаём число разбиений n
    n = (b - a) / h;

    // вычисляем интеграл по формуле центральных прямугольников
    /*integral = 0.0;
    for(i = 1; i <= n; i++)
    integral = integral + h * Integral::Function(a + h * (i - 0.5));
    //cout << "I1 = " << Integral << "\n";*/


    // вычисляем интеграл по формуле трапеций
    integral = h * (Function(a) + Function(b)) / 2.0;
    for(i = 1; i <= n-1; i++)
    integral += h * Function(a + h * i);
    //cout << "I2 = " << Integral << "\n";

    // вычисляем интеграл по формуле центральных прямугольников
    /*integral = h * (Function(a) + Function(b)) / 6.0;
    for(i = 1; i <= n; i++)
    integral = integral + 4.0 / 6.0 * h * Function(a + h * (i - 0.5));
    for(i = 1; i <= n-1; i++)
    integral = integral + 2.0 / 6.0 * h * Function(a + h * i);*/
    //cout << "I3 = " << Integral << "\n";
    return integral;
}

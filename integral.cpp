#include "integral.h"

Integral::Integral()
{

}

double Integral::Function(double t)
{

}

double Integral::CalculateIntegral(double a, double b)
{
  int i; // счётчик
  double Integral; // здесь будет интеграл

  double h = 0.1;// задаём шаг интегрирования

  double n; // задаём число разбиений n

  n = (b - a) / h;
  // вычисляем интеграл по формуле центральных прямугольников
  Integral = 0.0;
  for(i = 1; i <= n; i++)
    Integral = Integral + h * Function(a + h * (i - 0.5));
  //cout << "I1 = " << Integral << "\n";

  // вычисляем интеграл по формуле трапеций
  Integral = h * (Function(a) + Function(b)) / 2.0;
  for(i = 1; i <= n-1; i++)
    Integral = Integral + h * Function(a + h * i);
  //cout << "I2 = " << Integral << "\n";

  // вычисляем интеграл по формуле центральных прямугольников
  Integral = h * (Function(a) + Function(b)) / 6.0;
  for(i = 1; i <= n; i++)
    Integral = Integral + 4.0 / 6.0 * h * Function(a + h * (i - 0.5));
  for(i = 1; i <= n-1; i++)
    Integral = Integral + 2.0 / 6.0 * h * Function(a + h * i);
  //cout << "I3 = " << Integral << "\n";

  //system("pause");
}

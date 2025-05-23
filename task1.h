#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "const.h"
using namespace std;

// Функция и её производная (исправлены знаки)
double f_task1(double x) {
   return (x - 6) * (x - 6) - log(x); // Исправлен знак перед log(x)
}

double df_task1(double x) {
   return 2 * (x - 6) - 1.0 / x;      // Исправлена производная
}

// Итерационная функция (переопределена для корректной сходимости)
double phi(double x) {
   return 6.0 + sqrt(log(x));         // Новый вид итерационной функции
}

// Метод половинного деления (добавлена точность вывода)
void bisection(double a, double b) {
   vector<double> approximations;
   if (f_task1(a) * f_task1(b) >= 0) {
      cout << "[Bisection] Нет смены знака на [" << a << "," << b << "] – корня нет\n";
      return;
   }
   cout << "  Итерации (Bisection):\n";
   cout << fixed << setprecision(6);  // Установка точности вывода
   cout << "   N      a_n         b_n       b_n - a_n\n";
   double c = 0.0;
   for (int k = 1; k <= MAX_IT; ++k) {
      c = (a + b) / 2;
      approximations.push_back(c);
      cout << setw(3) << k << "  "
           << setw(10) << a << "  "
           << setw(10) << b << "  "
           << setw(10) << b - a << "\n";
      if (abs(b - a) < EPS) break;
      f_task1(a) * f_task1(c) < 0 ? b = c : a = c;
   }
   cout << "  Приближённый корень (Bisection): x* = " << c << "\n\n";
}

// Метод Ньютона
void newton(double x0) {
   vector<double> approximations;
   cout << "  Итерации (Newton):\n";
   cout << fixed << setprecision(6);
   cout << "  N  x_n         x_{n+1}    x_{n+1}-x_n\n";
   double x = x0, x_prev;
   for (int k = 1; k <= MAX_IT; ++k) {
      if (x <= 0) {
         cout << "  Ошибка: x выходит за область определения\n";
         break;
      }
      x_prev = x;
      x = x - f_task1(x) / df_task1(x);
      approximations.push_back(x);
      cout << setw(3) << k << "  "
           << setw(10) << x_prev << "  "
           << setw(10) << x << "  "
           << setw(10) << x - x_prev << "\n";
      if (abs(x - x_prev) < EPS) break;
   }
   cout << "  Приближённый корень (Newton): x* = " << x << "\n\n";
}

// Метод простых итераций (исправлена логика)
void simple_iteration(double x0) {
   vector<double> approximations;
   cout << "  Итерации (Simple Iteration):\n";
   cout << fixed << setprecision(6);
   cout << "  N  x_n         x_{n+1}    x_{n+1}-x_n\n";
   double x = x0, x_prev;
   for (int k = 1; k <= MAX_IT; ++k) {
      if (x < 1.0) {  // Проверка области определения log(x)
         cout << "  Ошибка: x < 1.0\n";
         break;
      }
      x_prev = x;
      x = phi(x);
      approximations.push_back(x);
      cout << setw(3) << k << "  "
           << setw(10) << x_prev << "  "
           << setw(10) << x << "  "
           << setw(10) << x - x_prev << "\n";
      if (abs(x - x_prev) < EPS) break;
   }
   cout << "  Приближённый корень (Simple Iteration): x* = " << x << "\n\n";
}

#endif
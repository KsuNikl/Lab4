#include <iostream>
#include <iomanip>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

using namespace std;

int main()
{
    int choice = 0;
    cout << "Выберите номер задачи (1-5): ";
    cin >> choice;

    switch (choice)
    {
    case 1: {
        cout << "Вы выбрали задачу 1\n";
        cout << fixed << setprecision(6);
        cout << "Уравнение: (x-6)^2 + ln(x) = 0\n\n";
        cout << "1) Метод половинного деления:\n";
        bisection(7.0, 8.0);
        cout << "\n2) Метод Ньютона:\n";
        newton(7.5);
        cout << "\n3) Метод простых итераций:\n";
        simple_iteration(7.5);
        break;
    }
    case 2: {
        cout << "Вы выбрали задачу 2\n";
        task2();
        break;
    }
    case 3: {
        cout << "Вы выбрали задачу 3\n";
        task3();
        break;
    }
    case 4: {
        cout << "Вы выбрали задачу 4\n";
        task4();
        break;
    }
    case 5: {
        cout << "Вы выбрали задачу 5\n";
        task5();
        break;
    }
    default:
        cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
    }

    return 0;
}
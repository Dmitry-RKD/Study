#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef double (*func_t)(double);

// Поиск корня уравнения f(x) - g(x) = 0 на [a, b] методом Ньютона
// df и dg - производные функций f и g
double root(func_t f, func_t g, func_t df, func_t dg, double a, double b, double eps, int *iterations);

// Вычисление определенного интеграла функции f на [a, b] методом Симпсона
double integral(func_t f, double a, double b, double eps);
// #include "solver.h"

// Функции согласно варианту
double f1(double x) { return 0.6 * x + 3; }
double df1(double x) { return 0.6; }

double f2(double x) { return pow(x - 2, 3) - 1; }
double df2(double x) { return 3 * pow(x - 2, 2); }

double f3(double x) { return 3.0 / x; }
double df3(double x) { return -3.0 / (x * x); }

// Тестовые функции
double ft1(double x) { return x * x; }
double dft1(double x) { return 2 * x; }
double ft2(double x) { return x + 2; }
double dft2(double x) { return 1; }

void print_help() {
    printf("Valid keys:\n");
    printf("  -roots       Printing of abscissas of intersection points\n");
    printf("  -iterations  Printing the number of iterations when searching for roots\n");
    printf("  -area        Printing the final area\n");
    printf("  -test-root  Testing the root function  (x^2 = x+2)\n");
    printf("  -test-int    Testing the integral function (x^2 on [0,3])\n");
    printf("  -help        The output of this help \n");
}

int main(int argc, char *argv[]) {
    double eps1 = 0.0001; // Точность для корней
    double eps2 = 0.0001; // Точность для интеграла
    
    int show_roots = 0, show_iter = 0, show_area = 0;

    if (argc == 1) { print_help(); return 0; }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-help") == 0) { print_help(); return 0; }
        if (strcmp(argv[i], "-roots") == 0) show_roots = 1;
        if (strcmp(argv[i], "-iterations") == 0) show_iter = 1;
        if (strcmp(argv[i], "-area") == 0) show_area = 1;
        
        if (strcmp(argv[i], "-test-root") == 0) {
            int it;
            double r = root(ft1, ft2, dft1, dft2, 1, 3, 0.0001, &it);
            printf("Test Root (x^2 = x+2) on [1,3]: %f, iter: %d (Expected: 2.0)\n", r, it);
            return 0;
        }
        if (strcmp(argv[i], "-test-int") == 0) {
            double res = integral(ft1, 0, 3, 0.0001);
            printf("Test Integral (x^2) on [0,3]: %f (Expected: 9.0)\n", res);
            return 0;
        }
    }

    int it1, it2, it3;
    // Находим точки пересечения (интервалы подобраны аналитически)
    double x13 = root(f1, f3, df1, df3, 0.5, 1.5, eps1, &it1); // f1 и f3
    double x23 = root(f2, f3, df2, df3, 2.0, 3.5, eps1, &it2); // f2 и f3
    double x12 = root(f1, f2, df1, df2, 3.5, 5.0, eps1, &it3); // f1 и f2

    if (show_roots) {
        printf("Points of intersection:\n x13 (f1,f3): %f\n x23 (f2,f3): %f\n x12 (f1,f2): %f\n", x13, x23, x12);
    }
    if (show_iter) {
        printf("Iterations:\n x13: %d, x23: %d, x12: %d\n", it1, it2, it3);
    }

    // Площадь = Интеграл(f1 - f3) от x13 до x23 + Интеграл(f1 - f2) от x23 до x12
    // Для этого создаем лямбда-подобные вычисления внутри integral
    // Но так как в Си нет лямбд, используем вспомогательные функции или вычитаем результаты
    double s1 = integral(f1, x13, x23, eps2) - integral(f3, x13, x23, eps2);
    double s2 = integral(f1, x23, x12, eps2) - integral(f2, x23, x12, eps2);
    double total_area = s1 + s2;

    if (show_area) {
        printf("The area of the figure: %f\n", total_area);
    }

    return 0;
}



double root(func_t f, func_t g, func_t df, func_t dg, double a, double b, double eps, int *iterations) {
    double x = (a + b) / 2.0; // Начальное приближение
    *iterations = 0;
    
    while (1) {
        (*iterations)++;
        double f_val = f(x) - g(x);
        double df_val = df(x) - dg(x);
        
        double x_next = x - f_val / df_val;
        
        if (fabs(x_next - x) < eps) {
            return x_next;
        }
        x = x_next;
        
        // Защита от бесконечного цикла
        if (*iterations > 1000) break;
    }
    return x;
}

double integral(func_t f, double a, double b, double eps) {
    int n = 10; // Начальное число разбиений
    double s_old, s_new = 0;
    
    // Итеративное удвоение шага для достижения точности
    do {
        s_old = s_new;
        double h = (b - a) / n;
        double sum = f(a) + f(b);
        
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            sum += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
        }
        s_new = (h / 3.0) * sum;
        n *= 2;
    } while (fabs(s_new - s_old) > eps);
    
    return s_new;
}
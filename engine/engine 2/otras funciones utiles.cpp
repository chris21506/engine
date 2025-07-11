#ifndef MATH_UTILITY_FUNCTIONS_H
#define MATH_UTILITY_FUNCTIONS_H

namespace MathLib {

    /**
     * @brief Realiza interpolación lineal entre dos valores.
     * @param a Valor inicial.
     * @param b Valor final.
     * @param t Factor de interpolación (0 a 1).
     * @return Valor interpolado.
     */
    double Lerp(double a, double b, double t);

    /**
     * @brief Calcula el factorial de un número entero no negativo.
     * @param n Número entero >= 0.
     * @return Factorial de n.
     */
    unsigned long long Factorial(int n);

    /**
     * @brief Compara dos números flotantes con una tolerancia.
     * @param a Primer valor.
     * @param b Segundo valor.
     * @param epsilon Tolerancia permitida.
     * @return true si los valores son aproximadamente iguales.
     */
    bool ApproxEqual(double a, double b, double epsilon = 1e-6);

} // namespace MathLib

#endif // MATH_UTILITY_FUNCTIONS_H

#include "utility_functions.h"
#include <cmath> // std::fabs

namespace MathLib {

    double Lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }

    unsigned long long Factorial(int n) {
        if (n < 0) return 0; // No definido para negativos
        if (n == 0 || n == 1) return 1;
        unsigned long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    bool ApproxEqual(double a, double b, double epsilon) {
        return std::fabs(a - b) < epsilon;
    }

} // namespace MathLib
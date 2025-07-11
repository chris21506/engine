#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

namespace MathLib {

    /**
     * @brief Calcula la raíz cuadrada de un número.
     */
    double Sqrt(double value);

    /**
     * @brief Calcula el cuadrado de un número.
     */
    double Square(double value);

    /**
     * @brief Calcula el cubo de un número.
     */
    double Cube(double value);

    /**
     * @brief Eleva una base a una potencia.
     */
    double Power(double base, double exponent);

    /**
     * @brief Devuelve el valor absoluto de un número.
     */
    double Abs(double value);

    /**
     * @brief Devuelve el máximo entre dos valores.
     */
    double EMax(double a, double b);

    /**
     * @brief Devuelve el mínimo entre dos valores.
     */
    double EMin(double a, double b);

    /**
     * @brief Redondea al entero más cercano.
     */
    double Round(double value);

    /**
     * @brief Redondea hacia abajo (entero menor o igual).
     */
    double Floor(double value);

    /**
     * @brief Redondea hacia arriba (entero mayor o igual).
     */
    double Ceil(double value);

    /**
     * @brief Valor absoluto en punto flotante.
     */
    double FAbs(double value);

    /**
     * @brief Resto de una división (módulo).
     */
    double Mod(double a, double b);

    /**
     * @brief Calcula e^x.
     */
    double Exp(double x);

    /**
     * @brief Calcula logaritmo natural (base e).
     */
    double Log(double x);

    /**
     * @brief Calcula logaritmo en base 10.
     */
    double Log10(double x);

} // namespace MathLib

#endif // MATH_FUNCTIONS_H

#include "math_functions.h"
#include <cmath> // Funciones estándar de C++

namespace MathLib {

    double Sqrt(double value) {
        return std::sqrt(value);
    }

    double Square(double value) {
        return value * value;
    }

    double Cube(double value) {
        return value * value * value;
    }

    double Power(double base, double exponent) {
        return std::pow(base, exponent);
    }

    double Abs(double value) {
        return (value < 0) ? -value : value;
    }

    double EMax(double a, double b) {
        return (a > b) ? a : b;
    }

    double EMin(double a, double b) {
        return (a < b) ? a : b;
    }

    double Round(double value) {
        return std::round(value);
    }

    double Floor(double value) {
        return std::floor(value);
    }

    double Ceil(double value) {
        return std::ceil(value);
    }

    double FAbs(double value) {
        return std::fabs(value);
    }

    double Mod(double a, double b) {
        return std::fmod(a, b); // Para punto flotante
    }

    double Exp(double x) {
        return std::exp(x);
    }

    double Log(double x) {
        return std::log(x);
    }

    double Log10(double x) {
        return std::log10(x);
    }

} // namespace MathLib

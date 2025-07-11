#ifndef MATH_TRIGONOMETRY_H
#define MATH_TRIGONOMETRY_H

namespace MathLib {

    /**
     * @brief Calcula el seno de un ángulo en radianes.
     */
    double Sin(double angleRad);

    /**
     * @brief Calcula el coseno de un ángulo en radianes.
     */
    double Cos(double angleRad);

    /**
     * @brief Calcula la tangente de un ángulo en radianes.
     */
    double Tan(double angleRad);

    /**
     * @brief Calcula el arco seno (resultado en radianes).
     */
    double Asin(double value);

    /**
     * @brief Calcula el arco coseno (resultado en radianes).
     */
    double Acos(double value);

    /**
     * @brief Calcula el arco tangente (resultado en radianes).
     */
    double Atan(double value);

    /**
     * @brief Calcula el seno hiperbólico de un número.
     */
    double Sinh(double value);

    /**
     * @brief Calcula el coseno hiperbólico de un número.
     */
    double Cosh(double value);

    /**
     * @brief Calcula la tangente hiperbólica de un número.
     */
    double Tanh(double value);

} // namespace MathLib

#endif // MATH_TRIGONOMETRY_H

#include "trigonometry.h"
#include <cmath> // Incluye funciones matemáticas estándar

namespace MathLib {

    double Sin(double angleRad) {
        return std::sin(angleRad);
    }

    double Cos(double angleRad) {
        return std::cos(angleRad);
    }

    double Tan(double angleRad) {
        return std::tan(angleRad);
    }

    double Asin(double value) {
        return std::asin(value);
    }

    double Acos(double value) {
        return std::acos(value);
    }

    double Atan(double value) {
        return std::atan(value);
    }

    double Sinh(double value) {
        return std::sinh(value);
    }

    double Cosh(double value) {
        return std::cosh(value);
    }

    double Tanh(double value) {
        return std::tanh(value);
    }

} // namespace MathLib

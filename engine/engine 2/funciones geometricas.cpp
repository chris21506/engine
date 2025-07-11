#ifndef MATH_GEOMETRY_FUNCTIONS_H
#define MATH_GEOMETRY_FUNCTIONS_H

namespace MathLib {

    /**
     * @brief Calcula el área de un círculo.
     * @param radius Radio del círculo.
     * @return Área del círculo.
     */
    double CircleArea(double radius);

    /**
     * @brief Calcula la circunferencia de un círculo.
     * @param radius Radio del círculo.
     * @return Longitud de la circunferencia.
     */
    double CircleCircumference(double radius);

    /**
     * @brief Calcula el área de un rectángulo.
     * @param width Ancho del rectángulo.
     * @param height Alto del rectángulo.
     * @return Área del rectángulo.
     */
    double RectangleArea(double width, double height);

    /**
     * @brief Calcula el perímetro de un rectángulo.
     * @param width Ancho del rectángulo.
     * @param height Alto del rectángulo.
     * @return Perímetro del rectángulo.
     */
    double RectanglePerimeter(double width, double height);

    /**
     * @brief Calcula el área de un triángulo usando base y altura.
     * @param base Longitud de la base.
     * @param height Altura del triángulo.
     * @return Área del triángulo.
     */
    double TriangleArea(double base, double height);

    /**
     * @brief Calcula la distancia entre dos puntos 2D.
     * @param x1 Coordenada X del punto 1.
     * @param y1 Coordenada Y del punto 1.
     * @param x2 Coordenada X del punto 2.
     * @param y2 Coordenada Y del punto 2.
     * @return Distancia entre los dos puntos.
     */
    double Distance(double x1, double y1, double x2, double y2);

} // namespace MathLib

#endif // MATH_GEOMETRY_FUNCTIONS_H

#include "geometry_functions.h"
#include <cmath> // Para M_PI, sqrt

namespace MathLib {

    // Pi constante si no está definida en cmath
    const double PI = 3.14159265358979323846;

    double CircleArea(double radius) {
        return PI * radius * radius;
    }

    double CircleCircumference(double radius) {
        return 2 * PI * radius;
    }

    double RectangleArea(double width, double height) {
        return width * height;
    }

    double RectanglePerimeter(double width, double height) {
        return 2 * (width + height);
    }

    double TriangleArea(double base, double height) {
        return 0.5 * base * height;
    }

    double Distance(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        return std::sqrt(dx * dx + dy * dy);
    }

} // namespace MathLib

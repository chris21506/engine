#ifndef MATH_ANGLE_CONVERSION_H
#define MATH_ANGLE_CONVERSION_H

namespace MathLib {

    /**
     * @brief Convierte un ángulo en grados a radianes.
     * @param degrees Ángulo en grados.
     * @return Ángulo en radianes.
     */
    double ToRadians(double degrees);

    /**
     * @brief Convierte un ángulo en radianes a grados.
     * @param radians Ángulo en radianes.
     * @return Ángulo en grados.
     */
    double ToDegrees(double radians);

} // namespace MathLib

#endif // MATH_ANGLE_CONVERSION_H

#include "angle_conversion.h"
#include <cmath> // Para constantes como M_PI (si está disponible)

namespace MathLib {

    // Constante pi explícita en caso de que no esté definida en cmath
    const double PI = 3.14159265358979323846;

    double ToRadians(double degrees) {
        return degrees * (PI / 180.0);
    }

    double ToDegrees(double radians) {
        return radians * (180.0 / PI);
    }

} // namespace MathLib

#include "angle_conversion.h"
#include <iostream>

int main() {
    double grados = 90.0;
    double radianes = MathLib::ToRadians(grados);
    std::cout << "90 grados = " << radianes << " radianes" << std::endl;

    double gradosConvertidos = MathLib::ToDegrees(3.14159);
    std::cout << "PI radianes = " << gradosConvertidos << " grados" << std::endl;

    return 0;
}

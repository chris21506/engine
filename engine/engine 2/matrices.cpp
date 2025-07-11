#ifndef MATH_QUATERNION_H
#define MATH_QUATERNION_H

namespace MathLib {

    /**
     * @brief Representa una rotación en 3D usando cuaterniones.
     */
    class Quaternion {
    private:
        float w, x, y, z; ///< Componentes del cuaternión

    public:
        /// Constructor por defecto (identidad).
        Quaternion();

        /// Constructor con componentes.
        Quaternion(float w, float x, float y, float z);

        /**
         * @brief Crea un cuaternión desde un eje y un ángulo (en radianes).
         */
        static Quaternion FromAxisAngle(float axisX, float axisY, float axisZ, float angleRad);

        /**
         * @brief Normaliza el cuaternión.
         */
        Quaternion Normalize() const;

        /**
         * @brief Multiplica este cuaternión por otro.
         */
        Quaternion Multiply(const Quaternion& other) const;

        /**
         * @brief Convierte el cuaternión en una matriz de rotación 3x3.
         * @param outMatrix Matriz de 9 elementos en arreglo (fila mayor).
         */
        void ToRotationMatrix(float outMatrix[9]) const;
    };

} // namespace MathLib

#endif // MATH_QUATERNION_H

#include "MathLib"
#include <cmath>

namespace MathLib {

    // ==================== Constructores ====================
    Quaternion::Quaternion() : w(1), x(0), y(0), z(0) {}
    Quaternion::Quaternion(float w, float x, float y, float z)
        : w(w), x(x), y(y), z(z) {
    }

    // ==================== FromAxisAngle ====================
    Quaternion Quaternion::FromAxisAngle(float axisX, float axisY, float axisZ, float angleRad) {
        float halfAngle = angleRad / 2;
        float sinHalf = std::sin(halfAngle);
        return Quaternion(
            std::cos(halfAngle),
            axisX * sinHalf,
            axisY * sinHalf,
            axisZ * sinHalf
        );
    }

    // ==================== Normalize ====================
    Quaternion Quaternion::Normalize() const {
        float magnitude = std::sqrt(w * w + x * x + y * y + z * z);
        if (magnitude == 0) return Quaternion();
        return Quaternion(w / magnitude, x / magnitude, y / magnitude, z / magnitude);
    }

    // ==================== Multiply ====================
    Quaternion Quaternion::Multiply(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    // ==================== ToRotationMatrix ====================
    void Quaternion::ToRotationMatrix(float outMatrix[9]) const {
        float xx = x * x;
        float yy = y * y;
        float zz = z * z;
        float xy = x * y;
        float xz = x * z;
        float yz = y * z;
        float wx = w * x;
        float wy = w * y;
        float wz = w * z;

        outMatrix[0] = 1 - 2 * (yy + zz);
        outMatrix[1] = 2 * (xy - wz);
        outMatrix[2] = 2 * (xz + wy);

        outMatrix[3] = 2 * (xy + wz);
        outMatrix[4] = 1 - 2 * (xx + zz);
        outMatrix[5] = 2 * (yz - wx);

        outMatrix[6] = 2 * (xz - wy);
        outMatrix[7] = 2 * (yz + wx);
        outMatrix[8] = 1 - 2 * (xx + yy);
    }

} // namespace MathLib
#ifndef MATH_MATRICES_H
#define MATH_MATRICES_H

namespace MathLib {

    /**
     * @brief Matriz 2x2 usada principalmente para transformaciones 2D simples.
     */
    class Matrix2x2 {
    private:
        float m[4]; // [a, b, c, d] = fila mayor

    public:
        Matrix2x2(); ///< Crea matriz identidad.
        Matrix2x2(float a, float b, float c, float d);

        static Matrix2x2 Rotation(float angleRad);  ///< Matriz de rotación 2D
        static Matrix2x2 Scale(float sx, float sy); ///< Matriz de escala 2D

        float Determinant() const;
        Matrix2x2 Inverse() const;
        Matrix2x2 Transpose() const;
        Matrix2x2 Multiply(const Matrix2x2& other) const;
    };

    /**
     * @brief Matriz 3x3 usada para transformaciones 2D con traslación o rotaciones 3D simples.
     */
    class Matrix3x3 {
    private:
        float m[9]; // 3x3 en fila mayor

    public:
        Matrix3x3(); ///< Matriz identidad.
        Matrix3x3(float values[9]); ///< Inicializa con arreglo.

        static Matrix3x3 Translation(float tx, float ty); ///< Traslación 2D
        static Matrix3x3 Rotation(float angleRad);        ///< Rotación 2D
        static Matrix3x3 Scale(float sx, float sy);       ///< Escala 2D

        float Determinant() const;
        Matrix3x3 Inverse() const;
        Matrix3x3 Transpose() const;
        Matrix3x3 Multiply(const Matrix3x3& other) const;
    };

    /**
     * @brief Matriz 4x4 usada en transformaciones 3D completas.
     */
    class Matrix4x4 {
    private:
        float m[16]; // 4x4 fila mayor

    public:
        Matrix4x4(); ///< Identidad
        Matrix4x4(float values[16]);

        static Matrix4x4 Translation(float tx, float ty, float tz);
        static Matrix4x4 RotationX(float angleRad);
        static Matrix4x4 RotationY(float angleRad);
        static Matrix4x4 RotationZ(float angleRad);
        static Matrix4x4 Scale(float sx, float sy, float sz);

        float Determinant() const;
        Matrix4x4 Inverse() const;
        Matrix4x4 Transpose() const;
        Matrix4x4 Multiply(const Matrix4x4& other) const;
    };

} // namespace MathLib

#endif // MATH_MATRICES_H

#include "matrices.h"
#include <cmath> // std::cos, std::sin

namespace MathLib {

    // ========== Matrix2x2 ==========
    Matrix2x2::Matrix2x2() : m{ 1, 0, 0, 1 } {}
    Matrix2x2::Matrix2x2(float a, float b, float c, float d) : m{ a, b, c, d } {}

    Matrix2x2 Matrix2x2::Rotation(float angleRad) {
        float c = std::cos(angleRad);
        float s = std::sin(angleRad);
        return Matrix2x2(c, -s, s, c);
    }

    Matrix2x2 Matrix2x2::Scale(float sx, float sy) {
        return Matrix2x2(sx, 0, 0, sy);
    }

    float Matrix2x2::Determinant() const {
        return m[0] * m[3] - m[1] * m[2];
    }

    Matrix2x2 Matrix2x2::Inverse() const {
        float det = Determinant();
        if (det == 0) return Matrix2x2(); // No inversa
        return Matrix2x2(
            m[3] / det, -m[1] / det,
            -m[2] / det, m[0] / det
        );
    }

    Matrix2x2 Matrix2x2::Transpose() const {
        return Matrix2x2(m[0], m[2], m[1], m[3]);
    }

    Matrix2x2 Matrix2x2::Multiply(const Matrix2x2& o) const {
        return Matrix2x2(
            m[0] * o.m[0] + m[1] * o.m[2], m[0] * o.m[1] + m[1] * o.m[3],
            m[2] * o.m[0] + m[3] * o.m[2], m[2] * o.m[1] + m[3] * o.m[3]
        );
    }

    // ========== Matrix3x3 y Matrix4x4 (solo ejemplo) ==========
    Matrix3x3::Matrix3x3() : m{
        1,0,0,
        0,1,0,
        0,0,1
    } {
    }

    Matrix3x3 Matrix3x3::Translation(float tx, float ty) {
        Matrix3x3 result;
        result.m[6] = tx;
        result.m[7] = ty;
        return result;
    }

    Matrix4x4::Matrix4x4() : m{
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    } {
    }

    Matrix4x4 Matrix4x4::Translation(float tx, float ty, float tz) {
        Matrix4x4 result;
        result.m[12] = tx;
        result.m[13] = ty;
        result.m[14] = tz;
        return result;
    }

} // namespace MathLib
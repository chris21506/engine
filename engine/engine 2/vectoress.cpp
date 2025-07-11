#ifndef MATH_VECTORS_H
#define MATH_VECTORS_H

namespace MathLib {

    /**
     * @brief Representa un vector bidimensional.
     */
    class Vector2 {
    private:
        float x, y;

    public:
        /// Constructor por defecto.
        Vector2();

        /// Constructor con parámetros.
        Vector2(float x, float y);

        /// Suma de vectores.
        Vector2 Add(const Vector2& other) const;

        /// Resta de vectores.
        Vector2 Subtract(const Vector2& other) const;

        /// Escalar por vector.
        Vector2 Scale(float scalar) const;

        /// Devuelve la magnitud del vector.
        float Magnitude() const;

        /// Normaliza el vector.
        Vector2 Normalize() const;
    };

    /**
     * @brief Representa un vector tridimensional.
     */
    class Vector3 {
    private:
        float x, y, z;

    public:
        Vector3();
        Vector3(float x, float y, float z);

        Vector3 Add(const Vector3& other) const;
        Vector3 Subtract(const Vector3& other) const;
        Vector3 Scale(float scalar) const;
        float Magnitude() const;
        Vector3 Normalize() const;
    };

    /**
     * @brief Representa un vector de cuatro dimensiones.
     */
    class Vector4 {
    private:
        float x, y, z, w;

    public:
        Vector4();
        Vector4(float x, float y, float z, float w);

        Vector4 Add(const Vector4& other) const;
        Vector4 Subtract(const Vector4& other) const;
        Vector4 Scale(float scalar) const;
        float Magnitude() const;
        Vector4 Normalize() const;
    };

} // namespace MathLib

#endif // MATH_VECTORS_H
#include vectoress.h
#include <cmath> // Para sqrt

namespace MathLib {

    // ===================== Vector2 =====================
    Vector2::Vector2() : x(0), y(0) {}
    Vector2::Vector2(float x, float y) : x(x), y(y) {}

    Vector2 Vector2::Add(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Vector2::Subtract(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 Vector2::Scale(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    float Vector2::Magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 Vector2::Normalize() const {
        float mag = Magnitude();
        return (mag == 0) ? Vector2() : Vector2(x / mag, y / mag);
    }

    // ===================== Vector3 =====================
    Vector3::Vector3() : x(0), y(0), z(0) {}
    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3 Vector3::Add(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 Vector3::Subtract(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 Vector3::Scale(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    float Vector3::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3 Vector3::Normalize() const {
        float mag = Magnitude();
        return (mag == 0) ? Vector3() : Vector3(x / mag, y / mag, z / mag);
    }

    // ===================== Vector4 =====================
    Vector4::Vector4() : x(0), y(0), z(0), w(0) {}
    Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Vector4 Vector4::Add(const Vector4& other) const {
        return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Vector4 Vector4::Subtract(const Vector4& other) const {
        return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Vector4 Vector4::Scale(float scalar) const {
        return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    float Vector4::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    Vector4 Vector4::Normalize() const {
        float mag = Magnitude();
        return (mag == 0) ? Vector4() : Vector4(x / mag, y / mag, z / mag, w / mag);
    }

} // namespace MathLib

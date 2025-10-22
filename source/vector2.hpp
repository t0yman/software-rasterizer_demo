#pragma once

#include <cmath>

struct Vector2
{
    Vector2() = default;
    Vector2(Vector2&&) = default;
    Vector2(const Vector2&) = default;
    inline explicit Vector2(double n) : x{n}, y{n} {};
    inline Vector2(double x, double y) : x{x}, y{y} {};

    Vector2& operator=(Vector2&&) = default;
    Vector2& operator=(const Vector2&) = default;

    ~Vector2() = default;

    inline Vector2& operator+=(const Vector2& v);
    inline Vector2& operator-=(const Vector2& v);
    inline Vector2& operator*=(double f);
    inline Vector2& operator/=(double f);

    inline double Magnitude() const { return std::sqrt((x * x) + (y * y)); };
    inline double MagnitudeSquared() const { return ((x * x) + (y * y)); };

    double x;
    double y;
};

Vector2& Vector2::operator+=(const Vector2& v)
{
    x += v.x;
    y += v.y;

    return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

Vector2& Vector2::operator*=(double f)
{
    x *= f;
    y *= f;

    return *this;
}

Vector2& Vector2::operator/=(double f)
{
    x /= f;
    y /= f;

    return *this;
}

inline Vector2 operator-(const Vector2& u)
{
    return {-u.x, -u.y};
}

inline Vector2 operator+(const Vector2& u, const Vector2& v)
{
    return {u.x + v.x, u.y + v.y};
}

inline Vector2 operator-(const Vector2& u, const Vector2& v)
{
    return {u.x - v.x, u.y - v.y};
}

inline Vector2 operator*(const Vector2& u, double f)
{
    return {u.x * f, u.y * f};
}

inline Vector2 operator*(double f, const Vector2& u)
{
    return (u * f);
}

inline Vector2 operator/(const Vector2& u, double f)
{
    return (u * (1 / f));
}

inline double DotProduct(const Vector2& u, const Vector2& v)
{
    return ((u.x * v.x) + (u.y * v.y));
}

inline Vector2 Normalize(const Vector2& u)
{
    return (u / u.Magnitude());
}
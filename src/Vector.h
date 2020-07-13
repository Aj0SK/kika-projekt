#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>

class Vector
{
private:
    double _x, _y, _z;
public:
    Vector(double x, double y, double z = 0.0) : _x(x), _y(y), _z(z) {};
    Vector() : _x(0.0), _y(0.0), _z(0.0) {};

    double size() const
    {
        return sqrt(_x*_x + _y*_y + _z*_z);
    }

    void print() const
    {
        std::cout << _x << " " << _y << " " << _z << std::endl;
    }

    double x() const { return _x;}
    double y() const { return _y;}
    double z() const { return _z;}
    
    friend Vector operator+(const Vector& a, const Vector& b)
    {
        return Vector(a._x + b._x, a._y + b._y, a._z + b._z);
    }
    friend Vector operator-(const Vector& a, const Vector& b)
    {
        return Vector(a._x - b._x, a._y - b._y, a._z - b._z);
    }
    friend double operator*(const Vector& a, const Vector& b)
    {
        return (a._x * b._x + a._y * b._y + a._z * b._z);
    }
    friend Vector operator^(const Vector& a, const Vector& b)
    {
        return Vector(a._y * b._z - a._z * b._y, a._z * b._x - a._x * b._z, a._x * b._y - a._y * b._x);
    }
    
    friend Vector operator*(const Vector& a, const double k)
    {
        return Vector(a._x * k, a._y * k, a._z * k);
    }
    friend Vector operator*(const double k, const Vector& a)
    {
        return Vector(a._x * k, a._y * k, a._z * k);
    }
    friend Vector operator*(const Vector& a, const int k)
    {
        return Vector(a._x * k, a._y * k, a._z * k);
    }
    friend Vector operator*(const int k, const Vector& a)
    {
        return Vector(a._x * k, a._y * k, a._z * k);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& a)
    {
        os << '[' << a._x << ',' << a._y << ',' << a._z << ']';
        return os;
    }
};

#endif

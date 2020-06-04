#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <cmath>

class Vector
{
private:
    double _x, _y, _z;
public:
    Vector(double x, double y, double z = 0) : _x(x), _y(y), _z(z) {};
    Vector() {};
    
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
    
    double size() const
    {
        return sqrt(_x*_x + _y*_y + _z*_z);
    }
    
    void print() const
    {
        std::cout << _x << " " << _y << " " << _z << std::endl;
    }
    
    double x() { return _x;}
    double y() { return _y;}
    double z() { return _z;}
};

#endif

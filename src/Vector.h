#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>

class Vector;
using Point = Vector;

class Vector
{
private:
  double _x, _y, _z;

public:
  Vector(double x, double y, double z = 0.0) : _x(x), _y(y), _z(z){};
  Vector() = default;
  Vector(const Vector& v) : _x(v.x()), _y(v.y()), _z(v.z()){};

  double length() const { return sqrt(length_squared()); }
  double length_squared() const { return _x * _x + _y * _y + _z * _z; }
  Vector unit() const { return Vector(*this / length()); }
  Vector inverse() const { return Vector(-_x, -_y, -_z); }

  void print() const { std::cout << _x << " " << _y << " " << _z << std::endl; }

  double x() const { return _x; }
  double y() const { return _y; }
  double z() const { return _z; }

  friend Vector operator+(const Vector& a, const Vector& b)
  {
    return Vector(a._x + b._x, a._y + b._y, a._z + b._z);
  }
  friend Vector operator-(const Vector& a, const Vector& b)
  {
    return Vector(a._x - b._x, a._y - b._y, a._z - b._z);
  }
  friend double operator*(const Vector& a, const Vector& b)
  // dot product
  {
    return (a._x * b._x + a._y * b._y + a._z * b._z);
  }
  friend Vector operator^(const Vector& a, const Vector& b)
  // cross product
  {
    return Vector(a._y * b._z - a._z * b._y, a._z * b._x - a._x * b._z,
                  a._x * b._y - a._y * b._x);
  }

  friend Vector operator*(const Vector& a, const double k)
  {
    return Vector(a._x * k, a._y * k, a._z * k);
  }
  friend Vector operator*(const double k, const Vector& a)
  {
    return Vector(a._x * k, a._y * k, a._z * k);
  }
  friend Vector operator/(const Vector& a, const double k)
  {
    double frac = 1.0 / k;
    return Vector(a._x * frac, a._y * frac, a._z * frac);
  }

  friend std::ostream& operator<<(std::ostream& os, const Vector& a)
  {
    os << '[' << a._x << ',' << a._y << ',' << a._z << ']';
    return os;
  }
};

#endif

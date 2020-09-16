#ifndef COLOR_H
#define COLOR_H

#include "Vector.h"
#include <cstddef>

struct Color : Vector
{
  double _r, _g, _b;
  Color(double r, double g, double b) : _r(r), _g(g), _b(b){};
  Color() {}
  std::byte r_byte() { return static_cast<std::byte>(255.0 * _r); }
  std::byte g_byte() { return static_cast<std::byte>(255.0 * _g); }
  std::byte b_byte() { return static_cast<std::byte>(255.0 * _b); }

  friend Color operator*(const double k, const Color& a)
  {
    return Color(a._r * k, a._g * k, a._b * k);
  }
  friend Color operator*(const Color& a, const double k) { return k * a; }
  friend Color operator+(const Color& a, const Color& b)
  {
    return Color(a._r + b._r, a._g + b._g, a._b + b._b);
  }
};

#endif

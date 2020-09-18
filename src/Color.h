#ifndef COLOR_H
#define COLOR_H

#include "Vector.h"
#include <algorithm>
#include <cstddef>

using std::clamp;

struct Color : Vector
{
  double _r, _g, _b;
  Color(double r, double g, double b) : _r(r), _g(g), _b(b){};
  Color() {}
  std::byte r_byte()
  {
    return static_cast<std::byte>(256.0 * clamp(_r, 0.0, 0.999));
  }
  std::byte g_byte()
  {
    return static_cast<std::byte>(256.0 * clamp(_g, 0.0, 0.999));
  }
  std::byte b_byte()
  {
    return static_cast<std::byte>(256.0 * clamp(_b, 0.0, 0.999));
  }

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

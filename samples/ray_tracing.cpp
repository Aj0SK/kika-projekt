#include "Ray.h"
#include "Vector.h"
#include "bmpWrite.h"

#include <fstream>
#include <iostream>
#include <vector>

struct Color
{
  double _r, _g, _b;
  Color(double r, double g, double b) : _r(r), _g(g), _b(b){};
  Color() {}
  std::byte r_byte() { return static_cast<std::byte>(255.0 * _r); }
  std::byte g_byte() { return static_cast<std::byte>(255.0 * _g); }
  std::byte b_byte() { return static_cast<std::byte>(255.0 * _b); }
};

int main()
{
  std::vector<std::byte> data;
  Ray a;
  int W = 128;
  int H = 128;

  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
    {
      Color pixel_color(double(i) / (W - 1), double(j) / (H - 1), 0.25);
      data.push_back(pixel_color.r_byte());
      data.push_back(pixel_color.g_byte());
      data.push_back(pixel_color.b_byte());
    }

  bmp::bmpWrite("testOut.bmp", W, H, data);

  return 0;
}

#include "Vector.h"
#include "bmpWrite.h"
#include "objLoad.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::byte;
using std::pair;

constexpr int kFrames = 600;
constexpr int kW = 1024;
constexpr int kH = 1024;

std::vector<std::byte> data;

void Color_pixel(int X, int Y, int w, byte R, byte G, byte B)
{
  data[3 * Y * w + 3 * X] = B;
  data[3 * Y * w + 3 * X + 1] = G;
  data[3 * Y * w + 3 * X + 2] = R;
}

bool Is_inside(Vector AB, Vector BC, Vector CA, Vector AX, Vector BX, Vector CX)
{
  if (((AX ^ AB).z() > 0) && ((BX ^ BC).z() > 0) && ((CX ^ CA).z() > 0))
    return true;
  if (((AX ^ AB).z() < 0) && ((BX ^ BC).z() < 0) && ((CX ^ CA).z() < 0))
    return true;
  return false;
}

struct circle
{
  circle(Vector S, int r) : S(S), r(r){};
  Vector S;
  int r;
};

void drawCircle(int x, int y, int r)
{
  circle C({(double)x, (double)y}, r);

  for (int i = 0; i < kW; ++i)
    for (int j = 0; j < kH; ++j)
    {
      Color_pixel(i, j, kW, (byte)100, (byte)100, (byte)100);
      Vector X(i, j);
      if ((X - C.S).length() <= C.r)
      {
        Color_pixel(i, j, kW, (byte)255, (byte)0, (byte)0);
      }
    }
  return;
}

int main()
{
  data.resize(3 * kW * kH);

  int currx = 200, curry = 200;

  for (int f = 0; f < kFrames; ++f)
  {
    drawCircle(currx, curry, kFrames);
    currx += 1;
    curry += 1;
    bmp::bmpWrite("img-" + std::to_string(f) + ".bmp", kW, kH, data);
  }

  return 0;
}

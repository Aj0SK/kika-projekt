#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"
#include "Vector.h"

class Camera
{
private:
  Point origin;
  Point lower_left_corner;
  Vector horizontal;
  Vector vertical;

public:
  Camera(double viewport_height, double viewport_width,
         double focal_length = 1.0)
  {
    origin = Point(0, 0, 0);
    horizontal = Point(viewport_width, 0.0, 0.0);
    vertical = Point(0.0, viewport_height, 0.0);
    lower_left_corner =
        origin - horizontal / 2 - vertical / 2 - Vector(0, 0, focal_length);
  }

  Ray get_ray(double u, double v) const
  {
    return Ray(origin,
               lower_left_corner + u * horizontal + v * vertical - origin);
  }
};

#endif
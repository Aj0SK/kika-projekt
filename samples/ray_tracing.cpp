#include "Color.h"
#include "Hittable.h"
#include "HittablesList.h"
#include "Ray.h"
#include "Sphere.h"
#include "Utility.h"
#include "Vector.h"
#include "bmpWrite.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>

using std::make_shared;

Color ray_color(const Ray& r, const HittablesList& world)
{
  HitRecord rec;
  if (world.is_hit(r, 0, my_utils::infinity, rec))
  {
    return 0.5 *
           (Color(1 + rec.normal.x(), 1 + rec.normal.y(), 1 + rec.normal.z()));
  }
  Vector unit_direction = r.direction().unit();
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main()
{
  // Image
  constexpr double aspect_ratio = 16.0 / 9.0;
  constexpr int W = 400;
  constexpr int H = static_cast<int>(W / aspect_ratio);

  constexpr double viewport_height = 2.0;
  constexpr double viewport_width = aspect_ratio * viewport_height;
  constexpr double focal_length = 1.0;

  Vector origin = Vector(0, 0, 0);
  Vector horizontal = Vector(viewport_width, 0, 0);
  Vector vertical = Vector(0, viewport_height, 0);
  Vector lower_left_corner =
      origin - horizontal / 2 - vertical / 2 - Vector(0, 0, focal_length);

  // Objects

  HittablesList objects;
  objects.add(make_shared<Sphere>(Vector(0, 0, -1), 0.5));
  objects.add(make_shared<Sphere>(Vector(0, -100.5, -1), 100));

  // Render

  std::vector<std::byte> data;

  for (int j = H - 1; j >= 0; --j)
  {
    for (int i = 0; i < W; ++i)
    {
      double u = double(i) / (W - 1);
      double v = double(j) / (H - 1);
      Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
      Color pixel_color = ray_color(r, objects);
      data.push_back(pixel_color.b_byte());
      data.push_back(pixel_color.g_byte());
      data.push_back(pixel_color.r_byte());
    }
  }

  bmp::bmpWrite("testOut.bmp", W, H, data);

  return 0;
}

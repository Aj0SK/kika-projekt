#include "Camera.h"
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

using std::cout;
using std::endl;

using std::make_shared;

Color ray_color(const Ray& r, const HittablesList& world)
{
  HitRecord rec;
  if (world.is_hit(r, 0, my_constants::infinity, rec))
  {
    return 0.5 *
           (Color(1 + rec.normal.x(), 1 + rec.normal.y(), 1 + rec.normal.z()));
  }
  Vector unit_direction = r.direction().unit();
  double t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main()
{
  // Image
  constexpr double aspect_ratio = 16.0 / 9.0;
  constexpr int W = 1200;
  constexpr int H = static_cast<int>(W / aspect_ratio);
  constexpr int samples_per_pixel = 50;

  constexpr double viewport_height = 2.0;
  constexpr double viewport_width = aspect_ratio * viewport_height;
  constexpr double focal_length = 1.0;

  // Camera
  Camera cam(viewport_height, viewport_width, focal_length);

  // Objects
  HittablesList objects;
  objects.add(make_shared<Sphere>(Vector(0, 0, -1), 0.5));
  objects.add(make_shared<Sphere>(Vector(0, -100.5, -1), 100));

  // Render
  std::vector<std::byte> data(W * H * 3);

  for (int j = H - 1; j >= 0; --j)
  {
    for (int i = 0; i < W; ++i)
    {
      Color pixel_color{0, 0, 0};
      for (int s = 0; s < samples_per_pixel; ++s)
      {
        double u = (i + random_double()) / (W - 1);
        double v = (j + random_double()) / (H - 1);
        Ray r = cam.get_ray(u, v);
        pixel_color = pixel_color + ray_color(r, objects);
      }

      pixel_color = (1.0 / samples_per_pixel) * pixel_color;

      int index = ((H - j - 1) * W + i) * 3;
      data[index] = pixel_color.b_byte();
      data[index + 1] = pixel_color.g_byte();
      data[index + 2] = pixel_color.r_byte();
    }
  }

  cout << "Data size is " << data.size() << " of " << W << "x" << H << endl;

  bmp::bmpWrite("testOut.bmp", W, H, data);

  return 0;
}

#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"

struct HitRecord
{
  Vector p;
  Vector normal;
  double t;
  bool front_face;

  void set_face_normal(const Ray& r, const Vector& outward_normal)
  {
    front_face = (r.direction() * outward_normal) < 0;
    normal = front_face ? outward_normal : outward_normal.inverse();
  }
};

class Hittable
{
public:
  virtual ~Hittable() = default;
  virtual bool is_hit(const Ray& r, double t_min, double t_max,
                      HitRecord& rec) const = 0;
};

#endif
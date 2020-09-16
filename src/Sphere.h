#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"
#include "Vector.h"

class Sphere : public Hittable
{
private:
  Vector center;
  double radius;

public:
  Sphere() = default;
  ~Sphere() = default;
  Sphere(const Vector& cen, double r) : center(cen), radius(r){};

  virtual bool is_hit(const Ray& r, double tmin, double tmax,
                      HitRecord& rec) const override;
};

bool Sphere::is_hit(const Ray& r, double t_min, double t_max,
                    HitRecord& rec) const
{
  Vector oc = r.origin() - center;
  double a = r.direction().length_squared();
  double half_b = oc * r.direction();
  double c = oc.length_squared() - radius * radius;
  double discriminant = half_b * half_b - a * c;

  if (discriminant > 0)
  {
    double root = sqrt(discriminant);

    double temp = (-half_b - root) / a;
    if (temp < t_max && temp > t_min)
    {
      rec.t = temp;
      rec.p = r.at(rec.t);
      rec.normal = (rec.p - center) / radius;
      Vector outward_normal = (rec.p - center) / radius;
      rec.set_face_normal(r, outward_normal);
      return true;
    }

    temp = (-half_b + root) / a;
    if (temp < t_max && temp > t_min)
    {
      rec.t = temp;
      rec.p = r.at(rec.t);
      rec.normal = (rec.p - center) / radius;
      Vector outward_normal = (rec.p - center) / radius;
      rec.set_face_normal(r, outward_normal);
      return true;
    }
  }

  return false;
}

#endif

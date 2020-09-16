#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "Hittable.h"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class HittablesList : public Hittable
{
public:
  HittablesList() {}
  HittablesList(shared_ptr<Hittable> object) { add(object); }

  void clear() { objects.clear(); }
  void add(shared_ptr<Hittable> object) { objects.push_back(object); }

  virtual bool is_hit(const Ray& r, double tmin, double tmax,
                      HitRecord& rec) const override;

public:
  std::vector<shared_ptr<Hittable>> objects;
};

bool HittablesList::is_hit(const Ray& r, double t_min, double t_max,
                           HitRecord& rec) const
{
  HitRecord temp_rec;
  bool hit_anything = false;
  auto closest_so_far = t_max;

  for (const auto& object : objects)
  {
    if (object->is_hit(r, t_min, closest_so_far, temp_rec))
    {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }

  return hit_anything;
}

#endif
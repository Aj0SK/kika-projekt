#ifndef RAY_H
#define RAY_H

#include "Vector.h"

class Ray
{
private:
  Vector orig;
  Vector dir;

public:
  Ray() = default;
  Ray(const Vector& origin, const Vector& direction)
      : orig(origin), dir(direction)
  {
  }

  Vector origin() const { return orig; }
  Vector direction() const { return dir; }

  Vector at(double t) const { return orig + t * dir; }
};

#endif

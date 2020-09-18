#ifndef UTILITY_H
#define UTILITY_H

#include <limits>
#include <random>

namespace my_constants
{
constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.1415926535897932385;
} // namespace my_constants

double get_random()
{
  static std::uniform_real_distribution<double> distribution(0.0, 1.0);
  static std::mt19937 generator;
  return distribution(generator);
}

inline double random_double(double min = 0.0, double max = 1.0)
{
  // Returns a random real in [min,max).
  return min + (max - min) * get_random();
}

constexpr double degrees_to_radians(double degrees)
{
  return degrees * my_constants::pi / 180.0;
}
#endif

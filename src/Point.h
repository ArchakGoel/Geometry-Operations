#pragma once
#include "MathUtils.h"

namespace Entities {

  class Vector3D;

  class Point {
    double x, y, z;

  public:
    explicit Point(const double x, const double y, const double z)
        : x(x), y(y), z(z) {};
    Point() : x(0.0), y(0.0), z(0.0) {};

    bool operator==(const Point &rhs) const {
      return (MathUtils::isEqual(*this, rhs));
    }
    Point operator+(const Point &rhs) const {
      return Point(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Point operator-(const Point &rhs) const {
      return Point(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    Vector3D getVector() const;
  };

}

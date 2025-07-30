#pragma once

namespace entities {

  class Vector3D;

  //! brief: operations like dot and cross product don't apply to points. So no vector3D inheritance.

  // todo: 1. make a 3D operator only base class for point and vector
  // common. todo: 2. Point copy operator non explicit.
  class Point {
    double x, y, z;

  public:
    explicit Point(const double x, const double y, const double z)
        : x(x), y(y), z(z) {};
    explicit Point() : x(0.0), y(0.0), z(0.0) {};

    // todo: use precision here.
    bool operator==(const Point &rhs) const {
      return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
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

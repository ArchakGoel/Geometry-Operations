#pragma once
#include "Point.h"
#include "Vector3D.h"
namespace entities {

  class Plane {
    Point point;
    Vector3D normal;

  public:
    explicit Plane(Point point, Vector3D direction);
    Point getPoint() const { return point; }
    Vector3D getNormal() const { return Vector3D(normal); }
    // other functions:
    // 1. Coplanar
    // 2. Same Plane via ==
    // 3. include precision value for comparison for all elements.
  };
} 
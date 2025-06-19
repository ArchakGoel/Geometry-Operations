#pragma once

#include "Vector3D.h"

namespace entities {

  class Point : public Vector3D {
  public:
    explicit Point(const double x, const double y, const double z)
        : Vector3D(x, y, z) {};
    explicit Point() : Vector3D(0.0, 0.0, 0.0) {};
    explicit Point(Vector3D vector):Vector3D(vector){};
  };

}

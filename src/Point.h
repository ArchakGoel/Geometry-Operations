#pragma once

#include "vector3d.h"

namespace entities {

  class Point : public vector3d {
  public:
    explicit Point(const double x, const double y, const double z)
        : vector3d(x, y, z) {};
    explicit Point() : vector3d(0.0, 0.0, 0.0) {};
  };

}

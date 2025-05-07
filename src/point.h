#ifndef POINT
#define POINT

#include "vector3D.h"

namespace entities {

  class point : public vector3D {
  public:
    explicit point(const double x, const double y, const double z)
        : vector3D(x, y, z) {};
    explicit point() : vector3D(0.0, 0.0, 0.0) {};
  };

} // namespace entities

#endif

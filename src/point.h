#ifndef POINT
#define POINT

#include "vector3d.h"

namespace entities {

  class point : public vector3d {
  public:
    explicit point(const double x, const double y, const double z)
        : vector3d(x, y, z) {};
    explicit point() : vector3d(0.0, 0.0, 0.0) {};
  };

} // namespace entities

#endif

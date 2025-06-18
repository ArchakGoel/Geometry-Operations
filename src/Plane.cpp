#include "Plane.h"

namespace entities {

    Plane::Plane(Point point, Vector3D direction)
      : point(point), normal(direction.normalized()) {

    };
}
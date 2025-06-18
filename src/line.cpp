
#include "Line.h"

namespace entities {

  Line::Line(const Point _vertex1, const Point _vertex2)
      : vertex1(_vertex1), vertex2(_vertex2),
        direction(Vector3D((vertex2.getX() - vertex1.getX()),
                           (vertex2.getY() - vertex1.getY()),
                           (vertex2.getZ() - vertex1.getZ()))) {};

  Line::Line(const Line &lineObject)
      : vertex1(lineObject.vertex1), vertex2(lineObject.vertex2),
        direction(lineObject.direction) {};

  Vector3D Line::getDirection() const {
    return Vector3D(direction);
  } // This behavior seems odd. When direction is already a Vector3D object, why
    // method is copy constr'r being explicit is stopping from returning it directly!

  
  double Line::dot(const Line &rhs) const {
    return direction.dot(rhs.getDirection());
  }
} // namespace entities
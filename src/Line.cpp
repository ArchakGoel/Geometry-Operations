
#include "Line.h"

namespace entities {

  Line::Line(const Point _vertex1, const Point _vertex2)
      : vertex1(_vertex1), vertex2(_vertex2),
        direction(vector3d((vertex2.getX() - vertex1.getX()),
                           (vertex2.getY() - vertex1.getY()),
                           (vertex2.getZ() - vertex1.getZ()))) {};

  Line::Line(const Line &lineObject)
      : vertex1(lineObject.vertex1), vertex2(lineObject.vertex2),
        direction(lineObject.direction) {};

  vector3d Line::getDirection() const {
    return vector3d(direction);
  } // This behavior seems odd. When direction is already a vector3d object, why
    // method is copy constr'r being explicit is stopping from returning it directly!

  
  double Line::dot(const Line &rhs) const {
    return direction.dot(rhs.getDirection());
  }
} // namespace entities
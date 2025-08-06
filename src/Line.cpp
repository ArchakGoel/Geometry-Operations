#include "Line.h"

namespace entities {

  Line::Line(const Point _vertex1, const Point _vertex2)
      : vertex1(_vertex1), vertex2(_vertex2),
        direction1To2(Vector3D((vertex2.getX() - vertex1.getX()),
                           (vertex2.getY() - vertex1.getY()),
                           (vertex2.getZ() - vertex1.getZ()))) {};

  bool Line::operator==(const Line& rhs) const{
      return (MathUtils::isEqual(vertex1, rhs.vertex1) && MathUtils::isEqual(vertex2, rhs.vertex2)) ||
              (MathUtils::isEqual(vertex1, rhs.vertex2) && MathUtils::isEqual(vertex2, rhs.vertex1));
    }

  bool Line::operator!=(const Line& rhs) const{
    return !(*this==rhs);
  }

}
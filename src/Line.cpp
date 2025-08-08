#include "Line.h"

namespace Entities {

  Line::Line(const Point inputVertex1, const Point inputVertex2){

    if (MathUtils::isEqual(inputVertex1, inputVertex2)) {
          throw std::invalid_argument("Cannot create line from identical points");
      }
    vertex1 = inputVertex1;
    vertex2 = inputVertex2;
    direction1To2 = Vector3D((vertex2.getX() - vertex1.getX()),
                           (vertex2.getY() - vertex1.getY()),
                           (vertex2.getZ() - vertex1.getZ()));
  }
      

  bool Line::operator==(const Line& rhs) const{
      return (MathUtils::isEqual(vertex1, rhs.vertex1) && MathUtils::isEqual(vertex2, rhs.vertex2)) ||
              (MathUtils::isEqual(vertex1, rhs.vertex2) && MathUtils::isEqual(vertex2, rhs.vertex1));
    }

  bool Line::operator!=(const Line& rhs) const{
    return !(*this==rhs);
  }

}
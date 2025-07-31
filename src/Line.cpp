
#include "Line.h"

namespace entities {

  Line::Line(const Point _vertex1, const Point _vertex2)
      : vertex1(_vertex1), vertex2(_vertex2),
        direction1To2(Vector3D((vertex2.getX() - vertex1.getX()),
                           (vertex2.getY() - vertex1.getY()),
                           (vertex2.getZ() - vertex1.getZ()))) {};

  Line::Line(const Line &lineObject)
      : vertex1(lineObject.getVertex1()), vertex2(lineObject.getVertex2()),
        direction1To2(lineObject.getDirection()) {};

  Vector3D Line::getDirection() const {
    return Vector3D(direction1To2);
  } 
    // Vector3D's copy constr'r being explicit is stopping from returning it
    // directly!

}
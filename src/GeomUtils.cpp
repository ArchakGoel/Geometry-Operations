#include "GeomUtils.h"
//check why need to be included again:-
#include "Plane.h"
#include "Point.h"
//

namespace GeomUtils {

  using namespace entities;

  double distanceOfPointFromPlane(const Point &point, const Plane &plane) {

    Vector3D pointToPlane = point - plane.getPoint();

    return (pointToPlane.dot(plane.getNormal()));
  }

}
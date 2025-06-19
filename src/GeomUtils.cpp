#include "GeomUtils.h"
// todo: check why need to be included again:
#include "Plane.h"
#include "Point.h"
//

namespace GeomUtils {

  using namespace entities;

  //! @brief:returns false if point on plane or opposite side.
  bool isPointOnSameSideOfPlane(const Point &point, const Plane &plane) {

    auto signedDistance = signedDistanceOfPointFromPlane(point, plane);

    return !(
        std::fabs(signedDistance < std::numeric_limits<double>::epsilon()) ||
        std::signbit(signedDistance));
    // todo: put isZero in a method in Mathutils for better readability.
  }

  double signedDistanceOfPointFromPlane(const Point &point,
                                        const Plane &plane) {

    Vector3D planeToPoint = point - plane.getPoint();

    return (planeToPoint.dot(plane.getNormal()));
  }

  double distanceOfPointFromPlane(const Point &point, const Plane &plane) {

    return (std::fabs(signedDistanceOfPointFromPlane(point, plane)));
  }

  Point projectionOfPointOnPlane(const Point &point, const Plane &plane) {

    return Point(point - (plane.getNormal() * signedDistanceOfPointFromPlane(point, plane)));
    //todo: check why need to redefine? Vector3D to Point constr is given.
  }

} // namespace GeomUtils
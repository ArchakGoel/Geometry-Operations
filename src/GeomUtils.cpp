#include "GeomUtils.h"
// todo: check why Plane and Point need to be included again despite GeomUtils.
#include "Plane.h"
#include "Point.h"


namespace GeomUtils {

  using namespace entities;

  bool isPointOnSameSideOfPlane(const Point &point, const Plane &plane) {

    auto signedDistance = signedDistanceOfPointFromPlane(point, plane);

    return !(
        std::fabs(signedDistance < std::numeric_limits<double>::epsilon()) ||
        std::signbit(signedDistance));
    // todo: put isZero in a method in Mathutils for better readability.
  }

  double signedDistanceOfPointFromPlane(const Point &point,
                                        const Plane &plane) {

    Vector3D planeToPoint(plane.getPoint(), point);

    return (planeToPoint.dot(plane.getNormal()));
  }

  double distanceOfPointFromPlane(const Point &point, const Plane &plane) {

    return (std::fabs(signedDistanceOfPointFromPlane(point, plane)));
  }

  Point projectionOfPointOnPlane(const Point &point, const Plane &plane) {


    auto pointVector = point.getVector() - (plane.getNormal() *
                          signedDistanceOfPointFromPlane(point, plane));
                          
    return Point(pointVector.getX(), pointVector.getY(), pointVector.getZ());
    // todo: check why need to redefine? Vector3D to Point constr is given.
  }

}
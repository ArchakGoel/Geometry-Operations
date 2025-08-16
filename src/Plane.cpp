#include "Plane.h"
#include "GeomUtils.h"

namespace Entities {

  Plane::Plane(const Point& point, const Vector3D& direction)
      : point(point), normal(direction.normalized()) {

        };

  bool Plane::isPointOnSameSide(const Point &point) const {

    auto signedDistance = Plane::signedDistanceFromPlane(point);

    return (!MathUtils::isZero(signedDistance) && (signedDistance > 0));
  }

  double Plane::signedDistanceFromPlane(const Point &point) const {

    Vector3D planeToPoint(this->point, point);

    return planeToPoint.dot(this->normal);
  }

  double Plane::distanceFromPlane(const Point &point) const {

    return std::abs(signedDistanceFromPlane(point));
  }

  Point Plane::projectionOnPlane(const Point &point) const {

    auto pointVector =
        point.getVector() - (this->normal * signedDistanceFromPlane(point));

    return Point(pointVector.getX(), pointVector.getY(), pointVector.getZ());
  }

  bool Plane::operator==(const Plane &plane) const {

    return (this->normal.isParallel(plane.getNormal()) &&
            MathUtils::isZero(
                Vector3D(this->point, plane.point).dot(this->normal)));
  }
}
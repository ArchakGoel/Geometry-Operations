#include "Plane.h"
#include "GeomUtils.h"

namespace entities {

  Plane::Plane(Point point, Vector3D direction)
      : point(point), normal(direction.normalized()) {

        };

  bool Plane::isPointOnSameSide(const Point &point) const {

    auto signedDistance = Plane::signedDistanceFromPlane(point);

    return !(
        std::fabs(signedDistance < std::numeric_limits<double>::epsilon()) ||
        std::signbit(signedDistance));
  }

  double Plane::signedDistanceFromPlane(const Point &point) const {

    Vector3D planeToPoint(this->point, point);

    return (planeToPoint.dot(this->normal));
  }

  double Plane::distanceFromPlane(const Point &point) const {

    return (std::fabs(signedDistanceFromPlane(point)));
  }

  Point Plane::projectionOnPlane(const Point &point) const {

    auto pointVector =
        point.getVector() - (this->normal * signedDistanceFromPlane(point));

    return Point(pointVector.getX(), pointVector.getY(), pointVector.getZ());
  }

  bool Plane::operator==(const Plane &plane) const {

    return ((this->normal.cross(plane.getNormal()).isZero()) &&
            (std::fabs(Vector3D(this->point, plane.point).dot(this->normal)) <
             precision::CAD::LINEAR));
  }
}
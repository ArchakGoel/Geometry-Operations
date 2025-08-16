#pragma once
#include "Point.h"
#include "Vector3D.h"
namespace Entities {

  class Plane {

    Point point;
    Vector3D normal;

  public:

    explicit Plane(const Point& point, const Vector3D& direction);
    Plane():point(Point()), normal(Vector3D()){};

    Point getPoint() const { return point; }
    Vector3D getNormal() const { return Vector3D(normal); }
    double signedDistanceFromPlane(const Point &) const;
    Point projectionOnPlane(const Point &) const;
    bool isPointOnSameSide(const Point &) const;
    double distanceFromPlane(const Point &point) const;

    bool operator==(const Plane &) const;
  };
}
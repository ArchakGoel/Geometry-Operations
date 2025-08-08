#pragma once
#include "Point.h"
#include "Vector3D.h"
namespace Entities {

  class Plane {

    Point point;
    Vector3D normal;

  public:

    explicit Plane(Point point, Vector3D direction);
    
    Point getPoint() const { return point; }
    Vector3D getNormal() const { return Vector3D(normal); }
    double signedDistanceFromPlane(const Point &) const;
    Point projectionOnPlane(const Point &) const;
    bool isPointOnSameSide(const Point &) const;
    double distanceFromPlane(const Point &point) const;

    bool operator==(const Plane &) const;
  };
}
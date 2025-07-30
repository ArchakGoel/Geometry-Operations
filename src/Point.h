#pragma once
namespace entities {

//!brief: dot and cross product don't apply to points. So no vector3D form.
  class Point{
    double x, y, z;

  public:
    explicit Point(const double x, const double y, const double z)
        :x(x), y(y), z(z) {};
    explicit Point() : x(0.0), y(0.0), z(0.0) {};

    //todo: use precision here.
    bool operator==(const Point &rhs) const {
    return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
  }
    Point operator+(const Point& rhs) const {
      return Point(x+rhs.x, y+rhs.y, z+rhs.z);
    }

    Point operator-(const Point &rhs) const {
      return Point(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    Vector3D getVector() const{
      return Vector3D(x, y, z);
    }
    // todo: write copy constr'
  };

}

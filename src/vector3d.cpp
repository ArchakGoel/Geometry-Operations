#include "vector3d.h"

namespace entities {
  vector3d::vector3d(const double x, const double y, const double z)
      : x(x), y(y), z(z),
        modulus((std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2)))) {
  }

  vector3d::vector3d() : x(0), y(0), z(0), modulus(0) {}

  vector3d::vector3d(const vector3d &object)
      : x(object.getX()), y(object.getY()), z(object.getZ()),
        modulus(object.getModulus()) {}

  double vector3d::getX() const { return x; }

  double vector3d::getY() const { return y; }

  double vector3d::getZ() const { return z; }

  double vector3d::getModulus() const { return modulus; }

  const double vector3d::operator[](size_t index) const {
    switch (index) {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    default:
      throw std::out_of_range("Index out of range\n");
    }
  }

  vector3d vector3d::operator-(const vector3d &rhs) const {
    return vector3d(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
  }

  vector3d vector3d::operator+(const vector3d &rhs) const {
    return vector3d(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
  }

  bool vector3d::operator==(const vector3d &rhs) const {
    return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
  }

  bool vector3d::operator!=(const vector3d &rhs) const {
    return ((x != rhs.x) || (y != rhs.y) || (z != rhs.z));
  }

  vector3d vector3d::operator*(const double scalar) const {
    return (vector3d(x * scalar, y * scalar, z * scalar));
  }

  vector3d vector3d::operator/(const double scalar) const {
    if (scalar != 0) {
      return (vector3d(x / scalar, y / scalar, z / scalar));
    } else {
      throw std::runtime_error("attempting to divide by zero\n");
    }
  }

  double vector3d::dot(const vector3d &rhs) const {
    return (x * rhs.getX() + y * rhs.getY() + z * rhs.getZ());
  }

  vector3d vector3d::cross(const vector3d &rhs) const {
    auto xComponent = (y * rhs.z - z * rhs.y);
    auto yComponent = -(x * rhs.z - z * rhs.x);
    auto zComponent = (x * rhs.y - y * rhs.x);
    return (vector3d(xComponent, yComponent, zComponent));
  }

  vector3d vector3d::normalized() const {
    if (modulus != 0) {
      return vector3d(x / modulus, y / modulus, z / modulus);
    } else {
      throw std::runtime_error("modulus is zero, cannot normalize\n");
    }
  }

  void vector3d::normalize() {
    if (modulus != 0) {
      x = x / modulus;
      y = y / modulus;
      z = z / modulus;
    }
  }

  std::ostream &operator<<(std::ostream &os, const vector3d &object) {
    os << "vector coordinates are: "
          "("
       << object.x << ", " << object.y << ", " << object.z << ")" << "\n";
    return os;
  }

} 

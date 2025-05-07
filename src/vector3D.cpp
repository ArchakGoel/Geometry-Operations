#include "vector3d.h"

namespace entities {
  vector3D::vector3D(const double x, const double y, const double z)
      : x(x), y(y), z(z),
        modulus((std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2)))) {
  }

  vector3D::vector3D() : x(0), y(0), z(0), modulus(0) {}

  vector3D::vector3D(const vector3D &object)
      : x(object.getX()), y(object.getY()), z(object.getZ()),
        modulus(object.getModulus()) {}

  double vector3D::getX() const { return x; }

  double vector3D::getY() const { return y; }

  double vector3D::getZ() const { return z; }

  double vector3D::getModulus() const { return modulus; }

  const double vector3D::operator[](size_t index) const {
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

  vector3D vector3D::operator-(const vector3D &rhs) const {
    return vector3D(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
  }

  vector3D vector3D::operator+(const vector3D &rhs) const {
    return vector3D(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
  }

  bool vector3D::operator==(const vector3D &rhs) const {
    return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
  }

  bool vector3D::operator!=(const vector3D &rhs) const {
    return ((x != rhs.x) || (y != rhs.y) || (z != rhs.z));
  }

  vector3D vector3D::operator*(const double scalar) const {
    return (vector3D(x * scalar, y * scalar, z * scalar));
  }

  vector3D vector3D::operator/(const double scalar) const {
    if (scalar != 0) {
      return (vector3D(x / scalar, y / scalar, z / scalar));
    } else {
      throw std::runtime_error("attempting to divide by zero\n");
    }
  }

  double vector3D::dot(const vector3D &rhs) const {
    return (x * rhs.getX() + y * rhs.getY() + z * rhs.getZ());
  }

  vector3D vector3D::cross(const vector3D &rhs) const {
    auto xComponent = (y * rhs.z - z * rhs.y);
    auto yComponent = -(x * rhs.z - z * rhs.x);
    auto zComponent = (x * rhs.y - y * rhs.x);
    return (vector3D(xComponent, yComponent, zComponent));
  }

  vector3D vector3D::normalized() const {
    if (modulus != 0) {
      return vector3D(x / modulus, y / modulus, z / modulus);
    } else {
      throw std::runtime_error("modulus is zero, cannot normalize\n");
    }
  }

  void vector3D::normalize() {
    if (modulus != 0) {
      x = x / modulus;
      y = y / modulus;
      z = z / modulus;
    }
  }

  std::ostream &operator<<(std::ostream &os, const vector3D &object) {
    os << "vector coordinates are: "
          "("
       << object.x << ", " << object.y << ", " << object.z << ")" << "\n";
    return os;
  }

} 

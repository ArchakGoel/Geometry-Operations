#include "Vector3D.h"

namespace entities {
  Vector3D::Vector3D(const double x, const double y, const double z)
      : x(x), y(y), z(z),
        modulus((std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2)))) {
    isNormalized = isModulusUnity();
  }

  Vector3D::Vector3D() : x(0), y(0), z(0), modulus(0) {
    isNormalized = isModulusUnity();
  }

  Vector3D::Vector3D(const Vector3D &object)
      : x(object.getX()), y(object.getY()), z(object.getZ()),
        modulus(object.getModulus()) {

    isNormalized = isModulusUnity();
  }

  bool Vector3D::isModulusUnity() const { return (modulus == 1.0); }
  double Vector3D::getX() const { return x; }

  double Vector3D::getY() const { return y; }

  double Vector3D::getZ() const { return z; }

  double Vector3D::getModulus() const { return modulus; }

  const double Vector3D::operator[](size_t index) const {
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

  Vector3D Vector3D::operator-(const Vector3D &rhs) const {
    return Vector3D(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
  }

  Vector3D Vector3D::operator+(const Vector3D &rhs) const {
    return Vector3D(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
  }

  bool Vector3D::operator==(const Vector3D &rhs) const {
    return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
  }

  bool Vector3D::operator!=(const Vector3D &rhs) const {
    return ((x != rhs.x) || (y != rhs.y) || (z != rhs.z));
  }

  Vector3D Vector3D::operator*(const double scalar) const {
    return (Vector3D(x * scalar, y * scalar, z * scalar));
  }

  Vector3D Vector3D::operator/(const double scalar) const {
    if (scalar != 0) {
      return (Vector3D(x / scalar, y / scalar, z / scalar));
    } else {
      throw std::runtime_error("attempting to divide by zero\n");
    }
  }

  double Vector3D::dot(const Vector3D &rhs) const {
    return (x * rhs.getX() + y * rhs.getY() + z * rhs.getZ());
  }

  Vector3D Vector3D::cross(const Vector3D &rhs) const {
    auto xComponent = (y * rhs.z - z * rhs.y);
    auto yComponent = -(x * rhs.z - z * rhs.x);
    auto zComponent = (x * rhs.y - y * rhs.x);
    return (Vector3D(xComponent, yComponent, zComponent));
  }

  Vector3D Vector3D::normalized() const {
    if (isNormalized) {
      return Vector3D(*this);
    }
    if (modulus != 0) {
      return Vector3D(x / modulus, y / modulus, z / modulus);
    } else {
      throw std::runtime_error("modulus is zero, cannot normalize\n");
    }
  }

  void Vector3D::normalize() {
    if (modulus != 0) {
      x = x / modulus;
      y = y / modulus;
      z = z / modulus;
      isNormalized = true;
    }
  }

  std::ostream &operator<<(std::ostream &os, const Vector3D &object) {
    os << "vector coordinates are: "
          "("
       << object.x << ", " << object.y << ", " << object.z << ")" << "\n";
    return os;
  }

}

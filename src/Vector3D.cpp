#include "Vector3D.h"
#include "MathUtils.h"
#include "Point.h"

namespace Entities {
  // todo: make modulus optional or through separate method as its expensive.
  Vector3D::Vector3D(const double x, const double y, const double z)
      : x(x), y(y), z(z), modulus(calculateModulus()),
        isNormalized(isModulusUnity()) {}

  Vector3D::Vector3D()
      : x(0.0), y(0.0), z(0.0), modulus(0.0), isNormalized(false) {}

  Vector3D::Vector3D(const Point &point1, const Point &point2)
      : x(point2.getX() - point1.getX()), y(point2.getY() - point1.getY()),
        z(point2.getZ() - point1.getZ()), modulus(calculateModulus()),
        isNormalized(isModulusUnity()) {}

  double Vector3D::operator[](size_t index) const {
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

  bool Vector3D::isModulusUnity() const {
    return MathUtils::isEqual(modulus, 1);
  }

  Vector3D Vector3D::operator-(const Vector3D &rhs) const {
    return Vector3D(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
  }

  Vector3D Vector3D::operator+(const Vector3D &rhs) const {
    return Vector3D(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
  }

  bool Vector3D::operator==(const Vector3D &rhs) const {
    return MathUtils::isEqual(*this, rhs);
  }

  bool Vector3D::operator!=(const Vector3D &rhs) const {
    return !(*this == rhs);
  }

  Vector3D Vector3D::operator*(const double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
  }

  Vector3D Vector3D::operator/(const double scalar) const {
    if (!MathUtils::isZero(scalar)) {
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
    return Vector3D(xComponent, yComponent, zComponent);
  }

  Vector3D Vector3D::normalized() const {
    if (isNormalized) {
      return *this;
    }
    if (!MathUtils::isZero(modulus)) {
      return Vector3D(x / modulus, y / modulus, z / modulus);
    } else {
      throw std::runtime_error("modulus is zero, cannot normalize\n");
    }
  }

  //private.
  double Vector3D::calculateModulus() {
    return (std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2)));
  }

  void Vector3D::normalize() {
    if (!MathUtils::isZero(modulus) && !isNormalized) {
      x = x / modulus;
      y = y / modulus;
      z = z / modulus;
      isNormalized = true;
    }
  }

  bool Vector3D::isZero() const {
    return (MathUtils::isZero(x) && MathUtils::isZero(y) &&
            MathUtils::isZero(z));
  }

  bool Vector3D::isParallel(const Vector3D &rhs) const {

    if (!rhs.isZero() && !this->isZero()) {
      return this->cross(rhs).isZero() && MathUtils::isPositive(this->dot(rhs));
    } else {
      throw std::runtime_error("this vector or input is a zero vector\n");
    }
  }

  bool Vector3D::isAntiparallel(const Vector3D &rhs) const {
    if (!rhs.isZero() && !this->isZero()){
      return this->cross(rhs).isZero() && MathUtils::isNegative(this->dot(rhs));
    } else {
    throw std::runtime_error("this vector or input is a zero vector\n");
    }
  }

  std::ostream &operator<<(std::ostream &os, const Vector3D &object) {
    os << "vector coordinates are: "
          "("
       << object.x << ", " << object.y << ", " << object.z << ")" << "\n";
    return os;
  }

}

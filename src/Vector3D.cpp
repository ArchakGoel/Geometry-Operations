#include "Vector3D.h"
#include "Point.h"

namespace entities {
  //todo: make modulus optional or through separate method as its expensive.
  Vector3D::Vector3D(const double x, const double y, const double z)
      : x(x), y(y), z(z), modulus(calculateModulus()),
        isNormalized(isModulusUnity()) {}

  Vector3D::Vector3D()
      : x(0), y(0), z(0), modulus(0), isNormalized(isModulusUnity()) {}

  Vector3D::Vector3D(const Point &point1, const Point &point2)
      : x(point2.getX() - point1.getX()), y(point2.getY() - point1.getY()),
        z(point2.getZ() - point1.getZ()), modulus(calculateModulus()),
        isNormalized(isModulusUnity()) {}

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
  //todo: use precision
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

  double Vector3D::calculateModulus() {
    return (std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2)));
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

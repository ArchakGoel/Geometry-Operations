#ifndef VECTOR3D
#define VECTOR3D

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace entities {

  class vector3D {
  private:
    double x;
    double y;
    double z;
    double modulus;

  public:
    explicit vector3D(const double, const double, const double);
    explicit vector3D();
    explicit vector3D(const vector3D &);

    double getX() const;
    double getY() const;
    double getZ() const;
    double getModulus() const;

    const double operator[](size_t) const;

    vector3D operator-(const vector3D &) const;
    vector3D operator+(const vector3D &) const;

    bool operator==(const vector3D &) const;
    bool operator!=(const vector3D &) const;

    vector3D operator*(const double) const;
    vector3D operator/(const double) const;

    double dot(const vector3D &) const;
    vector3D cross(const vector3D &) const;

    vector3D normalized() const;
    void normalize();

    friend std::ostream &operator<<(std::ostream &, const vector3D &);
  };

} // namespace entities

#endif
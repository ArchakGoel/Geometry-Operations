#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace entities {

  class vector3d {
  private:
    double x;
    double y;
    double z;
    double modulus;

  public:
    explicit vector3d(const double, const double, const double);
    explicit vector3d();
    explicit vector3d(const vector3d &);

    double getX() const;
    double getY() const;
    double getZ() const;
    double getModulus() const;

    const double operator[](size_t) const;

    vector3d operator-(const vector3d &) const;
    vector3d operator+(const vector3d &) const;

    bool operator==(const vector3d &) const;
    bool operator!=(const vector3d &) const;

    vector3d operator*(const double) const;
    vector3d operator/(const double) const;

    double dot(const vector3d &) const;
    vector3d cross(const vector3d &) const;

    vector3d normalized() const;
    void normalize();

    friend std::ostream &operator<<(std::ostream &, const vector3d &);
  };

}
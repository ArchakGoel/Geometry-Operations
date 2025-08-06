#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>
#include "Constants.h"


namespace entities {

   // todo: make vector class copy and move operator if default is not enough.
  class Point;

  class Vector3D {
  private:
    double x;
    double y;
    double z;
    double modulus;
    bool isNormalized = false;

    double calculateModulus();

  public:
    explicit Vector3D(const double, const double, const double);
    explicit Vector3D(const Point& point1, const Point& point2);
    explicit Vector3D();

    bool isModulusUnity() const;

    double getX() const { return x; }

    double getY() const { return y; }

    double getZ() const { return z; }

    double getModulus() const { return modulus; }

    const double operator[](size_t) const;

    Vector3D operator-(const Vector3D &) const;
    Vector3D operator+(const Vector3D &) const;

    bool operator==(const Vector3D &) const;
    bool operator!=(const Vector3D &) const;

    Vector3D operator*(const double) const;
    Vector3D operator/(const double) const;

    double dot(const Vector3D &) const;
    Vector3D cross(const Vector3D &) const;

    Vector3D normalized() const;
    void normalize();

    bool isZero() const;
    bool isParallel(const Vector3D &) const;
    bool isAntiparallel(const Vector3D & rhs) const;

    friend std::ostream &operator<<(std::ostream &, const Vector3D &);
    
};

}
#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>
#include "Point.h"
namespace entities {

  class Vector3D {
  private:
    double x;
    double y;
    double z;
    double modulus;
    bool isNormalized = false;

    bool isModulusUnity() const;

    double calculateModulus();

  public:
    explicit Vector3D(const double, const double, const double);
    explicit Vector3D(const Point& point1, const Point& point2);

    explicit Vector3D();
    Vector3D(const Vector3D&);

    double getX() const;
    double getY() const;
    double getZ() const;
    double getModulus() const;

    const double operator[](size_t) const;

    Vector3D operator-(const Vector3D &) const;
    Vector3D operator+(const Vector3D &) const;

    bool operator==(const Vector3D &) const;
    bool operator!=(const Vector3D &) const;

    Vector3D operator*(const double) const;
    Vector3D operator/(const double) const;

    double dot(const Vector3D &) const;
    Vector3D cross(const Vector3D &) const;

    Vector3D& operator=(const Vector3D& ob){
        this->x = ob.x;
        return *this;
    }

    Vector3D normalized() const;
    void normalize();

    friend std::ostream &operator<<(std::ostream &, const Vector3D &);
  };

}
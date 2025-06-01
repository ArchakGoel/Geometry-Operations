#ifndef ENTITIES
#define ENTITIES

#include <iostream>
#include <vector>

// namespace {

//   class vector3D {

//     double x, y, z;
//     double modulus;

//   public:
  
//     explicit vector3D(const double _x, const double _y, const double _z)
//         : x(_x), y(_y), z(_z),
//           modulus(
//               (std::sqrt(std::pow(x, 2) + std::pow(y, 2)) + std::pow(z, 2))) {}

//     explicit vector3D():x(0), y(0), z(0), modulus(0){};

//     double getx() const { return x; }
//     double gety() const { return y; }
//     double getz() const { return z; }
//     double getModulus() const { return modulus; }

//     const double operator[](size_t index) const {

//       switch (index) {
//       case 0:
//         return x;
//       case 1:
//         return y;
//       case 2:
//         return z;
//       default:
//         throw std::out_of_range("Index out of range\n");
//       }
//     }

//     vector3D operator-(const vector3D &rhs) const {
//       return vector3D(x - rhs.getx(), y - rhs.gety(), z - rhs.getz());
//     }

//     vector3D operator+(const vector3D &rhs) const {
//       return vector3D(x + rhs.getx(), y + rhs.gety(), z + rhs.getz());
//     }

//     bool operator==(const vector3D &rhs) const {
//       return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
//     }

//     bool operator!=(const vector3D &rhs) const {
//       return ((x != rhs.x) || (y != rhs.y) || (z != rhs.z));
//     }

//     vector3D operator*(const double scalar) const {
//       return (vector3D(x * scalar, y * scalar, z * scalar));
//     }

//     vector3D operator/(const double scalar) const {
//       if (!scalar) {
//         return (vector3D(x / scalar, y / scalar, z / scalar));
//       } else {
//         throw std::runtime_error("atttempting to divide by zero\n");
//       }
//     }

//     double dot(const vector3D &rhs) const {
//       return (x * rhs.getx() + y * rhs.gety() + z * rhs.getz());
//     }

//     vector3D cross(const vector3D &rhs) const {
//       auto xComponent = (y * rhs.z - z * rhs.y);
//       auto yComponent = -(x * rhs.z - z * rhs.x);
//       auto zComponent = (x * rhs.y - y * rhs.x);
//       return (vector3D(xComponent, yComponent, zComponent));
//     }

//     vector3D normalized() const {
//       return vector3D(x / modulus, y / modulus, z / modulus);
//     }

//     void normalize() {
//       x = x / modulus;
//       y = y / modulus;
//       z = z / modulus;
//     }

//     friend std::ostream &operator<<(std::ostream &os, const vector3D &object) {
//       os << "vector coordinates are: "
//             "("
//          << object.x << ", " << object.y << ", " << object.z << ")" << "\n";
//       return os;
//     }
//   };

//   /*Questions:

//   1. for operator == is it better from precision to evaluate using == instead of
//   !=?
//   2.
//   */



  // class line { // is implemented in terms of vector.

  //   point vertex1, vertex2;
  //   vector3D direction;

  // public:
  //   explicit line(const point _vertex1, const point _vertex2)
  //       : vertex1(_vertex1), vertex2(_vertex2),
  //         direction((vertex2.getx() - vertex1.getx()),
  //                   (vertex2.gety() - vertex1.gety()),
  //                   (vertex2.getz() - vertex1.getz())) {};

  //   vector3D getDirection() const { return direction; }

  //   double dot(const line &rhs) const {
  //     return direction.dot(rhs.getDirection());
  //   }
  // };

  // class plane {

  //   vector3D normal;
  //   point pointOnPlane;

  // public:
  //   explicit plane(point inputPoint, vector3D inputNormal)
  //       : pointOnPlane(inputPoint), normal(inputNormal) {};

  //   vector3D getNormal() const { return normal; }
  //   point getPoint() const { return pointOnPlane; }
  // };

#endif

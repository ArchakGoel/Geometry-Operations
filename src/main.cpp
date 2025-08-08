#include "GeomUtils.h"
#include "Plane.h"

int main() {

  // a few initialisations of various Entities objects for smoke tests.
  Entities::Vector3D p1{3, 2, 1};

  Entities::Vector3D p2(4, 2, 1);

  Entities::Line l1(Entities::Point(p1.getX(), p1.getY(), p1.getZ()), Entities::Point(p2.getX(), p2.getY(), p2.getZ())); 
  //note: see what happens if move is made private.

  Entities::Plane plane1(Entities::Point(p1.getX(), p1.getY(), p1.getZ()), p1);

  auto dotVal = p1.dot(p2);

  std::cout << "main is generating output" << dotVal;

  return 0;
}
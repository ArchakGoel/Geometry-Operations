#include "GeomUtils.h"
#include "Plane.h"

int main() {

  // a few initialisations of various entities objects for smoke tests.
  entities::Vector3D p1{3, 2, 1};

  entities::Vector3D p2(4, 2, 1);

  entities::Line l1(entities::Point(p1.getX(), p1.getY(), p1.getZ()), entities::Point(p2.getX(), p2.getY(), p2.getZ())); 
  //note: see what happens if move is made private.

  entities::Plane plane1(entities::Point(p1.getX(), p1.getY(), p1.getZ()), p1);

  auto dotVal = p1.dot(p2);

  std::cout << "main is generating output" << dotVal;

  return 0;
}
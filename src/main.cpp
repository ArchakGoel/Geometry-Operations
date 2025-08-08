#include "GeomUtils.h"
#include "Plane.h"

int main() {

  // a few initialisations of various Entities objects for smoke tests.
  Entities::Vector3D p1{3, 2, 1};

  Entities::Vector3D p2(4, 2, 1);

  Entities::Vector3D p3;

  std::cout << p3 << std::endl;

  Entities::Line l1(Entities::Point(p1.getX(), p1.getY(), p1.getZ()), Entities::Point(p2.getX(), p2.getY(), p2.getZ())); 

  Entities::Plane plane1(Entities::Point(p1.getX(), p1.getY(), p1.getZ()), p1);

  auto dotVal = p1.dot(p2);

  std::cout << "main is generating output. Dot is " << dotVal;

  return 0;
}
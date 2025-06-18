#include "Vector3D.h"

int main() {
  entities::Vector3D p1{3, 2, 1};

  entities::Vector3D p2(4, 2, 1);

  auto dotVal = p1.dot(p2);

  std::cout << dotVal;

  return 0;
}
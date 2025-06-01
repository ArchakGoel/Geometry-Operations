#include "vector3d.h"

int main() {
  entities::vector3d p1{3, 2, 1};

  entities::vector3d p2(4, 2, 1);

  auto dotVal = p1.dot(p2);

  std::cout << dotVal;

  return 0;
}

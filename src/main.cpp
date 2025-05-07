#include "vector3D.h"

int main() {
  entities::vector3D p1{3, 2, 1};

  entities::vector3D p2(4, 2, 1);

  auto dotVal = p1.dot(p2);

  std::cout << dotVal;

  // class test {
  // private:
  //   int member1;
  //   double second;
  //   std::string chaera;

  // public:
  //   int rando;
  //   test() { int a = 2; }
  // };

  return 0;
}

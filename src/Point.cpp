#include "Point.h"
#include "Vector3D.h"

namespace entities
{
    Vector3D Point::getVector() const{
      return Vector3D(x, y, z);
    }
    
}
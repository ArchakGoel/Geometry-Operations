#ifndef LINE
#define LINE

#include "point.h"
#include "vector3D.h"

namespace entities {

  class line {

    point vertex1, vertex2;
    vector3D direction;

  public:
    explicit line(const point _vertex1, const point _vertex2);

    explicit line (const line&);

    vector3D getDirection() const;

    double dot(const line &rhs) const;
  };
} 

//alternate design options:
// 1. namespace with lineoperations limit to 2 inputs.
// 2. lineAnalyzer class
// 3.  

#endif
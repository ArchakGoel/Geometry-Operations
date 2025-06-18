#pragma once


#include "Point.h"
#include "vector3d.h"

namespace entities {

  class line {

    Point vertex1, vertex2;
    vector3d direction;

  public:
    explicit line(const Point _vertex1, const Point _vertex2);

    explicit line (const line&);

    vector3d getDirection() const;

    double dot(const line &rhs) const;
  };
} 

//alternate design options:
// 1. namespace with lineoperations limit to 2 inputs.
// 2. lineAnalyzer class
// 3.  
#pragma once


#include "Point.h"
#include "vector3d.h"

namespace entities {

  class Line {

    Point vertex1, vertex2;
    vector3d direction;

  public:
    explicit Line(const Point _vertex1, const Point _vertex2);

    explicit Line (const Line&);

    vector3d getDirection() const;

    double dot(const Line &rhs) const;
  };
} 

//alternate design options:
// 1. namespace with lineoperations limit to 2 inputs.
// 2. lineAnalyzer class
// 3.  
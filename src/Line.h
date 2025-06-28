#pragma once


#include "Point.h"
#include "Vector3D.h"

namespace entities {

  class Line {

    Point vertex1, vertex2;
    Vector3D direction;

  public:
    explicit Line(const Point _vertex1, const Point _vertex2);

    Line (const Line&);

    Vector3D getDirection() const;

    Point getFirstPoint() const;
    Point getSecondPoint() const;

    // double dot(const Line &rhs) const;

    // Vector3D cross(const Line&rhs) const;
  };
} 

//alternate design options:
// 1. namespace with lineoperations limit to 2 inputs.
// 2. lineAnalyzer class
// 3.  
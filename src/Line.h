#pragma once


#include "Point.h"
#include "Vector3D.h"

namespace entities {

  
  class Line {

    Point vertex1, vertex2;
    Vector3D direction1To2;

  public:
    explicit Line(const Point _vertex1, const Point _vertex2);

    Line (const Line&);

    Vector3D getDirection() const;

  Point getVertex1() const { return vertex1; }
  Point getVertex2() const { return vertex2; }
  };
} 

//todo: change to getDirection1To2() and getDirection2To1();
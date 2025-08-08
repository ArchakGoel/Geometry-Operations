#pragma once


#include "Point.h"
#include "Vector3D.h"
#include "MathUtils.h"
namespace Entities {
  class Line {

    Point vertex1, vertex2;
    Vector3D direction1To2;
    //Vector3D direction2To1;

  public:
    explicit Line(const Point _vertex1, const Point _vertex2);
    Line():vertex1(Point()), vertex2(Point()), direction1To2(Vector3D()){};

    bool operator==(const Line& rhs) const;
    
    bool operator!=(const Line& rhs) const;

    Vector3D getDirection() const { return direction1To2; }
    //Vector3D getDirection1To2() const { return direction1To2; }
    //Vector3D getDirection2To1() const { return direction2To1; }
    Point getVertex1() const { return vertex1; }
    Point getVertex2() const { return vertex2; }
  };
} 


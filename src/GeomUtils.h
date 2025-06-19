#pragma once

#include "Constants.h"
#include "Plane.h"
#include "Line.h"


namespace GeomUtils{

    using namespace entities;

    double signedDistanceOfPointFromPlane(const Point&, const Plane&);
    Point projectionOfPointOnPlane(const Point&, const Plane&);

    bool isPointOnSameSideOfPlane(const Point&, const Plane&);

    bool doLinesIntersect(const Line&, const Line&);
    std::optional<Point> intersectionOfTwoLines(const Line&, const Line&);
}
#pragma once

#include "Constants.h"
#include "Line.h"
#include "Plane.h"

namespace GeomUtils {

  using namespace entities;

  double signedDistanceOfPointFromPlane(const Point &, const Plane &);
  Point projectionOfPointOnPlane(const Point &, const Plane &);

  //! @brief:returns false if point on plane or opposite side.
  bool isPointOnSameSideOfPlane(const Point &, const Plane &);

  bool doLinesIntersect(const Line &, const Line &);
  std::optional<Point> intersectionOfTwoLines(const Line &, const Line &);
}

namespace GeomUtils {
  // 2. Maybe will have to change file name of GeomUtils to GeomOperations

  namespace TwoLines {
    // todo: can make a vector<Line> input instead of separate to avoid
    // interchanging line1 with line2
    //!@brief: A and B are 1st and 2nd points of Line1 and C and D are for
    //!Line2.
    // todo: remove this comment if not required
    class CrossAndDotCalculator {

    private:
      Vector3D aToc;
      std::optional<Vector3D> line1CrossLine2;
      std::optional<Vector3D> aTocCrossLine1;
      std::optional<Vector3D> aTocCrossLine2;

      std::optional<double> line1DotLine2;
      std::optional<double> line1DotLine2Normalized;

      void calculateCross(const Line &, const Line &);

      void calculateDot(); //todo: define this.

    public:
      CrossAndDotCalculator(const Line &line1, const Line &line2,
                            bool doCross = true, bool doDot = false);

      std::optional<Vector3D> getLine1CrossLine2() const {
        return (line1CrossLine2.has_value()? line1CrossLine2 : std::nullopt);
      }
      std::optional<Vector3D> getaTocCrossLine1() const {
        return (aTocCrossLine1.has_value()? aTocCrossLine1 : std::nullopt);;
      }
      std::optional<Vector3D> getaTocCrossLine2() const {
        return (aTocCrossLine2.has_value()? aTocCrossLine2 : std::nullopt);
      }
      Vector3D getVectorAToC() const { return aToc; }
    };

    class MutualOrientationChecker {

      // 1. areSkew
      // 2. areParallel
      // 3, areAntiparallel
      // 4. areCoincident
      // 5. areCollinear

      // other void functions to check skew/parallel/etc.
    };

    using crossAndDotDataPtr = std::shared_ptr<CrossAndDotCalculator>;

    crossAndDotDataPtr makeLinePairAnalysis(const Line &line1,
                                            const Line &line2,
                                            bool doCross = true,
                                            bool doDot = false) {
      return std::make_shared<CrossAndDotCalculator>(line1, line2, doCross,
                                                     doDot);
    }
    class IntersectionChecker {
      // todo: put check for null lines. make rep for null vectors.
      // todo: update type name from "using" for data.
      std::shared_ptr<CrossAndDotCalculator> data;
      std::optional<Point> intersectionPoint;
      Line line1, line2;
      bool intersects;

      double paramLine1, paramLine2;

      void checkIntersectionExistence();

    public:
      // do hasValue() in the client before calling the checker.
      explicit IntersectionChecker(const Line &line1, const Line &line2,
                                   crossAndDotDataPtr crossAndDotData);

      void calculateIntersectionPoint();

      std::vector<Line> getLines() const { return {line1, line2}; }
      std::optional<Point> getIntersectionPoint() const {
        return(intersectionPoint.has_value()?intersectionPoint:std::nullopt);
      }
      bool doLinesIntersect() const { return intersects; }
    };
  }
  //!@brief: Interesection checker for lines in parametric form. Has
  //! optionality to not compute intersection point, and just check if
  //! intersects or not - which will be checked mandatorily in the
  //! constructor.

}

// notes for main usage:
//  check lines are non-zero.
//  check cross-es has value before sending to intersectionChecker, as we are
//  not doing, hasValue check here.
#pragma once

#include "Constants.h"
#include "Line.h"
#include <optional>

using namespace Entities;
namespace GeomUtils {
  namespace TwoLines {
    // note: can make a vector<Line> input instead of separate lines to avoid
    // interchanging line1 with line2
    //!@brief: A and B are 1st and 2nd points of Line1 and C and D are for
    //! Line2.
    class CrossAndDotCalculator {

    private:
      Vector3D aToc;
      Vector3D line1CrossLine2;
      Vector3D aTocCrossLine1;
      Vector3D aTocCrossLine2;

      std::optional<double> line1DotLine2;
      std::optional<double> line1DotLine2Normalized;

      void calculateCross(const Line &, const Line &);

      void calculateDot(const Line &, const Line &) {
        throw std::runtime_error("dot product not implemented");
      }

      CrossAndDotCalculator();
    public:
      CrossAndDotCalculator(const Line &line1, const Line &line2,
                            bool doCross = true, bool doDot = false);

      Vector3D getLine1CrossLine2() const { return line1CrossLine2; }
      Vector3D getaTocCrossLine1() const { return aTocCrossLine1; }
      Vector3D getaTocCrossLine2() const { return aTocCrossLine2; }
      Vector3D getVectorAToC() const { return aToc; }
    };

    class MutualOrientationChecker {

      // 1. areSkew
      // 2. areParallel
      // 3. areAntiparallel
      // 4. areCoincident
      // 5. areCollinear

      // other void functions to check skew/parallel/etc.
    };

    using crossAndDotDataPtr = std::shared_ptr<CrossAndDotCalculator>;
    crossAndDotDataPtr makeLinePairAnalysis(const Line &line1,
                                            const Line &line2,
                                            bool doCross = true,
                                            bool doDot = false);

    //!@brief: Interesection checker for lines in parametric form. Has
    //! optionality to not compute intersection point, and just check if
    //! intersects or not - which will be checked mandatorily in the
    //! constructor.
    class IntersectionChecker {

      Line line1, line2;
      crossAndDotDataPtr data;
      bool intersects = false;
      double paramLine1, paramLine2;
      std::optional<Point> intersectionPoint;

      void checkIntersectionExistence();

      IntersectionChecker();
    public:
      explicit IntersectionChecker(const Line &line1, const Line &line2,
                                   crossAndDotDataPtr crossAndDotData);

      void calculateIntersectionPoint();

      std::vector<Line> getLines() const { return {line1, line2}; }
      std::optional<Point> getIntersectionPoint() const {
        return (intersectionPoint.has_value() ? intersectionPoint
                                              : std::nullopt);
      }
      bool doLinesIntersect() const { return intersects; }
    };
  }

}
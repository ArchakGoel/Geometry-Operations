#pragma once

#include "Constants.h"
#include "Line.h"
#include <optional>

namespace GeomUtils {

  enum class Axis{ X = 0, Y = 1, Z = 2 };
  namespace TwoLines {

    // note: can make a vector<Line> input instead of separate lines to avoid
    // interchanging line1 with line2
    //!@brief: A and B are 1st and 2nd points of Line1 and C and D are for
    //! Line2.
    class CrossAndDotCalculator {

    private:
      Entities::Vector3D aToc;
      Entities::Vector3D line1CrossLine2;
      Entities::Vector3D aTocCrossLine1;
      Entities::Vector3D aTocCrossLine2;

      std::optional<double> line1DotLine2;

      void calculateCross(const Entities::Line &, const Entities::Line &);

      void calculateDot(const Entities::Line &, const Entities::Line &);

      CrossAndDotCalculator();
    public:
      CrossAndDotCalculator(const Entities::Line &line1, const Entities::Line &line2,
                            bool doCross = true, bool doDot = false);

      Entities::Vector3D getLine1CrossLine2() const { return line1CrossLine2; }
      Entities::Vector3D getaTocCrossLine1() const { return aTocCrossLine1; }
      Entities::Vector3D getaTocCrossLine2() const { return aTocCrossLine2; }
      Entities::Vector3D getVectorAToC() const { return aToc; }
       std::optional<double> getDot() const { return line1DotLine2.has_value() ? line1DotLine2 : std::nullopt; }
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
    crossAndDotDataPtr makeLinePairAnalysis(const Entities::Line &line1,
                                            const Entities::Line &line2,
                                            bool doCross = true,
                                            bool doDot = false);

    //!@brief: Interesection checker for lines in parametric form. Has
    //! optionality to not compute intersection point, and just check if
    //! intersects or not - which will be checked mandatorily in the
    //! constructor.
    class IntersectionChecker {

      Entities::Line line1, line2;
      crossAndDotDataPtr data;
      bool intersects = false;
      double paramLine1, paramLine2;
      std::optional<Entities::Point> intersectionPoint;

      void checkIntersectionExistence();
      IntersectionChecker();
      void calculateParametersUsing(Axis axis);

    public:
      explicit IntersectionChecker(const Entities::Line &line1, const Entities::Line &line2,
                                   crossAndDotDataPtr crossAndDotData);

      void calculateIntersectionPoint();

      std::vector<Entities::Line> getLines() const { return {line1, line2}; }
      std::optional<Entities::Point> getIntersectionPoint() const {
        return (intersectionPoint.has_value() ? intersectionPoint
                                              : std::nullopt);
      }
      bool doLinesIntersect() const { return intersects; }
    };
  }

}
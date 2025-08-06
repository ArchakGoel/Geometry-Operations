#include "GeomUtils.h"
#include "MathUtils.h"

namespace GeomUtils {

  using namespace entities;

  namespace TwoLines {

    crossAndDotDataPtr makeLinePairAnalysis(const Line &line1,
                                            const Line &line2, bool doCross,
                                            bool doDot) {
      return std::make_shared<CrossAndDotCalculator>(line1, line2, doCross,
                                                     doDot);
    }

    CrossAndDotCalculator::CrossAndDotCalculator(const Line &line1,
                                                 const Line &line2,
                                                 bool doCross, bool doDot)
        : aToc(Vector3D(line1.getVertex1(), line2.getVertex1())) {

      if (doCross) {
        calculateCross(line1, line2);
      }
      if (doDot) {
        calculateDot(line1, line2);
      }
    };

    void CrossAndDotCalculator::calculateCross(const Line &line1,
                                               const Line &line2) {
      line1CrossLine2 = line1.getDirection().cross(line2.getDirection());
      aTocCrossLine1 = aToc.cross(line1.getDirection());
    }

  }

  namespace TwoLines {

    // todo: shorten/refactor this method.

    void IntersectionChecker::checkIntersectionExistence() {
      if ((data->getLine1CrossLine2().isZero()) &&
          !(data->getaTocCrossLine1().isZero())) { // parallel but not aligned.
        intersects = false;
        return;
      }

      if (!MathUtils::isZero(data->getLine1CrossLine2().dot(data->getVectorAToC()))) // skew
      {
        intersects = false;
        return;
      }

      if ((line1.getVertex1() == line2.getVertex1()) ||
          (line1.getVertex1() == line2.getVertex2()) ||
          (line1.getVertex2() == line2.getVertex1()) ||
          (line1.getVertex2() == line2.getVertex2())) {
        intersects = true;
        return;
      }

      if (!MathUtils::isZero(data->getLine1CrossLine2().getX())) {

        paramLine1 = data->getaTocCrossLine2().getX() /
                     data->getLine1CrossLine2().getX();
        paramLine2 = data->getaTocCrossLine1().getX() /
                     data->getLine1CrossLine2().getX();

      } else if (!MathUtils::isZero(data->getLine1CrossLine2().getY())) {

        paramLine1 = data->getaTocCrossLine2().getY() /
                     data->getLine1CrossLine2().getY();
        paramLine2 = data->getaTocCrossLine1().getY() /
                     data->getLine1CrossLine2().getY();

      } else if (!MathUtils::isZero(data->getLine1CrossLine2().getZ())) {

        paramLine1 = data->getaTocCrossLine2().getZ() /
                     data->getLine1CrossLine2().getZ();
        paramLine2 = data->getaTocCrossLine1().getZ() /
                     data->getLine1CrossLine2().getZ();
      }

      if (paramLine1 < 0 || paramLine1 > 1 || paramLine2 < 0 ||
          paramLine2 > 1) {
        intersects = false;
        return;
      }
    }

    IntersectionChecker::IntersectionChecker(const Line &line1,
                                             const Line &line2,
                                             crossAndDotDataPtr crossAndDotData)
        : line1(line1), line2(line2), data(crossAndDotData) {
      checkIntersectionExistence();
    }

    void IntersectionChecker::calculateIntersectionPoint() {

      if (intersects) {

        auto pointVector =
            Vector3D(line1.getVertex1().getX(), line1.getVertex1().getY(),
                     line1.getVertex1().getZ());

        pointVector = (line1.getDirection() * paramLine1) + pointVector;

        intersectionPoint =
            Point(pointVector.getX(), pointVector.getY(), pointVector.getZ());
        // test by matching with point from paramLine2.
      }
    }

  }

}
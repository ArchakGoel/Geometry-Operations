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
      if ((data->getLine1CrossLine2().value().isZero()) &&
          (data->getaTocCrossLine1().value().isZero())) {
        intersects = false;
        return;
      }

      if (std::fabs(data->getLine1CrossLine2().value().dot(data->getVectorAToC())) >
          precision::CAD::LINEAR) // skew
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

      if (data->getLine1CrossLine2().value().getX() > precision::CAD::LINEAR) {

        paramLine1 = data->getaTocCrossLine2().value().getX() /
                     data->getLine1CrossLine2().value().getX();
        paramLine2 = data->getaTocCrossLine1().value().getX() /
                     data->getLine1CrossLine2().value().getX();

      } else if (data->getLine1CrossLine2().value().getY() >
                 precision::CAD::LINEAR) {

        paramLine1 = data->getaTocCrossLine2().value().getY() /
                     data->getLine1CrossLine2().value().getY();
        paramLine2 = data->getaTocCrossLine1().value().getY() /
                     data->getLine1CrossLine2().value().getY();

      } else if (data->getLine1CrossLine2().value().getZ() >
                 precision::CAD::LINEAR) {

        paramLine1 = data->getaTocCrossLine2().value().getZ() /
                     data->getLine1CrossLine2().value().getZ();
        paramLine2 = data->getaTocCrossLine1().value().getZ() /
                     data->getLine1CrossLine2().value().getZ();
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
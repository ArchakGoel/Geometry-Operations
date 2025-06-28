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
  //! todo:
  // 1. split in .h and .cpp later.
  // 2. Maybe will have to change file name of GeomUtils to GeomOperations

  namespace TwoLines {

    using crossAndDotDataPtr = std::shared_ptr<CrossAndDotCalculator>;
    crossAndDotDataPtr makeLinePairAnalysis(const Line& line1, const Line& line2, bool doCross = true, bool doDot = false) {
    return std::make_shared<CrossAndDotCalculator>(line1, line2,doCross, doDot);
}

    // Possibly a base class storing basic computation params like num, denom,
    // dot. todo: can make a vector<Line> input instead of separate to avoid
    // interchanging line1 with line2

    //!@brief: A and B are 1st and 2nd points of Line1 and C and D are for Line2.

    // todo: remove this comment if not required
    class CrossAndDotCalculator {

    private:
      Vector3D aToc;
      std::optional<Vector3D> line1CrossLine2;
      std::optional<Vector3D> aTocCrossLine1;
      std::optional<Vector3D> aTocCrossLine2;

      std::optional<double> line1DotLine2;
      std::optional<double> line1DotLine2Normalized;

      void calculateCross(const Line &line1, const Line &line2) {
        line1CrossLine2 = line1.getDirection().cross(line2.getDirection());
        aTocCrossLine1 = aToc.cross(line1.getDirection());
      }

      void calculateDot();

    public:
      CrossAndDotCalculator(const Line &line1, const Line &line2,
                            bool doCross = true,
                            bool doDot = false)
          : aToc(Vector3D(line1.getFirstPoint(), line2.getSecondPoint())) {

            if (doCross){
                calculateCross(line1, line2);
            }
            if(doDot){
                calculateDot();
            }
          };

        std::optional<Vector3D> getLine1CrossLine2() const { return line1CrossLine2;}
        std::optional<Vector3D> getaTocCrossLine1() const { return aTocCrossLine1;}
        std::optional<Vector3D> getaTocCrossLine2() const { return aTocCrossLine2;}
        Vector3D getVectorAToC() const { return aToc;}
    };

      class MutualOrientationChecker {

        // 1. areSkew
        // 2. areParallel
        // 3, areAntiparallel
        // 4. areCoincident
        // 5. areCollinear

        // other void functions to check skew/parallel/etc.
      };

      class IntersectionChecker {
        // todo: put check for null lines. make rep for null vectors.

        std::shared_ptr<CrossAndDotCalculator> data;
        std::optional<Point> intersectionPoint;
        Line line1, line2;
        bool intersects;

        double paramLine1, paramLine2;

        bool isCrossProductVectorZero(const Vector3D& vector) const{
            if( fabs(vector.getX()) < precision::LINEAR &&
                fabs(vector.getY()) < precision::LINEAR &&
                fabs(vector.getZ()) < precision::LINEAR){
                return true;
            }
        }

        void checkIntersectionExistence() {
            if( isCrossProductVectorZero(data->getLine1CrossLine2().value()) &&
                isCrossProductVectorZero(data->getaTocCrossLine1().value())){
                intersects = false;
                return;
            }

            if(!(data->getLine1CrossLine2().value().dot(data->getVectorAToC()) < precision::LINEAR)) //skew
            {
                intersects = false;
                return;
            }
            //todo: return point.
            if( (line1.getFirstPoint()==line2.getFirstPoint()) || (line1.getFirstPoint() == line2.getSecondPoint()) ||
                (line1.getSecondPoint() == line2.getFirstPoint()) || (line1.getSecondPoint() == line2.getSecondPoint()) ){
                intersects = true;
                return;
                }

            
            if (data->getLine1CrossLine2().value().getX() > precision::LINEAR){

                paramLine1 = data->getaTocCrossLine2().value().getX() / data->getLine1CrossLine2().value().getX();
                paramLine2 = data->getaTocCrossLine1().value().getX() / data->getLine1CrossLine2().value().getX();

            }else if(data->getLine1CrossLine2().value().getY() > precision::LINEAR){

                paramLine1 = data->getaTocCrossLine2().value().getY() / data->getLine1CrossLine2().value().getY();
                paramLine2 = data->getaTocCrossLine1().value().getY() / data->getLine1CrossLine2().value().getY();

            }else if(data->getLine1CrossLine2().value().getZ() > precision::LINEAR){

                paramLine1 = data->getaTocCrossLine2().value().getZ() / data->getLine1CrossLine2().value().getZ();
                paramLine2 = data->getaTocCrossLine1().value().getZ() / data->getLine1CrossLine2().value().getZ();
            }

            if (paramLine1 < 0 || paramLine1 > 1 || paramLine2 < 0 || paramLine2 > 1){
                intersects = false;
                return;
            }

        }

      public:
        //do hasValue() in the client before calling the checker.
        explicit IntersectionChecker(const Line &line1, const Line &line2, crossAndDotDataPtr crossAndDotData)
            : line1(line1), line2(line2), data(crossAndDotData) {

          checkIntersectionExistence();
        }

        Point intersectionPoint() const {
            //todo: 1. make a 3D operator only base class for point and vector common.
            //todo: 2. Point copy operator non explicit.

            if(intersects){

                auto pointVector = Vector3D(line1.getFirstPoint().getX(), line1.getFirstPoint().getY(), 
                                            line1.getFirstPoint().getZ());

                pointVector = (line1.getDirection()*paramLine1) + pointVector;

                return Point(pointVector.getX(), pointVector.getY(), pointVector.getZ());
            }

        }

        std::vector<Line> getLines() const { return {line1, line2}; }
        // todo: make vector class copy and move operator.
        // todo: implement this return style everywhere else.

        bool doLinesIntersect() const { return intersects; }
      };
    }

    //note: "lineIntersectionChecker" is not enough, as it doesn't tell line intersection with what and how many?.\
    Hence the name "TwoLinesIntersectionChecker".
    //!@brief: Interesection checker for lines in parametric form. Has
    //! optionality to not compute intersection point, and just check if
    //! intersects or not - which will be checked mandatorily in the
    //! constructor.

  }

  //notes for main usage:
    // check lines are non-zero.
    // check cross-es has value before sending to intersectionChecker, as we are not doing, hasValue check here.
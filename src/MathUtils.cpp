#include "MathUtils.h"
#include "Point.h"
#include "Vector3D.h"

namespace MathUtils {

  bool isPositive(const double a, const double epsilon) { return a > epsilon; }

  bool isNegative(const double a, const double epsilon) { return a < -epsilon; }

  bool isZero(const double a, const double epsilon) {
    return std::abs(a) < epsilon;
  }
  bool isEqual(const double a, const double b, const double epsilon) {
    return (std::abs(b - a) <= epsilon);
  }
  bool isLinearEqual(const double a, const double b, const double epsilon) {
    return (MathUtils::isEqual(a, b, epsilon));
  };

  bool isAngularEqual(const double a, const double b, const double epsilon) {
    return (MathUtils::isEqual(a, b, epsilon));
  };

  bool isEqual(const Entities::Vector3D &vector1,
               const Entities::Vector3D &vector2, double epsilon) {
    return (isLinearEqual(vector1.getX(), vector2.getX()) &&
            (isLinearEqual(vector1.getY(), vector2.getY())) &&
            (isLinearEqual(vector1.getZ(), vector2.getZ())));
  };

  bool isEqual(const Entities::Point &point1, const Entities::Point &point2,
               double epsilon) {
    return (isLinearEqual(point1.getX(), point2.getX()) &&
            (isLinearEqual(point1.getY(), point2.getY())) &&
            (isLinearEqual(point1.getZ(), point2.getZ())));
  };

  double round(float value, const int Precision) {
    int multiplier = std::pow(10, Precision);
    value = (int)(value * multiplier + .5);
    return (double)value / multiplier;
  }

}

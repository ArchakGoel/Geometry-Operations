#pragma once
#include "Constants.h"

namespace MathUtils {

  double isEqual(double a, double b,
                 double epsilon = precision::Math::EPSILON) {
    return (std::abs(b - a) <= epsilon);
  };
  
  double isLinearEqual(double a, double b,
                       double epsilon = precision::CAD::LINEAR) {
    return (MathUtils::isEqual(a, b, epsilon));
  };

  double isAngularEqual(double a, double b,
                        double epsilon = precision::CAD::ANGULAR) {
    return (MathUtils::isEqual(a, b, epsilon));
  };

  double round(float value, int precision = 3) {
    int multiplier = std::pow(10, precision);
    value = (int)(value * multiplier + .5);
    return (double)value / multiplier;
  }
};

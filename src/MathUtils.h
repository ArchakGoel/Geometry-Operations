#pragma once
#include "Constants.h"
  namespace entities {
      class Vector3D; 
      class Point;     
  }
namespace MathUtils {

  bool isPositive(const double a, const double epsilon = precision::Math::EPSILON);

  bool isNegative(const double a, const double epsilon = precision::Math::EPSILON);

  bool isZero(const double a, const double epsilon = precision::Math::EPSILON);

  bool isEqual(const double a, const double b,
                        const double epsilon = precision::Math::EPSILON);

  bool isLinearEqual(const double a, const double b,
                        const double epsilon = precision::CAD::LINEAR);

  bool isAngularEqual(const double a, const double b,
                    const double epsilon = precision::CAD::ANGULAR);

  bool isEqual(const entities::Vector3D& vector1, const entities::Vector3D& vector2, 
                double tolerance = precision::CAD::LINEAR);

  bool isEqual(const entities::Point& point1, const entities::Point& point2, 
                double tolerance = precision::CAD::LINEAR);

  double round(float value, const int precision = 3);
};

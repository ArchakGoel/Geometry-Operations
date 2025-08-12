#pragma once
#include "Constants.h"
  namespace Entities {
      class Vector3D; 
      class Point;     
  }
namespace MathUtils {

  bool isPositive(const double a, const double epsilon = Precision::Math::EPSILON);

  bool isNegative(const double a, const double epsilon = Precision::Math::EPSILON);

  bool isZero(const double a, const double epsilon = Precision::Math::EPSILON);

  bool isEqual(const double a, const double b,
                        const double epsilon = Precision::Math::EPSILON);

  bool isLinearEqual(const double a, const double b,
                        const double epsilon = Precision::CAD::LINEAR);

  bool isAngularEqual(const double a, const double b,
                    const double epsilon = Precision::CAD::ANGULAR);

  bool isEqual(const Entities::Vector3D& vector1, const Entities::Vector3D& vector2, 
                double tolerance = Precision::CAD::LINEAR);
  bool isEqual(const Entities::Vector3D& vector1, const Entities::Vector3D& vector2);

  bool isEqual(const Entities::Point& point1, const Entities::Point& point2);

  double round(float value, const int Precision = 3);
};

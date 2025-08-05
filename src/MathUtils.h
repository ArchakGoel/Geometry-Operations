#pragma once
#include "Constants.h"

namespace MathUtils {

    bool isZero(double x, double epsilon = precision::Math::EPSILON);

    double round(float value, int precision = 3){
        int multiplier = std::pow(10, precision);
        value = (int)(value * multiplier + .5);
        return (double)value / multiplier;
    }

    double isEqual(double a, double b, double epsilon = precision::Math::EPSILON) {
        return (std::abs(b - a) <= epsilon);
    };
};

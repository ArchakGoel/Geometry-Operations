#pragma once
#include "Constants.h"

namespace MathUtils {

    bool isZero(double x, double epsilon = std::numeric_limits<double>::epsilon());

    double round(float value, int precision = 3);

    static double approxEqual(double a, double b, double epsilon = 1e-6) {
        double difference = fabs(b - a);
        return (difference <= epsilon);
    };
};

#include "MathUtils.h"


namespace MathUtils {

    bool isZero(double x, double epsilon) {
        return std::abs(x) < epsilon;
    }

    double round(float value, int precision) {
        int multiplier = std::pow(10, precision);
        value = (int)(value * multiplier + .5);
        return (double)value / multiplier;
    }

}

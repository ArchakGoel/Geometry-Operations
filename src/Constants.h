#pragma once
#include <cmath>

namespace precision{
    namespace CAD{

        const double LINEAR = 1.0e-7;
        const double ANGULAR = 1.0e-12;

    }
    namespace Math{
        double EPSILON = std::numeric_limits<double>::epsilon();
    }
}
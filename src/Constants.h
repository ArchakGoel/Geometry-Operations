#pragma once
#include <limits>

namespace precision{
    namespace CAD{

        inline constexpr double LINEAR = 1.0e-7;
        inline const double ANGULAR = 1.0e-12;

    }
    namespace Math{
        inline constexpr double EPSILON = std::numeric_limits<double>::epsilon();
    }
}
#pragma once
#include <limits>

namespace Precision{
    namespace CAD{

        inline constexpr double LINEAR = 1.0e-7;
        inline constexpr double ANGULAR = 1.0e-12;

    }
    namespace Math{
        inline constexpr double EPSILON = std::numeric_limits<double>::epsilon();
    }
}
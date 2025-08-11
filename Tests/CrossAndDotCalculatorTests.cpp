// #include <gtest/gtest.h>
// #include "GeomUtils.h"
// #include "Line.h"
// #include "Point.h"
// #include "Vector3D.h"
// #include "MathUtils.h"
// #include <cmath>

// using namespace Entities;
// using namespace GeomUtils::TwoLines;

// class CrossAndDotCalculatorTest : public ::testing::Test {
// protected:
//     void SetUp() override {
//         // Common test setup
//     }
// };

// // Test 1: Perpendicular lines cross product
// TEST_F(CrossAndDotCalculatorTest, PerpendicularLinesCross) {
//     Line line1(Point(0, 0, 0), Point(1, 0, 0));     // X-axis direction
//     Line line2(Point(0, 0, 0), Point(0, 1, 0));     // Y-axis direction
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D crossProduct = calculator.getLine1CrossLine2();
    
//     // Cross product of X-axis and Y-axis should be Z-axis
//     EXPECT_TRUE(MathUtils::isEqual(crossProduct.getX(), 0.0));
//     EXPECT_TRUE(MathUtils::isEqual(crossProduct.getY(), 0.0));
//     EXPECT_TRUE(MathUtils::isEqual(crossProduct.getZ(), 1.0));
// }

// // Test 2: Parallel lines cross product should be zero
// TEST_F(CrossAndDotCalculatorTest, ParallelLinesCrossIsZero) {
//     Line line1(Point(0, 0, 0), Point(1, 0, 0));     // X-axis direction
//     Line line2(Point(0, 1, 0), Point(2, 1, 0));     // Parallel to X-axis
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D crossProduct = calculator.getLine1CrossLine2();
    
//     EXPECT_TRUE(crossProduct.isZero());
// }

// // Test 3: Vector A to C calculation
// TEST_F(CrossAndDotCalculatorTest, VectorAToCCalculation) {
//     Line line1(Point(1, 2, 3), Point(4, 5, 6));     // Line from A(1,2,3) to B
//     Line line2(Point(7, 8, 9), Point(10, 11, 12));  // Line from C(7,8,9) to D
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D vectorAToC = calculator.getVectorAToC();
    
//     // Vector from A(1,2,3) to C(7,8,9) should be (6,6,6)
//     EXPECT_TRUE(MathUtils::isEqual(vectorAToC.getX(), 6.0));
//     EXPECT_TRUE(MathUtils::isEqual(vectorAToC.getY(), 6.0));
//     EXPECT_TRUE(MathUtils::isEqual(vectorAToC.getZ(), 6.0));
// }

// // Test 4: Cross product aToc × line1
// TEST_F(CrossAndDotCalculatorTest, ATocCrossLine1) {
//     Line line1(Point(0, 0, 0), Point(1, 0, 0));     // X-axis direction (1,0,0)
//     Line line2(Point(0, 1, 0), Point(1, 1, 0));     // aToc = (0,1,0)
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D aTocCrossLine1 = calculator.getaTocCrossLine1();
    
//     // (0,1,0) × (1,0,0) = (0,0,-1)
//     EXPECT_TRUE(MathUtils::isEqual(aTocCrossLine1.getX(), 0.0));
//     EXPECT_TRUE(MathUtils::isEqual(aTocCrossLine1.getY(), 0.0));
//     EXPECT_TRUE(MathUtils::isEqual(aTocCrossLine1.getZ(), -1.0));
// }

// // Test 5: Cross product aToc × line2
// TEST_F(CrossAndDotCalculatorTest, ATocCrossLine2) {
//     Line line1(Point(0, 0, 0), Point(1, 0, 0));     // Line1 direction (1,0,0)
//     Line line2(Point(0, 1, 0), Point(0, 2, 0));     // Line2 direction (0,1,0), aToc = (0,1,0)
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D aTocCrossLine2 = calculator.getaTocCrossLine2();
    
//     // (0,1,0) × (0,1,0) = (0,0,0) - same vector cross itself is zero
//     EXPECT_TRUE(aTocCrossLine2.isZero());
// }

// // Test 6: 3D cross product calculation
// TEST_F(CrossAndDotCalculatorTest, ThreeDimensionalCross) {
//     Line line1(Point(0, 0, 0), Point(1, 2, 3));     // Direction (1,2,3)
//     Line line2(Point(0, 0, 0), Point(4, 5, 6));     // Direction (4,5,6)
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D crossProduct = calculator.getLine1CrossLine2();
    
//     // (1,2,3) × (4,5,6) = (2*6-3*5, 3*4-1*6, 1*5-2*4) = (12-15, 12-6, 5-8) = (-3,6,-3)
//     EXPECT_TRUE(MathUtils::isEqual(crossProduct.getX(), -3.0));
//     EXPECT_TRUE(MathUtils::isEqual(crossProduct.getY(), 6.0));
//     EXPECT_TRUE(MathUtils::isEqual(crossProduct.getZ(), -3.0));
// }

// // Test 7: Cross product magnitude for unit vectors
// TEST_F(CrossAndDotCalculatorTest, UnitVectorsCrossMagnitude) {
//     Line line1(Point(0, 0, 0), Point(1, 0, 0));     // Unit X
//     Line line2(Point(0, 0, 0), Point(0, 1, 0));     // Unit Y
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D crossProduct = calculator.getLine1CrossLine2();
//     double magnitude = crossProduct.getModulus();
    
//     // Cross product of two unit perpendicular vectors should have magnitude 1
//     EXPECT_TRUE(MathUtils::isEqual(magnitude, 1.0));
// }

// // Test 8: Antiparallel lines cross product
// TEST_F(CrossAndDotCalculatorTest, AntiparallelLinesCross) {
//     Line line1(Point(0, 0, 0), Point(1, 0, 0));     // Direction (1,0,0)
//     Line line2(Point(0, 0, 0), Point(-2, 0, 0));    // Direction (-2,0,0) - antiparallel
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D crossProduct = calculator.getLine1CrossLine2();
    
//     // Antiparallel vectors should have zero cross product
//     EXPECT_TRUE(crossProduct.isZero());
// }

// // Test 9: Cross product properties - anti-commutative
// TEST_F(CrossAndDotCalculatorTest, CrossProductAntiCommutative) {
//     Line line1(Point(0, 0, 0), Point(1, 2, 0));
//     Line line2(Point(0, 0, 0), Point(3, 1, 0));
    
//     CrossAndDotCalculator calc1(line1, line2, true, false);
//     CrossAndDotCalculator calc2(line2, line1, true, false);
    
//     Vector3D cross1 = calc1.getLine1CrossLine2();
//     Vector3D cross2 = calc2.getLine1CrossLine2();
    
//     // line1 × line2 = -(line2 × line1)
//     EXPECT_TRUE(MathUtils::isEqual(cross1.getX(), -cross2.getX()));
//     EXPECT_TRUE(MathUtils::isEqual(cross1.getY(), -cross2.getY()));
//     EXPECT_TRUE(MathUtils::isEqual(cross1.getZ(), -cross2.getZ()));
// }

// // Test 10: Edge case - very small vectors
// TEST_F(CrossAndDotCalculatorTest, SmallVectorsCross) {
//     double small = 1e-10;
//     Line line1(Point(0, 0, 0), Point(small, 0, 0));
//     Line line2(Point(0, 0, 0), Point(0, small, 0));
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D crossProduct = calculator.getLine1CrossLine2();
    
//     // Even very small perpendicular vectors should give a cross product
//     EXPECT_TRUE(MathUtils::isEqual(crossProduct.getZ(), small * small));
// }

// // Test 11: Constructor with dot calculation disabled should not crash
// TEST_F(CrossAndDotCalculatorTest, DotCalculationDisabled) {
//     Line line1(Point(0, 0, 0), Point(1, 0, 0));
//     Line line2(Point(0, 1, 0), Point(1, 1, 0));
    
//     // This should not crash even though dot calculation throws
//     EXPECT_NO_THROW({
//         CrossAndDotCalculator calculator(line1, line2, true, false);
//     });
// }

// // Test 12: Cross product orthogonality
// TEST_F(CrossAndDotCalculatorTest, CrossProductOrthogonality) {
//     Line line1(Point(0, 0, 0), Point(1, 1, 0));
//     Line line2(Point(0, 0, 0), Point(-1, 1, 0));
    
//     CrossAndDotCalculator calculator(line1, line2, true, false);
    
//     Vector3D crossProduct = calculator.getLine1CrossLine2();
//     Vector3D line1Dir = line1.getDirection();
//     Vector3D line2Dir = line2.getDirection();
    
//     // Cross product should be orthogonal to both input vectors
//     EXPECT_TRUE(MathUtils::isZero(crossProduct.dot(line1Dir)));
//     EXPECT_TRUE(MathUtils::isZero(crossProduct.dot(line2Dir)));
// }
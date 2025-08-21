#include <gtest/gtest.h>
#include "GeomUtils.h"
#include "Line.h"
#include "Point.h"
#include "Vector3D.h"
#include "MathUtils.h"

using namespace Entities;
using namespace GeomUtils;

//todo: 1. if it makes sense to replace EXPECT with ASSERT.
//todo: 2. Get parameters of lines too if needed.

class LineIntersectionTests : public ::testing::Test {
protected:
    void SetUp() override {

    }
};

// Test 1: Lines intersecting at midpoint
TEST_F(LineIntersectionTests, IntersectionAtMidpoint) {
    Line line1(Point(0, 0, 0), Point(2, 0, 0));  // X-axis from 0 to 2
    Line line2(Point(1, -1, 0), Point(1, 1, 0)); // Vertical line at x=1
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);
    
    EXPECT_TRUE(checker.doLinesIntersect());
    
    checker.calculateIntersectionPoint();
    auto intersection = checker.getIntersectionPoint();
    
    ASSERT_TRUE(intersection.has_value());
    EXPECT_TRUE(MathUtils::isEqual(intersection->getX(), 1.0));
    EXPECT_TRUE(MathUtils::isEqual(intersection->getY(), 0.0));
    EXPECT_TRUE(MathUtils::isEqual(intersection->getZ(), 0.0));
}

// Test 2: Lines intersecting at endpoints
TEST_F(LineIntersectionTests, IntersectionAtEndpoint) {
    Line line1(Point(0, 0, 0), Point(1, 1, 0));
    Line line2(Point(1, 1, 0), Point(2, 0, 0));
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);
    
    EXPECT_TRUE(checker.doLinesIntersect());
    
    checker.calculateIntersectionPoint();
    auto intersection = checker.getIntersectionPoint();
    
    ASSERT_TRUE(intersection.has_value());
    EXPECT_TRUE(MathUtils::isEqual(intersection->getX(), 1.0));
    EXPECT_TRUE(MathUtils::isEqual(intersection->getY(), 1.0));
}

// Test 3: Skew lines
TEST_F(LineIntersectionTests, SkewLines) {
    Line line1(Point(0, 0, 0), Point(1, 0, 0));     
    Line line2(Point(1, 1, 1), Point(1, -1, 2));    
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);
    
    EXPECT_FALSE(checker.doLinesIntersect());
    
    checker.calculateIntersectionPoint();
    auto intersection = checker.getIntersectionPoint();
    EXPECT_FALSE(intersection.has_value());
}

// Test 4: Parallel lines
TEST_F(LineIntersectionTests, ParallelNonAligned) {
    Line line1(Point(0, 0, 0), Point(1, 0, 0));     
    Line line2(Point(0, 1, 0), Point(1, 1, 0));
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);
    
    EXPECT_FALSE(checker.doLinesIntersect());
}

// todo: Test 5: passes but investigate.
TEST_F(LineIntersectionTests, CoincidentLines) {
    Line line1(Point(0, 0, 0), Point(2, 0, 0));
    Line line2(Point(1, 0, 0), Point(3, 0, 0));     // Overlapping on same line
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);

    EXPECT_TRUE(checker.doLinesIntersect());
}

// Test 6: Lines intersecting beyond endpoints (parametric intersection outside [0,1])
TEST_F(LineIntersectionTests, IntersectionBeyondEndpoints) {
    Line line1(Point(0, 0, 0), Point(1, 0, 0));     
    Line line2(Point(2, -1, 0), Point(2, 1, 0));    
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);

    
    EXPECT_FALSE(checker.doLinesIntersect()); 
}

// Test 7: 3D intersection
TEST_F(LineIntersectionTests, ThreeDimensionalIntersection) {
    Line line1(Point(0, 0, 0), Point(1, 1, 1));     // Diagonal in 3D
    Line line2(Point(0, 1, 0), Point(1, 0, 1));     // Another 3D line
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);
    
    if (checker.doLinesIntersect()) {
        checker.calculateIntersectionPoint();
        auto intersection = checker.getIntersectionPoint();
        ASSERT_TRUE(intersection.has_value());
        

        EXPECT_TRUE(MathUtils::isEqual(intersection->getX(), 0.5));
        EXPECT_TRUE(MathUtils::isEqual(intersection->getY(), 0.5));
    }
}

// Test 8: Edge case - very small lines
TEST_F(LineIntersectionTests, SmallLines) {
    Line line1(Point(0, 0, 0), Point(1e-6, 0, 0));
    Line line2(Point(0, -1e-6, 0), Point(0, 1e-6, 0));
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);
    
    EXPECT_TRUE(checker.doLinesIntersect());
}

// Test 9: Lines at Precision boundary
TEST_F(LineIntersectionTests, PrecisionBoundary) {
    double epsilon = Precision::CAD::LINEAR;
    Line line1(Point(0, 0, 0), Point(1, 0, 0));
    Line line2(Point(0.5, -epsilon, 0), Point(0.5, epsilon, 0));
    
    auto data = TwoLines::makeLinePairAnalysis(line1, line2);
    TwoLines::IntersectionChecker checker(line1, line2, data);
    
    EXPECT_TRUE(checker.doLinesIntersect());
}

// Test 10: Dot Product Check
TEST_F(LineIntersectionTests, DotProducts){

    Line line1(Point(3, 2, 0), Point(2, 1, 0));
    Line line2(Point(1, 1, 0 ), Point(2, 3, 0));

    auto data = TwoLines::makeLinePairAnalysis(line1, line2, true, true);
    EXPECT_TRUE(MathUtils::isEqual(data->getDot().value(),-3));

}
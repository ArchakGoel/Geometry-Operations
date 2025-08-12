#include <gtest/gtest.h>
#include "Plane.h"
#include "Point.h"
#include "Vector3D.h"
#include "MathUtils.h"

using namespace Entities;

class PlaneTests : public ::testing::Test {
protected:
    void SetUp() override {
    }
};

//Basic plane construction
TEST_F(PlaneTests, BasicConstruction) {
    Point origin(0, 0, 0);
    Vector3D normalZ(0, 0, 1);
    
    Plane plane(origin, normalZ);
    
    EXPECT_TRUE(MathUtils::isEqual(plane.getPoint(), origin));
    EXPECT_TRUE(MathUtils::isEqual(plane.getNormal(), normalZ));
}

//Point on plane
TEST_F(PlaneTests, PointOnPlane) {
    Point origin(0, 0, 0);
    Vector3D normalZ(0, 0, 1);  
    Plane plane(origin, normalZ);
    
    Point pointOnPlane(5, 3, 0);
    Point anotherPointOnPlane(-2, 7, 0);
    
    EXPECT_TRUE(MathUtils::isZero(plane.signedDistanceFromPlane(pointOnPlane)));
    EXPECT_TRUE(MathUtils::isZero(plane.signedDistanceFromPlane(anotherPointOnPlane)));
    EXPECT_TRUE(MathUtils::isZero(plane.distanceFromPlane(pointOnPlane)));
}

//Points above and below plane
TEST_F(PlaneTests, PointsAboveAndBelowPlane) {
    Point origin(0, 0, 0);
    Vector3D normalZ(0, 0, 1);  
    Plane plane(origin, normalZ);
    
    Point pointAbove(1, 2, 5);
    Point pointBelow(3, -1, -3);
    
    EXPECT_TRUE(plane.signedDistanceFromPlane(pointAbove) > 0);
    EXPECT_TRUE(plane.signedDistanceFromPlane(pointBelow) < 0);
    EXPECT_TRUE(plane.isPointOnSameSide(pointAbove));
    EXPECT_FALSE(plane.isPointOnSameSide(pointBelow));
}

//Distance calculations
TEST_F(PlaneTests, DistanceCalculations) {
    Point origin(0, 0, 0);
    Vector3D normalZ(0, 0, 1);
    Plane plane(origin, normalZ);
    
    Point testPoint(2, 3, 4);
    
    EXPECT_TRUE(MathUtils::isEqual(plane.signedDistanceFromPlane(testPoint), 4.0));
    EXPECT_TRUE(MathUtils::isEqual(plane.distanceFromPlane(testPoint), 4.0));
    
    Point belowPoint(1, 1, -2.5);
    EXPECT_TRUE(MathUtils::isEqual(plane.signedDistanceFromPlane(belowPoint), -2.5));
    EXPECT_TRUE(MathUtils::isEqual(plane.distanceFromPlane(belowPoint), 2.5));
}

//Projection onto plane
TEST_F(PlaneTests, ProjectionOntoPlane) {
    Point origin(0, 0, 0);
    Vector3D normalZ(0, 0, 1);
    Plane plane(origin, normalZ);
    
    Point testPoint(3, 4, 7);
    Point projection = plane.projectionOnPlane(testPoint);
    
    EXPECT_TRUE(MathUtils::isEqual(projection.getX(), 3.0));
    EXPECT_TRUE(MathUtils::isEqual(projection.getY(), 4.0));
    EXPECT_TRUE(MathUtils::isEqual(projection.getZ(), 0.0));
    
    EXPECT_TRUE(MathUtils::isZero(plane.distanceFromPlane(projection)));
}

//Plane equality
TEST_F(PlaneTests, PlaneEquality) {
    Point origin(0, 0, 0);
    Vector3D normalZ(0, 0, 1);
    Plane plane1(origin, normalZ);
    
    Point differentPoint(5, 3, 0);
    Plane plane2(differentPoint, normalZ);
    
    EXPECT_TRUE(plane1 == plane2);
    
    Vector3D normalY(0, 1, 0);
    Plane plane3(origin, normalY);
    
    EXPECT_FALSE(plane1 == plane3);
}

//Projection preserves in-plane coordinates
TEST_F(PlaneTests, ProjectionPreservesInPlaneCoordinates) {
    Point origin(0, 0, 0);
    Vector3D normalY(0, 1, 0); 
    Plane plane(origin, normalY);
    
    Point testPoint(3, 5, 7);
    Point projection = plane.projectionOnPlane(testPoint);
    
    EXPECT_TRUE(MathUtils::isEqual(projection.getX(), 3.0));  
    EXPECT_TRUE(MathUtils::isEqual(projection.getY(), 0.0));  
    EXPECT_TRUE(MathUtils::isEqual(projection.getZ(), 7.0));  
}

//Multiple projections
TEST_F(PlaneTests, MultipleProjections) {
    Point planePoint(1, 2, 3);
    Vector3D normal(0, 0, 1);
    Plane plane(planePoint, normal);
    
    Point point1(5, 6, 10);
    Point point2(-2, 3, -1);
    
    Point proj1 = plane.projectionOnPlane(point1);
    Point proj2 = plane.projectionOnPlane(point2);
    
    EXPECT_TRUE(MathUtils::isZero(plane.distanceFromPlane(proj1)));
    EXPECT_TRUE(MathUtils::isZero(plane.distanceFromPlane(proj2)));
    
    EXPECT_TRUE(MathUtils::isEqual(proj1.getZ(), 3.0));
    EXPECT_TRUE(MathUtils::isEqual(proj2.getZ(), 3.0));
}

//Edge cases - point very close to plane
TEST_F(PlaneTests, PointCloseToPlane) {
    Point origin(0, 0, 0);
    Vector3D normalZ(0, 0, 1);
    Plane plane(origin, normalZ);
    
    // Point very close to plane (within precision tolerance)
    double epsilon = Precision::CAD::LINEAR;
    Point closePoint(1, 2, epsilon/2);
    
    EXPECT_TRUE(MathUtils::isZero(plane.signedDistanceFromPlane(closePoint)));
    EXPECT_TRUE(MathUtils::isZero(plane.distanceFromPlane(closePoint)));
}
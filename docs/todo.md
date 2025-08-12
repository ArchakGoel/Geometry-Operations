# Code specific

## General

1. Remove explicit from default constructors. Done
2. Initialize all members of every class in a constructor even if default is needed. Done
3. Check what type of functions should go inline in header and what not. For example, point const'r.-- simple returns should go inline. DONE.
4. Method of getting angle betweeen vectors.
5. MathUtils for isEqual using precision. Very urgent for all == operators. DONE
6. Forward declaration can be used everywhere. Check if worth the advantage other than for resolving circular dependency. DONE
7. There is no need for custom definitions of the famous 5. It was only done for practice. Remove as much as possible with a note. More custom operators lead to more bugs. DONE
8. Separate src and include folders. Not Needed now - DONE
9. Round off double representation of real numbers in the final result/calculation.

## Vector Class

1. Remove << from friend.
2. Add precision comparison in all places in class where needed. Done.
3. If two vectors are parallel or antiparallel. DONE
4. Templatize vectors and points. As it will help save memory if an external library wants to export in another numeric data type that takes less memory than double.

## Line Class

1. change to getDirection1To2() and getDirection2To1();
2. == operator here. DONE
3. should = be made private? as two same lines would be inconsistent geometry. Same for point.
4. Add wrapper to IntersectionChecker *

## JSONS

1. change shell to cppbuild again. DONE

## Tests*

1. Add Gtests. Done
2. Add tests example: simple line intersections case: yes, skew, coincident, overlapping. Maybe 1 cross component zero, r or s > 1 and < 0. DONE

## Point Class

1. Remove is a inheritance from vector. As a point is not a vector. Make composition. Return a vector form if needed, by passing origin and point. DONE

## GeomUtils

1. Think again if its better software to put line utility operations in line class. No. DONE
2. If Line and Vector and other entities leave GeomUtils such that their includes are not needed. Move isEqual to GeomUtils with forward declarations.


## MathUtils

1. Considering renaming to GeometryComparison. For Future.
2. isNotEqual in MathUtils.
3. test epsilon is used or not in ` bool isEqual(const Entities::Point &point1, const Entities::Point &point2,
               double epsilon)`. Done

## Tests

1. Make sure overlapping lines are handled correctly for intersection point**
2. Fix precision test that is failing. DONE

## Notes

### Vector and Point common stuff for base class

1. == operator
2. . getters
3. != operators
4. + operators
5. + operator
6. + scalar multiplier.
7. NOT isZero(). zero point is origin.
8. [] opeartor
9. osstream
10. isEqual in MathUtils.

## Reading/Concepts

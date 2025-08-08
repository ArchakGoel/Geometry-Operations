# Code specific

## General

1. Check what type of functions should go in line in header and what not. For example, point const'r.-- simple returns should go inline
2. Method of getting angle betweeen vectors.
3. Cmake.
4. MathUtils for isEqual using precision. Very urgent for all == operators. DONE
5. Forward declaration can be used everywhere. Check if worth the advantage other than for resolving circular dependency. DONE
6. There is no need for custom definitions of the famous 5. It was only done for practice. Remove as much as possible with a note. More custom operators lead to more bugs. DONE
7. Check constexpr need even in getters in Scott's book.
8. Check =default guidelines in Scott's book.

## Vector Class

1. {} operator - not needed. Works for vector3D{}
2. fix the return issues with copy constr'. Check Scott Meyer's advice on removing explicit from copy const'r.
3. = operator make default. Done
4. Remove << from friend.
5. Advantage of Template over keeping just double.
6. Add precision comparison in all places in class where needed. Done 
7. If two vectors are parallel or antiparallel.

## Line Class

1. Define edge, for 2 points.
2. change to getDirection1To2() and getDirection2To1();
3. == operator here. done
4. should = be made private? as two same lines would be inconsistent geometry. Same for point.
5. Add wrapper to IntersectionChecker *

## JSONS

1. change shell to cppbuild again.
2. Remove //namespace in automatic clang format.

## Tests

1. Add Gtests.
2. Add tests example: simple line intersections case: yes, skew, coincident, overlapping. Maybe 1 cross component zero, r or s > 1 and < 0.

## Point Class

1. Remove is a inheritance from vector. As a point is not a vector. Make composition. Return a vector form if needed, by passing origin and point. -- done.


## GeomUtils

1. Think again if its better software to put line utility operations in line class.
2. If Line and Vector and other entities leave GeomUtils such that their includes are not needed. Move isEqual to GeomUtils with forward declarations.
3.  

## MathUtils

1. Considering renaming to GeometryComparison

## Notes

### Vector and Point common stuff for base class

1. == operator
2. . getters
3. != operators
4. + operators
5. - operator
6. * scalar multiplier.
7. NOT isZero(). zero point is origin.
8. [] opeartor
9. osstream


## Reading/Concepts

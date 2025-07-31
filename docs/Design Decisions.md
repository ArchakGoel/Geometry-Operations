General:
1. Rule of 5 only when custom ones are really needed. Avoid unnecessary clutter.
2. To avoid issues for circular dependency, removed includes and included forward class declarations.

Vector3D Class

1. ostream is a friend to allow usage in correct format: `cout << vector object`. Otherwise if its a member function, it would have to be `object << ` 
2. [] operator is not returning a reference, as its a just a small double value and its not intended to be changed. Keeping it simple.
3. Keep everything in a named or unnamed namespace for avoiding name conflicts.
4. Keep constructors explicit to avoid implicit conversions which is bug prone.
5. Make sure to never allow setMethods to set x, y, z and modulus in vector3D. That can cause lot of issues, mismatching modulus, incorrect values and so on.
6. Since we have normalized() function, member IsNormalized was introduced to avoid re-computing normalization repeatedly as its expensive operation.


Line Class

1. A line segment is not a vector. So no public inhertance but composition of point and vector.
2. Dot and Cross operators are for pure vectors, hence not defined for line. Extract the direction from line and then use dot and cross on the vector.



GeomUtils namespace

1. Functions common to lines, planes and other entities for geometric operations are kept here. Its very complicated to keep them in classes of individual entities. For example, in a member fucntion based approach, point to plane distance goes in point or plane class or both?
2. Getter methods are set to inline without the keyword. Its inline by default.
3. Re-start a new {} under the last level namespace for separation of definitions belonging to a different class in a .cpp file. This is for ease of readability.
4.  "lineIntersectionChecker" is not enough, as it doesn't tell line intersection with what and how many?. Hence the name "TwoLinesIntersectionChecker".
5.  Cross and Dot Calculator:
    1.  not storing lines. The client will have access to lines given as input, so not needed. Plus not needed anywhere after constructor.

Point Class

1. A point is not a vector. So it is not inherited as a vector3D or made available in that format via composition. For example, vector operators like Dot and cross product don't apply to a point.


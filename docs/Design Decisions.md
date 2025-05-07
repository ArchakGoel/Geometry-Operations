Vector3D Class

1. ostream is a friend to allow usage in correct format: `cout << vector object`. Otherwise if its a member function, it would have to be `object << `
2. [] operator is not returning a reference, as its a just a small double value and its not intended to be changed. Keeping it simple.
3. Keep everything in a named or unnamed namespace for avoiding name conflicts.
4. Keep constructors explicit to avoid implicit conversions which is bug prone.
5. Make sure to never allow setMethods to set x, y, z and modulus in vector3D. That can cause lot of issues, mismatching modulus, incorrect values and so on.

Line Class

1. A line segment is not a vector. So no public inhertance but composition of point and vector.
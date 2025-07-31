1. Keep methods non-member non-friend as much as possible for encapsulation.
2. Supporter methods keep them standalone, grouped in namespaces under separate header files based on sub-grouping. Like GeomUtils.
3. Use smart pointers. Check customer deleters for arrays and such. Declare and initialize in separate line without clubbing with other functions.


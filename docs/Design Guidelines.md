1. Rule of 5 only when custom ones are really needed. Avoid unnecessary clutter. Plus they are very bug prone when new data members are added or removed.
   1. put them as = default to show intent. 
2. Keep methods non-member non-friend as much as possible for encapsulation.
3. Supporter methods keep them standalone, grouped in namespaces under separate header files based on sub-grouping. Like GeomUtils.
4. Use smart pointers. Check customer deleters for arrays and such. Declare and initialize in separate line without clubbing with other functions.
5. Use forward declarations when possible.
6. Keep methods inline in .h file when there is only 1 line.
7. Keep non-util headers or all headers forward declaration if possible in all util .h files. Even if at the cost of leaving inlining. This is to avoid circular includes problem.


# Design Guidelines

1. Class members that are private and not marked "private" as its by default and reduces code clutter.
2. Rule of 5 only when custom ones are really needed. Avoid unnecessary clutter. Plus they are very bug prone when new data members are added or removed.
   1. put them as = default to show intent.
3. Keep methods non-member non-friend as much as possible for encapsulation.
4. Supporter methods keep them standalone, grouped in namespaces under separate header files based on sub-grouping. Like GeomUtils.
5. Use smart pointers. Check customer deleters for arrays and such. Declare and initialize in separate line without clubbing with other functions.
6. Use forward declarations when possible.
7. Keep methods inline in .h file when there is only 1 line.
8. Keep non-util headers or all headers forward declaration if possible in all util .h files. Even if at the cost of leaving inlining. This is to avoid circular includes problem.
9. Advantage of Template over keeping just double - Facilitates memory savings for float types while using with other libs. Otherwise not needed here, double is enough.
10. Default Constructors should be looked into. Prefer to mention for all classes - private or public. Default or custom. As they could be called by compiler with un-initialized data members which can be a hard bug to find.

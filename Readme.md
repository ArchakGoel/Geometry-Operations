# Geometry-Operations (In Works)

Basic 3D vector algebra elements and operations. This code is in works. Designed to be stand-alone. The individual files like Vector3D, Line, Plane, MathUtils etc. can be separated out to use in your code library. Everything is in 3 dimensions. Here is the overall structure:

1. Contains classes of geometric entities like vector, line, point, plane and associated methods. All files are located in ./src folder.
2. Contains a geometric utility .h and .cpp file by name GeomUtils for operations like finding intersections of two lines, orientations, cross and dot products and so on. These oprations are grouped under appropriate classes and namespaces for minimizing code repitition, and facilatiting modularization and readability.
3. A set of documents to describe the naming convention, design decisions and design guidelines I have followed are included in ./doc folder. Its written properly but with goal of my own reference or or for somebody to join the repo. There is also a file wise todo document for my own use. I put anything or that catches my interest and I want to include in my code.

## Compatibility

1. Setup to run on MacOS ARM architecture using .json setup files on Visual Studio.
2. Future goal to develop a cross-platform cmake system.

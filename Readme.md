# Geometry-Operations (Works but in Works)

An effort to showcase production quality code for basic 3D vector algebra elements and operations using modern C++. A lot of focus is on clean code, modularity, ease of readability and minimal repitition and simplicity. So you'll see pointers and rule of 3/5 only when extremely necessary or none at all. Designed to be stand-alone. The individual files like Vector3D, Line, Plane, MathUtils etc. can be separated out to use in your code library. Everything is in 3 dimensions. Here is the overall structure:

1. Contains classes of geometric entities like vector, line, point, plane and associated methods. All code files are located in `./src` folder.
2. Contains a geometric utility .h and .cpp file by name GeomUtils for operations like finding intersections of two lines, orientations, cross and dot products and so on. These oprations are grouped under appropriate classes and namespaces for minimizing code repitition, and facilatiting modularization and readability.
3. A set of documents to describe the usage, naming convention, design decisions and design guidelines I have followed are included in `./doc` folder. Its written properly but with goal of my own reference or or for somebody to join the repo.
  1. There is also a quite organized todo document for my own use also in `./docs`. If you think of something, "why is this not put that way", there is a good chance I haven't been able to come to it yet and its in my list of todos. I put there anything that catches my interest to take my code to the next level.

## Tests

1. Tests are in `./Tests` folder. All except 1 tests pass for Line-Line Intersections.
2. More tests are planned for Plane-Point operations and other features in GeomUtils.

## Compatibility

1. Setup to run on Apple Silicon machines using .json setup files on Visual Studio. 
2. Future goal to develop a cross-platform cmake system.

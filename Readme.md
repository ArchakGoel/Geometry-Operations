# Geometry-Operations

An effort to showcase production quality code for basic 3D vector algebra elements and operations using modern C++. A lot of focus is on clean code, modularity, ease of readability and minimal repitition and simplicity. So you'll see pointers and rule of 3/5 only when extremely necessary or none at all. Everything is in 3 dimensions. Here is the overall structure:

1. Contains classes of geometric entities like vector, line, point, plane and associated methods. All code files are located in `./src` folder.
2. Contains a geometric utility "GeomUtils" for operations like finding intersections of two lines, orientations, cross and dot products and so on. These oprations are grouped under appropriate classes and namespaces for minimizing code repitition, and facilatiting modularization and readability.
3. A set of documents to describe the usage, naming convention, design decisions and design guidelines I have followed are included in `./docs` folder. Its written properly for my own reference or or for somebody to join the repo.
   1. There is also a quite organized `todo.md` document for my own use also in `./docs`. If you think of something, "why is this not put that way", there is a good chance I haven't been able to come to it yet and its in my list of todos. I put there anything that catches my interest to take my code to the next level.

This is developed to be a stand-alone project. The individual files like Vector3D, Line, Plane, MathUtils etc. can be extracted out of this project to use in your code as a library. Please add authorship credits if so.

## Tests

1. Tests are in `./Tests` folder.

## Compatibility

1. Setup to run on Apple Silicon machines using .json setup files on Visual Studio Code.
2. Future goal is to develop a cross-platform CMAKE system and to add more geometric functionalities.

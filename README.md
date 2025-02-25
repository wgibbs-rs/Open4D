
<div align="center">
 <img alt="The Official Logo for Open4D."src="img/Open4DText.png" width="75%" />
</div>

# Open4D
Open4D is a lightweight library for simulating four dimensional physics and geometry. Built with usability in mind, Open4D aims to provide a toolkit for various usages of 4D physics. Regardless of needs, Open4D provides a robust toolkit for hobbiests, developers, and researchers exploring four dimensional space.

# Usage
Built with usage in mind, Open4D is a library which provides decentralized tools for simulating physics and geometry. Open4D currently supports physics simulation, tetrahedral geometry, and creating 3D slices.

## Physics
Physics simulation relies on an object-based animation system. To create an object with physical values, create an OFD_Rigidbody. This struct contains values on the object's physical transform, as well as its structure. To animate this object by a given time interval, calling `OFD_AnimateRigidbody` can animate all features of the object, including translational velocity and position, angular velocity and rotation, and collision.

All OFD_Rigidbody objects are considered to be able to collide. To allow objects to collide with only specific other objects, or with no objects, all collidable rigidbodies are provided when calling `OFD_AnimateRigidbody`. For an object that shouldn't collide, no collidable object's should be provided.

All OFD_Rigidbodies have an OFD_Transform value. The OFD_Transform structure contains information on

- Position (m)
- Velocity (m/s)
- Rotation (degrees)
- Rotational Velocity (degrees/second)
- Mass (kg)
- Restitution
- Static Friction
- Kinetic Friction
- Rolling Friction
- Moment of Inertia

Currently, Moment of Inertia uses a single value for all planes of rotation. This is not the real-world calculation, but a placeholder during development. While it can provide a realistic simulation, this value is not perfect, and should be redone in the future.

## Creating a 3D Slice
To view 4D objects, we can take a 3D slice of its geometry. To create a slice of a given OFD_Mesh, we can call `OFD_SliceMesh`, providing the mesh we'd like to take a slice from, and the W position of our slice. This function will return a pointer to an array of OFD_Triangles. 

As well as providing an array of OFD_Triangles, Open4D also provides a series of functions to gather vertex positions for use outside of Open4D.

- `OFD_TriangleToX(OFD_Triangle3D tri)` returns a pointer to the x positions of a triangle's vertices.
- `OFD_TriangleToY(OFD_Triangle3D tri)` returns a pointer to the y positions of a triangle's vertices.
- `OFD_TriangleToZ(OFD_Triangle3D tri)` returns a pointer to the z positions of a triangle's vertices.
- `OFD_TriangleToArray(OFD_Triangle3D tri` returns the vertices of the triangle as a 2D array.

To simplify the process of calculating and slicing geometries, all rigidbodies are defined as an array of tetrahedrons. Slicing individual tetrahedrons proves drastically faster and more efficient than algorithms that slice through complex shapes, so Open4D slices through each tetrahedron individually.

There is currently no standard way to convert a standard 4D mesh to tetrahedrons. The most common way to convert a mesh to tetrahedrons is by taking each triangle and connecting it to a center point. This does not work for more complex shapes, but does work for primitives, like cubes, dodecahedra, or octohedra.
# Contributing
We welcome any and all developers interested in contributing to this project. Open4D is *for* developers of any background, and we encourage developers of any background to contribute. If you're unsure how to contribute to the project, we heavily advise looking at the open Github Issues. These forums can provide insight into what needs immediate work, and how new users can contribute. To help develop this software, users must follow a few conventions and rules for development.
## Getting Started
1. **Fork the Repository:** Click the "Fork" button at the top of the repository to create your own copy. While any development to the project is encourages, a fork should attempt to stay on topic, so as to keep this project organized.
2. **Clone the Fork:** After forking the project source code, clone this fork to your machine to work on it individually.
3. **Create a new Branch:** After adding your contributions on *your* machine, commit these changes to a new branch. This branch should be named appropriately to reflect the changes you plan on contributing. This way, other users can contribute to the same changes.
4. **Implement your changes:** Fix a bug, add a feature, or write some documentation.
5. **Push your Branch:** After you've implemented your changes, you can push this branch to the fork you previously created.
6. **Open a Pull Request:** After merging the branch, create a Pull Request (PR) to have your changes reviewed and made official. Go to the official Open4D Github repository. On the "Pull Requests" tab, click "Open Pull Request" and follow the given instructions.
## Contribution Guidelines
While contributions to Open4D are encouraged and welcomed, we want to ensure the project stays organized and usable. To do this, we've implemented a few rules that should be followed. **If these rules cannot be followed, contact an Open4D administrator.
- **Do not create a new file.** All current files for Open4D are compiled and used across the software. Creating new files can introduce underlying issues and slow down the efficiency of the project. If you'd like to create a new file, request a file in the repositories Issues section.
- **Do not use any external libraries.** This software is intended to be a lightweight physics library. Introducing libraries for things like rendering, physics, or computation is unnecessary. If you must do so, open an Issue to discuss this with other collaborators.
- **Do not upload broken code.** While you may commit *incomplete* code to your branch, do not commit broken, errored, or bugged code to the official repository. This code will be rejected.
- **Using a language other than C/C++:** While we encourage developers to seek out the best and most efficient ways to implement features, we want to maintain portability to almost all platforms. Additions to the core physics/geometry library **must** be in C/C++, and any non-C/C++ additions should not be a dependency. Languages that are inefficient or interpreted, like R or Python should never be used for real-time work, like cross-sections or physics. **If you are adding a new language binding,** you can use any languages needed. This must be a binding itself, and should **not** be introduced to the official code.
## Issues
Given the advanced nature of higher-dimensional space, and the community-oriented development of Open4D, errors and bugs are inevitable. If you observe a runtime error or bug, go to the *Issues* tab on Github. From there, create a new issue, creating an appropriate title and documentation of the bug, including the platform it occured on, the environment involved in creating this issue, and any printed errors or codes provided by the library. Everyone is welcome to contribute to Issues, and discussion should remain civil, aiming to fix the issue and contribute to the project.

# Non-Developers
Open4D is a physics engine with a strong focus on kinematics and geometry. If you do not know how to code, or how to code in C/C++ (Given you're implementing core functionality), there are still ways to contribute. If you have a background in physics, higher dimensional geometry, or other topics that may be valuable to development, there are still ways to contribute. On our Github Wiki, there's information on the math behind our project. If you'd like to update or correct this math, you can create a new Issue, and work with other developers to implement of fix previous mathmatical concepts. For non-developers interested in adding new methods or features to this library, the same process is used. 

- **Create an issue** to let C/C++ developers know you're looking to implement a concept.
- **Implement the changes** to a seperate fork and branch, following the steps in the Contributing section.
- **Update the documentation** once the appropriate changes have been made.

# Legal
Open4D is licensed under the "ZLib License" In short, any usage of this project is permitted, so long as the original license is included, a change to the software is noted, and the product is not claimed to be the creation of any individual other than William Gibbs, S.V, or the Open4D open-source community. This is not legal advice. For the official license for Open4D, go to LICENSE.


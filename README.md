
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

- `OFD_TriangleToX(OFD_Triangle3D tri)` returns the x positions of a triangle's vertices.
- `OFD_TriangleToY(OFD_Triangle3D tri)` returns the y positions of a triangle's vertices.
- `OFD_TriangleToArray(OFD_Triangle3D tri` returns the vertices of the triangle as a 2D array.

To simplify the process of calculating and slicing geometries, all rigidbodies are defined as an array of tetrahedrons. Slicing individual tetrahedrons proves drastically faster and more efficient than algorithms that slice through complex shapes, so Open4D slices through each tetrahedron individually.

There is currently no standard way to convert a standard 4D mesh to tetrahedrons. The most common way to convert a mesh to tetrahedrons is by taking each triangle and connecting it to a center point. This does not work for more complex shapes, but does work for primitives, like cubes, dodecahedra, or octohedra.
# Contributing

 TODO

## Issues

 TODO

# Legal

 MIT License? LGPL? ZLib?



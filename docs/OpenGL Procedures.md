# OpenGL Procedures

Assorted helper OpenGL procedures.

**Include File**: AfxGlut.inc.

| Name       | Description |
| ---------- | ----------- |
| [AfxGlutSolidCone](#AfxGlutCone) | Draws a solid cone. |
| [AfxGlutWireCone](#AfxGlutCone) | Draws a wireframe cone. |
| [AfxGlutSolidCube](#AfxGlutCube) | Draws a solid cube. |
| [AfxGlutWireCube](#AfxGlutCube) | Draws a wireframe cube. |
| [AfxGlutSolidCylinder](#AfxGlutCylinder) | Draws a solid cylinder. |
| [AfxGlutWireCylinder](#AfxGlutCylinder) | Draws a wireframe cylinder. |
| [AfxGlutSolidDodecahedron](#AfxGlutDodecahedron) | Draws a solid dodecahedron. |
| [AfxGlutWireDodecahedron](#AfxGlutDodecahedron) | Draws a wireframe dodecahedron. |
| [AfxGlutSolidIcosahedron](#AfxGlutSolidIcosahedron) | Draws a solid icosahedron. |
| [AfxGlutWireIcosahedron](#AfxGlutWireIcosahedron) | Draws a wireframe icosahedron. |
| [AfxGlutSolidOctahedron](#AfxGlutSolidOctahedron) | Draws a solid octahedron. |
| [AfxGlutWireOctahedron](#AfxGlutWireOctahedron) | Draws a wireframe octahedron. |
| [AfxGlutSolidRhombicDodecahedron](#AfxGlutSolidRhombicDodecahedron) | Draws a solid rhombic dodecahedron. |
| [AfxGlutWireRhombicDodecahedron](#AfxGlutWireRhombicDodecahedron) | Draws a wireframe rhombic dodecahedron. |
| [AfxGlutSolidSphere](#AfxGlutSolidSphere) | Renders a solid sphere centered at the origin of the modeling coordinate system. |
| [AfxGlutWireSphere](#AfxGlutWireSphere) | Renders a wireframe sphere centered at the origin of the modeling coordinate system. |
| [AfxGlutSolidTeapot](#AfxGlutSolidTeapot) | Renders a solid teapot of the desired size, centered at the origin. |
| [AfxGlutSolidTeapot](#AfxGlutSolidTeapot) | Renders a wireframe teapot of the desired size, centered at the origin. |
| [AfxGlutSolidTetrahedron](#AfxGlutSolidTetrahedron) | Renders a solid tetrahedron. |
| [AfxGlutWireTetrahedron](#AfxGlutWireTetrahedron) | Renders a wireframe tetrahedron. |
| [AfxGlutSolidTorus](#AfxGlutSolidTorus) | Renders a solid torus (doughnut shape). |
| [AfxGlutWireTorus](#AfxGlutWireTorus) | Renders a wireframe torus (doughnut shape). |

# <a name="AfxGlutCone"></a>AfxGlutSolidCone / AfxGlutWireCone

Renders a right circular cone with a base centered at the origin and in the X-Y plane and its tip on the positive Z-axis. The wire cone is rendered with triangular elements.

```
SUB AfxGlutSolidCone (BYVAL dbase AS DOUBLE, BYVAL height AS DOUBLE, _
   BYVAL slices AS LONG, BYVAL stacks AS LONG)
```
```
SUB AfxGlutWireCone (BYVAL dbase AS DOUBLE, BYVAL height AS DOUBLE, _
   BYVAL slices AS LONG, BYVAL stacks AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *dbase* | The desired radius of the base of the cone. |
| *height* | The desired height of the cone. |
| *slices* | The desired number of slices around the cone. |
| *stacks* | The desired number of segments between the base and the tip of the cone (the number of points, including the tip, is stacks + 1). |

# <a name="AfxGlutCube"></a>AfxGlutSolidCube / AfxGlutWireCube

Renders a cube of the desired size, centered at the origin. Its faces are normal to the coordinate directions.

```
SUB AfxGlutSolidCube (BYVAL dbSize AS DOUBLE)
SUB AfxGlutWireCube (BYVAL dbSize AS DOUBLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *dbSize* | The desired length of an edge of the cube. |

# <a name="AfxGlutCylinder"></a>AfxGlutSolidCylinder / AfxGlutWireCylinder

Renders a right circular cone with a base centered at the origin and in the X-Y plane and its tip on the positive Z-axis. The wire cone is rendered with triangular elements.

```
SUB AfxGlutSolidCylinder (BYVAL radius AS DOUBLE, BYVAL height AS DOUBLE, _
   BYVAL slices AS LONG, BYVAL stacks AS LONG)
```
```
SUB AfxGlutWireCylinder (BYVAL radius AS DOUBLE, BYVAL height AS DOUBLE, _
   BYVAL slices AS LONG, BYVAL stacks AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *radius* | The desired radius of the cylinder. |
| *height* | The desired height of the cylinder. |
| *slices* | The desired number of slices around the cylinder. |
| *stacks* | The desired number of segments between the base and the top of the cylinder (the number of points, including the tip, is stacks + 1). |

# <a name="AfxGlutDodecahedron"></a>AfxGlutSolidDodecahedron / AfxGlutWireDodecahedron

Renders a solid dodecahedron (12-sided Platonic solid). The **AfxGlutSolidDodecahedron** procedure renders a dodecahedron whose corners are each a distance of sqrt(3) from the origin. The length of each side is sqrt(5)-1. There are twenty corners; interestingly enough, eight of them coincide with the corners of a cube with sizes of length 2.

```
SUB AfxGlutSolidDodecahedron
SUB AfxGlutWireDodecahedron
```

#include "stdafx.h"
#include "Dodecahedron.h"
#include "Ray.h"
#include "Intersection.h"

std::vector<Vertex> vertices = {
		Vertex({0.745355992500, 0.577350269190, 0.333333333333}), // 0
		Vertex({0.127322003750, 0.934172358963, 0.333333333333}), // 1
		Vertex({0.666666666667, -0.000000000000, 0.745355992500}), // 2
		Vertex({-0.333333333333, 0.577350269190, 0.745355992500}), // 3
		Vertex({0.000000000000, -0.000000000000, 1.000000000000}), // 4
		Vertex({-0.666666666667, -0.000000000000, -0.745355992500}), // 5
		Vertex({-0.000000000000, -0.000000000000, -1.000000000000}), // 6
		Vertex({-0.745355992500, -0.577350269190, -0.333333333333}), // 7
		Vertex({0.333333333333, -0.577350269190, -0.745355992500}), // 8
		Vertex({-0.127322003750, -0.934172358963, -0.333333333333}), // 9
		Vertex({-0.872677996250, 0.356822089773, 0.333333333333}), // 10
		Vertex({-0.872677996250, -0.356822089773, 0.333333333333}), // 11
		Vertex({-0.333333333333, -0.577350269190, 0.745355992500}), // 12
		Vertex({0.872677996250, -0.356822089773, -0.333333333333}), // 13
		Vertex({0.333333333333, 0.577350269190, -0.745355992500}), // 14
		Vertex({0.872677996250, 0.356822089773, -0.333333333333}), // 15
		Vertex({0.127322003750, -0.934172358963, 0.333333333333}), // 16
		Vertex({0.745355992500, -0.577350269190, 0.333333333333}), // 17
		Vertex({-0.127322003750, 0.934172358963, -0.333333333333}), // 18
		Vertex({-0.745355992500, 0.577350269190, -0.333333333333}), // 19
};

std::vector<Face> faces = {
	Face(0, 1, 2),
	Face(1, 3, 2),
	Face(3, 4, 2),
	Face(5, 6, 7),
	Face(6, 8, 7),
	Face(8, 9, 7),
	Face(10, 11, 3),
	Face(11, 12, 3),
	Face(12, 4, 3),
	Face(8, 6, 13),
	Face(6, 14, 13),
	Face(14, 15, 13),
	Face(16, 17, 12),
	Face(17, 2, 12),
	Face(2, 4, 12),
	Face(14, 6, 18),
	Face(6, 5, 18),
	Face(5, 19, 18),
	Face(13, 15, 17),
	Face(15, 0, 17),
	Face(0, 2, 17),
	Face(5, 7, 19),
	Face(7, 11, 19),
	Face(11, 10, 19),
	Face(18, 19, 1),
	Face(19, 10, 1),
	Face(10, 3, 1),
	Face(8, 13, 9),
	Face(13, 17, 9),
	Face(17, 16, 9),
	Face(7, 9, 11),
	Face(9, 16, 11),
	Face(16, 12, 11),
	Face(14, 18, 15),
	Face(18, 1, 15),
	Face(1, 0, 15),
};

const CTriangleMeshData CDodecahedron::m_triangleMeshData = CTriangleMeshData(vertices, faces);

CDodecahedron::CDodecahedron(
	CMatrix4d const& transform
)
	:CGeometryObjectWithInitialTransformImpl(transform)
	, m_triangleMesh(CTriangleMesh(&m_triangleMeshData, transform))
{
}

bool CDodecahedron::Hit(CRay const& ray, CIntersection& intersection)const
{
	return m_triangleMesh.Hit(ray, intersection);
}

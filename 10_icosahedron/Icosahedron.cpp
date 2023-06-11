#include "stdafx.h"
#include "Icosahedron.h"
#include "Ray.h"
#include "Intersection.h"

std::vector<Vertex> vertices = {
		Vertex({0.850651, 0.000000, -0.525731}), // 0
		Vertex({-0.850651, 0.000000, -0.525731}), // 1
		Vertex({0.850651, 0.000000, 0.525731}), // 2
		Vertex({-0.850651, 0.000000, 0.525731}), // 3
		Vertex({0.525731, 0.850651, 0.000000}), // 4
		Vertex({0.525731, -0.850651, 0.000000}), // 5
		Vertex({-0.525731, 0.850651, 0.000000}), // 6
		Vertex({-0.525731, -0.850651, 0.000000}), // 7
		Vertex({0.000000, 0.525731, -0.850651}), // 8
		Vertex({0.000000, 0.525731, 0.850651}), // 9
		Vertex({0.000000, -0.525731, -0.850651}), // 10
		Vertex({0.000000, -0.525731, 0.850651}), // 11
};

std::vector<Face> faces = {
	Face(0, 8, 4),
	Face(0, 5, 10),
	Face(2, 4, 9),
	Face(2, 11, 5),
	Face(1, 6, 8),
	Face(1, 10, 7),
	Face(3, 9, 6),
	Face(3, 7, 11),
	Face(0, 10, 8),
	Face(1, 8, 10),
	Face(2, 9, 11),
	Face(3, 11, 9),
	Face(4, 2, 0),
	Face(5, 0, 2),
	Face(6, 1, 3),
	Face(7, 3, 1),
	Face(8, 6, 4),
	Face(9, 4, 6),
	Face(10, 5, 7),
	Face(11, 7, 5),
};
const CTriangleMeshData CIcosahedron::m_triangleMeshData = CTriangleMeshData(vertices, faces);

CIcosahedron::CIcosahedron(
	CMatrix4d const& transform
)
	:CGeometryObjectWithInitialTransformImpl(transform)
	,m_triangleMesh(CTriangleMesh(&m_triangleMeshData, transform))
{
}

bool CIcosahedron::Hit(CRay const& ray, CIntersection& intersection)const
{
	return m_triangleMesh.Hit(ray, intersection);
}

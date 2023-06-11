#include "stdafx.h"
#include "Octahedron.h"
#include "Ray.h"
#include "Intersection.h"

std::vector<Vertex> vertices = {
		Vertex({0, 1, 0}), // 0
		Vertex({ 1, 0, 0 }), // 1
		Vertex({ 0, 0, -1 }), // 2
		Vertex({ -1, 0, 0 }), // 3
		Vertex({ 0, 0, 1 }), // 4
		Vertex({ 0, -1, 0 }), // 5
};

std::vector<Face> faces = {
	Face(0, 1, 2),
	Face(0, 2, 3),
	Face(0, 3, 4),
	Face(0, 4, 1),
	Face(2, 1, 5),
	Face(3, 2, 5),
	Face(4, 3, 5),
	Face(1, 4, 5),
};

const CTriangleMeshData COctahedron::m_triangleMeshData = CTriangleMeshData(vertices, faces);

COctahedron::COctahedron(
	CMatrix4d const& transform
)
	:CGeometryObjectWithInitialTransformImpl(transform)
	, m_triangleMesh(CTriangleMesh(&m_triangleMeshData, transform))
{
}

bool COctahedron::Hit(CRay const& ray, CIntersection& intersection)const
{
	return m_triangleMesh.Hit(ray, intersection);
}

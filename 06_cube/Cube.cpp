#include "stdafx.h"
#include "Cube.h"
#include "Ray.h"
#include "Intersection.h"

std::vector<Vertex> vertices = {
		Vertex({ -1, -1, -1 }), // 0
		Vertex({ +1, -1, -1 }), // 1
		Vertex({ +1, +1, -1 }), // 2
		Vertex({ -1, +1, -1 }), // 3
		Vertex({ -1, -1, +1 }), // 4
		Vertex({ +1, -1, +1 }), // 5
		Vertex({ +1, +1, +1 }), // 6
		Vertex({ -1, +1, +1 }), // 7
};

std::vector<Face> faces = {
	Face(4, 7, 3),
	Face(4, 3, 0),
	Face(5, 1, 2),
	Face(5, 2, 6),
	Face(4, 0, 1),
	Face(4, 1, 5),
	Face(7, 6, 2),
	Face(7, 2, 3),
	Face(0, 3, 2),
	Face(0, 2, 1),
	Face(4, 5, 6),
	Face(4, 6, 7),
};

const CTriangleMeshData CCube::m_triangleMeshData = CTriangleMeshData(vertices, faces);

// TODO: Передавать transform, хранить Triangle Mash, ошибка матрица нормали N = M^-1^T
CCube::CCube(CMatrix4d const& transform)
	:CGeometryObjectWithInitialTransformImpl(transform)
	, m_triangleMesh(CTriangleMesh(&m_triangleMeshData, transform))
{
}

bool CCube::Hit(CRay const& ray, CIntersection& intersection)const
{
	return m_triangleMesh.Hit(ray, intersection);
}

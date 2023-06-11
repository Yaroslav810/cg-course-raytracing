#include "stdafx.h"
#include "Tetrahedron.h"
#include "Ray.h"
#include "Intersection.h"

CTetrahedron::CTetrahedron(
	CVector3d const& v1,
	CVector3d const& v2,
	CVector3d const& v3, 
	CVector3d const& v4, 
	CMatrix4d const& transform
)
	:CGeometryObjectWithInitialTransformImpl(transform)
	, m_triangleMesh(nullptr)
{
	std::vector<Vertex> vertices = {
		Vertex(v1),
		Vertex(v2),
		Vertex(v3),
		Vertex(v4)
	};
	std::vector<Face> faces = {
		Face(0, 2, 1),
		Face(3, 0, 1),
		Face(3, 1, 2),
		Face(3, 2, 0),
	};
	CTriangleMeshData* triangleMeshData = new CTriangleMeshData(vertices, faces);
	m_triangleMesh = CTriangleMesh(triangleMeshData, transform);
}

bool CTetrahedron::Hit(CRay const& ray, CIntersection& intersection)const
{
	return m_triangleMesh.Hit(ray, intersection);
}

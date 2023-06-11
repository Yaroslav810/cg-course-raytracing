#pragma once
#include "GeometryObjectWithInitialTransformImpl.h"
#include "TriangleMesh.h"

/************************************************************************/
/* Геометрический объект с начальной трансформацией "Икосаэдр"          */
/************************************************************************/
class CIcosahedron :
	public CGeometryObjectWithInitialTransformImpl
{
public:
	/*
	Инициализация икосаэдра заданного положения в пространстве
	*/
	CIcosahedron(
		CMatrix4d const& transform = CMatrix4d()
	);

	/*
	Пересечение луча с икосаэдром
	*/
	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
	const static CTriangleMeshData m_triangleMeshData;
	CTriangleMesh m_triangleMesh;
};

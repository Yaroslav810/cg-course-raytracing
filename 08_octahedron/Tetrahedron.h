#pragma once
#include "GeometryObjectWithInitialTransformImpl.h"
#include "TriangleMesh.h"

/************************************************************************/
/* Геометрический объект с начальной трансформацией "Тетраэдр"          */
/************************************************************************/
class CTetrahedron :
	public CGeometryObjectWithInitialTransformImpl
{
public:
	/*
	Инициализация тетраэдра заданного размера и положения в пространстве
	*/
	CTetrahedron(
		CVector3d const& v1 = CVector3d(),
		CVector3d const& v2 = CVector3d(),
		CVector3d const& v3 = CVector3d(),
		CVector3d const& v4 = CVector3d(),
		CMatrix4d const& transform = CMatrix4d());

	/*
	Пересечение луча с тетраэдром
	*/
	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
	CTriangleMesh m_triangleMesh;
};

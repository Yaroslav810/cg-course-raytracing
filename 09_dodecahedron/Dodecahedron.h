#pragma once
#include "GeometryObjectWithInitialTransformImpl.h"
#include "TriangleMesh.h"

/************************************************************************/
/* Геометрический объект с начальной трансформацией "Додекаэдр"         */
/************************************************************************/
class CDodecahedron :
	public CGeometryObjectWithInitialTransformImpl
{
public:
	/*
	Инициализация октаэдра заданного положения в пространстве
	*/
	CDodecahedron(
		CMatrix4d const& transform = CMatrix4d()
	);

	/*
	Пересечение луча с октаэдром
	*/
	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
	const static CTriangleMeshData m_triangleMeshData;
	CTriangleMesh m_triangleMesh;
};

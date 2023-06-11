#pragma once
#include "GeometryObjectWithInitialTransformImpl.h"
#include "TriangleMesh.h"

/************************************************************************/
/* Геометрический объект с начальной трансформацией "Куб"               */
/************************************************************************/
class CCube :
	public CGeometryObjectWithInitialTransformImpl
{
public:
	/*
	Инициализация куба заданного размера и положения в пространстве
	*/
	CCube(
		double size = 2,
		CVector3d const& center = CVector3d(),
		CMatrix4d const& transform = CMatrix4d());

	/*
	Пересечение луча с кубом
	*/
	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
	CTriangleMesh m_triangleMesh;
};

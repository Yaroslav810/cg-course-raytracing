#pragma once
#include "GeometryObjectWithInitialTransformImpl.h"

/************************************************************************/
/* Геометрический объект с начальной трансформацией "Сфера"             */
/************************************************************************/
class CHyperbolicParaboloid :
	public CGeometryObjectWithInitialTransformImpl
{
public:
	/*
	Инициализация сферы заданного радиуса и положения в пространстве
	*/
	CHyperbolicParaboloid(
		CMatrix4d const& transform = CMatrix4d());

	/*
	Пересечение луча со сферой
	*/
	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
};

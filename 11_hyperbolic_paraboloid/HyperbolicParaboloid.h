#pragma once
#include "GeometryObjectWithInitialTransformImpl.h"

/************************************************************************/
/* �������������� ������ � ��������� �������������� "�����"             */
/************************************************************************/
class CHyperbolicParaboloid :
	public CGeometryObjectWithInitialTransformImpl
{
public:
	/*
	������������� ����� ��������� ������� � ��������� � ������������
	*/
	CHyperbolicParaboloid(
		CMatrix4d const& transform = CMatrix4d());

	/*
	����������� ���� �� ������
	*/
	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
};

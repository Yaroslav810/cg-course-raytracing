#pragma once
#include "GeometryObjectWithInitialTransformImpl.h"
#include "TriangleMesh.h"

/************************************************************************/
/* �������������� ������ � ��������� �������������� "���"               */
/************************************************************************/
class CCube :
	public CGeometryObjectWithInitialTransformImpl
{
public:
	/*
	������������� ���� ��������� ������� � ��������� � ������������
	*/
	CCube(
		double size = 2,
		CVector3d const& center = CVector3d(),
		CMatrix4d const& transform = CMatrix4d());

	/*
	����������� ���� � �����
	*/
	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
	CTriangleMesh m_triangleMesh;
};

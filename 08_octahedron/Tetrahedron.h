#pragma once
#include "GeometryObjectWithInitialTransformImpl.h"
#include "TriangleMesh.h"

/************************************************************************/
/* �������������� ������ � ��������� �������������� "��������"          */
/************************************************************************/
class CTetrahedron :
	public CGeometryObjectWithInitialTransformImpl
{
public:
	/*
	������������� ��������� ��������� ������� � ��������� � ������������
	*/
	CTetrahedron(
		CVector3d const& v1 = CVector3d(),
		CVector3d const& v2 = CVector3d(),
		CVector3d const& v3 = CVector3d(),
		CVector3d const& v4 = CVector3d(),
		CMatrix4d const& transform = CMatrix4d());

	/*
	����������� ���� � ����������
	*/
	virtual bool Hit(CRay const& ray, CIntersection& intersection)const;
private:
	CTriangleMesh m_triangleMesh;
};

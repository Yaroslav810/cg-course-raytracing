#include "stdafx.h"
#include "HyperbolicParaboloid.h"
#include "Ray.h"
#include "Intersection.h"

CHyperbolicParaboloid::CHyperbolicParaboloid(CMatrix4d const& transform)
	:CGeometryObjectWithInitialTransformImpl(transform)
{
}

bool CHyperbolicParaboloid::Hit(CRay const& ray, CIntersection& intersection)const
{
	CRay invRay = Transform(ray, GetInverseTransform());

	auto& direction = invRay.GetDirection();
	auto& start = invRay.GetStart();

	/*
	��������� ��������� ��������� �����������
	*/
	double a = Sqr(direction.x) - Sqr(direction.z);
	double b = start.x * direction.x - start.z * direction.z - direction.y / 2;
	double c = Sqr(start.x) - Sqr(start.z) - start.y;

	// ��������� ������������ (��� ������ ������� ������������ ��� x)
	double d = b * b - a * c;

	if (d < 0)
	{
		// ��� ������ - ��� � ����� ����������� (��� �� �������� ������ �����)
		return false;
	}


	// �����, ������� ��� �������� �� ����� ����������, �� ��������� ������������
	// ����� ��� ����, ����� ����������/������������ ��� ��� ���������� �� ������� ������� ����� ������������
	static const double HIT_TIME_EPSILON = 1e-8;

	double invA = 1 / a;
	double discRoot = sqrt(d);

	CHitInfo hits[2];
	unsigned count = 0;
	
	{
		// ������ ������ ���������
		double t0 = (-b - discRoot) * invA;
		CVector2d hit = CVector2d(start.x + direction.x * t0, start.z + direction.z * t0);

		if (t0 > HIT_TIME_EPSILON && hit.x >= -1 && hit.x <= 1 && hit.y >= -1 && hit.y <= 1)
		{
			CVector3d hitPoint0 = ray.GetPointAtTime(t0);
			CVector3d hitPoint0InObjectSpace = invRay.GetPointAtTime(t0);
			// ���������� ������
			CVector3d hitNormal0InObjectSpace = CVector3d(2 * hitPoint0InObjectSpace.x, -2 * hitPoint0InObjectSpace.z, -1);
			if (Dot(hitNormal0InObjectSpace, direction) > 0) {
				hitNormal0InObjectSpace = -hitNormal0InObjectSpace;
			}
			CVector3d hitNormal0 = GetNormalMatrix() * hitNormal0InObjectSpace;
			hits[count] = CHitInfo(
				t0,
				*this,
				hitPoint0,
				hitPoint0InObjectSpace,
				hitNormal0,
				hitNormal0InObjectSpace
			);
			count++;
		}
	}
	{
		// ������ ������ ���������
		double t1 = (-b + discRoot) * invA;
		CVector2d hit = CVector2d(start.x + direction.x * t1, start.z + direction.z * t1);
		// ��������� ���������� � ������ ������������, ���� ��� ��������� ������� �����
		if (t1 > HIT_TIME_EPSILON && hit.x >= -1 && hit.x <= 1 && hit.y >= -1 && hit.y <= 1)
		{
			// ��������� ���������� ����� ������������� � ������� ������� ��������� � ������� ��������� �������
			CVector3d hitPoint1 = ray.GetPointAtTime(t1);
			CVector3d hitPoint1InObjectSpace = invRay.GetPointAtTime(t1);
			CVector3d hitNormal1InObjectSpace = CVector3d(2 * hitPoint1InObjectSpace.x, -2 * hitPoint1InObjectSpace.z, -1);
			if (Dot(hitNormal1InObjectSpace, direction) > 0) {
				hitNormal1InObjectSpace = -hitNormal1InObjectSpace;
			}
			CVector3d hitNormal1 = GetNormalMatrix() * hitNormal1InObjectSpace;
			hits[count] = CHitInfo(
				t1,
				*this,
				hitPoint1,
				hitPoint1InObjectSpace,
				hitNormal1,
				hitNormal1InObjectSpace
			);
			count++;
		}
	}

	if (count == 2) {
		if (hits[0].GetHitTime() > hits[1].GetHitTime()) {
			intersection.AddHit(hits[1]);
			intersection.AddHit(hits[2]);
		}
		else 
		{
			intersection.AddHit(hits[0]);
			intersection.AddHit(hits[1]);
		}
	} 
	if (count == 1)
	{
		intersection.AddHit(hits[0]);
	}

	// ���� �� ���� �� ���� ������������ ���� �� ������ � ������������� �������?
	return intersection.GetHitsCount() > 0;
}

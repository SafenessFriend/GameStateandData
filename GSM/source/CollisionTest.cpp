#include "CollisionTest.h"

CollisionTest::CollisionTest()
{
}


CollisionTest::~CollisionTest()
{
}

void CollisionTest::run()
{
}

bool CollisionTest::PointToAABB(const Point & point, const AABB & aabb)
{
	// find all four planes
	float top = aabb.centre.y + aabb.size.y / 2.0f;
	float bottom = aabb.centre.y - aabb.size.y / 2.0f;
	float left = aabb.centre.x + aabb.size.x / 2.0f;
	float right = aabb.centre.x - aabb.size.x / 2.0f;

	// test the point against each plane
	if (point.y <= top && point.y >= bottom && point.x <= right && point.x >= left)
	{
		return true;
	}
	// if we pass all tests, we're inside the AABB

	return false; // TODO return result
}


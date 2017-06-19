#pragma once

#include "Geometry.h"
class CollisionTest
{
public:
	CollisionTest();
	~CollisionTest();

	void run();

	bool PointToAABB(const Point & point, const AABB & aabb);
};


#include "UnitTest.h"
#include "CollisionTest.h"
#include <assert.h>

UnitTest::UnitTest()
{
}

UnitTest::UnitTest(CollisionTest * collision) : m_collision(collision)
{

}


UnitTest::~UnitTest()
{
}

bool UnitTest::run()
{
	AABB a;
	a.centre = { 0,0 };
	a.size = { 3,5 };

	// Test Upper
	Point p = { 0,6 };
	bool upperResult = m_collision->PointToAABB(p, a);
	assert(!upperResult);
	// Test Upper Right

	// Test Right

	// Test Lower Right

	// Test inside
	p = { 1,4 };
	bool insideResult = m_collision->PointToAABB(p, a);
	assert(insideResult);

	return (!upperResult && insideResult);
}

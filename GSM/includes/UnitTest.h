#pragma once

class CollisionTest;

class UnitTest
{
public:
	UnitTest();
	UnitTest(CollisionTest* collision);
	~UnitTest();

	bool run();

protected:
	CollisionTest* m_collision;

private:


};


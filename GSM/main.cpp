///////////////////////////////////////////////////////////////////
////	Description:	A program that does things?
////	Created By:		Someone
////


// Game State Manager by Jack Booker

#include "GSMApp.h"
#include "UnitTest.h"
#include "CollisionTest.h"

int main() {
	
	auto app = new GSMApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}

//int main()
//{
//	CollisionTest* collision = new CollisionTest();
//	UnitTest* unit = new UnitTest(collision);
//	unit->run(); //TODO: Implement this to run every time
//	collision->run(); //TODO: Show some simple AABB testing
//	
//}
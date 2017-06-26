///////////////////////////////////////////////////////////////////
////	Description:	Fishing, a game state manager, custom data structure and design pattern program.
////	Created By:		 by Jack Booker
////
////

#include "GSMApp.h"
#include "UnitTest.h"
#include <iostream>

int main() {
	
	auto app = new GSMApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}

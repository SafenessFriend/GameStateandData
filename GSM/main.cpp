///////////////////////////////////////////////////////////////////
////	Description:	A program that does things?
////	Created By:		Someone
////


// Game State Manager by Jack Booker

#include "GSMApp.h"
#include "UnitTest.h"


int main() {
	
	auto app = new GSMApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}



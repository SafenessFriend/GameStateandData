////////////////////////////////////////////////////////////////////////////////////////////////////////////
////																									
////		Name:		Utility										
////																									
////		Purpose:	Utility															
////																									
////		Author:		Jack Booker s171742 / CIT213657 2017
////

#pragma once

#define _PI 3.14159265358979323846
#define _2PI (_2PI*2)
#define _PI_OVER_180 0.01745329		// 1 radian
#define _180_OVER_PI 57.29578		 

class Vector2;
float degToRad(float degrees);
float radToDeg(float radians);
Vector2 linearHalf(Vector2 &p1, Vector2 &p2);
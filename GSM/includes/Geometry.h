#pragma once

struct Point
{
	float x;
	float y;
};

struct AABB
{
	Point centre;
	Point size;
};
#pragma once
#include <stdlib.h> 

class Entity
{
public:
	Entity();
	~Entity();

	bool	mIsActive;			
	float	dir;				
	float	mX;					
	float	mY;					
	float	mRadius;			
	float	mSpeed;				
	float	mHealth;			

	void randomizeDir();
};


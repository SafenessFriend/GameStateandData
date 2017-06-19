#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::randomizeDir()
{
	(rand() % 2 == 0) ? (dir = mSpeed / 1.7f) : (dir = mSpeed / -1.7f);
}

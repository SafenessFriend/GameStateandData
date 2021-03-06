#pragma once
#include "IPrototype.h"
#include "ResourceManager.h"
#include "Vector2.h"

namespace aie {
	class Texture;
	class Renderer2D;
}

class Entity : public IPrototype
{
public:
	Entity(const std::string name, std::shared_ptr<ResourceBase> texture);
	Entity(const std::string name, const char* filename);
	Entity(const Entity& other);
	~Entity();

	Entity& operator=(const Entity& other);

	virtual std::shared_ptr<IPrototype> clone();
	virtual std::string getName() { return m_name; }

	bool isAlive() { return m_bAlive; }
	Vector2 getPosition() { return m_position; }

	void setAlive(bool state) { m_bAlive = state; }
	void setVelocity(float x, float y);
	void setPosition(float x, float y);

	void update(float dt);
	void draw(aie::Renderer2D* renderer);

private:
	std::shared_ptr<ResourceBase> m_texture;
	Vector2 m_position;
	Vector2 m_velocity;
	bool m_bAlive;
	std::string m_name;
};


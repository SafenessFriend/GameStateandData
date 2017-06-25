#include "Entity.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "ResourceManager.h"
#include <iostream>

Entity::Entity(const std::string name, std::shared_ptr<ResourceBase> texture) :
	m_name(name), m_texture(texture), m_position(Vector2(0, 0)), m_velocity(Vector2(0, 0))
{
}

Entity::Entity(const std::string name, const char* filename) :
	m_name(name), m_position(Vector2(0, 0)), m_velocity(Vector2(0, 0))
{
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

Entity::Entity(const Entity& other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_name = other.m_name;
}

Entity::~Entity()
{
	std::cout << m_name << " deallocated" << std::endl;
}

Entity& Entity::operator=(const Entity& other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_name = other.m_name;
	return *this;
}

std::shared_ptr<IPrototype> Entity::clone()
{
	return std::shared_ptr<IPrototype>(new Entity(*this));
}

void Entity::setPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

void Entity::setVelocity(float x, float y)
{
	m_velocity.x = x;
	m_velocity.y = y;
}

void Entity::update(float dt)
{
	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;
}

void Entity::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(m_texture->as<aie::Texture>(), m_position.x, m_position.y);
}
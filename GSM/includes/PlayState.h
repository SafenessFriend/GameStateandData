#pragma once
#include "IGameState.h"
#include <list>
#include <IPrototype.h>
#include "Renderer2D.h"


class Entity;
class Factory;

namespace aie
{
	class Font;
	class Texture;
}


class PlayState : public IGameState
{
public:
	PlayState(GSMApp *pApp);
	virtual ~PlayState();

	virtual bool startup();
	virtual void shutDown();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_background;
	std::unique_ptr<Factory> m_factory;
	std::list<std::shared_ptr<Entity>> m_entities;

private:

};

#pragma once
#include "IGameState.h"

namespace aie
{
	class Font;
	class Texture;
}

class MenuState : public IGameState
{
public:
	MenuState(GSMApp *pApp);
	virtual ~MenuState();

	virtual bool startup();
	virtual void shutDown();
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	aie::Texture*		m_title;
	aie::Font *m_font;

private:

};
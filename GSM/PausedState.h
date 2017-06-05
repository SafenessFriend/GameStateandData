#pragma once
#include "IGameState.h"


namespace aie
{
	class Font;
	class Texture;
}

class PausedState : public IGameState
{
public:
	PausedState(GSMApp *pApp);
	virtual ~PausedState();

	virtual void Update(float deltaTime);
	virtual void Draw();

	aie::Font *m_font;

protected:

private:

};
#pragma once
#include "IGameState.h"

namespace aie
{

	class Texture;
}

class SplashState : public IGameState
{
public:
	SplashState(GSMApp *pApp);
	virtual ~SplashState();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	float m_splashTimer = 10.0f;
	aie::Texture*		m_splash;
	aie::Texture*		m_title;

private:

};
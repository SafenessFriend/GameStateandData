#pragma once
#include "IGameState.h"

class SplashState : public IGameState
{
public:
	SplashState(GSMApp *pApp);
	virtual ~SplashState();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	float m_splashTimer = 3.0f;

private:

};
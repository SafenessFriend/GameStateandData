#include "SplashState.h"
#include "GSMApp.h"
#include "GameStateManager.h"
#include <iostream>

SplashState::SplashState(GSMApp *pApp) : IGameState(pApp)
{
	// Constructor - load assets here
}

SplashState::~SplashState()
{
	//destructor - unload assets here
}

void SplashState::Update(float deltaTime)
{
	m_splashTimer -= deltaTime;
	if (m_splashTimer < 0.0f)
	{
		m_splashTimer = 3.0f;
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("MENU");
		m_app->GetGameStateManager()->SetState("SPLASH", nullptr);
	}
}

void SplashState::Draw()
{
	// do draw logic here
	std::cout << "Splash - Draw" << std::endl;

	m_app->GetRenderer()->begin();
	m_app->GetRenderer()->drawBox(100, 100, 100, 100);
	m_app->GetRenderer()->end();
}

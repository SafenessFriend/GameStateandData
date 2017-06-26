#include "SplashState.h"
#include "GSMApp.h"
#include "GameStateManager.h"
#include <iostream>
#include <Texture.h>



SplashState::SplashState(GSMApp *pApp) : IGameState(pApp)
{
	// Constructor - load assets here
	m_splash = new aie::Texture("./textures/splash.png");

}

SplashState::~SplashState()
{
	delete m_splash;

}

bool SplashState::startup()
{
	return false;
}

void SplashState::shutDown()
{
}

void SplashState::Update(float deltaTime)
{
	m_splashTimer -= deltaTime;
	if (m_splashTimer < 0.0f)
	{
		m_splashTimer = 4.0f;
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

	if (m_splashTimer < 4.0f)
	{
		m_app->GetRenderer()->drawSprite(m_splash, 640, 360);
	}

	m_app->GetRenderer()->end();
}

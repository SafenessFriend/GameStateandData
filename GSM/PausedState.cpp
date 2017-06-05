#include "PausedState.h"
#include "GSMApp.h"
#include <Font.h>
#include <iostream>
#include "GameStateManager.h"
#include <Input.h>


PausedState::PausedState(GSMApp *pApp) : IGameState(pApp)
{
	m_font = new aie::Font("./font/consolas.ttf", 32);
	// Constructor - load assets here
}

PausedState::~PausedState()
{
	delete m_font;
	//destructor - unload assets here
}

void PausedState::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	// do update logic here
	std::cout << "Paused - Update" << std::endl;

	if (input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("PLAY");
	}


}

void PausedState::Draw()
{
	// do draw logic here
	std::cout << "Paused - Draw" << std::endl;

	m_app->GetRenderer()->begin();
	m_app->GetRenderer()->drawText(m_font, "paused", 500, 500, 0);
	m_app->GetRenderer()->end();
}

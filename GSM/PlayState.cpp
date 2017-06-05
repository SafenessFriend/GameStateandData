#include "PlayState.h"
#include "GSMApp.h"
#include <iostream>
#include <Input.h>
#include "GameStateManager.h"

PlayState::PlayState(GSMApp *pApp) : IGameState(pApp)
{
	// Constructor - load assets here
}

PlayState::~PlayState()
{
	//destructor - unload assets here
}

void PlayState::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	// do update logic here
	std::cout << "Play - Update" << std::endl;

	if (input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		m_app->GetGameStateManager()->PushState("PAUSE");
	}

}

void PlayState::Draw()
{
	// do draw logic here
	std::cout << "Play - Draw" << std::endl;

	m_app->GetRenderer()->begin();
	m_app->GetRenderer()->drawLine(600, 650, 450, 400, 5, 0);
	m_app->GetRenderer()->end();
}

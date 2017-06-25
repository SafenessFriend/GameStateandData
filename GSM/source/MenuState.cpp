#include "MenuState.h"
#include "GSMApp.h"
#include "GameStateManager.h"
#include <iostream>
#include <Input.h>

MenuState::MenuState(GSMApp *pApp) : IGameState(pApp)
{
	// Constructor - load assets here
}

MenuState::~MenuState()
{
	//destructor - unload assets here
}

bool MenuState::startup()
{
	return false;
}

void MenuState::shutDown()
{

}

void MenuState::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	// do update logic here
	std::cout << "Menu - Update" << std::endl;


	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("PLAY");
	}
		
}

void MenuState::Draw()
{
	// do draw logic here
	std::cout << "Menu - Draw" << std::endl;

	m_app->GetRenderer()->begin();
	m_app->GetRenderer()->drawCircle(300, 300, 300, 0);
	m_app->GetRenderer()->end();
}

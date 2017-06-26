#include "MenuState.h"
#include "GSMApp.h"
#include "GameStateManager.h"
#include <iostream>
#include <Input.h>
#include <Texture.h>
#include <Font.h>

MenuState::MenuState(GSMApp *pApp) : IGameState(pApp)
{

	m_title = new aie::Texture("./textures/title.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
}

MenuState::~MenuState()
{
	delete m_title;
	delete m_font;

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
	m_app->GetRenderer()->drawSprite(m_title, 640, 360);
	m_app->GetRenderer()->drawText(m_font, "Press SPACE to begin", 440, 100, 0);
	m_app->GetRenderer()->end();
}

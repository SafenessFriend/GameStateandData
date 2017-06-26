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

bool PausedState::startup()
{
	return false;
}

void PausedState::shutDown()
{

}

void PausedState::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	std::cout << "Paused - Update" << std::endl;



}

void PausedState::Draw()
{
	// do draw logic here
	std::cout << "Paused - Draw" << std::endl;

	m_app->GetRenderer()->begin();
	m_app->GetRenderer()->drawText(m_font, "paused", 640, 360, 0);
	m_app->GetRenderer()->end();
}

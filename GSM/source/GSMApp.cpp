///////////////////////////////////////////////////////////////////
////	Description:	Aquarium, a game state manager, custom data structure and design pattern program.
////	Created By:		by Jack Booker
////
////	


#include "GSMApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "SplashState.h"
#include "PausedState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameStateManager.h"

GSMApp::GSMApp() {

}

GSMApp::~GSMApp() {

}

bool GSMApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_splash = new aie::Texture("./textures/fhammer.png");
	m_skelly = new aie::Texture("./textures/skelly.png");

	m_gameStateManager = new GameStateManager();
	m_gameStateManager->SetState("SPLASH", new SplashState(this));
	m_gameStateManager->SetState("MENU", new MenuState(this));
	m_gameStateManager->SetState("PAUSE", new PausedState(this));
	m_gameStateManager->SetState("PLAY", new PlayState(this));

	m_gameStateManager->PushState("SPLASH");


	return true;
}

void GSMApp::shutdown() {

	delete m_gameStateManager;
	delete m_font;
	delete m_2dRenderer;
	delete m_skelly;

}

void GSMApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	if (input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		if (isPaused == false)
		{
			m_gameStateManager->PopState();
			m_gameStateManager->PushState("PAUSE");
			isPaused = true;
		}
		else
		{
			m_gameStateManager->PopState();
			m_gameStateManager->PushState("PLAY");
			isPaused = false;
		}
	}


	m_gameStateManager->UpdateGameStates(deltaTime);
}

void GSMApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	m_gameStateManager->DrawGameStates();
	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

aie::Renderer2D* GSMApp::GetRenderer()
{
	return m_2dRenderer;
}

GameStateManager * GSMApp::GetGameStateManager()
{
	return m_gameStateManager;
}

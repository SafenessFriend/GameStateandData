#pragma once

#include "Application.h"
#include "Renderer2D.h"

//predeclare types
class GameStateManager;

class GSMApp : public aie::Application {
public:

	GSMApp();
	virtual ~GSMApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	aie::Renderer2D* GetRenderer();
	GameStateManager *GetGameStateManager();

protected:

	GameStateManager *m_gameStateManager = nullptr;
	bool isPaused;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};
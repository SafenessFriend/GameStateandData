#include "IGameState.h"

IGameState::IGameState(GSMApp *pApp)
{
	m_app = pApp;
}

IGameState::~IGameState()
{
}

void IGameState::Update(float deltaTime)
{
}

void IGameState::Draw()
{
}

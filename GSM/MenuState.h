#pragma once
#include "IGameState.h"

class MenuState : public IGameState
{
public:
	MenuState(GSMApp *pApp);
	virtual ~MenuState();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

private:

};
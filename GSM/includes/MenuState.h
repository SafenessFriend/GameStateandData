#pragma once
#include "IGameState.h"

class MenuState : public IGameState
{
public:
	MenuState(GSMApp *pApp);
	virtual ~MenuState();

	virtual bool startup();
	virtual void shutDown();
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

private:

};
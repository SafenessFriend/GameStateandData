#pragma once
#include "IGameState.h"

class PlayState : public IGameState
{
public:
	PlayState(GSMApp *pApp);
	virtual ~PlayState();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

private:

};
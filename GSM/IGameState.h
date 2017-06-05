#pragma once

class GSMApp;

class IGameState
{
public:

	IGameState(GSMApp *pApp);
	virtual ~IGameState();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	GSMApp *m_app;

private:

};
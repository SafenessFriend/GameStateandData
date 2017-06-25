#pragma once

class GSMApp;

class IGameState
{
public:

	IGameState(GSMApp *pApp) : m_app(pApp) {}
	virtual ~IGameState() = default;

	virtual bool startup() = 0;
	virtual void shutDown() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

protected:

	GSMApp *m_app;

private:

};
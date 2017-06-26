#pragma once
#include "DynArr.h"
#include "Map.h"

class IGameState;

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	void UpdateGameStates(float deltaTime);
	void DrawGameStates();

	void SetState(const char *name, IGameState *state);
	void PushState(const char *name);
	void PopState();

protected:

	void ProcessCommands();

	void DoSetState(const char *name, IGameState *state);
	void DoPushState(const char *name);
	void DoPopState();

	Map<const char *, IGameState*> m_availableStates;

	DynArr<IGameState*> m_states;

	enum class ECommands
	{
		SET_STATE,
		PUSH_STATE,
		POP_STATE
	};

	struct Commands
	{
		ECommands cmd;
		const char *name;
		IGameState *state;
	};

	DynArr<Commands> m_commands;

private:

};
#include "GameStateManager.h"
#include "IGameState.h"

GameStateManager::GameStateManager()
{

}

GameStateManager::~GameStateManager()
{
	//clean that memory up
	for (auto iter = m_availableStates.begin(); iter != m_availableStates.end(); iter++)
	{
		delete iter->second;
	}
	m_availableStates.clear();
}

void GameStateManager::UpdateGameStates(float deltaTime)
{
	ProcessCommands();
	for (auto iter = m_states.begin(); iter != m_states.end(); iter++)
	{
		(*iter)->Update(deltaTime);
	}
}

void GameStateManager::DrawGameStates()
{
	for (auto iter = m_states.begin(); iter != m_states.end(); iter++)
	{
		(*iter)->Draw();
	}
}

void GameStateManager::SetState(const char * name, IGameState * state)
{
	Commands cmd;
	cmd.cmd = ECommands::SET_STATE;
	cmd.name = name;
	cmd.state = state;

	m_commands.push_back(cmd);
}

void GameStateManager::PushState(const char * name)
{
	Commands cmd;
	cmd.cmd = ECommands::PUSH_STATE;
	cmd.name = name;

	m_commands.push_back(cmd);
}

void GameStateManager::PopState()
{
	Commands cmd;
	cmd.cmd = ECommands::POP_STATE;

	m_commands.push_back(cmd);
}


void GameStateManager::DoSetState(const char * name, IGameState * state)
{
	auto iter = m_availableStates.find(name);
		if (iter != m_availableStates.end())
			delete iter->second;

	m_availableStates[name] = state;
}

void GameStateManager::DoPushState(const char * name)
{
	auto iter = m_availableStates.find(name);
	if (iter != m_availableStates.end())
	{
		m_states.push_back(iter->second);
		//TODO: assert if m_states alread had the states in the collection
	}
	else
	{
		//TODO: assert, the state was not found
	} 
}

void GameStateManager::DoPopState()
{
	if (m_states.empty())
	{
		//TODO: assert, trying to pop off a state when there are no states active
		return;
	}
	m_states.pop_back();
}

void GameStateManager::ProcessCommands()
{
	for (auto iter = m_commands.begin(); iter != m_commands.end(); iter++)
	{
		Commands &cmd = (*iter);
		switch (cmd.cmd)
		{
		case ECommands::SET_STATE: DoSetState(cmd.name, cmd.state); break;

		case ECommands::PUSH_STATE: DoPushState(cmd.name); break;
		case ECommands::POP_STATE: DoPopState(); break;
		}
	}
	m_commands.clear();
}

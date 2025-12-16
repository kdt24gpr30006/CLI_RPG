#include "GameState.hpp"

void InGame::GameState::AddMessage(const std::string& msg)
{
	if (!message.empty()) {
		message += "\n";
	}
	message += msg;
}
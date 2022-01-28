#include "gamemanager.h"

GameManager::GameManager()
{
    this->m_dungeonController = new DungeonController();
    this->m_characterController = new CharacterController();
}


void GameManager::Update()
{
    update_game_states();
    render();
}


void GameManager::update_game_states()
{

}

void GameManager::render()
{
    this->m_characterController->Render();
    this->m_dungeonController->Render();
}

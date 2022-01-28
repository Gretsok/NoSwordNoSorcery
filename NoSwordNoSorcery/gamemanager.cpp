#include "gamemanager.h"

GameManager::GameManager()
{

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
    this->m_dungeonController->Render();
    this->CharacterController->Render();
}

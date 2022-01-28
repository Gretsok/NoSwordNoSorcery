#include "gamemanager.h"
#include<QDebug>

GameManager::GameManager()
{
    this->m_timeOfLastFrame = clock();
    this->m_dungeonController = new DungeonController();
    this->m_characterController = new CharacterController();
}

double GameManager::s_deltaTime = 0.0f;

void GameManager::Update()
{
    update_game_states();
    render();

    float timeOfNow = clock();
    GameManager::s_deltaTime = double(timeOfNow - this->m_timeOfLastFrame)/CLOCKS_PER_SEC;
    this->m_timeOfLastFrame = timeOfNow;

    //qDebug() << " delta Time : " << GameManager::GetDeltaTime();
}


void GameManager::update_game_states()
{
    this->m_characterController->UpdateGameStates();
    this->m_dungeonController->UpdateGameStates();
}


void GameManager::render()
{
    this->m_characterController->Render();
    this->m_dungeonController->Render();
}

double GameManager::GetDeltaTime()
{
    return GameManager::s_deltaTime;
}

#include "gamemanager.h"


GameManager::GameManager()
{
    this->m_timeOfLastFrame = clock();
}

double GameManager::s_deltaTime = 0.0f;

void GameManager::Update()
{
    update_game_states();
    render();

    float timeOfNow = clock();
    GameManager::s_deltaTime = double(timeOfNow - this->m_timeOfLastFrame)/CLOCKS_PER_SEC;
    this->m_timeOfLastFrame = timeOfNow;
    printf("truc");
}


void GameManager::update_game_states()
{

}


void GameManager::render()
{
    this->m_dungeonController->Render();
    this->m_characterController->Render();
}

double GameManager::GetDeltaTime()
{
    return GameManager::s_deltaTime;
}

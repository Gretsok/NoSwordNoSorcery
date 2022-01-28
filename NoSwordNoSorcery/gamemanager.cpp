#include "gamemanager.h"
#include "collidercontroller.h"
#include<QDebug>

GameManager::GameManager()
{
    qDebug() << "Constructor GameManager";
    this->m_timeOfLastFrame = clock();
    this->m_dungeonController = new DungeonController();
    qDebug() << "DungeonController created";
    this->m_characterController = new CharacterController();
    this->m_displayColliders = true;
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

    if(this->m_displayColliders)
    {
        std::list<ColliderController*>::iterator it;
        for(it = ColliderController::GetColliderControllers().begin(); it != ColliderController::GetColliderControllers().end(); ++it)
        {
            (*it)->UpdateGameStates();
        }
    }
}


void GameManager::render()
{
    if(this->m_displayColliders)
    {
        std::list<ColliderController*>::iterator it;
        for(it = ColliderController::GetColliderControllers().begin(); it != ColliderController::GetColliderControllers().end(); ++it)
        {
            (*it)->Render();
        }
    }
    this->m_characterController->Render();
    this->m_dungeonController->Render();
}

double GameManager::GetDeltaTime()
{
    return GameManager::s_deltaTime;
}

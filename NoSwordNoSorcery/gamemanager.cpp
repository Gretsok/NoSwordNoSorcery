#include "gamemanager.h"
#include "collidercontroller.h"
#include "bulletsmanager.h"
#include<QDebug>

GameManager::GameManager()
{
   //qDebug()<< "Constructor GameManager";
    this->m_timeOfLastFrame = clock();
   //qDebug()<< "DungeonController created";
    this->m_characterController = new CharacterController();
    this->m_dungeonController = new DungeonController(m_characterController);
    this->m_displayColliders = true;
    this->m_viewSwitchCooldown = 0.3;
    this->m_timeSinceLastViewSwitch = 0.3;
}

GameManager::~GameManager()
{
    delete this->m_dungeonController;
    delete this->m_characterController;
}



double GameManager::s_deltaTime = 0.0f;
bool GameManager::s_isView3D = true;

void GameManager::Update()
{
    if(GetKeyState('P') < 0 && m_timeSinceLastViewSwitch >= m_viewSwitchCooldown)
    {
        this->m_timeSinceLastViewSwitch = 0;
        this->switch_view();
    }
    update_game_states();
    render();

    float timeOfNow = clock();
    GameManager::s_deltaTime = double(timeOfNow - this->m_timeOfLastFrame)/CLOCKS_PER_SEC;

    this->m_timeSinceLastViewSwitch += s_deltaTime;
    this->m_timeOfLastFrame = timeOfNow;

    //qDebug() << " delta Time : " << GameManager::GetDeltaTime();
}


void GameManager::update_game_states()
{
    this->m_characterController->UpdateGameStates();
    this->m_dungeonController->UpdateGameStates();
    BulletsManager::UpdateGameStates();
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
    /*if(this->m_displayColliders)
    {
        std::list<ColliderController*>::iterator it;
        for(it = ColliderController::GetColliderControllers().begin(); it != ColliderController::GetColliderControllers().end(); ++it)
        {
            (*it)->Render();
        }
    }*/
    this->m_characterController->Render();
    BulletsManager::Render();
    this->m_dungeonController->Render();
}

double GameManager::GetDeltaTime()
{
    return GameManager::s_deltaTime;
}

bool GameManager::IsView3D()
{
    return GameManager::s_isView3D;
}
void GameManager::switch_view()
{
    GameManager::s_isView3D = !GameManager::s_isView3D;
    this->m_characterController->OnViewSwitched();
    this->m_dungeonController->OnViewSwitched();
    BulletsManager::OnSwitchView();
}

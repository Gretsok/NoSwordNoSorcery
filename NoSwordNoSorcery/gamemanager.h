#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "dungeongenerator.h"
#include "dungeoncontroller.h"
#include "charactercontroller.h"

class GameManager
{
public:
    GameManager();
    void Update();
private:
    DungeonGenerator* m_dungeonGenerator;
    DungeonController* m_dungeonController;
    CharacterController* m_characterController;
    void update_game_states();
    void render();
};

#endif // GAMEMANAGER_H

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "dungeongenerator.h"
#include "dungeoncontroller.h"
#include "charactercontroller.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();
    void Update();
    static double GetDeltaTime();

private:
    bool m_displayColliders;
    static double s_deltaTime;
    double m_timeOfLastFrame;
    DungeonGenerator* m_dungeonGenerator;
    DungeonController* m_dungeonController;
    CharacterController* m_characterController;
    void update_game_states();
    void render();
};

#endif // GAMEMANAGER_H

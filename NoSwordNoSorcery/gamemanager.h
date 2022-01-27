#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H


class GameManager
{
public:
    GameManager();
    void Update();
private:
    void UpdateGameStates();
    void Render();
};

#endif // GAMEMANAGER_H

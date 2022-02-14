#ifndef DUNGEONGENERATOR_H
#define DUNGEONGENERATOR_H

#include <vector>
class Cell{
public:
    int x, y;
};


class DungeonGenerator
{
public:
    DungeonGenerator();
    virtual ~DungeonGenerator();
    int dungeonLayout [5][5] = {{0}};
    int startRoomX;
    int startRoomY;
private:
    //std::vector<std::vector<int>> layout(std::vector<int>(),std::vector<int>()); TO DO WTF J'Y ARRIVE PAS
    Cell cells [5];
    Cell FillRandomCell(int nodeNumber);
    void FillCornerCells(void);
    void CreatePathBetweenCells(Cell cell_1, Cell cell_2);
    void Prim(void);
};

#endif // DUNGEONGENERATOR_H

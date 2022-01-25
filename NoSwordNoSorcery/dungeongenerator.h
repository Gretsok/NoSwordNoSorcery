#ifndef DUNGEONGENERATOR_H
#define DUNGEONGENERATOR_H


class Cell{
public:
    int x, y;
};


class DungeonGenerator
{
public:
    DungeonGenerator();
private:
    int dungeonLayout [5][5] = {{0}};
    Cell cells [5];
    Cell FillRandomCell(void);
    void FillCornerCells(void);
    void CreatePathBetweenCells(Cell cell_1, Cell cell_2);
};

#endif // DUNGEONGENERATOR_H
#include "dungeongenerator.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
#include <QDebug>

using namespace std;

#define row 10
#define col 10

DungeonGenerator::DungeonGenerator()
{
    srand(time(0));
    FillCornerCells();
    cells[2] = FillRandomCell(3);
    cells[3] = FillRandomCell(4);
    cells[4] = FillRandomCell(5);
    CreatePathBetweenCells(cells[0],cells[1]);
    CreatePathBetweenCells(cells[0],cells[2]);
    CreatePathBetweenCells(cells[0],cells[3]);
    CreatePathBetweenCells(cells[0],cells[4]);
    CreatePathBetweenCells(cells[1],cells[2]);
    CreatePathBetweenCells(cells[1],cells[3]);
    CreatePathBetweenCells(cells[1],cells[4]);
    CreatePathBetweenCells(cells[2],cells[3]);
    CreatePathBetweenCells(cells[2],cells[4]);
    CreatePathBetweenCells(cells[3],cells[4]);



    //PRINT TEMPORAIRE
    for(int i = 0;i<5;i++){
        QDebug deb = qDebug();
        for(int j =0;j<5;j++){
            deb << dungeonLayout[i][j];
            //printf("%d ",dungeonLayout[i][j]);
        }
        //printf("\n");
    }
    /*for(int i = 0;i<5;i++){
        for(int j =0;j<5;j++){
            printf("%d ",layout[i][j]);
        }
        printf("\n");
    }*/

}

DungeonGenerator::~DungeonGenerator()
{

}

Cell DungeonGenerator::FillRandomCell(int nodeNumber){
    Cell c;
    int x,y;
    x = rand()%5;
    y = rand()%5;
    while(dungeonLayout[x][y]!=0){
        x = rand()%5;
        y = rand()%5;
    }
    dungeonLayout[x][y] = nodeNumber;
    c.x = x;
    c.y = y;
    return c;
}

void DungeonGenerator::FillCornerCells(){
    Cell c1,c2;
    int corner1,corner2;
    vector<int> vec;

    corner1 = rand()%4;
    corner2 = rand()%4;
    while(corner2==corner1){
        corner2 = rand()%4;
    }
    switch(corner1){
        case 0:
            //vec = layout[0];
            //vec[0] = 1;
            //layout[0] = vec;
            dungeonLayout[0][0] = 1;
            c1.x = 0;
            c1.y = 0;
            startRoomX = 0;
            startRoomY = 0;
            break;
        case 1:
            //vec = layout[0];
            //vec[4] = 1;
            //layout[0] = vec;
            dungeonLayout[0][4] = 1;
            c1.x = 0;
            c1.y = 4;
            startRoomX = 0;
            startRoomY = 4;
            break;
        case 2:
            //vec = layout[4];
            //vec[0] = 1;
            //layout[4] = vec;
            dungeonLayout[4][0] = 1;
            c1.x = 4;
            c1.y = 0;
            startRoomX = 4;
            startRoomY = 0;
            break;
        case 3:
            //vec = layout[4];
            //vec[4] = 1;
            //layout[4] = vec;
            dungeonLayout[4][4] = 1;
            c1.x = 4;
            c1.y = 4;
            startRoomX = 4;
            startRoomY = 4;
            break;
        default:
            break;
    }
    switch(corner2){
        case 0:
            dungeonLayout[0][0] = 2;
            c2.x = 0;
            c2.y = 0;
            break;
        case 1:
            dungeonLayout[0][4] = 2;
            c2.x = 0;
            c2.y = 4;
            break;
        case 2:
            dungeonLayout[4][0] = 2;
            c2.x = 4;
            c2.y = 0;
            break;
        case 3:
            dungeonLayout[4][4] = 2;
            c2.x = 4;
            c2.y = 4;
            break;
        default:
            break;
    }

    cells[0] = c1;
    cells[1] = c2;
}

void DungeonGenerator::CreatePathBetweenCells(Cell cell_1, Cell cell_2){
    int startX,startY,endX,endY, i, j;

    if(cell_1.x<cell_2.x){
        startX = cell_1.x;
        startY = cell_1.y;
        endX = cell_2.x;
        endY = cell_2.y;
    }
    else{
        startX = cell_2.x;
        startY = cell_2.y;
        endX = cell_1.x;
        endY = cell_1.y;
    }
    i = startX;
    j = startY;
    while(i!=endX || j!=endY){
        if(i!=endX){
            i++;
            if(dungeonLayout[i][j]==0)
                dungeonLayout[i][j] = 9;
        }
        if(j!=endY){
            if(j<endY)
                j++;
            else
                j--;
            if(dungeonLayout[i][j]==0)
                dungeonLayout[i][j] = 9;
        }
    }
}

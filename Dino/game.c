#include "main.h"

void Game(){
    InitGame();
    PrintPlayer(2, 2);
}

void InitGame(){
    InitScreen();
}

void PrintPlayer(int x, int y){
    GotoXY(x, y);
    printf("%s", "Aaa");
}
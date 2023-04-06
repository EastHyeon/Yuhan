#include "main.h"

void Init(void);

int main(){
    enum GameState gameState;
    int lastTick = 0;
    gameState = MENU;

    Init();

    while(1){
        int currentTick = GetTickCount();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        
    }
}

void Init(){
    system("mode con cols=91 lines=35 | title 디노게임 0.1 | color 70");
    CursorHide();
    InitBackGround();
    RenderAuthor();
}
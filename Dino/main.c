#include "main.h"

void Init(void);

int main(){
    enum GameState gameState;
    int lastTick = 0;
    gameState = MENU;

    Init();

    RenderTitle();
    while(1){
        switch(gameState){
            case EXIT:
                break;
            case MENU:
                gameState = RenderMenu();
                break;
            case GAME:
                gameState = Game();
                break;
            case HELP:
                gameState = RenderHelp();
                break;
        }
    }
}

void Init(){
    system("mode con cols=88 lines=35 | title ������ 0.1 | color 70");
    CursorHide();
    InitBackGround();
    RenderAuthor();
}
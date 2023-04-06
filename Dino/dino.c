#include "inc\dino.h"

void Init(void);

int main(){
    enum GameState gameState;
    int lastTick = 0;
    gameState = MENU;

    void Init();

    while(1){
        int currentTick = GetTickCount();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        // �Է�

        // �Է�, ���� ó��

        // ������
        Renderer(gameState);
    }
}

void Init(){
    system("mode con cols=91 lines=35 | title ������ 0.1 | color 70");
    CursorHide();
    InitScreen();
    RenderAuthor();
}
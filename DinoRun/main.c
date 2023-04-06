#include "game.h"

int main()
{
    int GameState = 1;

    Init();
    CursorHide();
    
    
    RenderTitle();
    do
    {
        switch(GameState){
        case 1:
            GameState = RenderMenu();
            continue;
        case 2:
            GameState = RenderHelp();
            continue;
        case 3:
            Sleep(1000);
            system("cls");
            printf("Á¾·áµÊ");
            exit(0);
        default:
            continue;
        }
        ClearBackground();
    } while (GameState != 0);
} 
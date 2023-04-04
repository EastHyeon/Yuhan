#include "game.h"

int main()
{
    int GameState = 1;

    Init();
    CursorHide();

    do
    {
        RenderTitle();
        ClearBackground();
    } while (GameState != 0);
}
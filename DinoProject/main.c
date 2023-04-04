#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void Init();
void GotoXY(int, int);
int GetKeyDown();
void render_background();
void render_title();

int main()
{
    Init();
    int GameState = 1;

    while(GameState != 0)
    {
        switch (GameState)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    }

    return 0;
}

void Init()
{
    system("mode con cols=83 lines=30 | title 디노게임 0.1");
}

void GotoXY(int x, int y)
{
    COORD Pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

void render_background()
{
    puts("┌──────────────────────────────────────────────────────────────────────────────┐");
    puts("│                                                                              │");
    puts("│                                                                              │");
    puts("│                                                                              │");
    puts("│                                                                              │");
    puts("│                                                                              │");
    puts("│                                                                              │");
    puts("│                                                                              │");
    puts("│                                                                              │");
    puts("└──────────────────────────────────────────────────────────────────────────────┘");
}

void render_title()
{
    render_background();
    gotoxy(3, 2);
    printf("DINO GAME v0.1");
    gotoxy(3, 5);
    printf("▶ 게임시작");
    gotoxy(3, 6);
    printf("플레이 방법");
    gotoxy(3, 7);
    printf("종료");
}
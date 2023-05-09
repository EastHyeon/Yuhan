#include <stdio.h>
#include <windows.h>

#define SCREEN_MAX_Y 25
#define SCREEN_MAX_X 50

void SetColor(int, int);

enum ConsoleColor
{
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    CYAN,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
    DEFAULT_BACKGROUND = BLACK,
    DEFAULT_TEXT = GRAY,
};

int main()
{
    int gameState = 1;
    // 출력하는데 배열은 하나만 사용할 것
    char screenBuffer[SCREEN_MAX_Y][SCREEN_MAX_X] = {' '};

    // 오직 컬러를 입히기 위한 배열입니다, 제외해도 작동합니다.
    enum ConsoleColor colorBuffer[SCREEN_MAX_Y][SCREEN_MAX_X] = {DEFAULT_BACKGROUND};

    
    
    // 스크린 배열 초기화
        //Input & Logic PASS
    for (int y = 0; y < SCREEN_MAX_Y; y++)
    {
        for (int x = 0; x < SCREEN_MAX_X; x++)
        {
            if(y == 0 || x == 0 || y == SCREEN_MAX_Y - 1 || x == SCREEN_MAX_X - 1)
            {
                screenBuffer[y][x] = '#';
                colorBuffer
            }
            else
            {
                screenBuffer[y][x] = '0';
            }
        }
    }



    //Render PASS
    for (int y = 0; y < SCREEN_MAX_Y; y++)
    {
        for (int x = 0; x < SCREEN_MAX_X; x++)
        {
            printf("%c", screenBuffer[y][x]);
        }
        printf("\n");
    }
}

void SetColor(int backGroundColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (backGroundColor<<4);
}
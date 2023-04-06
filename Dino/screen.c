#include "main.h"

//스크린 영역을 초기화
void InitScreen(){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = SCREEN_MIN_Y; i < SCREEN_MAX_Y; i++){
        GotoXY(SCREEN_MIN_X,i);
        printf("                                                                                     ");
    }
}

//스크린 영역을 위에서 아래로 사라지는 효과를 주면서 초기화
void InitScreenFade(){
    for(int i = SCREEN_MIN_Y; i < SCREEN_MAX_Y; i++){
        GotoXY(SCREEN_MIN_X,i);
        printf("                                                                                     ");
        Sleep(20);
    }
}

//기본 배경을 초기화
void InitBackGround(){
    GotoXY(0, 0);
    puts("┌──────────────────────────────────────────────────────────────────────────────────────┐");
    for(int i = 1; i < 30; i++){
        puts("│                                                                                      │");
    }
    puts("└──────────────────────────────────────────────────────────────────────────────────────┘");
    GotoXY(0, 31);
    puts("┌──────────────────────────────────────────────────────────────────────────────────────┐");
    for(int i = 0; i < 1; i++){
        puts("│                                                                                      │");
    }
    puts("└──────────────────────────────────────────────────────────────────────────────────────┘");
    WriteLineCenter(GAME_VERSION, 32);
}
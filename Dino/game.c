#include "main.h"

void PrintPos(int x, int y){
    SetAllColor(DARK_GRAY, WHITE);
    char buffer[256];
    sprintf_s(buffer,sizeof(buffer), "(%d, %d)", x / 2, y);
    char* msg = buffer;
    int PosX = SCREEN_MAX_X - euc_kr_strlen(msg) + 1;
    GotoXY(78, 35);
    printf("     ");
    GotoXY(73, 35);
    SetAllColor(DARK_GRAY, WHITE);
    printf("Pos: ");
    GotoXY(PosX, 35);
    printf(msg);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}

void PrintLog(const char* str){
    SetAllColor(DARK_GRAY, WHITE);
    GotoXY(SCREEN_MIN_X, 35);
    printf("                                                                      ");
    GotoXY(SCREEN_MIN_X, 35);
    printf("ป๓ลย: %s", str);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}
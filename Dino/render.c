#include "main.h"

void Renderer(int state){
    enum GameState gameState = state;

    switch(gameState){
    case MENU:

        break;
    default:
        break;
    }
}

void RenderAuthor(){
    SetAllColor(DARK_GRAY, BLACK);
    
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     ");
        Sleep(80);
    }

    SetAllColor(DARK_GRAY, GREEN);
    WriteLineCenter(" __ __ _____ _____ _____ _____    _____ _____ _____ _____ ", 12);
    WriteLineCenter("|  |  |  |  |  |  |  _  |   | |  |   __|  _  |     |   __|", 13);
    WriteLineCenter("|_   _|  |  |     |     | | | |  |  |  |     | | | |   __|", 14);
    WriteLineCenter("  |_| |_____|__|__|__|__|_|___|  |_____|__|__|_|_|_|_____|", 15);
    SetAllColor(DARK_GRAY, BLACK);

    Sleep(1000);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}

void RenderMenu(){
    InitScreen();
    SetAllColor(BLACK, WHITE);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 3);
    WriteLineCenter("::'########::'####:'##::: ##::'#######:::", 4);
    WriteLineCenter(":: ##:::: ##:: ##:: ####: ##: ##:::: ##::", 5);
    WriteLineCenter(":: ##:::: ##:: ##:: ## ## ##: ##:::: ##::", 6);
    WriteLineCenter(":: ##:::: ##:: ##:: ##. ####: ##:::: ##::", 7);
    WriteLineCenter(":: ##:::: ##:: ##:: ##:. ###: ##:::: ##::", 8);
    WriteLineCenter(":: ########::'####: ##::. ##:. #######:::", 9);
    WriteLineCenter("::........:::....::..::::..:::.......::::", 10);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 11);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}
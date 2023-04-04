#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int keyControl();
void gotoxy(int, int);
void init();
void render_title();
void render_menu();

int main(){
    const int WAIT_TICK = 1000/30;
    int lastTick = 0;

    init();

    while(1){
        int input;
        char exit_flag;
        int currentTick = (int)GetTickCount64();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        system("cls");
        render_title();
        render_menu();
        printf("메뉴를 고르세요 : ");
        int key_code = keyControl();
        printf("입력 : %d", key_code);
    }
    return 0;
}

int keyControl(){
    char temp = getchar();
    if(temp == 'w' || temp == 'W')
        return UP;
    else if (temp == 'a' || temp == 'A')
        return LEFT;
    else if (temp == 's' || temp == 'S')
        return DOWN;
    else if (temp == 'd' || temp == 'D')
        return RIGHT;
}

void init(){
    CONSOLE_CURSOR_INFO cursorInfo;
    system("mode con cols=90 lines=30 | title 디노게임 0.1");
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void render_title(){
		puts("┌──────────────────────────────────────────────────────────────────────────────┐");
		puts("│                                                                              │");
		puts("│  디노게임 메뉴 v 0.1                                                         │");
        puts("│                                                                              │");
		puts("└──────────────────────────────────────────────────────────────────────────────┘");
}

void render_menu(){
    gotoxy(34 - 2, 5);
    printf("> 게임시작 ");
    gotoxy(34, 6);
    printf("플레이 방법 ");
    gotoxy(34, 7);
    printf("종료 ");
}

void gotoxy(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
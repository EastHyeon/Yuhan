#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

void init();
void render_title();
void render_help();
void render_background();
void render_game();
void gotoxy(int, int);

int main(){
    int game_state = 1;

    char map[465]; /* 가로 : 30 세로 : 15 */

    for(int i = 0; i < 464; i++){
        if((i + 1) % 31 == 0)
            map[i] = '\n';
        else
            map[i] = '0';
    }
    map[464] = '\0';
    printf("%s", map);
}
void init(){
    system("mode con cols=83 lines=30 | title 디노게임 0.1");
}

void render_title(){
    render_background();
    gotoxy(3, 2);
    printf("▶ DINO GAME v0.1");
    gotoxy(3, 5);
    printf("1.게임시작");
    gotoxy(3, 6);
    printf("2.플레이 방법");
    gotoxy(3, 7);
    printf("3.종료");
}

void render_help(){
    render_background();
    gotoxy(3, 2);
    printf("▶ 도움말");
    gotoxy(3, 5);
    printf("스페이스 바를 눌러서 점프");
    gotoxy(3, 6);
    printf("아래 방향키를 눌러서 숙이기");
    gotoxy(3, 7);
    printf("다가오는 장애물을 피하세요!");
}

void render_background(){

}

void render_game(){
}

void gotoxy(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
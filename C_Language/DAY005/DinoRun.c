#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define JUMP 4

int keyControl();
void init();
void render_title();
void render_help();
void render_background();
void game_logic();
void render_game();
void gotoxy(int, int);

int main(){
    int game_state = 1;

    init();

    while (game_state)
    {
        system("cls");
        // input 변수에 입력 값을 받는다.
        // game_state에 따라 출력할 메뉴를 결정한다.
        // game_state == 1 : 타이틀 메뉴
        // game_state == 2 : 도움말 메뉴
        // game_state == 3 : 종료
        int input = 0;
        if(game_state == 1){
            render_title();
            gotoxy(0, 10);
            printf("메뉴를 선택하세요 : ");
            scanf("%d", &input);
            if (input == 1){
                continue;
            }
            else if (input == 2){
                game_state = 2;
                continue;
            }
            else if (input == 3){
                game_state = 3;
                continue;
            }
            else{
                continue;
            }
        }
        else if(game_state == 2){
            render_help();
            gotoxy(0, 10);
            printf("메뉴로 돌아갑니까? (1.Yes / 2. NO) : ");
            scanf("%d", &input);
            if (input == 1){
                game_state = 1;
                continue;
            }
            else if (input == 2){
                game_state = 2;
                continue;
            }
        }
        else if(game_state == 3){
            printf("정말로 종료합니까? (1.Yes / 2. NO) : ");
            scanf("%d", &input);
            if (input == 1){
                break;
            }
            else if (input == 2){
                game_state = 1;
                continue;
            }
            else
                continue;
        }
        else if(game_state == 4){
            game_logic();
        }
    }
    
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

void game_logic(){
    render_background();
    int keyCode = keyControl();
    gotoxy(0, 10);
    printf("입력 : %d", keyCode);
}

void render_game(){
}

void gotoxy(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

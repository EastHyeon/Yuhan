#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>

#define WAIT 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define JUMP 5
#define EXIT 6

struct Player{
    bool isDead;
    bool isGrounded;
    int x;
    int y;

};

int keyControl();
void init();
void render_title();
void render_help();
void render_background();
void game_logic();
void render_input();
void render_game();
void gotoxy(int, int);

int keyCode = 0;

int main(){
    int game_state = 1;

    init();

    while (game_state != 0)
    {
        system("cls");
        // input ������ �Է� ���� �޴´�.
        // game_state�� ���� ����� �޴��� �����Ѵ�.
        // game_state == 1 : Ÿ��Ʋ �޴�
        // game_state == 2 : ���� �޴�
        // game_state == 3 : ����
        int input = 0;
        if(game_state == 1){
            render_title();
            gotoxy(0, 10);
            //�Է�
            printf("�޴��� �����ϼ��� : ");
            scanf("%d", &input);
            if (input == 1){
                game_state = 4;
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
                printf("�߸��� �Է�");
                Sleep(1000);
                continue;
            }
        }
        else if(game_state == 2){
            render_help();
            gotoxy(0, 10);
            printf("�޴��� ���ư��ϱ�? (1.Yes / 2. NO) : ");
            scanf("%d", &input);
            if (input == 1){
                game_state = 1;
                continue;
            }
            else if (input == 2){
                game_state = 2;
                continue;
            }
            else{
                printf("�߸��� �Է�");
                Sleep(1000);
                continue;
            }
        }
        else if(game_state == 3){
            printf("������ �����մϱ�? (1.Yes / 2. NO) : ");
            scanf("%d", &input);
            if (input == 1){
                break;
            }
            else if (input == 2){
                game_state = 1;
                continue;
            }
            else{
                printf("�߸��� �Է�");
                Sleep(1000);
                continue;
            }
        }
        else if(game_state == 4){
            game_logic();
        }
    }
}

void init(){
    system("mode con cols=83 lines=30 | title ������ 0.1");
}

void render_title(){
    render_background();
    gotoxy(3, 2);
    printf("�� DINO GAME v0.1");
    gotoxy(3, 5);
    printf("1.���ӽ���");
    gotoxy(3, 6);
    printf("2.�÷��� ���");
    gotoxy(3, 7);
    printf("3.����");
}

void render_help(){
    render_background();
    gotoxy(3, 2);
    printf("�� ����");
    gotoxy(3, 5);
    printf("�����̽� �ٸ� ������ ����");
    gotoxy(3, 6);
    printf("�Ʒ� ����Ű�� ������ ���̱�");
    gotoxy(3, 7);
    printf("�ٰ����� ��ֹ��� ���ϼ���!");
}

void render_background(){
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
}

int keyControl(){
    char temp = getch();

    if(temp == 'w' || temp == 'W'){
        return UP;
    }
    else if(temp == 'a' || temp == 'A'){
        return LEFT;
    }
    else if(temp == 's' || temp == 'S'){
        return DOWN;
    }
    else if(temp == 'd' || temp == 'D'){
        return RIGHT;
    }
    else if(temp == 'q' || temp == 'Q'){
        return EXIT;
    }
    else if(temp == ' '){
        return JUMP;
    }
}

void game_logic(){
    render_input();
    render_game();
    keyCode = keyControl();
    struct Player player = {0, 0};
}

void render_input(){
    gotoxy(0, 10);
    if (keyCode == UP){
        printf("�Է� : UP");
    }
    else if (keyCode == DOWN){
        printf("�Է� : DOWN");
    }
    else if (keyCode == LEFT){
        printf("�Է� : LEFT");
    }
    else if (keyCode == RIGHT){
        printf("�Է� : RIGHT");
    }
    else if (keyCode == JUMP){
        printf("�Է� : JUMP");
    }
    else if (keyCode == EXIT){
        gotoxy(0, 0);
        render_background();
        gotoxy(3, 4);
        printf("�޴��� ���ư��ϴ�.");
        Sleep(1000);
    }
    else{
        printf("�Է� : �����");
    }
}

void render_game(){
    gotoxy(0,0);
    render_background();
    gotoxy(2, 8);
    printf("-----------------------------------------------------------------------------");
    gotoxy(5, 7);
    printf("��");
    gotoxy(0, 0);
}

void gotoxy(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

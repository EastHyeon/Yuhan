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

    char map[465]; /* ���� : 30 ���� : 15 */

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

}

void render_game(){
}

void gotoxy(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
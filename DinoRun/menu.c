#include "game.h"

void Init(void){
    system("mode con cols=83 lines=30 | title ������ 0.1");
}

void CursorHide(void){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void RenderBackground(void){
    GotoXY(0, 0);
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("��                                                                              ��"); Sleep(40);
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������"); Sleep(40);
}

void ClearBackground(void){
    for(int i = 1; i < 10; i++){
        GotoXY(1,i);
        printf("                                                                              ");
    }
}

void RenderTitle(void){
    int count;
    RenderBackground();
    GotoXY(3, 2);
    printf("D"); Sleep(80);
    printf("I"); Sleep(80);
    printf("N"); Sleep(80);
    printf("O"); Sleep(80);
    printf(" G"); Sleep(80);
    printf("A"); Sleep(80);
    printf("M"); Sleep(80);
    printf("E"); Sleep(80);
    printf(" v"); Sleep(80);
    printf("0"); Sleep(80);
    printf("."); Sleep(80);
    printf("1"); Sleep(80);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 0x8000) break;

        count++;
        if(count>50){
            GotoXY(3,6);
            printf("�����̽��ٸ� ������ ����");
            count = 0;
        }

        count++;
        if(count>50){
            GotoXY(3,6);
            printf("                          ");
            count = 0;
        }
        Sleep(17);
    }

}

void RenderHelp(void){
    RenderBackground();
    GotoXY(3, 2);
    printf("�� ����");
    GotoXY(3, 5);
    printf("�����̽� �ٸ� ������ ����");
    GotoXY(3, 6);
    printf("�Ʒ� ����Ű�� ������ ���̱�");
    GotoXY(3, 7);
    printf("�ٰ����� ��ֹ��� ���ϼ���!");
}

void GotoXY(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
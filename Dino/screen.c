#include "main.h"

//��ũ�� ������ �ʱ�ȭ
void InitScreen(){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = SCREEN_MIN_Y; i <= SCREEN_MAX_Y; i++){
        GotoXY(SCREEN_MIN_X,i);
        printf("                                                                                    ");
    }
}

//��ũ�� ������ ������ �Ʒ��� ������� ȿ���� �ָ鼭 �ʱ�ȭ
void InitScreenFade(){
    for(int i = SCREEN_MIN_Y; i <= SCREEN_MAX_Y; i++){
        GotoXY(SCREEN_MIN_X,i);
        printf("                                                                                    ");
        Sleep(20);
    }
}
//��ũ�� ������ ������ �ٲٰ� ������ �Ʒ��� ������� ȿ���� �ָ鼭 �ʱ�ȭ
void InitScreenFadeColor(int backGroundColor, int textColor){
    SetAllColor(backGroundColor, textColor);
    for(int i = SCREEN_MIN_Y; i <= SCREEN_MAX_Y; i++){
        GotoXY(SCREEN_MIN_X,i);
        printf("                                                                                    ");
        Sleep(20);
    }
}

//�⺻ ����� �ʱ�ȭ
void InitBackGround(){
    SetAllColor(GRAY, BLACK);
    GotoXY(0, 0);
    puts("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for(int i = 1; i < 30; i++){
        puts("��                                                                                     ��");
    }
    puts("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    GotoXY(0, 31);
    puts("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for(int i = 0; i < 1; i++){
        puts("��                                                                                     ��");
    }
    puts("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    WriteLineCenter(GAME_VERSION, 32);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    InitScreen();
}
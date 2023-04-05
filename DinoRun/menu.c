#include "game.h"

void Init(void){
    system("mode con cols=90 lines=32 | title ������ 0.1");
}

void CursorHide(void){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void RenderBackground(void){
    GotoXY(0, 0);
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������"); Sleep(40);
    for(int i = 1; i < 30; i++){
        puts("��                                                                                       ��"); Sleep(40);
    }
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������"); Sleep(40);
}

void ClearBackground(void){
    for(int i = 1; i < 10; i++){
        GotoXY(2,i);
        printf("                                                                             ");
    }
}

void RenderTitle(void){
    int count;
    RenderBackground();
    GotoXY(2, 2); puts("???   ??????   ??????  ??? ?????? ????   ???    ??????? ???????   ??? ??????? "); Sleep(80);
    GotoXY(2, 3); puts("???? ???????   ??????  ????????????????  ???    ????????????????  ????????????"); Sleep(80);
    GotoXY(2, 4); puts(" ??????? ???   ????????????????????????? ???    ???  ???????????? ??????   ???"); Sleep(80);
    GotoXY(2, 5); puts("  ?????  ???   ?????????????????????????????    ???  ???????????????????   ???"); Sleep(80);
    GotoXY(2, 6); puts("   ???   ????????????  ??????  ?????? ??????    ?????????????? ???????????????"); Sleep(80);
    GotoXY(2, 7); puts("   ???    ??????? ???  ??????  ??????  ?????    ??????? ??????  ????? ??????? "); Sleep(80);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            break;
        } 

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

int RenderMenu(void){
    ClearBackground();
    GotoXY(3, 2);
    printf("DINO GAME v0.1");
    int count = 0;
    int choose = 1;
    while(1){
        //Input �н�

        if((GetAsyncKeyState(KEY_UP) & 1 ) && (choose > 1)){
            choose--;
        }else if((GetAsyncKeyState(KEY_DOWN) & 1) && (choose < 3)){
            choose++;
        }else if(GetAsyncKeyState(VK_SPACE) & 1){
            GotoXY(4, 4);
            switch (choose)
            {
            case 1:
                GotoXY(3, 5);
                printf("�� ���� : ���õ�");
                Sleep(1000);
                return 1;
            case 2:
                GotoXY(3, 6);
                printf("�� �������� : ���õ�");
                Sleep(1000);
                return 2;
            case 3:
                GotoXY(3, 7);
                printf("�� ���� : ������ �����մϱ�? (Y/N)");
                while(1){
                    if(GetAsyncKeyState(KEY_Y) & 1){
                        GotoXY(3, 7);
                        printf("�� ���� : ���� ��...               ");
                        return 3;
                    }
                    else if(GetAsyncKeyState(KEY_N) & 1){
                        GotoXY(3, 7);
                        printf("                                   ");
                        break;
                    }
                }
                break;
            default: 
                break;
            }
        }
 
        //Render �н� 
        GotoXY(3, 4);
        printf("%d", choose);

        if(choose == 1){
            GotoXY(3, 5);
            printf("�� ����       ");
        }else{
            GotoXY(3, 5);
            printf("   ����       ");
        }

        if(choose == 2){
            GotoXY(3, 6);
            printf("�� ��������       ");
        }else{
            GotoXY(3, 6);
            printf("   ��������       ");
        }

        if(choose == 3){
            GotoXY(3, 7);
            printf("�� ����       ");
        }else{
            GotoXY(3, 7);
            printf("   ����       ");
        }
    }
}

int RenderHelp(void){
    ClearBackground();
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 1){
            GotoXY(3, 8);
            printf("                                    "); 
            GotoXY(3, 8);
            printf("�޴��� ���ư��ϴ�."); 
            Sleep(1000);
            break;
        } 
        GotoXY(3, 2);
        printf("����");
        GotoXY(3, 5);
        printf("�����̽� �ٸ� ������ ����");
        GotoXY(3, 6);
        printf("�Ʒ� ����Ű�� ������ ���̱�");
        GotoXY(3, 7);
        printf("�ٰ����� ��ֹ��� ���ϼ���!");
        GotoXY(3, 8);
        printf("���ư����� �����̽��ٸ� �����ʽÿ�.");
    }
    return 1;
}

void GotoXY(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void PrintCenter(const char *Str){

}
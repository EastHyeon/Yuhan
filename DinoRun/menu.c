#include "game.h"

void Init(void){
    system("mode con cols=90 lines=32 | title ������ 0.1 | color 70");
}

void CursorHide(void){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void RenderBackground(void){
    GotoXY(0, 0);
    puts("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");;
    for(int i = 1; i < 30; i++){
        puts("��                                                                                      ��");;
    }
    puts("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");;
}

void ClearBackground(void){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     ");
    }
}

void ClearAnimation(void){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     "); Sleep(20);
    }
}

void RenderTitle(void){
    int count;
    RenderBackground();
    ClearAnimation();
    SetAllColor(BLACK, WHITE);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 3); Sleep(40);
    WriteLineCenter("::'########::'####:'##::: ##::'#######:::", 4); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ####: ##: ##:::: ##::", 5); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ## ## ##: ##:::: ##::", 6); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ##. ####: ##:::: ##::", 7); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ##:. ###: ##:::: ##::", 8); Sleep(40);
    WriteLineCenter(":: ########::'####: ##::. ##:. #######:::", 9); Sleep(40);
    WriteLineCenter("::........:::....::..::::..:::.......::::", 10); Sleep(40);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 11); Sleep(40);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    WriteLineCenter("V 0.1 202327005 �赿��", 13);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            break;
        } 

        count++;
        if(count>50){
            SetColor(GREEN);
            WriteLineCenter(">> �����̽��ٸ� ������ ���� <<", 18);
            SetColor(DEFAULT_TEXT);
            count = 0;
        }

        count++;
        if(count>50){
            WriteLineCenter("                              ", 18);
            count = 0;
        }
        Sleep(17);
    }

}

int RenderMenu(void){
    ClearBackground();
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
    int count = 0;
    static int choose = 1;
    int xPos = GetCenter("����") - 2;
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
                SetColor(GREEN);
                GotoXY(xPos, 18);
                printf("����");
                SetColor(DEFAULT_TEXT);
                Sleep(500);
                return 1;
            case 2:
                SetColor(GREEN);
                GotoXY(xPos, 19);
                printf("��������");
                Sleep(500);
                SetColor(DEFAULT_TEXT);
                return 2;
            case 3:
                SetColor(GREEN);
                GotoXY(xPos, 20);
                printf("���� | ������ �����մϱ�? (Y/N)");
                while(1){
                    if(GetAsyncKeyState(KEY_Y) & 0x8000){
                        ClearLine(20);
                        GotoXY(xPos, 20);
                        printf("�������Դϴ�...");
                        SetColor(DEFAULT_TEXT);
                        return 3;
                    }
                    else if(GetAsyncKeyState(KEY_N) & 0x8000){
                        ClearLine(20);
                        break;
                    }
                }
                break;
            default: 
                break;
            }
        }
 
        //Render �н� 
        WriteCenter("���� : ", 13);
        printf("%d", choose);
        GotoXY(xPos, 18);
        printf("����");
        GotoXY(xPos, 19);
        printf("��������");
        GotoXY(xPos, 20);
        printf("����");

        if(choose == 1){
            SetColor(DARK_GREEN);
            GotoXY(xPos - 2, 18);
            printf(">");
            SetColor(DEFAULT_TEXT);
            GotoXY(xPos - 2, 19);
            printf(" ");
            GotoXY(xPos - 2, 20);
            printf(" ");
        }
        else if(choose == 2){
            SetColor(DARK_GREEN);
            GotoXY(xPos - 2, 19);
            printf(">");
            SetColor(DEFAULT_TEXT);
            GotoXY(xPos - 2, 18);
            printf(" ");
            GotoXY(xPos - 2, 20);
            printf(" ");
        }
        else if(choose == 3){
            SetColor(DARK_GREEN);
            GotoXY(xPos - 2, 20);
            printf(">");
            SetColor(DEFAULT_TEXT);
            GotoXY(xPos - 2, 18);
            printf(" ");
            GotoXY(xPos - 2, 19);
            printf(" ");
        }
    }
}

int RenderHelp(void){
    ClearBackground();
    int xPos = 9;
    WriteLineCenter("����", 3);
    GotoXY(xPos,6);
    printf("�Ʒ� ����Ű�� ������ ���̱�");
    GotoXY(xPos,7);
    printf("�Ʒ� ����Ű�� ������ ���̱�");
    GotoXY(xPos,8);
    printf("�ٰ����� ��ֹ��� ���ϼ���!");

    GotoXY(xPos,9);
    printf("C��� ���θ� ���� ���۵� �����Դϴ�.");
    GotoXY(xPos,10);
    printf("CHROME DINO ������ ������� �ϰ��ֽ��ϴ�.");
    GotoXY(xPos,11);
    printf("202327005 �赿��");
    WriteLineCenter("���ư����� �����̽��ٸ� �����ʽÿ�.",25);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 1){
            SetColor(GREEN);
            ClearLine(25);
            WriteLineCenter("�޴��� ���ư��ϴ�.", 25); 
            SetColor(DEFAULT_TEXT);
            Sleep(1000);
            break;
        } 
        GotoXY(3, 2);
    }
    return 1;
}

int ExitMenu(void){
    
}

void GotoXY(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int euc_kr_strlen(const char *str) {
    int length = 0;
    while (*str) {
        if ((*str & 0x80) != 0) { // ���� ��Ʈ�� 1�� ���
            if ((unsigned char)*str >= 0xA1 && (unsigned char)*str <= 0xFE) {
                // EUC-KR ���ڵ����� �ѱ� ���� �Ǵ� Ư�� ���� ������ ���
                str++; // ���� ����Ʈ�� �ǳʶݴϴ�.
                length++;
            }
        }
        length++;
        str++;
    }
    return length;
}

int WriteLineCenter(const char *Str, int y){
    int screenWidth = 88;
    int len = euc_kr_strlen(Str);
    int xPos = (screenWidth - len) / 2 + 1;

    if(xPos <2){
        xPos = 2;
    }

    GotoXY(xPos, y);
    printf("%s\n", Str);
    return xPos;
}

int WriteCenter(const char *Str, int y){
    int screenWidth = 88;
    int len = euc_kr_strlen(Str);
    int xPos = (screenWidth - len) / 2 + 1;

    if(xPos <2){
        xPos = 2;
    }

    GotoXY(xPos, y);
    printf("%s", Str);
    return xPos;
}

int GetCenter(const char *Str){
        int screenWidth = 88;
    int len = euc_kr_strlen(Str);
    int xPos = (screenWidth - len) / 2 + 1;

    if(xPos <2){
        xPos = 2;
    }
    return xPos;
}

void ClearLine(int y){
    GotoXY(2, y);
    printf("                                                                                     ");
}

void SetColor(int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (DEFAULT_BACKGROUND<<4) + TextColor);
}

void SetAllColor(int BackGroundColor, int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (BackGroundColor<<4) + TextColor);
}
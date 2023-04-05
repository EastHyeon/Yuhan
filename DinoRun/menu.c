#include "game.h"

void Init(void){
    system("mode con cols=90 lines=32 | title 디노게임 0.1 |");
    SetAllColor(DARK_GRAY, GRAY);
}

void CursorHide(void){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void RenderBackground(void){
    GotoXY(0, 0);
    puts("┌──────────────────────────────────────────────────────────────────────────────────────┐"); Sleep(40);
    for(int i = 1; i < 30; i++){
        puts("│                                                                                      │"); Sleep(40);
    }
    puts("└──────────────────────────────────────────────────────────────────────────────────────┘"); Sleep(40);
}

void ClearBackground(void){
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     ");
    }
}

void RenderTitle(void){
    int count;
    RenderBackground();
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 3); Sleep(40);
    WriteLineCenter("::'########::'####:'##::: ##::'#######:::", 4); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ####: ##: ##:::: ##::", 5); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ## ## ##: ##:::: ##::", 6); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ##. ####: ##:::: ##::", 7); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ##:. ###: ##:::: ##::", 8); Sleep(40);
    WriteLineCenter(":: ########::'####: ##::. ##:. #######:::", 9); Sleep(40);
    WriteLineCenter("::........:::....::..::::..:::.......::::", 10); Sleep(40);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 11); Sleep(40);
    WriteLineCenter("V 0.1 개발:202327005 김동현", 13);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            break;
        } 

        count++;
        if(count>50){
            WriteLineCenter("스페이스바를 눌러서 시작", 18);
            count = 0;
        }

        count++;
        if(count>50){
            WriteLineCenter("                          ", 18);
            count = 0;
        }
        Sleep(17);
    }

}

int RenderMenu(void){
    ClearBackground();
    SetColor(WHITE);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 3);
    WriteLineCenter("::'########::'####:'##::: ##::'#######:::", 4);
    WriteLineCenter(":: ##:::: ##:: ##:: ####: ##: ##:::: ##::", 5);
    WriteLineCenter(":: ##:::: ##:: ##:: ## ## ##: ##:::: ##::", 6);
    WriteLineCenter(":: ##:::: ##:: ##:: ##. ####: ##:::: ##::", 7);
    WriteLineCenter(":: ##:::: ##:: ##:: ##:. ###: ##:::: ##::", 8);
    WriteLineCenter(":: ########::'####: ##::. ##:. #######:::", 9);
    WriteLineCenter("::........:::....::..::::..:::.......::::", 10);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 11);
    SetColor(GRAY);
    int count = 0;
    int choose = 1;
    while(1){
        //Input 패스

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
                WriteLineCenter("> 시작 : 선택됨", 18);
                SetColor(GRAY);
                Sleep(1000);
                return 1;
            case 2:
                SetColor(GREEN);
                WriteLineCenter("> 게임정보 : 선택됨", 19);
                Sleep(1000);
                SetColor(GRAY);
                return 2;
            case 3:
                SetColor(GREEN);
                WriteLineCenter("> 종료 : 정말로 종료합니까? (Y/N)", 20);
                while(1){
                    if(GetAsyncKeyState(KEY_Y) & 0x8000){
                        WriteLineCenter("> 종료 : 종료 중...", 20);
                        SetColor(GRAY);
                        return 3;
                    }
                    else if(GetAsyncKeyState(KEY_N) & 0x8000){
                        WriteLineCenter("                                   ", 20); 
                        SetColor(GRAY);
                        break;
                    }
                }
                break;
            default: 
                break;
            }
        }
 
        //Render 패스 
        WriteCenter("선택 : ", 13);
        printf("%d", choose);
        int xPos = GetCenter("시작") - 2;
        GotoXY(xPos, 18);
        printf("시작");
        GotoXY(xPos, 19);
        printf("게임정보");
        GotoXY(xPos, 20);
        printf("종료");
        if(choose == 1){
            SetColor(GREEN);
            GotoXY(xPos - 2, 18);
            printf(">");
            SetColor(GRAY);
            GotoXY(xPos - 2, 19);
            printf(" ");
            GotoXY(xPos - 2, 20);
            printf(" ");
        }
        else if(choose == 2){
            SetColor(GREEN);
            GotoXY(xPos - 2, 19);
            printf(">");
            SetColor(GRAY);
            GotoXY(xPos - 2, 18);
            printf(" ");
            GotoXY(xPos - 2, 20);
            printf(" ");
        }
        else if(choose == 3){
            SetColor(GREEN);
            GotoXY(xPos - 2, 20);
            printf(">");
            SetColor(GRAY);
            GotoXY(xPos - 2, 18);
            printf(" ");
            GotoXY(xPos - 2, 19);
            printf(" ");
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
            printf("메뉴로 돌아갑니다."); 
            Sleep(1000);
            break;
        } 
        GotoXY(3, 2);
        printf("도움말");
        GotoXY(3, 5);
        printf("스페이스 바를 눌러서 점프");
        GotoXY(3, 6);
        printf("아래 방향키를 눌러서 숙이기");
        GotoXY(3, 7);
        printf("다가오는 장애물을 피하세요!");
        GotoXY(3, 8);
        printf("돌아갈려면 스페이스바를 누르십시오.");
    }
    return 1;
}

void GotoXY(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int euc_kr_strlen(const char *str) {
    int length = 0;
    while (*str) {
        if ((*str & 0x80) != 0) { // 상위 비트가 1인 경우
            if ((unsigned char)*str >= 0xA1 && (unsigned char)*str <= 0xFE) {
                // EUC-KR 인코딩에서 한글 문자 또는 특수 문자 범위인 경우
                str++; // 다음 바이트로 건너뜁니다.
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
    SetConsoleTextAttribute(handle, TextColor);
}

void SetAllColor(int BackGroundColor, int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (BackGroundColor<<4) + TextColor);
}
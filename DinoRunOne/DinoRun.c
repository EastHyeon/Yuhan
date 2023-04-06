#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

// ��������
#define GAME_VERSION "������ v0.1 | 202327005 �赿��" 

// Ű
#define KEY_UP 0x26
#define KEY_DOWN 0x28
#define KEY_SPACE 0x20
#define KEY_Y 0x59
#define KEY_N 0x4E

#define INPUT_SENSITIVITY 100 // �Է� ����

//�ؽ�Ʈ �� ��� ���� ������ ���� enum
enum {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    CYAN,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
    DEFAULT_BACKGROUND = 0,
    DEFAULT_TEXT = 7,
};

/* ��ũ�� */
#define SCREEN_WIDTH 87
#define WAIT_TICK 1000 / 30

/* Game Funtions */
void Game(void);
void Start(void);
void Update(void);
void GameRender(void);

//Console Utill Funtions
void Init(void);
void CursorHide(void);

//Render Funtions
void RenderBackground(void);
void ClearBackground(void);
void ClearAnimation(void);
void RenderAuthor(void);
void RenderTitle(void);
int RenderMenu(void);
int RenderHelp(void);

//Text Utill Funtions
void GotoXY(int, int);
int WriteLineCenter(const char *, int);
int WriteCenter(const char *, int);
int GetCenter(const char*);
void ClearLine(int);

//Text Color Funtions
void SetColor(int);
void SetAllColor(int, int);

int main()
{
    int GameState = 1;

    Init();
    CursorHide();
    
    RenderTitle();
    do
    {
        switch(GameState){
        case 1:
            GameState = RenderMenu();
            continue;
        case 2:
            GameState = RenderHelp();
            continue;
        case 3:
            Sleep(1000);
            system("cls");
            printf("�����");
            exit(0);
        default:
            continue;
        }
        ClearBackground();
    } while (GameState != 0);
} 

//�� �ʱ�ȭ(ó������) �ܼ��� ũ�⸦ x 91 y 35�� �����ϰ� �ܼ��� �̸��� ������ 0.1�� ������ �⺻ ������ 7(���) 0(������)���� ����
void Init(void){
    system("mode con cols=91 lines=35 | title ������ 0.1 | color 70");
}

//Ŀ���� ����� �Լ�
void CursorHide(void){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//�׵θ��� �׸��� �Լ�
void RenderBackground(void){
    GotoXY(0, 0);
    //puts�� \n�� �⺻���� ��µǴ� printf
    puts("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for(int i = 1; i < 30; i++){
        puts("��                                                                                      ��");
    }
    puts("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    GotoXY(0, 31);
    puts("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for(int i = 0; i < 1; i++){
        puts("��                                                                                      ��");
    }
    puts("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    WriteLineCenter(GAME_VERSION, 32);
    RenderAuthor();
}

//ȭ�� ���� �Լ�
void ClearBackground(void){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     ");
    }
}

//������ �Ʒ��� ����� �ִϸ��̼� ȿ�����ִ� ȭ�� ���� �Լ�
void ClearAnimation(void){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     "); Sleep(20);
    }
}

//���� ȸ�� ��� �Լ�
void RenderAuthor(void){
    SetAllColor(DARK_GRAY, BLACK);
    
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     ");
    }

    SetAllColor(DARK_GRAY, GREEN);
    WriteLineCenter(" __ __ _____ _____ _____ _____    _____ _____ _____ _____ ", 13);
    WriteLineCenter("|  |  |  |  |  |  |  _  |   | |  |   __|  _  |     |   __|", 14);
    WriteLineCenter("|_   _|  |  |     |     | | | |  |  |  |     | | | |   __|", 15);
    WriteLineCenter("  |_| |_____|__|__|__|__|_|___|  |_____|__|__|_|_|_|_____|", 16);
    WriteLineCenter("                                                          ", 17);
    SetAllColor(DARK_GRAY, BLACK);

    Sleep(2000);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}

// ó�� Ÿ��Ʋ ȭ�� ���
void RenderTitle(void){
    int count;
    RenderBackground();
    ClearAnimation();

    //�ΰ� ���
    //������ ���� õõ�� ��µǴ� ȿ���� ���� Sleep() �Լ� ���
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

    WriteLineCenter("~ C��� ������ ���� ~", 13);

    while(1){
        //�����̽��ٸ� ������ �ݺ����� ��������
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            Sleep(200);
            break;
        } 

        //�����Ÿ��� ȿ��
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

//�޴�ȭ�� ���
int RenderMenu(void){
    ClearBackground();

    //�ΰ� ���
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

    //������ ������ ���� ����
    int lastTick = 0;
    //�ΰ��� ������ ���� ����
    int lastInputTick = 0;
    bool processingInput = false;
    while(1){
        //������ ���� 30���������� ����
        int currentTick = GetTickCount();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //Input �н�
        // �� ����Ű�� ������ ��
        if((GetAsyncKeyState(KEY_UP) & 0x8000  ) && (choose > 1)){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                choose--;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // �Ʒ� ����Ű�� ������ ��
        else if((GetAsyncKeyState(KEY_DOWN) & 0x8000 ) && (choose < 3)){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                choose++;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // �����̽��ٰ� ������ ��
        else if(GetAsyncKeyState(VK_SPACE) & 0x8000 ){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                switch (choose)
                {
                case 1:
                    SetColor(GREEN);
                    GotoXY(xPos, 18);
                    printf("���� ��");
                    SetColor(DEFAULT_TEXT);
                    Sleep(500);
                    return 1;
                case 2:
                    SetColor(GREEN);
                    GotoXY(xPos, 19);
                    printf("����");
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
                lastInputTick = currentTick;
            }
            processingInput = true;
        }else{
            processingInput = false;
        }
 
        //Render �н� 

        //���� �޴� ��ȣ ���
        WriteCenter("���� : ", 13);
        printf("%d", choose);

        //�޴� ���
        GotoXY(xPos, 18);
        printf("����");
        GotoXY(xPos, 19);
        printf("����");
        GotoXY(xPos, 20);
        printf("����");
        
        //���õǾ��ִ� �޴� ���� �ʷϻ� Ŀ���� ǥ����
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

// �������� ��� �Լ�
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
    printf("C��� ������ ���� ���۵� �����Դϴ�.");
    GotoXY(xPos,10);
    printf("CHROME DINO ������ ������� �ϰ��ֽ��ϴ�.");
    xPos = GetCenter("��                                                    ��");
    GotoXY(xPos,24);
    puts("������������������������������������������������������������������������������������������������������������");
    WriteLineCenter("��                                                    ��", 25);
    GotoXY(xPos,26);
    puts("������������������������������������������������������������������������������������������������������������");
    WriteLineCenter("���ư����� �����̽��ٸ� �����ʽÿ�.",25);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 1){
            ClearLine(25);
            GotoXY(xPos,24);
            SetColor(DEFAULT_TEXT);
            puts("������������������������������������������������������������������������������������������������������������");
            WriteLineCenter("��                                                    ��", 25);
            GotoXY(xPos,26);
            puts("������������������������������������������������������������������������������������������������������������");
            SetColor(GREEN);
            WriteLineCenter("�޴��� ���ư��ϴ�.", 25); 
            SetColor(DEFAULT_TEXT);
            Sleep(1000);
            break;
        } 
        GotoXY(3, 2);
    }
    return 1;
}

// ���� �޴� �ʿ��� �̱���
int ExitMenu(void){
    
}

//�ܼ� Ŀ���� �̵���Ű�� �Լ�
void GotoXY(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//EUC-KR ���ڵ����� ��Ȯ�� Str ���̸� ���ϴ� �Լ�
int euc_kr_strlen(const char *str) {
    int length = 0;
    while (*str) {
        if ((*str & 0x80) != 0) {
            if ((unsigned char)*str >= 0xA1 && (unsigned char)*str <= 0xFE) {
                str++; 
                length++;
            }
        }
        length++;
        str++;
    }
    return length;
}

//���� ���ڿ��� ȭ�� �߾ӿ� ����ϴ� �Լ�
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

//���� ���ڿ��� ȭ�� �߾ӿ� ����ϴ� �Լ� (���� ����)
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

//���� ���ڿ��� �߾����� �����ϱ� ���� Ŀ���� X��ǥ�� ���ϴ� �Լ�
int GetCenter(const char *Str){
        int screenWidth = 88;
    int len = euc_kr_strlen(Str);
    int xPos = (screenWidth - len) / 2 + 1;

    if(xPos <2){
        xPos = 2;
    }
    return xPos;
}

//Y��ǥ�� �޾� �ش� ���� ����ִ� �Լ�
void ClearLine(int y){
    GotoXY(2, y);
    printf("                                                                                     ");
}

//���� ������ �����ϴ� �Լ� ����� �ڵ����� �⺻ �������� ������
void SetColor(int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (DEFAULT_BACKGROUND<<4) + TextColor);
}

//���� ����� ������ ��� �����ϴ� �Լ�
void SetAllColor(int BackGroundColor, int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (BackGroundColor<<4) + TextColor);
}
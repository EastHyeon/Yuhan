#include "main.h"

int Game(){
    InitGame();

    struct Player player = {SCREEN_MIN_X, SCREEN_MIN_Y, 100, 0};

    int lastInputTick = 0;
    int sensitivity = INPUT_SENSITIVITY;
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    bool playerIsAtk = 0;
    bool State = true;
    while(State){
        int currentTick = GetTickCount();
        if(currentTick - lastInputTick > PLAYER_SPEED){
            if (GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000){
                PrintLog("���� : �� ����Ű ����");
                // if(currentTick - lastInputTick > PLAYER_SPEED){
                //     player.direction = 0;
                //     if(player.posY > SCREEN_MIN_Y)
                //         player.posY--;
                //     lastInputTick = currentTick;
                // }
                player.direction = 0;
                    if(player.posY > SCREEN_MIN_Y)
                        player.posY--;
            }
            if (GetAsyncKeyState(KEY_A) & 0x8000 || GetAsyncKeyState(KEY_LEFT) & 0x8000){
                PrintLog("���� : ���� ����Ű ����");
                // if(currentTick - lastInputTick > PLAYER_SPEED){
                //     player.direction = 1;
                //     if(player.posX > SCREEN_MIN_X)
                //         player.posX = player.posX - 2;
                //     lastInputTick = currentTick;
                // }
                player.direction = 1;
                if(player.posX > SCREEN_MIN_X)
                    player.posX = player.posX - 2;            
            }
            if (GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000){
                PrintLog("���� : �Ʒ��� ����Ű ����");
                // if(currentTick - lastInputTick > PLAYER_SPEED){
                //     player.direction = 2;
                //     if(player.posY < SCREEN_MAX_Y)
                //         player.posY++;
                //     lastInputTick = currentTick;
                // }
                player.direction = 2;
                if(player.posY < SCREEN_MAX_Y)
                    player.posY++;            
            }
            if (GetAsyncKeyState(KEY_D) & 0x8000 || GetAsyncKeyState(KEY_RIGHT) & 0x8000){
                PrintLog("���� : ������ ����Ű ����");
                // if(currentTick - lastInputTick > PLAYER_SPEED){
                //     player.direction = 3;
                //     if(player.posX < SCREEN_MAX_X - 2)
                //         player.posX = player.posX + 2;
                //     lastInputTick = currentTick;
                // }
                player.direction = 3;
                if(player.posX < SCREEN_MAX_X - 2)
                    player.posX = player.posX + 2;            
            }
            lastInputTick = currentTick;
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000){
            PrintLog("���� : �����̽��� ����");
            int choose = GamePause();
            if(MENU == choose)
                return MENU;
        }


        //Render �н�
        for(int x = SCREEN_MIN_X; x <= SCREEN_MAX_X; x++){
            for(int y = SCREEN_MIN_Y; y <= SCREEN_MAX_Y; y++){
                if(player.posX == x && player.posY == y){
                    GotoXY(x, y);
                    SetAllColor(DARK_GRAY, GREEN);
                    PrintPlayer(x, y, player.direction);
                    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                }
                else if((player.posX + 1 != x && x == SCREEN_MIN_X - 2) || (player.posY != y && x == SCREEN_MIN_X - 2)){
                    GotoXY(x, y);
                    printf("  ");
                }
                else if(player.posX + 1 != x || player.posY != y){
                    GotoXY(x, y);
                    printf(" ");
                }
            }
        }
    }
    return 1;
}

void InitGame(){
    InitScreen();
}

int GamePause(){
    PrintLog("���� : �Ͻ�����");
    static int choose = 1;
    int xPos = GetCenter("���� �簳") - 2;

    //������ ������ ���� ����
    int lastTick = 0;
    //�ΰ��� ������ ���� ����
    int lastInputTick = 0;
    int sensitivity = INPUT_SENSITIVITY + 50;
    bool processingInput = false;
    int boxCenter = GetCenter("                                        ");
    SetAllColor(DARK_RED, DEFAULT_TEXT);
    for(int i = 13; i < 17; i++){
        GotoXY(boxCenter, i);
        printf("                                        ");
    }
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    while(1){
        //������ ���� 30���������� ����
        int currentTick = GetTickCount();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //Input �н�
        // �� ����Ű�� ������ ��
        if(GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000){
            if(currentTick - lastInputTick > sensitivity){
                choose--;
                if(choose < 1)
                    choose = 2;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // �Ʒ� ����Ű�� ������ ��
        else if(GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000){
            if(currentTick - lastInputTick > sensitivity){
                choose++;
                if(choose > 2)
                    choose = 1;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // �����̽��ٰ� ������ ��
        else if(GetAsyncKeyState(VK_SPACE) & 0x8000 ){
            if(currentTick - lastInputTick > sensitivity){
                switch (choose)
                {
                case 1:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("�������� ���ư��ϴ�.",14);
                    PrintLog("���� : ���� �簳");
                    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                    Sleep(500);
                    return 0;
                case 2:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("���� �޴��� ���ư��ϱ�? (Y/N)",15);
                    while(1){
                        if(GetAsyncKeyState(KEY_Y) & 0x8000){
                            WriteLineCenter("�޴��� ���ư��ϴ�.",15);
                            PrintLog("���� : �޴��� �̵�");
                            Sleep(500);
                            SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                            return MENU;
                        }
                        else if(GetAsyncKeyState(KEY_N) & 0x8000){
                            WriteLineCenter("                              ",15);
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

        //�޴� ���
        SetAllColor(DARK_RED, WHITE);
        GotoXY(xPos, 14);
        printf("�����簳");
        GotoXY(xPos, 15);
        printf("�޴��� ���ư���");
        
        //���õǾ��ִ� �޴� ���� �ʷϻ� Ŀ���� ǥ����
        if(choose == 1){
            SetAllColor(DARK_RED, GREEN);
            GotoXY(xPos - 2, 14);
            printf(">");
            SetAllColor(DARK_RED, WHITE);
            GotoXY(xPos - 2, 15);
            printf(" ");
        }
        else if(choose == 2){
            SetAllColor(DARK_RED, GREEN);
            GotoXY(xPos - 2, 15);
            printf(">");
            SetAllColor(DARK_RED, WHITE);
            GotoXY(xPos - 2, 14);
            printf(" ");
        }
    }
}

void PrintPlayer(int x, int y, int dir){
    GotoXY(x, y);
    switch(dir){
    case 0:
        printf("%s", "��");
        break;
    case 1:
        printf("%s", "��");
        break;
    case 2:
        printf("%s", "��");
        break;
    case 3:
        printf("%s", "��");
        break;
    }
}

void PrintLog(const char* str){
    ClearLineColor(32, GRAY, BLACK);
    GotoXY(SCREEN_MIN_X, 32);
    printf("%s", str);
}
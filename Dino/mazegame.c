#include "main.h"

enum GameState Maze_Game(){
    struct Player player = {SCREEN_MIN_X, SCREEN_MIN_Y, 100, 0};

    Dino_InitGame();

    player.posX = SCREEN_MIN_X;
    player.posY = SCREEN_MIN_Y;

    int lastInputTick = 0;
    int lastFrameTick = 0;
    int sensitivity = INPUT_SENSITIVITY;
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    bool playerIsAtk = 0;
    bool State = true;
    while(State){
        int currentTick = GetTickCount();
        if(currentTick - lastFrameTick < WAIT_TICK)
            continue;
        lastFrameTick = currentTick;
        
        //Input && Logics �н�
        if(currentTick - lastInputTick > PLAYER_SPEED){
            PrintLog("�Է� ��� ��");
            if (GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000){
                PrintLog("�� ����Ű ����");
                player.direction = 0;
                    if(player.posY > SCREEN_MIN_Y)
                        player.posY--;
            }
            if (GetAsyncKeyState(KEY_A) & 0x8000 || GetAsyncKeyState(KEY_LEFT) & 0x8000){
                PrintLog("���� ����Ű ����");
                player.direction = 1;
                if(player.posX > SCREEN_MIN_X)
                    player.posX = player.posX - 2;            
            }
            if (GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000){
                PrintLog("�Ʒ��� ����Ű ����");
                player.direction = 2;
                if(player.posY < SCREEN_MAX_Y)
                    player.posY++;            
            }
            if (GetAsyncKeyState(KEY_D) & 0x8000 || GetAsyncKeyState(KEY_RIGHT) & 0x8000){
                PrintLog("������ ����Ű ����");
                player.direction = 3;
                if(player.posX < SCREEN_MAX_X - 2)
                    player.posX = player.posX + 2;            
            }
            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000){
                int choose = Dino_GamePause();
                if(MENU == choose)
                    return MENU;
            }
            if (GetAsyncKeyState(KEY_SPACE) & 0x8000){
                PrintLog("�����̽� �� ����");
            }

            lastInputTick = currentTick;
        }

        PrintPos(player.posX, player.posY);
        SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
        //Render �н�
        for(int x = SCREEN_MIN_X; x <= SCREEN_MAX_X; x++){
            for(int y = SCREEN_MIN_Y; y <= SCREEN_MAX_Y; y++){
                // X��ǥ�� ¦���� ���� ��� (��µǴ� ����� ���簢������ ���߱� ����)
                if(x == 0 || x % 2 == 0){
                    if(player.posX == x && player.posY == y){
                        GotoXY(x, y);
                        Dino_PrintPlayer(x, y, player.direction);
                    }
                    else if(player.posX + 1 != x || player.posY != y){
                        GotoXY(x, y);
                        printf("  ");
                    }
                }
            }
        }
    }
    return 1;
}

void Maze_InitGame(){
    InitScreen();
    for(int i = 0; i < 3; i++){
        ClearLineColor(i + 33, GRAY, BLACK);
    }
    PrintPos(0, 0);
    PrintLog("�Է� ��� ��");
}

int Maze_GamePause(){
    PrintLog("�Ͻ�����");
    int choose = 1;
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
                    PrintLog("���� �簳");
                    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                    Sleep(500);
                    return 0;
                case 2:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("���� �޴��� ���ư��ϱ�? (Y/N)",15);
                    while(1){
                        if(GetAsyncKeyState(KEY_Y) & 0x8000){
                            WriteLineCenter("                              ",15);
                            WriteLineCenter("�޴��� ���ư��ϴ�.",15);
                            PrintLog("�޴��� �̵�");
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

void Maze_PrintPlayer(int x, int y, int dir){
    SetAllColor(DARK_GRAY, GREEN);
    GotoXY(x, y);
    printf("  ");
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
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}
#include "main.h"

enum GameState Dino_Game(){
    struct Player player = {SCREEN_MIN_X, SCREEN_MIN_Y, 100, 0, .isJumping = false};
    enum TileType Tile[SCREEN_MAX_Y][(SCREEN_MAX_X) / 2 + 1] = {EMPTY};
    Dino_InitGame();

    player.posX = 4;
    player.posY = GROUND_HEIGHT;

    int lastInputTick = 0;
    int lastPyisicsTick = 0;
    int lastFrameTick = 0;
    int sensitivity = INPUT_SENSITIVITY;


    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    bool playerIsAtk = 0;
    bool State = true;
    player.direction = 3;
    while(State){
        int currentTick = GetTickCount64();
        if(currentTick - lastFrameTick < WAIT_TICK)
            continue;
        lastFrameTick = currentTick;
#pragma region INPUT
        //Input && Logics �н�
        if(currentTick - lastInputTick > PLAYER_SPEED){
            PrintLog("�Է� ��� ��");
            if (GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000){
                // PrintLog("�� ����Ű ����");
                // player.direction = 0;
                //     if(player.posY > SCREEN_MIN_Y)
                //         player.posY--;
            }
            if (GetAsyncKeyState(KEY_A) & 0x8000 || GetAsyncKeyState(KEY_LEFT) & 0x8000){
                PrintLog("���� ����Ű ����");
                player.direction = 1;
                if(player.posX > SCREEN_MIN_X)
                    player.posX = player.posX - 2;            
            }
            if (GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000){
                // PrintLog("�Ʒ��� ����Ű ����");
                // player.direction = 2;
                // if(player.posY < SCREEN_MAX_Y)
                //     player.posY++;            
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
                if(player.isGrounded){
                    player.isJumping = true;
                    player.isGrounded = false;
                }
            }
            lastInputTick = currentTick;
        }
#pragma endregion

        if(currentTick - lastPyisicsTick > PHYSIC_TICK){
            if(player.isJumping){
                player.posY -= 1;
            }
            else{
                player.posY += 1;
            }

            if(player.posY >= GROUND_HEIGHT){
                player.posY = GROUND_HEIGHT;
                player.isGrounded = true;
            }

            if(player.posY <= MAX_JUMP_HEIGHT){
                player.isJumping = false;
            }

            lastPyisicsTick = currentTick;
        }

        

        PrintPos(player.posX, player.posY);
        SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
        //Render �н�
        int RenderX = 0;
        for(int y = 0; y < SCREEN_MAX_Y; y++){
            for(int x = 0; x < SCREEN_MAX_X; x++){
                // X��ǥ�� ¦���� ���� ��� (��µǴ� ����� ���簢������ ���߱� ����)
                if(x == 0 || x % 2 == 0){
                    RenderX++;
                    GotoXY(x + SCREEN_MIN_X, y + SCREEN_MIN_Y);
                    SetAllColor(GetTileColor(Tile[y][RenderX]), DEFAULT_TEXT);
                    printf("  ");
                }
            }
            RenderX = 0;
            if (y == 28)
                PrintLog("Debug");
        }
    }
    return 1;
}

void Dino_InitGame(){
    InitScreen();
    for(int i = 0; i < 3; i++){
        ClearLineColor(i + 33, GRAY, BLACK);
    }
    PrintPos(0, 0);
    PrintLog("�Է� ��� ��");
}

int Dino_GamePause(){
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
        int currentTick = GetTickCount64();
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

void Dino_PrintPlayer(int x, int y, int dir){
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

enum ConsoleColor GetTileColor(enum TileType type){
    switch(type){
        case EMPTY:
            return DARK_GRAY;
        case WALL:
            return GRAY;
        default:
            return DEFAULT_BACKGROUND;
    }
}
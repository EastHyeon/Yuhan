#include "main.h"

enum GameState Maze_Game() {
    struct Player player = { SCREEN_MIN_X, SCREEN_MIN_Y, 100, 0, .isJumping = false };
    enum TileType Tile[SCREEN_MAX_Y][(SCREEN_MAX_X) / 2 + 1] = { EMPTY };


    player.posX = 0;
    player.posY = 0;

    int Score = 0;

    int lastInputTick = 0;
    int lastPyisicsTick = 0;
    int lastFrameTick = 0;
    int lastScoreTick = 0;
    int sensitivity = INPUT_SENSITIVITY;

    int RenderX = 0;

    int legFlag = 0;

    Dino_InitGame();

    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);

    bool playerIsAtk = 0;
    bool State = true;
    player.direction = 3;
    while (State) {
        int currentTick = GetTickCount64();
        if (currentTick - lastFrameTick < WAIT_TICK)
            continue;
        lastFrameTick = currentTick;
#pragma region INPUT
        //Input && Logics �н�
        if (currentTick - lastInputTick > PLAYER_SPEED) {
            PrintLog("�Է� ��� ��");
            if (GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000) {
                 PrintLog("�� ����Ű ����");
                 player.direction = 0;
                     if(player.posY >= SCREEN_MIN_Y)
                         player.posY--;
            }
            else if (GetAsyncKeyState(KEY_A) & 0x8000 || GetAsyncKeyState(KEY_LEFT) & 0x8000) {
                PrintLog("���� ����Ű ����");
                player.direction = 1;
                if (player.posX > 0)
                    player.posX--;
            }
            else if (GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000) {
                 PrintLog("�Ʒ��� ����Ű ����");
                 player.direction = 2;
                 if(player.posY < SCREEN_MAX_Y - 1)
                     player.posY++;            
            }
            else if (GetAsyncKeyState(KEY_D) & 0x8000 || GetAsyncKeyState(KEY_RIGHT) & 0x8000) {
                PrintLog("������ ����Ű ����");
                player.direction = 3;
                if (player.posX < SCREEN_MAX_X / 2 - 1)
                    player.posX++;
            }
            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                int choose = Dino_GamePause();
                if (MENU == choose)
                    return MENU;
            }
            lastInputTick = currentTick;
        }
        if (GetAsyncKeyState(KEY_SPACE) & 0x8000) {
            PrintLog("�����̽� �� ����");
            if (player.isGrounded) {
                player.isJumping = true;
                player.isGrounded = false;
            }
        }
#pragma endregion
        for (int y = 0; y < SCREEN_MAX_Y; y++) {
            for (int x = 0; x < SCREEN_MAX_X / 2; x++) {
                Tile[y][x] = EMPTY;
            }
        }
        if(player.posY < SCREEN_MAX_Y && player.posX < (SCREEN_MAX_X) / 2 + 1)
            Tile[player.posY][player.posX] = PLAYER;

        PrintPos(player.posX, player.posY);

        SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
        //Render �н�
        RenderX = 0;
        for (int y = 0; y < SCREEN_MAX_Y; y++) {
            for (int x = 0; x < SCREEN_MAX_X; x++) {
                // X��ǥ�� ¦���� ���� ��� (��µǴ� ����� ���簢������ ���߱� ����)
                if (x == 0 || x % 2 == 0) {
                    GotoXY(x + SCREEN_MIN_X, y + SCREEN_MIN_Y);
                    SetAllColor(GetTileColor(Tile[y][RenderX]), DEFAULT_TEXT);
                    printf("  ");
                    RenderX++;
                }
            }
            RenderX = 0;
        }
        if (currentTick - lastScoreTick > 2000) {
            PrintScore(Score);
            lastScoreTick = currentTick;
        }
    }
    return 1;
}

void Maze_InitGame() {
    InitScreen();
    for (int i = 0; i < 3; i++) {
        ClearLineColor(i + 33, GRAY, BLACK);
    }
    PrintPos(0, 0);
    PrintLog("�Է� ��� ��");
    PrintScore(0);
}

int Maze_ScoreScreen(int score) {
    PrintLog("�Ͻ�����");
    int choose = 1;
    int xPos = GetCenter("�ٽ� ����") - 2;


    //������ ������ ���� ����
    int lastTick = 0;
    //�ΰ��� ������ ���� ����
    int lastInputTick = 0;
    int sensitivity = INPUT_SENSITIVITY + 50;
    bool processingInput = false;
    int boxCenter = GetCenter("                                        ");
    SetAllColor(DARK_RED, DEFAULT_TEXT);
    for (int i = 0; i < 10; i++) {
        GotoXY(boxCenter, i + 10);
        printf("                                        ");
    }
    SetAllColor(DARK_RED, WHITE);
    WriteLineCenter("GAME OVER", 11);

    SetAllColor(DARK_RED, YELLOW);

    char buffer[256];
    sprintf_s(buffer, sizeof(buffer), "Score: %d", score);
    char* msg = buffer;
    if (score < 10) {
        GotoXY(GetCenter(msg) - 1, 13);
        printf(msg);
    }
    else
        WriteLineCenter(msg, 13);

    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    while (1) {
        //������ ���� 30���������� ����
        int currentTick = GetTickCount64();
        if (currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //Input �н�
        // �� ����Ű�� ������ ��
        if (GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000) {
            if (currentTick - lastInputTick > sensitivity) {
                choose--;
                if (choose < 1)
                    choose = 2;
                lastInputTick = currentTick;
            }
        }
        // �Ʒ� ����Ű�� ������ ��
        else if (GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000) {
            if (currentTick - lastInputTick > sensitivity) {
                choose++;
                if (choose > 2)
                    choose = 1;
                lastInputTick = currentTick;
            }
        }
        // �����̽��ٰ� ������ ��
        else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (currentTick - lastInputTick > sensitivity) {
                switch (choose)
                {
                case 1:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("�������� ���ư��ϴ�.", 17);
                    PrintLog("�ٽ� ����");
                    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                    Sleep(500);
                    return DINO;
                case 2:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("���� �޴��� ���ư��ϱ�? (Y/N)", 18);
                    while (1) {
                        if (GetAsyncKeyState(KEY_Y) & 0x8000) {
                            WriteLineCenter("                              ", 18);
                            WriteLineCenter("�޴��� ���ư��ϴ�.", 18);
                            PrintLog("�޴��� �̵�");
                            Sleep(500);
                            SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                            return MENU;
                        }
                        else if (GetAsyncKeyState(KEY_N) & 0x8000) {
                            WriteLineCenter("                              ", 18);
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
        }
        else {
            processingInput = false;
        }

        //Render �н� 

        //���� �޴� ��ȣ ���

        //�޴� ���
        SetAllColor(DARK_RED, WHITE);
        GotoXY(xPos, 17);
        printf("�ٽ� ����");
        GotoXY(xPos, 18);
        printf("�޴��� ���ư���");

        //���õǾ��ִ� �޴� ���� �ʷϻ� Ŀ���� ǥ����
        if (choose == 1) {
            SetAllColor(DARK_RED, GREEN);
            GotoXY(xPos - 2, 17);
            printf(">");
            SetAllColor(DARK_RED, WHITE);
            GotoXY(xPos - 2, 18);
            printf(" ");
        }
        else if (choose == 2) {
            SetAllColor(DARK_RED, GREEN);
            GotoXY(xPos - 2, 18);
            printf(">");
            SetAllColor(DARK_RED, WHITE);
            GotoXY(xPos - 2, 17);
            printf(" ");
        }
    }
}

int Maze_GamePause() {
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
    for (int i = 13; i < 17; i++) {
        GotoXY(boxCenter, i);
        printf("                                        ");
    }
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    while (1) {
        //������ ���� 30���������� ����
        int currentTick = GetTickCount64();
        if (currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //Input �н�
        // �� ����Ű�� ������ ��
        if (GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000) {
            if (currentTick - lastInputTick > sensitivity) {
                choose--;
                if (choose < 1)
                    choose = 2;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // �Ʒ� ����Ű�� ������ ��
        else if (GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000) {
            if (currentTick - lastInputTick > sensitivity) {
                choose++;
                if (choose > 2)
                    choose = 1;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // �����̽��ٰ� ������ ��
        else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (currentTick - lastInputTick > sensitivity) {
                switch (choose)
                {
                case 1:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("�������� ���ư��ϴ�.", 14);
                    PrintLog("���� �簳");
                    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                    Sleep(500);
                    return 0;
                case 2:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("���� �޴��� ���ư��ϱ�? (Y/N)", 15);
                    while (1) {
                        if (GetAsyncKeyState(KEY_Y) & 0x8000) {
                            WriteLineCenter("                              ", 15);
                            WriteLineCenter("�޴��� ���ư��ϴ�.", 15);
                            PrintLog("�޴��� �̵�");
                            Sleep(500);
                            SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                            return MENU;
                        }
                        else if (GetAsyncKeyState(KEY_N) & 0x8000) {
                            WriteLineCenter("                              ", 15);
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
        }
        else {
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
        if (choose == 1) {
            SetAllColor(DARK_RED, GREEN);
            GotoXY(xPos - 2, 14);
            printf(">");
            SetAllColor(DARK_RED, WHITE);
            GotoXY(xPos - 2, 15);
            printf(" ");
        }
        else if (choose == 2) {
            SetAllColor(DARK_RED, GREEN);
            GotoXY(xPos - 2, 15);
            printf(">");
            SetAllColor(DARK_RED, WHITE);
            GotoXY(xPos - 2, 14);
            printf(" ");
        }
    }
}

void Maze_PrintPlayer(int x, int y, int dir) {
    SetAllColor(DARK_GRAY, GREEN);
    GotoXY(x, y);
    printf("  ");
    GotoXY(x, y);
    switch (dir) {
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


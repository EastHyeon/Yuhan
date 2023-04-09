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
        
        //Input && Logics 패스
        if(currentTick - lastInputTick > PLAYER_SPEED){
            PrintLog("입력 대기 중");
            if (GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000){
                PrintLog("위 방향키 눌림");
                player.direction = 0;
                    if(player.posY > SCREEN_MIN_Y)
                        player.posY--;
            }
            if (GetAsyncKeyState(KEY_A) & 0x8000 || GetAsyncKeyState(KEY_LEFT) & 0x8000){
                PrintLog("왼쪽 방향키 눌림");
                player.direction = 1;
                if(player.posX > SCREEN_MIN_X)
                    player.posX = player.posX - 2;            
            }
            if (GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000){
                PrintLog("아래쪽 방향키 눌림");
                player.direction = 2;
                if(player.posY < SCREEN_MAX_Y)
                    player.posY++;            
            }
            if (GetAsyncKeyState(KEY_D) & 0x8000 || GetAsyncKeyState(KEY_RIGHT) & 0x8000){
                PrintLog("오른쪽 방향키 눌림");
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
                PrintLog("스페이스 바 눌림");
            }

            lastInputTick = currentTick;
        }

        PrintPos(player.posX, player.posY);
        SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
        //Render 패스
        for(int x = SCREEN_MIN_X; x <= SCREEN_MAX_X; x++){
            for(int y = SCREEN_MIN_Y; y <= SCREEN_MAX_Y; y++){
                // X좌표가 짝수일 때만 출력 (출력되는 모습을 정사각형으로 맞추기 위해)
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
    PrintLog("입력 대기 중");
}

int Maze_GamePause(){
    PrintLog("일시정지");
    int choose = 1;
    int xPos = GetCenter("게임 재개") - 2;

    //프레임 제한을 위한 변수
    int lastTick = 0;
    //민감도 설정을 위한 변수
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
        //프레임 관리 30프레임으로 고정
        int currentTick = GetTickCount();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //Input 패스
        // 위 방향키가 눌렸을 때
        if(GetAsyncKeyState(KEY_W) & 0x8000 || GetAsyncKeyState(KEY_UP) & 0x8000){
            if(currentTick - lastInputTick > sensitivity){
                choose--;
                if(choose < 1)
                    choose = 2;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // 아래 방향키가 눌렀을 때
        else if(GetAsyncKeyState(KEY_S) & 0x8000 || GetAsyncKeyState(KEY_DOWN) & 0x8000){
            if(currentTick - lastInputTick > sensitivity){
                choose++;
                if(choose > 2)
                    choose = 1;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // 스페이스바가 눌렸을 때
        else if(GetAsyncKeyState(VK_SPACE) & 0x8000 ){
            if(currentTick - lastInputTick > sensitivity){
                switch (choose)
                {
                case 1:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("게임으로 돌아갑니다.",14);
                    PrintLog("게임 재개");
                    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
                    Sleep(500);
                    return 0;
                case 2:
                    SetAllColor(DARK_RED, GREEN);
                    WriteLineCenter("정말 메뉴로 돌아갑니까? (Y/N)",15);
                    while(1){
                        if(GetAsyncKeyState(KEY_Y) & 0x8000){
                            WriteLineCenter("                              ",15);
                            WriteLineCenter("메뉴로 돌아갑니다.",15);
                            PrintLog("메뉴로 이동");
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
 
        //Render 패스 

        //선택 메뉴 번호 출력

        //메뉴 출력
        SetAllColor(DARK_RED, WHITE);
        GotoXY(xPos, 14);
        printf("게임재개");
        GotoXY(xPos, 15);
        printf("메뉴로 돌아가기");
        
        //선택되어있는 메뉴 옆에 초록색 커서를 표시함
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
        printf("%s", "▲");
        break;
    case 1:
        printf("%s", "◀");
        break;
    case 2:
        printf("%s", "▼");
        break;
    case 3:
        printf("%s", "▶");
        break;
    }
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}
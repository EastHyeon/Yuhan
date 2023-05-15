#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define SCREEN_MAX_Y 30
#define SCREEN_MAX_X 80
#define ARRAY_SIZE SCREEN_MAX_Y * SCREEN_MAX_X + SCREEN_MAX_Y
#define GROUND_HEIGHT 28

#define WAIT_TICK 1000 / 15
#define PHYSICS_TICK 1000 / 30
#define INPUT_SENSITIVITY 150
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

enum GameState MainMenu(void);
enum GameState HelpMenu(void);
enum GameState ExitMenu(void);
enum GameState Game(void);
enum GameState GameOverMenu(void);

void InitializeScreen(void);
void CursorHide(void);
void SetColor(int);
void GotoXY(int, int);
int InputCenter(const char*, int);
void InputYX(const char*, int, int);
void InitializeGame(void);

enum GameState {
    EXIT = 0,
    EXITMENU,
    MAINMENU,
    GAME,
    GAMEOVERMENU,
    HELPMENU
};

enum CurrentInput {
    KEY_Wait,
    KEY_W,
    KEY_A,
    KEY_S,
    KEY_D,
    KEY_UpArrow,
    KEY_LeftArrow,
    KEY_DownArrow,
    KEY_RightArrow,
    KEY_Spacebar,
    KEY_Enter
} currentInput;

struct Player
{
    int posX;
    int posY;
    int hp;
    bool isGrounded;
    bool isJumping;
    bool isRuning;
};

char screen2D[SCREEN_MAX_Y][SCREEN_MAX_X];

int inputValue = 0;
char getCharTemp = ' ';

struct Player player = {10, GROUND_HEIGHT, 1, false, false, false };
bool isGameOver = false;
char playerTexture = '#';
char objectTexture = '%';
int TreeX = -10;
int randomTree = 0;

int spaceBarInputSensitvity = 8;

bool legFlag = true;
bool isDown = false;

bool isPause = false;

#define MAX_JUMP_HEIGHT SCREEN_MAX_Y - 12

int score = 0;
clock_t startTime, currentTime;

int main() {
    enum GameState gameState = MAINMENU;

    system("cls");
    system("mode con cols=81 lines=31 | title Array Dino Game for C Lecture");
    CursorHide();

    while (1) {
        InitializeScreen();

        DWORD currentTick = GetTickCount();
        //Input PASS
        if (GetAsyncKeyState(VK_W) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000) {
            currentInput = KEY_W;
        }
        if (GetAsyncKeyState(VK_S) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000) {
            currentInput = KEY_S;
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_RETURN) & 0x8000) {
                currentInput = KEY_Spacebar;
        }

#pragma region Logic_PASS
        //Logic PASS

        switch (gameState) {
        case EXIT:
            system("cls");
            return 0;
        case EXITMENU:
            gameState = ExitMenu();
            break;
        case MAINMENU:
            gameState = MainMenu();
            break;
        case GAME:
            gameState = Game();
            break;
        case HELPMENU:
            gameState = HelpMenu();
            break;
        case GAMEOVERMENU:
            gameState = GameOverMenu();
            break;
        default:
            break;
        }

#pragma endregion
        // 2차원배열을 개행문자를 포함하여 1차원 배열로 변환
        char screen[ARRAY_SIZE];
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int y = i / (SCREEN_MAX_X + 1);
            int x = i % (SCREEN_MAX_X + 1);

            if (i != 0 && x == SCREEN_MAX_X)
                screen[i] = '\n';
            else
                screen[i] = screen2D[y][x];
        }
        screen[ARRAY_SIZE - 1] = '\0';

        //Render PASS
        printf("%s\n", screen);
    }
}

void SetColor(int bgColor) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (bgColor << 4) + 15);
}

void GotoXY(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

enum GameState MainMenu() {
    InputCenter("Dino Run Game", 3);
    int xPos = InputCenter("START", 5);
    InputYX("HELP", 6, xPos);
    InputYX("EXIT", 7, xPos);

    xPos -= 2;

    int yPos = inputValue + 5;

    if (currentInput == KEY_W && yPos > 5)
        inputValue--;
    if (currentInput == KEY_S && yPos < 7)
        inputValue++;

    screen2D[yPos][xPos] = '>';

    if (currentInput == KEY_Spacebar) {
        int temp = inputValue;
        inputValue = 0;
        switch (temp) {
        case 0:
            InitializeGame();
            return GAME;
        case 1:
            return HELPMENU;
        case 2:
            return EXITMENU;
        default:
            break;
        }
    }

    return MAINMENU;
}

enum GameState HelpMenu() {
    InputCenter("Help", 3);
    InputCenter("Created for a C language class assignment", 5);
    InputCenter("Both WASD and ArrowKeys are available", 6);
    InputCenter("A, D or Arrow Key to Move", 7);
    InputCenter("Space Key to Jump", 8);
    InputCenter("Escape Key to Game Exit", 9);

    InputCenter("Spacebar to return to the menu", 11);


    if (currentInput == KEY_Spacebar) {
        return MAINMENU;
    }

    return HELPMENU;
}

enum GameState ExitMenu() {
    InputCenter("Are you sure you want to exit?", 3);
    int xPos = InputCenter("Yes", 5);
    InputYX("No", 6, xPos);

    xPos -= 2;
    int yPos = inputValue + 5;
    if (currentInput == KEY_W && yPos > 5)
        inputValue--;
    if (currentInput == KEY_S && yPos < 6)
        inputValue++;

    screen2D[yPos][xPos] = '>';

    if (currentInput == KEY_Spacebar) {
        int temp = inputValue;
        inputValue = 0;
        switch (temp) {
        case 0:
            return EXIT;
        case 1:
            return MAINMENU;
        default:
            break;
        }
    }

    return EXITMENU;
}

enum GameState Game() {

    int currentTick = GetTickCount();


    // 비동기 입력을 위해 따로 입력받습니다.
    if ((GetAsyncKeyState(VK_D) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000) && player.posX < SCREEN_MAX_X - 6) {
        player.posX++;
    }

    if ((GetAsyncKeyState(VK_A) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000) && player.posX > 1) {
        player.posX--;
    }

    if (GetAsyncKeyState(VK_A) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_D) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000){
        player.isRuning = true;
    }
    else{
        player.isRuning = false;
    }

    if (GetAsyncKeyState(VK_S) & 0x8001 || GetAsyncKeyState(VK_DOWN) & 0x8000) {
        isDown = true;
    }
    else{
        isDown = false;
    }

    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        if (player.isGrounded) {
            player.isJumping = true;
            player.isGrounded = false;
        }
    }
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
        return MAINMENU;
    }

    if (TreeX < -10) {
        randomTree = rand() % 5;
        TreeX = SCREEN_MAX_X - 1;
    }
    TreeX--;

    if (player.isJumping)
        player.posY--;
    else
        player.posY++;

    if (player.posY > GROUND_HEIGHT) {
        player.posY = GROUND_HEIGHT;
        player.isGrounded = true;
    }

    if (player.posY <= MAX_JUMP_HEIGHT)
        player.isJumping = false;

    if (isDown) { 
        //001111
        //011111
        //111100
        //010100
        screen2D[player.posY - 3][player.posX + 3] = playerTexture;
        screen2D[player.posY - 3][player.posX + 4] = playerTexture;
        screen2D[player.posY - 3][player.posX + 5] = playerTexture;

        screen2D[player.posY - 2][player.posX + 1] = playerTexture;
        screen2D[player.posY - 2][player.posX + 2] = playerTexture;
        screen2D[player.posY - 2][player.posX + 3] = playerTexture;
        screen2D[player.posY - 2][player.posX + 4] = playerTexture;
        screen2D[player.posY - 2][player.posX + 5] = playerTexture;

        screen2D[player.posY - 1][player.posX] = playerTexture;
        screen2D[player.posY - 1][player.posX + 1] = playerTexture;
        screen2D[player.posY - 1][player.posX + 2] = playerTexture;
        screen2D[player.posY - 1][player.posX + 3] = playerTexture;
    }
    else {
        //00111
        //00111
        //01110
        //11110
        //01010
        screen2D[player.posY - 4][player.posX + 2] = playerTexture;
        screen2D[player.posY - 4][player.posX + 3] = playerTexture;
        screen2D[player.posY - 4][player.posX + 4] = playerTexture;

        screen2D[player.posY - 3][player.posX + 2] = playerTexture;
        screen2D[player.posY - 3][player.posX + 3] = playerTexture;
        screen2D[player.posY - 3][player.posX + 4] = playerTexture;

        screen2D[player.posY - 2][player.posX + 1] = playerTexture;
        screen2D[player.posY - 2][player.posX + 2] = playerTexture;
        screen2D[player.posY - 2][player.posX + 3] = playerTexture;

        screen2D[player.posY - 1][player.posX] = playerTexture;
        screen2D[player.posY - 1][player.posX + 1] = playerTexture;
        screen2D[player.posY - 1][player.posX + 2] = playerTexture;
        screen2D[player.posY - 1][player.posX + 3] = playerTexture;
    }

    if (legFlag) {
        legFlag = false;
    }
    else {
        legFlag = true;
    }
    
    if(player.isRuning){
        if (legFlag)
            screen2D[player.posY][player.posX + 1] = playerTexture;
        else
            screen2D[player.posY][player.posX + 3] = playerTexture;
    }
    else{
        screen2D[player.posY][player.posX + 1] = playerTexture;
        screen2D[player.posY][player.posX + 3] = playerTexture;
    }

    int ObjectX = 0;
    int ObjectY = 0;
    switch (randomTree){
    case 0:
        ObjectX = 5;
        ObjectY = 2;
        for (int i = 0; i < ObjectX * ObjectY; i++) {
            int y = i / ObjectX;
            int x = i % ObjectX;
            if (TreeX + x > 0 && TreeX + x < SCREEN_MAX_X - 1) {
                if (screen2D[GROUND_HEIGHT - y][TreeX + x] == playerTexture) {
                    return GAMEOVERMENU;
                }
                else {
                    screen2D[GROUND_HEIGHT - y][TreeX + x] = objectTexture;
                }
            }
        }
        break;
    case 1:
        ObjectX = 7;
        ObjectY = 6;
        for (int i = 0; i < ObjectX * ObjectY; i++) {
            int y = i / ObjectX;
            int x = i % ObjectX;
            if (TreeX + x > 0 && TreeX + x < SCREEN_MAX_X - 1) {
                if (screen2D[GROUND_HEIGHT - y][TreeX + x] == playerTexture) {
                    return GAMEOVERMENU;
                }
                else {
                    screen2D[GROUND_HEIGHT - y][TreeX + x] = objectTexture;
                }
            }
        }
        break;
    case 2:
        ObjectX = 2;
        ObjectY = 5;
        for (int i = 0; i < ObjectX * ObjectY; i++) {
            int y = i / ObjectX;
            int x = i % ObjectX;
            if (TreeX + x > 0 && TreeX + x < SCREEN_MAX_X - 1) {
                if (screen2D[GROUND_HEIGHT - y][TreeX + x] == playerTexture) {
                    return GAMEOVERMENU;
                }
                else {
                    screen2D[GROUND_HEIGHT - y][TreeX + x] = objectTexture;
                }
            }
        }
        break;
    case 3:
        ObjectX = 10;
        ObjectY = 6;
        for (int i = 0; i < ObjectX * ObjectY; i++) {
            int y = i / ObjectX;
            int x = i % ObjectX;
            if (TreeX + x > 0 && TreeX + x < SCREEN_MAX_X - 1) {
                if (screen2D[GROUND_HEIGHT - y - 4][TreeX + x] == playerTexture) {
                    return GAMEOVERMENU;
                }
                else {
                    screen2D[GROUND_HEIGHT - y - 4][TreeX + x] = objectTexture;
                }
            }
        }
        break;
    case 4:
        ObjectX = 5;
        ObjectY = 10;
        for (int i = 0; i < ObjectX * ObjectY; i++) {
            int y = i / ObjectX;
            int x = i % ObjectX;
            if (TreeX + x > 0 && TreeX + x < SCREEN_MAX_X - 1) {
                if (screen2D[GROUND_HEIGHT - y - 4][TreeX + x] == playerTexture) {
                    return GAMEOVERMENU;
                }
                else {
                    screen2D[GROUND_HEIGHT - y - 4][TreeX + x] = objectTexture;
                }
            }
        }
        break;
    default:
        break;
    }

    currentTime = clock();
    if (((currentTime - startTime) / CLOCKS_PER_SEC) >= 1) {
        score++;
        startTime = currentTime;
    }


    char msg[50] = " ";
    sprintf(msg, "Score : %d", score);
    InputYX(msg, 1, 1);
    return GAME;
}

enum GameState GameOverMenu() {
    InputCenter("--- YOU DIED ---", 3);
    char msg[50] = " ";
    sprintf(msg, "Score : %d", score);
    int xPos = InputCenter(msg, 5);
    InputYX("Retry", 7, xPos);
    InputYX("Return to Menu", 8, xPos);

    xPos -= 2;

    int yPos = inputValue + 7;

    if (currentInput == KEY_W && yPos > 7)
        inputValue--;
    if (currentInput == KEY_S && yPos < 8)
        inputValue++;

    screen2D[yPos][xPos] = '>';

    if (currentInput == KEY_Spacebar) {
        int temp = inputValue;
        inputValue = 0;
        switch (temp) {
        case 0:
            InitializeGame();
            return GAME;
        case 1:
            return MAINMENU;
        default:
            break;
        }
    }

    return GAMEOVERMENU;
}

void InitializeScreen() {
    currentInput = KEY_Wait;
    GotoXY(0, 0);
    for (int i = 0; i < SCREEN_MAX_Y * SCREEN_MAX_X; i++) {
        int y = i / SCREEN_MAX_X;
        int x = i % SCREEN_MAX_X;
        if (y == 0 && x == 0 || // 1
            x == SCREEN_MAX_X - 1 && y == 0 || // 2
            x == 0 && y == SCREEN_MAX_Y - 1 || // 3
            x == SCREEN_MAX_X - 1 && y == SCREEN_MAX_Y - 1)  // 4
            screen2D[y][x] = '#';
        else if (y == 0 || y == SCREEN_MAX_Y - 1)
            screen2D[y][x] = '-';
        else if (x == 0 || x == SCREEN_MAX_X - 1)
            screen2D[y][x] = '|';
        else
            screen2D[y][x] = ' ';
    }
    InputCenter("| 202327005 Kim Dong Hyeon |", SCREEN_MAX_Y - 1);
}

void CursorHide() {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int InputCenter(const char* msg, int y) {
    int xPos = (SCREEN_MAX_X / 2) - (strlen(msg) / 2);

    for (int i = 0; i < strlen(msg); i++) {
        screen2D[y][xPos + i] = msg[i];
    }
    return xPos;
}

void InputYX(const char* msg, int y, int x) {
    for (int i = 0; i < strlen(msg); i++) {
        screen2D[y][x + i] = msg[i];
    }
}

void InitializeGame(){
    startTime = clock();
    player.posX = 5;
    player.posY = GROUND_HEIGHT;
    player.isRuning = false;
    TreeX = -10;
    score = 0;
}
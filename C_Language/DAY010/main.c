#include <stdio.h>
#include <windows.h>
#include <string.h>

#define SCREEN_MAX_Y 30
#define SCREEN_MAX_X 80
#define ARRAY_SIZE SCREEN_MAX_Y * SCREEN_MAX_X + SCREEN_MAX_Y

#define WAIT_TICK 1000 / 15
#define INPUT_SENSITIVITY 150;
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

void SetColor(int);
void GotoXY(int, int);
int InputCenter(const char*, int);
void InputYX(const char*, int, int);
enum GameState MainMenu(void);
enum GameState HelpMenu(void);
enum GameState ExitMenu(void);
void InitializeScreen(void);

enum GameState {
    EXIT = 0,
    EXITMENU,
    MAINMENU,
    GAME,
    HELPMENU
};

enum CurrentInput{
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

// 스크린 출력 배열
char screenBuffer2D[SCREEN_MAX_Y][SCREEN_MAX_X];
int inputValue = 0;

int main() {
    enum GameState gameState = MAINMENU;

    system("cls");
    system("mode con cols=81 lines=31 | title C Lecture");

    int lastTick = 0;
    int lastInputTick = 0;
    int inputSensitivity = INPUT_SENSITIVITY;

    while (1) {
        InitializeScreen();

        int currentTick = GetTickCount();
        if (currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

#pragma region INPUT_PASS
        //Input PASS

        if (GetAsyncKeyState(VK_W) & 0x8000) {
            if (currentTick - lastInputTick > inputSensitivity){
                currentInput = KEY_W;
                lastInputTick = currentTick;
            }
        }
        if (GetAsyncKeyState(VK_A) & 0x8000) {
            if (currentTick - lastInputTick > inputSensitivity) {
                currentInput = KEY_A;
                lastInputTick = currentTick;
            }
        }
        if (GetAsyncKeyState(VK_S) & 0x8000) {
            if (currentTick - lastInputTick > inputSensitivity) {
                currentInput = KEY_S;
                lastInputTick = currentTick;
            }
        }
        if (GetAsyncKeyState(VK_D) & 0x8000) {
            if (currentTick - lastInputTick > inputSensitivity) {
                currentInput = KEY_D;
                lastInputTick = currentTick;
            }
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (currentTick - lastInputTick > inputSensitivity) {
                currentInput = KEY_Spacebar;
                lastInputTick = currentTick;
            }
        }
#pragma endregion

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
            break;
        case HELPMENU:
            gameState = HelpMenu();
            break;
        default:
            break;
        }
#pragma endregion

        // 2차원 배열을 개행문자를 포함한 1차원 배열로 전환
        char screenBuffer[ARRAY_SIZE];
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int y = i / (SCREEN_MAX_X + 1);
            int x = i % (SCREEN_MAX_X + 1);

            if (i != 0 && x == SCREEN_MAX_X)
                screenBuffer[i] = '\n';
            else
                screenBuffer[i] = screenBuffer2D[y][x];
        }
        screenBuffer[ARRAY_SIZE - 1] = '\0';

        //Render PASS
        printf("%s\n", screenBuffer);

        //Status Render PASS
        GotoXY(0, SCREEN_MAX_Y);
        printf("InputValue : %d", inputValue);
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
    InputCenter("Dino Game", 3);
    int xPos = InputCenter("START", 5);
    InputYX("HELP", 6, xPos);
    InputYX("EXIT", 7, xPos);

    xPos -= 2;

    int yPos = inputValue + 5;

    if (currentInput == KEY_W && yPos > 5)
        inputValue--;
    if (currentInput == KEY_S && yPos < 7)
        inputValue++;

    screenBuffer2D[yPos][xPos] = '>';
    
    if (currentInput == KEY_Spacebar) {
        int temp = inputValue;
        inputValue = 0;
        switch (temp) {
        case 0:
            return MAINMENU;
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
    InputCenter("Spacebar to return to the menu", 8);


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

    screenBuffer2D[yPos][xPos] = '>';

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

void InitializeScreen() {
    currentInput = KEY_Wait;
    GotoXY(0, 0);
    for (int i = 0; i < SCREEN_MAX_Y * SCREEN_MAX_X; i++) {
        int y = i / SCREEN_MAX_X;
        int x = i % SCREEN_MAX_X;
        if(y == 0 && x == 0 || // 1
        x == SCREEN_MAX_X - 1 && y == 0 || // 2
        x == 0 && y == SCREEN_MAX_Y - 1 || // 3
        x == SCREEN_MAX_X - 1 && y == SCREEN_MAX_Y - 1)  // 4
            screenBuffer2D[y][x] = '#';
        else if (y == 0 || y == SCREEN_MAX_Y - 1)
            screenBuffer2D[y][x] = '-';
        else if(x == 0 || x == SCREEN_MAX_X - 1)
            screenBuffer2D[y][x] = '|';
        else
            screenBuffer2D[y][x] = ' ';
    }
    
    InputCenter("| 202327005 Kim Dong Hyeon |", SCREEN_MAX_Y - 1);
}

int InputCenter(const char* msg, int y) {
    int xPos = (SCREEN_MAX_X - strlen(msg)) / 2;
    if (xPos % 2 != 0)
        xPos--;

    for (int i = 0; i < strlen(msg); i++) {
        screenBuffer2D[y][xPos + i] = msg[i];
    }

    return xPos;
}

void InputYX(const char* msg, int y, int x) {
    for (int i = 0; i < strlen(msg); i++) {
        screenBuffer2D[y][x + i] = msg[i];
    }
}
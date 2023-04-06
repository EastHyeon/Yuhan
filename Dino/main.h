#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#pragma region DATA_DECL
// ��������
#define GAME_VERSION "������ v0.1 | 202327005 �赿��" 
#define WAIT_TICK 1000 / 30
#define SCREEN_MIN_X 2
#define SCREEN_MAX_X 85
#define SCREEN_MIN_Y 1
#define SCREEN_MAX_Y 29

//ȭ�� ������ ���� enum
enum GameState{
    EXIT = 0,
    MENU,
    GAME,
    HELP,
};

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
#pragma endregion

#pragma region KEY
// Ű
#define KEY_UP 0x26
#define KEY_LEFT 0x25
#define KEY_DOWN 0x28
#define KEY_RIGHT 0x27

#define KEY_W 0x57
#define KEY_A 0x41
#define KEY_S 0x53
#define KEY_D 0x44

#define KEY_SPACE 0x20

#define KEY_Y 0x59
#define KEY_N 0x4E
#define KEY_ESCAPE 0x1B

#define INPUT_SENSITIVITY 100 // �Է� ����
#pragma endregion

#pragma region SCREEN_DECL
void InitScreen(void);
void InitScreenFade(void);
void InitScreenFadeColor(int, int);
void InitBackGround(void);
#pragma endregion

#pragma region RENDER_DECL
void RenderTitle(void);
void RenderAuthor(void);
void RenderTitle(void);
enum GameState RenderMenu(void);
enum GameState RenderHelp(void);
#pragma endregion

#pragma region UTILL_DECL
void GotoXY(int, int);
void CursorHide(void);
void SetColor(int);
void SetAllColor(int, int);
int WriteCenter(const char*, int );
int WriteLineCenter(const char*, int );
int GetCenter(const char*);
void ClearLine(int);
void ClearLineColor(int, int, int);
int euc_kr_strlen(const char*);
#pragma endregion

#pragma region GAME_DECL
int Game();
void InitGame();
void PrintPlayer(int, int, int);
int GamePause();
void RenderGame(void);
void PrintLog(const char*);

#define PLAYER_SPEED 50

struct Player{
    int posX;
    int posY;
    int hp;
    int direction;
};

#pragma endregion
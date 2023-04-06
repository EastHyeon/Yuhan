#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#pragma region DATA_DECL
// 게임정보
#define GAME_VERSION "디노게임 v0.1 | 202327005 김동현" 
#define WAIT_TICK 1000 / 30
#define SCREEN_MIN_X 2
#define SCREEN_MAX_X 86
#define SCREEN_MIN_Y 1
#define SCREEN_MAX_Y 30

//화면 선택을 위한 enum
enum GameState{
    EXIT = 0,
    MENU,
    GAME,
    HELP,
};

// 키
#define KEY_UP 0x26
#define KEY_DOWN 0x28
#define KEY_SPACE 0x20
#define KEY_Y 0x59
#define KEY_N 0x4E
#define INPUT_SENSITIVITY 100 // 입력 감도

//텍스트 및 배경 색상 지정을 위한 enum
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

#pragma region SCREEN_DECL
void InitScreen(void);
void InitScreenFade(void);
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
void ClearLine(int y);
int euc_kr_strlen(const char*);
#pragma endregion

#pragma region GAME_DECL
void Game();
void InitGame();
void PrintPlayer(int, int);
#pragma endregion
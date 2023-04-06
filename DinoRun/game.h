#include <stdio.h>
#include <windows.h>
#include <string.h>

#ifndef __DATA__
#define __DATA__
#include "data.h"
#endif

//Game Funtions
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
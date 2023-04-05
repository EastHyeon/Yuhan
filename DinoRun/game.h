#include <stdio.h>
#include <windows.h>
#include <string.h>

#ifndef __DATA__
#define __DATA__
#include "data.h"
#endif

void Init(void);
void CursorHide(void);
void RenderBackground(void);
void ClearBackground(void);
void CLearAnimation(void);
void RenderTitle(void);
int RenderMenu(void);
int RenderHelp(void);
void GotoXY(int, int);
int WriteLineCenter(const char *, int);
int WriteCenter(const char *, int);
int GetCenter(const char*);
void ClearLine(int);
void SetColor(int);
void SetAllColor(int, int);
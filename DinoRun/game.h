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
void RenderTitle(void);
int RenderMenu(void);
int RenderHelp(void);
void GotoXY(int, int);
void PrintCenter(const char *Str);

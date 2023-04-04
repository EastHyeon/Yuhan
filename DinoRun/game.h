#include <stdio.h>
#include <windows.h>

#include "console.h"
#include "data.h"

void Init(void);
void CursorHide(void);
void RenderBackground(void);
void ClearBackground(void);
void RenderTitle(void);
void RenderHelp(void);
void GotoXY(int, int);
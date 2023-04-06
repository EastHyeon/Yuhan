#include "dino.h"

void GotoXY(int, int);
void CursorHide(void);

void SetColor(int);
void SetAllColor(int, int);
int WriteCenter(const char*, int );
int WriteLineCenter(const char*, int );
int GetCenter(const char*);
void ClearLine(int y);
int euc_kr_strlen(const char*);
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

// °ÔÀÓÁ¤º¸
#define GAME_VERSION "µð³ë°ÔÀÓ v0.1 | 202327005 ±èµ¿Çö" 

// Å°
#define KEY_UP 0x26
#define KEY_DOWN 0x28
#define KEY_SPACE 0x20
#define KEY_Y 0x59
#define KEY_N 0x4E

#define INPUT_SENSITIVITY 100 // ÀÔ·Â °¨µµ

//ÅØ½ºÆ® ¹× ¹è°æ »ö»ó ÁöÁ¤À» À§ÇÑ enum
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

/* ½ºÅ©¸° */
#define SCREEN_WIDTH 87
#define WAIT_TICK 1000 / 30

/* Game Funtions */
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

int main()
{
    int GameState = 1;

    Init();
    CursorHide();
    
    RenderTitle();
    do
    {
        switch(GameState){
        case 1:
            GameState = RenderMenu();
            continue;
        case 2:
            GameState = RenderHelp();
            continue;
        case 3:
            Sleep(1000);
            system("cls");
            printf("Á¾·áµÊ");
            exit(0);
        default:
            continue;
        }
        ClearBackground();
    } while (GameState != 0);
} 

//¾Û ÃÊ±âÈ­(Ã³À½¼³Á¤) ÄÜ¼ÖÀÇ Å©±â¸¦ x 91 y 35·Î °íÁ¤ÇÏ°í ÄÜ¼ÖÀÇ ÀÌ¸§À» µð³ë°ÔÀÓ 0.1·Î º¯°æÈÄ ±âº» »ö»óÀ» 7(Èò»ö) 0(°ËÀº»ö)À¸·Î º¯°æ
void Init(void){
    system("mode con cols=91 lines=35 | title µð³ë°ÔÀÓ 0.1 | color 70");
}

//Ä¿¼­¸¦ ¼û±â´Â ÇÔ¼ö
void CursorHide(void){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//Å×µÎ¸®¸¦ ±×¸®´Â ÇÔ¼ö
void RenderBackground(void){
    GotoXY(0, 0);
    //puts´Â \nÀÌ ±âº»À¸·Î Ãâ·ÂµÇ´Â printf
    puts("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
    for(int i = 1; i < 30; i++){
        puts("¦¢                                                                                      ¦¢");
    }
    puts("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
    GotoXY(0, 31);
    puts("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
    for(int i = 0; i < 1; i++){
        puts("¦¢                                                                                      ¦¢");
    }
    puts("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
    WriteLineCenter(GAME_VERSION, 32);
    RenderAuthor();
}

//È­¸é ºñ¿ì±â ÇÔ¼ö
void ClearBackground(void){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     ");
    }
}

//À§¿¡¼­ ¾Æ·¡·Î Áö¿ì´Â ¾Ö´Ï¸ÞÀÌ¼Ç È¿°ú°¡ÀÖ´Â È­¸é ºñ¿ì±â ÇÔ¼ö
void ClearAnimation(void){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     "); Sleep(20);
    }
}

//°ÔÀÓ È¸»ç Ãâ·Â ÇÔ¼ö
void RenderAuthor(void){
    SetAllColor(DARK_GRAY, BLACK);
    
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     ");
    }

    SetAllColor(DARK_GRAY, GREEN);
    WriteLineCenter(" __ __ _____ _____ _____ _____    _____ _____ _____ _____ ", 13);
    WriteLineCenter("|  |  |  |  |  |  |  _  |   | |  |   __|  _  |     |   __|", 14);
    WriteLineCenter("|_   _|  |  |     |     | | | |  |  |  |     | | | |   __|", 15);
    WriteLineCenter("  |_| |_____|__|__|__|__|_|___|  |_____|__|__|_|_|_|_____|", 16);
    WriteLineCenter("                                                          ", 17);
    SetAllColor(DARK_GRAY, BLACK);

    Sleep(2000);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}

// Ã³À½ Å¸ÀÌÆ² È­¸é Ãâ·Â
void RenderTitle(void){
    int count;
    RenderBackground();
    ClearAnimation();

    //·Î°í Ãâ·Â
    //À§¿¡¼­ ºÎÅÍ ÃµÃµÈ÷ Ãâ·ÂµÇ´Â È¿°ú¸¦ À§ÇØ Sleep() ÇÔ¼ö »ç¿ë
    SetAllColor(BLACK, WHITE);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 3); Sleep(40);
    WriteLineCenter("::'########::'####:'##::: ##::'#######:::", 4); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ####: ##: ##:::: ##::", 5); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ## ## ##: ##:::: ##::", 6); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ##. ####: ##:::: ##::", 7); Sleep(40);
    WriteLineCenter(":: ##:::: ##:: ##:: ##:. ###: ##:::: ##::", 8); Sleep(40);
    WriteLineCenter(":: ########::'####: ##::. ##:. #######:::", 9); Sleep(40);
    WriteLineCenter("::........:::....::..::::..:::.......::::", 10); Sleep(40);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 11); Sleep(40);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);

    WriteLineCenter("~ C¾ð¾î °úÁ¦·Î ¸¸µê ~", 13);

    while(1){
        //½ºÆäÀÌ½º¹Ù¸¦ ´©¸¦½Ã ¹Ýº¹¹®À» ºüÁ®³ª¿È
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            Sleep(200);
            break;
        } 

        //±ôºý°Å¸®´Â È¿°ú
        count++;
        if(count>50){
            SetColor(GREEN);
            WriteLineCenter(">> ½ºÆäÀÌ½º¹Ù¸¦ ´­·¯¼­ ½ÃÀÛ <<", 18);
            SetColor(DEFAULT_TEXT);
            count = 0;
        }

        count++;
        if(count>50){
            WriteLineCenter("                              ", 18);
            count = 0;
        }
        Sleep(17);
    }
}

//¸Þ´ºÈ­¸é Ãâ·Â
int RenderMenu(void){
    ClearBackground();

    //·Î°í Ãâ·Â
    SetAllColor(BLACK, WHITE);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 3);
    WriteLineCenter("::'########::'####:'##::: ##::'#######:::", 4);
    WriteLineCenter(":: ##:::: ##:: ##:: ####: ##: ##:::: ##::", 5);
    WriteLineCenter(":: ##:::: ##:: ##:: ## ## ##: ##:::: ##::", 6);
    WriteLineCenter(":: ##:::: ##:: ##:: ##. ####: ##:::: ##::", 7);
    WriteLineCenter(":: ##:::: ##:: ##:: ##:. ###: ##:::: ##::", 8);
    WriteLineCenter(":: ########::'####: ##::. ##:. #######:::", 9);
    WriteLineCenter("::........:::....::..::::..:::.......::::", 10);
    WriteLineCenter(":::::::::::::::::::::::::::::::::::::::::", 11);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);

    int count = 0;
    static int choose = 1;
    int xPos = GetCenter("½ÃÀÛ") - 2;

    //ÇÁ·¹ÀÓ Á¦ÇÑÀ» À§ÇÑ º¯¼ö
    int lastTick = 0;
    //¹Î°¨µµ ¼³Á¤À» À§ÇÑ º¯¼ö
    int lastInputTick = 0;
    bool processingInput = false;
    while(1){
        //ÇÁ·¹ÀÓ °ü¸® 30ÇÁ·¹ÀÓÀ¸·Î °íÁ¤
        int currentTick = GetTickCount();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //Input ÆÐ½º
        // À§ ¹æÇâÅ°°¡ ´­·ÈÀ» ¶§
        if((GetAsyncKeyState(KEY_UP) & 0x8000  ) && (choose > 1)){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                choose--;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // ¾Æ·¡ ¹æÇâÅ°°¡ ´­·¶À» ¶§
        else if((GetAsyncKeyState(KEY_DOWN) & 0x8000 ) && (choose < 3)){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                choose++;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // ½ºÆäÀÌ½º¹Ù°¡ ´­·ÈÀ» ¶§
        else if(GetAsyncKeyState(VK_SPACE) & 0x8000 ){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                switch (choose)
                {
                case 1:
                    SetColor(GREEN);
                    GotoXY(xPos, 18);
                    printf("°³¹ß Áß");
                    SetColor(DEFAULT_TEXT);
                    Sleep(500);
                    return 1;
                case 2:
                    SetColor(GREEN);
                    GotoXY(xPos, 19);
                    printf("µµ¿ò¸»");
                    Sleep(500);
                    SetColor(DEFAULT_TEXT);
                    return 2;
                case 3:
                    SetColor(GREEN);
                    GotoXY(xPos, 20);
                    printf("Á¾·á | Á¤¸»·Î Á¾·áÇÕ´Ï±î? (Y/N)");
                    while(1){
                        if(GetAsyncKeyState(KEY_Y) & 0x8000){
                            ClearLine(20);
                            GotoXY(xPos, 20);
                            printf("Á¾·áÁßÀÔ´Ï´Ù...");
                            SetColor(DEFAULT_TEXT);
                            return 3;
                        }
                        else if(GetAsyncKeyState(KEY_N) & 0x8000){
                            ClearLine(20);
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
 
        //Render ÆÐ½º 

        //¼±ÅÃ ¸Þ´º ¹øÈ£ Ãâ·Â
        WriteCenter("¼±ÅÃ : ", 13);
        printf("%d", choose);

        //¸Þ´º Ãâ·Â
        GotoXY(xPos, 18);
        printf("½ÃÀÛ");
        GotoXY(xPos, 19);
        printf("µµ¿ò¸»");
        GotoXY(xPos, 20);
        printf("Á¾·á");
        
        //¼±ÅÃµÇ¾îÀÖ´Â ¸Þ´º ¿·¿¡ ÃÊ·Ï»ö Ä¿¼­¸¦ Ç¥½ÃÇÔ
        if(choose == 1){
            SetColor(DARK_GREEN);
            GotoXY(xPos - 2, 18);
            printf(">");
            SetColor(DEFAULT_TEXT);
            GotoXY(xPos - 2, 19);
            printf(" ");
            GotoXY(xPos - 2, 20);
            printf(" ");
        }
        else if(choose == 2){
            SetColor(DARK_GREEN);
            GotoXY(xPos - 2, 19);
            printf(">");
            SetColor(DEFAULT_TEXT);
            GotoXY(xPos - 2, 18);
            printf(" ");
            GotoXY(xPos - 2, 20);
            printf(" ");
        }
        else if(choose == 3){
            SetColor(DARK_GREEN);
            GotoXY(xPos - 2, 20);
            printf(">");
            SetColor(DEFAULT_TEXT);
            GotoXY(xPos - 2, 18);
            printf(" ");
            GotoXY(xPos - 2, 19);
            printf(" ");
        }
    }
}

// °ÔÀÓÁ¤º¸ Ãâ·Â ÇÔ¼ö
int RenderHelp(void){
    ClearBackground();
    int xPos = 9;
    WriteLineCenter("µµ¿ò¸»", 3);
    GotoXY(xPos,6);
    printf("¾Æ·¡ ¹æÇâÅ°¸¦ ´­·¯¼­ ¼÷ÀÌ±â");
    GotoXY(xPos,7);
    printf("¾Æ·¡ ¹æÇâÅ°¸¦ ´­·¯¼­ ¼÷ÀÌ±â");
    GotoXY(xPos,8);
    printf("´Ù°¡¿À´Â Àå¾Ö¹°À» ÇÇÇÏ¼¼¿ä!");

    GotoXY(xPos,9);
    printf("C¾ð¾î °úÁ¦¸¦ À§ÇØ Á¦ÀÛµÈ °ÔÀÓÀÔ´Ï´Ù.");
    GotoXY(xPos,10);
    printf("CHROME DINO °ÔÀÓÀ» ±â¹ÝÀ¸·Î ÇÏ°íÀÖ½À´Ï´Ù.");
    xPos = GetCenter("¦¢                                                    ¦¢");
    GotoXY(xPos,24);
    puts("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
    WriteLineCenter("¦¢                                                    ¦¢", 25);
    GotoXY(xPos,26);
    puts("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
    WriteLineCenter("µ¹¾Æ°¥·Á¸é ½ºÆäÀÌ½º¹Ù¸¦ ´©¸£½Ê½Ã¿À.",25);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 1){
            ClearLine(25);
            GotoXY(xPos,24);
            SetColor(DEFAULT_TEXT);
            puts("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
            WriteLineCenter("¦¢                                                    ¦¢", 25);
            GotoXY(xPos,26);
            puts("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
            SetColor(GREEN);
            WriteLineCenter("¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.", 25); 
            SetColor(DEFAULT_TEXT);
            Sleep(1000);
            break;
        } 
        GotoXY(3, 2);
    }
    return 1;
}

// Á¾·á ¸Þ´º ÇÊ¿ä¾ø¾î¼­ ¹Ì±¸Çö
int ExitMenu(void){
    
}

//ÄÜ¼Ö Ä¿¼­¸¦ ÀÌµ¿½ÃÅ°´Â ÇÔ¼ö
void GotoXY(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//EUC-KR ÀÎÄÚµù¿¡¼­ Á¤È®ÇÑ Str ±æÀÌ¸¦ ±¸ÇÏ´Â ÇÔ¼ö
int euc_kr_strlen(const char *str) {
    int length = 0;
    while (*str) {
        if ((*str & 0x80) != 0) {
            if ((unsigned char)*str >= 0xA1 && (unsigned char)*str <= 0xFE) {
                str++; 
                length++;
            }
        }
        length++;
        str++;
    }
    return length;
}

//¹ÞÀº ¹®ÀÚ¿­À» È­¸é Áß¾Ó¿¡ Ãâ·ÂÇÏ´Â ÇÔ¼ö
int WriteLineCenter(const char *Str, int y){
    int screenWidth = 88;
    int len = euc_kr_strlen(Str);
    int xPos = (screenWidth - len) / 2 + 1;

    if(xPos <2){
        xPos = 2;
    }

    GotoXY(xPos, y);
    printf("%s\n", Str);
    return xPos;
}

//¹ÞÀº ¹®ÀÚ¿­À» È­¸é Áß¾Ó¿¡ Ãâ·ÂÇÏ´Â ÇÔ¼ö (¿£ÅÍ ¾øÀ½)
int WriteCenter(const char *Str, int y){
    int screenWidth = 88;
    int len = euc_kr_strlen(Str);
    int xPos = (screenWidth - len) / 2 + 1;

    if(xPos <2){
        xPos = 2;
    }

    GotoXY(xPos, y);
    printf("%s", Str);
    return xPos;
}

//¹ÞÀº ¹®ÀÚ¿­À» Áß¾ÓÀ¸·Î Á¤·ÄÇÏ±â À§ÇÑ Ä¿¼­ÀÇ XÁÂÇ¥¸¦ ±¸ÇÏ´Â ÇÔ¼ö
int GetCenter(const char *Str){
        int screenWidth = 88;
    int len = euc_kr_strlen(Str);
    int xPos = (screenWidth - len) / 2 + 1;

    if(xPos <2){
        xPos = 2;
    }
    return xPos;
}

//YÁÂÇ¥¸¦ ¹Þ¾Æ ÇØ´ç ÁÙÀ» ºñ¿öÁÖ´Â ÇÔ¼ö
void ClearLine(int y){
    GotoXY(2, y);
    printf("                                                                                     ");
}

//±ÛÀÚ »ö»óÀ» º¯°æÇÏ´Â ÇÔ¼ö ¹è°æÀº ÀÚµ¿À¸·Î ±âº» »ö»óÀ¸·Î ¼³Á¤µÊ
void SetColor(int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (DEFAULT_BACKGROUND<<4) + TextColor);
}

//±ÛÀÚ »ö»ó°ú ¹è°æ»öÀ» ¸ðµÎ ¼³Á¤ÇÏ´Â ÇÔ¼ö
void SetAllColor(int BackGroundColor, int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (BackGroundColor<<4) + TextColor);
}
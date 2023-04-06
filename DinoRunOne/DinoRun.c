#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

// 啪歜薑爾
#define GAME_VERSION "蛤喻啪歜 v0.1 | 202327005 梯翕⑷" 

// 酈
#define KEY_UP 0x26
#define KEY_DOWN 0x28
#define KEY_SPACE 0x20
#define KEY_Y 0x59
#define KEY_N 0x4E

#define INPUT_SENSITIVITY 100 // 殮溘 馬紫

//臢蝶お 塽 寡唳 儀鼻 雖薑擊 嬪и enum
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

/* 蝶觼萼 */
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
            printf("謙猿脾");
            exit(0);
        default:
            continue;
        }
        ClearBackground();
    } while (GameState != 0);
} 

//擄 蟾晦��(籀擠撲薑) 夔樂曖 觼晦蒂 x 91 y 35煎 堅薑ж堅 夔樂曖 檜葷擊 蛤喻啪歜 0.1煎 滲唳�� 晦獄 儀鼻擊 7(�羃�) 0(匐擎儀)戲煎 滲唳
void Init(void){
    system("mode con cols=91 lines=35 | title 蛤喻啪歜 0.1 | color 70");
}

//醴憮蒂 獗晦朝 л熱
void CursorHide(void){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//纔舒葬蒂 斜葬朝 л熱
void RenderBackground(void){
    GotoXY(0, 0);
    //puts朝 \n檜 晦獄戲煎 轎溘腎朝 printf
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    for(int i = 1; i < 30; i++){
        puts("弛                                                                                      弛");
    }
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
    GotoXY(0, 31);
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    for(int i = 0; i < 1; i++){
        puts("弛                                                                                      弛");
    }
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
    WriteLineCenter(GAME_VERSION, 32);
    RenderAuthor();
}

//�飛� 綠辦晦 л熱
void ClearBackground(void){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     ");
    }
}

//嬪縑憮 嬴楚煎 雖辦朝 擁棲詭檜暮 �膩�陛氈朝 �飛� 綠辦晦 л熱
void ClearAnimation(void){
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
    for(int i = 1; i < 30; i++){
        GotoXY(2,i);
        printf("                                                                                     "); Sleep(20);
    }
}

//啪歜 �蜓� 轎溘 л熱
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

// 籀擠 顫檜ぎ �飛� 轎溘
void RenderTitle(void){
    int count;
    RenderBackground();
    ClearAnimation();

    //煎堅 轎溘
    //嬪縑憮 睡攪 繭繭�� 轎溘腎朝 �膩�蒂 嬪п Sleep() л熱 餌辨
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

    WriteLineCenter("~ C樹橫 婁薯煎 虜虛 ~", 13);

    while(1){
        //蝶む檜蝶夥蒂 援蒂衛 奩犒僥擊 緒螳釭褥
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            Sleep(200);
            break;
        } 

        //梭緇剪葬朝 �膩�
        count++;
        if(count>50){
            SetColor(GREEN);
            WriteLineCenter(">> 蝶む檜蝶夥蒂 揚楝憮 衛濛 <<", 18);
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

//詭景�飛� 轎溘
int RenderMenu(void){
    ClearBackground();

    //煎堅 轎溘
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
    int xPos = GetCenter("衛濛") - 2;

    //Щ溯歜 薯и擊 嬪и 滲熱
    int lastTick = 0;
    //團馬紫 撲薑擊 嬪и 滲熱
    int lastInputTick = 0;
    bool processingInput = false;
    while(1){
        //Щ溯歜 婦葬 30Щ溯歜戲煎 堅薑
        int currentTick = GetTickCount();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //Input ぬ蝶
        // 嬪 寞щ酈陛 揚溜擊 陽
        if((GetAsyncKeyState(KEY_UP) & 0x8000  ) && (choose > 1)){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                choose--;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // 嬴楚 寞щ酈陛 揚毓擊 陽
        else if((GetAsyncKeyState(KEY_DOWN) & 0x8000 ) && (choose < 3)){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                choose++;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // 蝶む檜蝶夥陛 揚溜擊 陽
        else if(GetAsyncKeyState(VK_SPACE) & 0x8000 ){
            if(currentTick - lastInputTick > INPUT_SENSITIVITY){
                switch (choose)
                {
                case 1:
                    SetColor(GREEN);
                    GotoXY(xPos, 18);
                    printf("偃嫦 醞");
                    SetColor(DEFAULT_TEXT);
                    Sleep(500);
                    return 1;
                case 2:
                    SetColor(GREEN);
                    GotoXY(xPos, 19);
                    printf("紫遺蜓");
                    Sleep(500);
                    SetColor(DEFAULT_TEXT);
                    return 2;
                case 3:
                    SetColor(GREEN);
                    GotoXY(xPos, 20);
                    printf("謙猿 | 薑蜓煎 謙猿м棲梱? (Y/N)");
                    while(1){
                        if(GetAsyncKeyState(KEY_Y) & 0x8000){
                            ClearLine(20);
                            GotoXY(xPos, 20);
                            printf("謙猿醞殮棲棻...");
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
 
        //Render ぬ蝶 

        //摹鷗 詭景 廓�� 轎溘
        WriteCenter("摹鷗 : ", 13);
        printf("%d", choose);

        //詭景 轎溘
        GotoXY(xPos, 18);
        printf("衛濛");
        GotoXY(xPos, 19);
        printf("紫遺蜓");
        GotoXY(xPos, 20);
        printf("謙猿");
        
        //摹鷗腎橫氈朝 詭景 蕙縑 蟾煙儀 醴憮蒂 ル衛л
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

// 啪歜薑爾 轎溘 л熱
int RenderHelp(void){
    ClearBackground();
    int xPos = 9;
    WriteLineCenter("紫遺蜓", 3);
    GotoXY(xPos,6);
    printf("嬴楚 寞щ酈蒂 揚楝憮 熨檜晦");
    GotoXY(xPos,7);
    printf("嬴楚 寞щ酈蒂 揚楝憮 熨檜晦");
    GotoXY(xPos,8);
    printf("棻陛螃朝 濰擁僭擊 Яж撮蹂!");

    GotoXY(xPos,9);
    printf("C樹橫 婁薯蒂 嬪п 薯濛脹 啪歜殮棲棻.");
    GotoXY(xPos,10);
    printf("CHROME DINO 啪歜擊 晦奩戲煎 ж堅氈蝗棲棻.");
    xPos = GetCenter("弛                                                    弛");
    GotoXY(xPos,24);
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    WriteLineCenter("弛                                                    弛", 25);
    GotoXY(xPos,26);
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
    WriteLineCenter("給嬴陞溥賊 蝶む檜蝶夥蒂 援腦褊衛螃.",25);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 1){
            ClearLine(25);
            GotoXY(xPos,24);
            SetColor(DEFAULT_TEXT);
            puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
            WriteLineCenter("弛                                                    弛", 25);
            GotoXY(xPos,26);
            puts("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
            SetColor(GREEN);
            WriteLineCenter("詭景煎 給嬴骨棲棻.", 25); 
            SetColor(DEFAULT_TEXT);
            Sleep(1000);
            break;
        } 
        GotoXY(3, 2);
    }
    return 1;
}

// 謙猿 詭景 в蹂橈橫憮 嘐掘⑷
int ExitMenu(void){
    
}

//夔樂 醴憮蒂 檜翕衛酈朝 л熱
void GotoXY(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//EUC-KR 檣囀註縑憮 薑�旁� Str 望檜蒂 掘ж朝 л熱
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

//嫡擎 僥濠翮擊 �飛� 醞懈縑 轎溘ж朝 л熱
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

//嫡擎 僥濠翮擊 �飛� 醞懈縑 轎溘ж朝 л熱 (縛攪 橈擠)
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

//嫡擎 僥濠翮擊 醞懈戲煎 薑溺ж晦 嬪и 醴憮曖 X謝ル蒂 掘ж朝 л熱
int GetCenter(const char *Str){
        int screenWidth = 88;
    int len = euc_kr_strlen(Str);
    int xPos = (screenWidth - len) / 2 + 1;

    if(xPos <2){
        xPos = 2;
    }
    return xPos;
}

//Y謝ル蒂 嫡嬴 п渡 還擊 綠錶輿朝 л熱
void ClearLine(int y){
    GotoXY(2, y);
    printf("                                                                                     ");
}

//旋濠 儀鼻擊 滲唳ж朝 л熱 寡唳擎 濠翕戲煎 晦獄 儀鼻戲煎 撲薑脾
void SetColor(int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (DEFAULT_BACKGROUND<<4) + TextColor);
}

//旋濠 儀鼻婁 寡唳儀擊 賅舒 撲薑ж朝 л熱
void SetAllColor(int BackGroundColor, int TextColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (BackGroundColor<<4) + TextColor);
}
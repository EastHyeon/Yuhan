#include "main.h"

void RenderAuthor(){
    SetAllColor(DARK_GRAY, BLACK);
    
    for(int i = SCREEN_MIN_Y; i < SCREEN_MAX_Y; i++){
        GotoXY(SCREEN_MIN_X,i);
        printf("                                                                                     ");
        Sleep(20);
    }

    SetAllColor(DARK_GRAY, GREEN);
    WriteLineCenter(" __ __ _____ _____ _____ _____    _____ _____ _____ _____ ", 13);
    WriteLineCenter("|  |  |  |  |  |  |  _  |   | |  |   __|  _  |     |   __|", 14);
    WriteLineCenter("|_   _|  |  |     |     | | | |  |  |  |     | | | |   __|", 15);
    WriteLineCenter("  |_| |_____|__|__|__|__|_|___|  |_____|__|__|_|_|_|_____|", 16);
    WriteLineCenter("                                                          ", 17);
    SetAllColor(DARK_GRAY, BLACK);

    Sleep(1000);
    SetAllColor(DEFAULT_BACKGROUND, DEFAULT_TEXT);
}

// ó�� Ÿ��Ʋ ȭ�� ���
void RenderTitle(void){
    InitScreenFade();

    //�ΰ� ���
    //������ ���� õõ�� ��µǴ� ȿ���� ���� Sleep() �Լ� ���
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

    WriteLineCenter("~ C��� ������ ���� ~", 13);
    WriteLineCenter("-----------------------------------------------------------------------", 14);
    WriteLineCenter("----------------------------------------------------------------------", 15);

    int count;
    while(1){
        //�����̽��ٸ� ������ �ݺ����� ��������
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            Sleep(200);
            break;
        } 

        //�����Ÿ��� ȿ��
        count++;
        if(count>50){
            SetColor(GREEN);
            WriteLineCenter(">> �����̽��ٸ� ������ ���� <<", 18);
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

enum GameState RenderMenu(){
    InitScreen();

    //�ΰ� ���
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
    int xPos = GetCenter("����") - 2;

    //������ ������ ���� ����
    int lastTick = 0;
    //�ΰ��� ������ ���� ����
    int lastInputTick = 0;
    int sensitivity = INPUT_SENSITIVITY + 50;
    bool processingInput = false;
    while(1){
        //������ ���� 30���������� ����
        int currentTick = GetTickCount();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //Input �н�
        // �� ����Ű�� ������ ��
        if((GetAsyncKeyState(KEY_UP) & 0x8000  ) && (choose > 1)){
            if(currentTick - lastInputTick > sensitivity){
                choose--;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // �Ʒ� ����Ű�� ������ ��
        else if((GetAsyncKeyState(KEY_DOWN) & 0x8000 ) && (choose < 3)){
            if(currentTick - lastInputTick > sensitivity){
                choose++;
                processingInput = true;
                lastInputTick = currentTick;
            }
        }
        // �����̽��ٰ� ������ ��
        else if(GetAsyncKeyState(VK_SPACE) & 0x8000 ){
            if(currentTick - lastInputTick > sensitivity){
                switch (choose)
                {
                case 1:
                    SetColor(GREEN);
                    GotoXY(xPos, 18);
                    printf("���� ��");
                    SetColor(DEFAULT_TEXT);
                    Sleep(500);
                    return GAME;
                case 2:
                    SetColor(GREEN);
                    GotoXY(xPos, 19);
                    printf("����");
                    Sleep(500);
                    SetColor(DEFAULT_TEXT);
                    return HELP;
                case 3:
                    SetColor(GREEN);
                    GotoXY(xPos, 20);
                    printf("���� | ������ �����մϱ�? (Y/N)");
                    while(1){
                        if(GetAsyncKeyState(KEY_Y) & 0x8000){
                            ClearLine(20);
                            GotoXY(xPos, 20);
                            printf("�������Դϴ�...");
                            SetColor(DEFAULT_TEXT);
                            return EXIT;
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
 
        //Render �н� 

        //���� �޴� ��ȣ ���
        WriteCenter("���� : ", 13);
        printf("%d", choose);

        //�޴� ���
        GotoXY(xPos, 18);
        printf("����");
        GotoXY(xPos, 19);
        printf("����");
        GotoXY(xPos, 20);
        printf("����");
        
        //���õǾ��ִ� �޴� ���� �ʷϻ� Ŀ���� ǥ����
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

// �������� ��� �Լ�
enum GameState RenderHelp(void){
    InitScreen();
    int xPos = 9;
    WriteLineCenter("����", 3);
    GotoXY(xPos,6);
    printf("�Ʒ� ����Ű�� ������ ���̱�");
    GotoXY(xPos,7);
    printf("�Ʒ� ����Ű�� ������ ���̱�");
    GotoXY(xPos,8);
    printf("�ٰ����� ��ֹ��� ���ϼ���!");

    GotoXY(xPos,9);
    printf("C��� ������ ���� ���۵� �����Դϴ�.");
    GotoXY(xPos,10);
    printf("CHROME DINO ������ ������� �ϰ��ֽ��ϴ�.");
    xPos = GetCenter("��                                                    ��");
    GotoXY(xPos,24);
    puts("������������������������������������������������������������������������������������������������������������");
    WriteLineCenter("��                                                    ��", 25);
    GotoXY(xPos,26);
    puts("������������������������������������������������������������������������������������������������������������");
    WriteLineCenter("���ư����� �����̽��ٸ� �����ʽÿ�.",25);
    while(1){
        if(GetAsyncKeyState(VK_SPACE) & 1){
            ClearLine(25);
            GotoXY(xPos,24);
            SetColor(DEFAULT_TEXT);
            puts("������������������������������������������������������������������������������������������������������������");
            WriteLineCenter("��                                                    ��", 25);
            GotoXY(xPos,26);
            puts("������������������������������������������������������������������������������������������������������������");
            SetColor(GREEN);
            WriteLineCenter("�޴��� ���ư��ϴ�.", 25); 
            SetColor(DEFAULT_TEXT);
            Sleep(1000);
            break;
        } 
        GotoXY(3, 2);
    }
    return MENU;
}
#include <stdio.h>
#include <windows.h>

void draw_menu(){

}

void gotoxy(int x, int y){
    COORD pos = {x, y};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){
    const int WAIT_TICK = 1000/30;
    int lastTick = 0;

    while(1){
        int currentTick = (int)GetTickCount64();
        if(currentTick - lastTick < WAIT_TICK)
            continue;
        lastTick = currentTick;

        //입력
        //로직
        //렌더링

        gotoxy(0, 0);

        for (int i = 0; i < 25; i++){
            for (int j = 0; j < 25; j++){
                printf("ㅁ");
            }
            printf("\n");
        }

    }

    return 0;
}
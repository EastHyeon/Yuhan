#include <stdio.h>

int main(){
	int time = 0;	

	printf("빨리 끝내고 싶은 시간을 입력하세요 : ");

	scanf("%d", &time);

	printf("오늘 %d분 빨리 끝내주려 했는데 미안..", time);

	return 0;
}

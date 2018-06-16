//난이도 중 깃발 생성
#include "my.h"

void secret_mid()
{
	int i;

	for (i = 0; i < 10; i++)
	{
		xmid[i] = (rand() % 47 + 2);
		ymid[i] = (rand() % 21 + 2);

		gotoxy(xmid[i], ymid[i]);
		printf("*");
	}
	xmid[8] = 0;//널문자 대입
	ymid[8] = 0;
}
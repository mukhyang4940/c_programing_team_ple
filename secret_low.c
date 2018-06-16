//난이도 하 깃발 생성
#include "my.h"

void secret_low()
{
	int i;

	for (i = 0; i < 8; i++)
	{
		do {
			xlow[i] = (rand() % 47 + 2);
			ylow[i] = (rand() % 21 + 2);

			gotoxy(xlow[i], ylow[i]);
		} while (xlow[i] >= 17 && xlow[i] <= 33 && ylow[i] >= 8 && ylow[i] <= 15);
		printf("*");
	}
}
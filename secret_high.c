//���̵� �� ��� ����
#include "my.h"

/* void secret_high(int high[24][50])
{
	int i;

	for (i = 0; i < 15; i = i)
	{
		xhigh[i] = (rand() % 47 + 2);
		yhigh[i] = (rand() % 21 + 2);

		if (high[yhigh[i]][xhigh[i]] == 0) {
			gotoxy(xhigh[i], yhigh[i]);
			printf("*");
			i++;
		}
		else
			continue;
	}
} */
//���ο� �ּ��� �߰��ߴ�.
void secret_high(int high[24][50])
{
	int i;

	for (i = 0; i < 15; i = i)
	{
		xhigh[i] = (rand() % 47 + 2); // 2~48
		yhigh[i] = (rand() % 21 + 2); // 2~22

		if (high[yhigh[i]][xhigh[i] / 2] == 1) {
			continue;
		}
		else if (high[yhigh[i]][xhigh[i] / 2] == 0) {
			gotoxy(xhigh[i], yhigh[i]);
			printf("*");
			i++;
		}
	}
}
//���̵� �� Ŀ�� �̵� 
#include "my.h"

void move_high()
{
	char ch = 0;
	x = 2;
	y = 1;

	while (1)
	{
		gotoxy(x, y);//������
		printf("!");
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch)
		{
		case 72:
			y--;
			move_number--;
			if (receive[y + 1][x / 2] != receive[y][x / 2])
			{
				y++;
				move_number++;
			}
			break;
		case 80:
			y++;
			move_number--;
			if (receive[y - 1][x / 2] != receive[y][x / 2])
			{
				y--;
				move_number++;
			}
			break;
		case 75:
			x--;
			move_number--;
			if (receive[y][x / 2] != receive[y][(x + 1) / 2])
			{
				x++;
				move_number++;
			}
			break;
		case 77:
			x++;
			move_number--;
			if (receive[y][x / 2] != receive[y][(x - 1) / 2])
			{
				x--;
				move_number++;
			}
			break;
		case 27:
			system("cls");
			main();
			break;
		}
		printf("\b ");

		gotoxy(36, 25);
		printf("���� Ƚ�� : %d��\n", move_number);
		gotoxy(x, y);

		if (move_number != 0) //�̵�Ƚ���� 0�� �ƴҶ��� ��� ���α׷� ����
			hint_interrupt_low();
		else
			break;

	}

	if (move_number == 0)
	{
		system("cls");
		gotoxy(40, 12);
		printf("-------------game over-------------\n");
		printf("                                                   ���� ��ε���...");
		Sleep(4000);
		system("cls");
		main();
	}
}
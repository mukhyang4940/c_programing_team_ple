//난이도 중 커서 이동 
#include "my.h"

void move_mid()
{
	char ch = 0;
	while (1)
	{
		gotoxy(x, y); //시작점
		printf("!");
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch)
		{
		case 72:
			if (y == 1) {
				y++;
				move_number++;
			}
			y--;
			move_number--;
			break;
		case 80:
			if (y == 22) {
				y--;
				move_number++;
			}
			y++;
			move_number--;
			break;
		case 75:
			if (x == 2) {
				x++;
				move_number++;
			}
			x--;
			move_number--;
			break;
		case 77:
			if (x == 49) {
				x--;
				move_number++;
			}
			x++;
			move_number--;
			break;

		}
		printf("\b ");

		gotoxy(36, 25);
		printf("남은 횟수 : %d번\n", move_number);
		gotoxy(x, y);

		if (move_number != 0) //이동횟수가 0이 아닐때는 계속 프로그램 실행
			hint_interrupt_mid();
		else
			break;
	}

	if (ch == 27)
	{
		system("cls");
		main();
	}

	if (move_number == 0)
	{
		system("cls");
		gotoxy(40, 12);
		printf("-------------game over-------------\n");
		printf("                                                   게임 재로딩중...");
		Sleep(4000);
		system("cls");
		main();
	}
}
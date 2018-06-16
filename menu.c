//메뉴
#include "my.h"

int menu()
{
	int a;

	//gotoxy(5, 5);

	printf("\n\n\n    ┌----------------MENU----------------┐\n");
	printf("    │                                    │\n");
	printf("    │   1.상                             │\n");
	printf("    │   2.중                             │\n");
	printf("    │   3.하                             │\n");
	printf("    │   4.도움말                         │\n");
	printf("    │   5.종료                           │\n");
	printf("    │                                    │\n");
	printf("    └------------------------------------┘\n");

	printf("       원하시는 메뉴를 선택하세요 : ");
	scanf("%d", &a);

	switch (a) {
	case 1:
		system("cls");
		map_high();
		break;
	case 2:
		system("cls");
		map_mid();
		break;
	case 3:
		system("cls");
		map_low();
		break;
	case 4:
		system("cls");
		guide();
		break;

	case 5:
		system("cls");
		gotoxy(10, 12);
		printf("종료되었습니다.\n");
		gotoxy(10, 15);
		break;
	}
	return 0;
}
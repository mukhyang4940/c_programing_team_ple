//�޴�
#include "my.h"

int menu()
{
	int a;

	//gotoxy(5, 5);

	printf("\n\n\n    ��----------------MENU----------------��\n");
	printf("    ��                                    ��\n");
	printf("    ��   1.��                             ��\n");
	printf("    ��   2.��                             ��\n");
	printf("    ��   3.��                             ��\n");
	printf("    ��   4.����                         ��\n");
	printf("    ��   5.����                           ��\n");
	printf("    ��                                    ��\n");
	printf("    ��------------------------------------��\n");

	printf("       ���Ͻô� �޴��� �����ϼ��� : ");
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
		printf("����Ǿ����ϴ�.\n");
		gotoxy(10, 15);
		break;
	}
	return 0;
}
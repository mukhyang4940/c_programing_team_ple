//map_low�� ��Ʈ,���� �Լ�
#include "my.h"

void hint_interrupt_low()
{
	int a = 0, b = 29;
	X = 0, Y = 26;

	int flag = 0;//
	int i;//
	int j = 0;//
	int l = 0;//
	int k = 0;//
	int m[10];//

	gotoxy(a, b);
	printf("  %d %d ���� x %d y %d ����˷��ֱ� x %d y %d �̵�Ƚ������ x %d y %d ������� x %d y %d \n", x, y, xlow[0], ylow[0], xlow[1], ylow[1], xlow[2], ylow[2], xlow[3], ylow[3]);
	printf("�������� x %d y %d �����ʱ�ȭ x %d y %d �������ε��ư��� x %d y %d �ƹ��͵�X ������ ��� �ݻ���� x %d y %d ", xlow[4], ylow[4], xlow[5], ylow[5], xlow[6], ylow[6], xlow[7], ylow[7]);

	if (x == xlow[0] && y == ylow[0]) //0�� ��� : ����
	{
		gotoxy(X, Y - 1);
		printf("�� �����Դϴ�! ��");
		Sleep(3000);
		system("cls");
		point += 200;
		gotoxy(36, 24);
		printf("���� : %d ��", point);
		gotoxy(0, 0);
		move_number = 0;
		map_mid();
	}
	if ((x == xlow[1]) && y == ylow[1])  //1�� ��� : ���� �˷��ֱ�
	{
		if (xlow[1] > xlow[0]) {
			gotoxy(X, Y);
			printf("�����̽� ������ ��ġ�� �˷��ݴϴ�!\n");
			printf("�ƽ��׿�. �������� �� �� �̵��ϼ���.");
		}
		if (xlow[1] < xlow[0]) {
			gotoxy(X, Y);
			printf("�����̽� ������ ��ġ�� �˷��ݴϴ�!\n");
			printf("�ƽ��׿�. �������� �� �� �̵��ϼ���.");
		}
		gotoxy(x, y);
		printf("!");
		xlow[1] = 990, ylow[1] = 990;//�ٽ� ������� �ʰ� �ϱ� ���� �ٸ� ������ ��ǥ �Ű� ����
		Sleep(2000);
		gotoxy(X, Y);// ���� �ȳ��� �ȳ����� ����� ����
		printf("                                                      ");
		gotoxy(X, Y + 1);
		printf("                                                      ");
		gotoxy(x, y);
		printf("   ");


		move_low();
	}
	if ((x == xlow[2]) && y == ylow[2]) //2�� ��� : �̵� Ƚ�� ���� 
	{
		move_number += 10;
		//�� �̵�Ƚ�� �� �� ������ų��?

		xlow[2] = 990, ylow[2] = 990;

		gotoxy(X, Y);
		printf("Ÿ�� ������ �ߵ��߽��ϴ�!   Ÿ�� ������ �ð��� ���� ������ �����־� �̵�Ƚ���� �����մϴ�.");

		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                               ");
		gotoxy(x, y);
		printf("     ");//!ǥ�� �ߴ� ���� �ٽ� ���ֱ�
		move_low();
	}
	if ((x == xlow[3]) && y == ylow[3]) //3�� ��� : ���� ���
	{
		point += 50;
		xlow[3] = 990, ylow[3] = 990;

		gotoxy(36, 24);
		printf("���� : %d ��", point);

		gotoxy(X, Y);
		printf("����Ƽ ������ �ߵ��߽��ϴ�!   ����Ƽ ������ ������ ���ڸ� �����Ͽ� ������ �����մϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                   ");
		gotoxy(x, y);
		printf("    ");

		move_low();
	}
	if ((x == xlow[4]) && y == ylow[4]) //4�� ��� : ���� ����
	{
		point -= 50;
		xlow[4] = 990, ylow[4] = 990;

		gotoxy(36, 24);
		printf("���� : %d ��", point);

		gotoxy(X, Y);
		printf("�ҿ� ������ �׳� ����� �Ⱦ��մϴ�. ������ ���ҵǾ����ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");
		gotoxy(x, y);
		printf("        ");

		move_low();
	}
	if ((x == xlow[5]) && y == ylow[5]) //5�� ��� : ���� �ʱ�ȭ
	{
		point = 200;
		xlow[5] = 990, ylow[5] = 990;

		gotoxy(36, 24);
		printf("���� :   %d ��", point);

		gotoxy(X, Y);
		printf("�Ŀ� ������ ����� �Ⱦ��մϴ�. ������ �ʱ�ȭ �Ǿ����ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");
		gotoxy(x, y);
		printf("     ");

		move_low();
	}
	if ((x == xlow[6]) && y == ylow[6]) //6�� ��� : �������� ���ư���
	{
		xlow[6] = 990, ylow[6] = 990;

		gotoxy(X, Y);
		printf("�������� �ŷ��� �Ϸ� �Դ�!");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                      ");
		gotoxy(x, y);
		printf("     ");

		x = 2, y = 1;
		move_low();
	}
	if ((x == xlow[7]) && y == ylow[7])//7�� ��� : ���� �ƹ��͵� X  || ������ >> ��� �� �����
	{

		for (i = 1; i < 8; i++) //���� ����� �� � �ִ��� ã��
		{
			if (xlow[i] != 990) //y�� ���� ������ ���� �ʿ�X
			{
				m[l] = i; // ���� �ִ� ����� ��ȣ�� m�̶�� �迭�� ����
				flag++;
				l++;
			}
		}
		for (; l < 10; l++)
			m[l] = '\0';

		if ((flag + 1) != 2) //����� �ΰ� ���������� ����X
		{
			for (; k < ((flag + 1) / 2); k++)
			{
				j = m[rand() % 3];
				gotoxy(xlow[j], ylow[j]);
				printf("   ");//��ĭ ����Ʈ
				xlow[j] = 990;// ��ǥ ġ��������
				ylow[j] = 990;
			}
		}
		xlow[7] = 990, ylow[7] = 990;

		gotoxy(X, Y);
		printf(" Ÿ�뽺�� �հ����� ƨ�� ������ ������ ����� ���� ��������ϴ� !");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                     ");
		gotoxy(x, y);
		printf("      ");

		move_low();
	}
}
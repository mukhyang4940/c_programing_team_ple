//map_mid�� ��Ʈ,���� �Լ�
#include "my.h"

void hint_interrupt_mid()
{
	int a = 0, b = 28;//���߿� ���ﳻ��

	X = 0, Y = 26;

	//���߿� ���ﳻ��
	gotoxy(a, b);
	printf("  %d %d ���� x %d y %d ����˷��ֱ� x %d y %d �̵�Ƚ������ x %d y %d ������� x %d y %d \n", x, y, xmid[0], ymid[0], xmid[1], ymid[1], xmid[2], ymid[2], xmid[3], ymid[3]);
	printf("�������� x %d y %d �����ʱ�ȭ x %d y %d �������ε��ư��� x %d y %d\n ", xmid[4], ymid[4], xmid[5], ymid[5], xmid[6], ymid[6]);
	printf("�ƹ��͵�X x %d y %d �̵�Ƚ������  x %d y %d ��ǥ���ġ  x %d y %d", xmid[7], ymid[7], xmid[8], ymid[8], xmid[9], ymid[9]);

	if (x == xmid[0] && y == ymid[0]) //0�� ��� : ����
	{
		gotoxy(X, Y - 1);
		printf("�� �����Դϴ�! ��");
		Sleep(3000);
		system("cls");
		point += 200;
		gotoxy(36, 24);
		printf("���� : %d ��", point);
		gotoxy(0, 0);
		map_high();
	}

	if ((x == xmid[1]) && y == ymid[1])  //1�� ��� : ��,�� ���� �˷��ֱ�
	{
		if (xmid[1] > xmid[0]) {
			gotoxy(X, Y);
			printf("�����̽� ������ ��ġ�� �˷��ݴϴ�!\n");
			printf("�ƽ��׿�. �������� �� �� �̵��ϼ���.");
		}
		if (xmid[1] < xmid[0]) {
			gotoxy(X, Y);
			printf("�����̽� ������ ��ġ�� �˷��ݴϴ�!\n");
			printf("�ƽ��׿�. �������� �� �� �̵��ϼ���.");
		}

		gotoxy(x, y);
		printf("!");
		xmid[1] = 990, ymid[1] = 990;//�ٽ� ������� �ʰ� �ϱ� ���� �ٸ� ������ ��ǥ �Ű� ����
		Sleep(2000);
		gotoxy(X, Y);// ���� �ȳ��� �ȳ����� ����� ����
		printf("                                                      ");
		gotoxy(X, Y + 1);
		printf("                                                      ");
		x++;
		move_mid();
	}

	if (x == xmid[2] && y == ymid[2]) //2�� ��� : �̵� Ƚ�� ����
	{
		move_number += 30;

		xmid[2] = 990, ymid[2] = 990;

		gotoxy(X, Y);
		printf("Ÿ�� ������ �ߵ��߽��ϴ�! Ÿ�� ������ �ð��� ���� ������ �����־� �̵�Ƚ���� �����մϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                    ");

		move_mid();
	}

	if (x == xmid[3] && y == ymid[3]) //3�� ��� : ���� ���
	{
		point += 100;
		xmid[3] = 990, ymid[3] = 990;

		gotoxy(36, 24);
		printf("���� : %d ��", point);

		gotoxy(X, Y);
		printf("����Ƽ ������ �ߵ��߽��ϴ�!   ����Ƽ ������ ������ ���ڸ� �����Ͽ� ������ ������ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                   ");

		move_mid();
	}

	if (x == xmid[4] && y == ymid[4]) //4�� ��� : ���� ����
	{
		point -= 50;
		xmid[4] = 990, ymid[4] = 990;

		gotoxy(36, 24);
		printf("���� : %d ��", point);

		gotoxy(X, Y);
		printf("�ҿ� ������ �׳� ����� �Ⱦ��մϴ�. ������ ���ҵǾ����ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");

		move_mid();
	}

	if (x == xmid[5] && y == ymid[5]) //5�� ��� : ���� �ʱ�ȭ
	{
		point = 200;
		xmid[5] = 990, ymid[5] = 990;

		gotoxy(36, 24);
		printf("���� :   %d ��", point);

		gotoxy(X, Y);
		printf("�Ŀ� ������ ����� �Ⱦ��մϴ�. ������ �ʱ�ȭ �Ǿ����ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                 ");

		move_mid();
	}

	if (x == xmid[6] && y == ymid[6]) //6�� ��� : �������� ���ư���
	{
		xmid[6] = 990, ymid[6] = 990;

		x = 2, y = 1;

		gotoxy(X, Y);
		printf("�������� �ŷ��� �Ϸ� �Դ�!");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                      ");

		move_mid();
	}

	if (x == xmid[7] && y == ymid[7])//7�� ��� : �ƹ��͵� X
	{
		xmid[7] = 990, ymid[7] = 990;

		gotoxy(X, Y);
		printf("������� ����� ���� �־����ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                        ");

		move_mid();
	}

	if (x == xmid[8] && y == ymid[8])//8�� ��� : �̵�Ƚ������
	{
		move_number -= 50;
		xmid[8] = 990, ymid[8] = 990;

		gotoxy(X, Y);
		printf("����Ƽ ������ ����� �Ⱦ��մϴ�. �̵� Ƚ���� �����մϴ�. ");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");

		move_mid();
	}

	if (x == xmid[9] && y == ymid[9])//9�� ��� : ��ǥ���ġ 
	{
		xmid[9] = 990, ymid[9] = 990;

		gotoxy(X, Y);
		printf("���ε� ���� : ���ݱ��� �� ���� ��� �����̾����ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                        ");

		x = rand() % 48 + 1;
		y = rand() % 22 + 1;
		gotoxy(x, y);

		move_mid();
	}
}
//map_high�� ��Ʈ,���� �Լ�
#include "my.h"

void hint_interrupt_high()
{
	int a = 0, b = 28;//���߿� ���ﳻ��
	int flag = 0;
	int i;
	int j = 0;
	int l = 0;
	int k = 0;
	int m[18];

	X = 0, Y = 26;


	//���߿� ���ﳻ��
	gotoxy(a, b);
	printf("  %d %d ���� x %d y %d ����˷��ֱ� x %d y %d �̵�Ƚ������ x %d y %d ������� x %d y %d \n", x, y, xhigh[0], yhigh[0], xhigh[1], yhigh[1], xhigh[2], yhigh[2], xhigh[3], yhigh[3]);
	printf("��� �ݻ���� x %d y %d ��������1 x %d y %d ��������2 x %d y %d �����ʱ�ȭ x %d y %d \n ", xhigh[4], yhigh[4], xhigh[5], yhigh[5], xhigh[6], yhigh[6], xhigh[7], yhigh[7]);
	printf("��������1 x %d y %d ��������2 x %d y %d �ƹ��͵�X 1 x %d y %d �ƹ��͵�X 2 x %d y %d \n ", xhigh[8], yhigh[8], xhigh[9], yhigh[9], xhigh[10], yhigh[10], xhigh[11], yhigh[11]);
	printf("������ġ x %d y %d ��ǥ���ġ x %d y %d �̵�Ƚ������ 1 x %d y %d \n ", xhigh[12], yhigh[12], xhigh[13], yhigh[13], xhigh[14], yhigh[14]);


	if (x == xhigh[0] && y == yhigh[0]) //0�� ��� : ����
	{
		gotoxy(X, Y - 1);
		printf("�� �����Դϴ�! ��");
		Sleep(3000);
		system("cls");
		point += 200;
		gotoxy(36, 24);
		printf("���� : %d ��", point);
		gotoxy(0, 0);
		main();
	}

	if (x == xhigh[1] && y == yhigh[1])  //1�� ��� : ���� �˷��ֱ�
	{

		if (xhigh[1] > xhigh[0]) {
			gotoxy(X, Y);
			printf("�����̽� ������ ��ġ�� �˷��ݴϴ�!\n");
			printf("�ƽ��׿�. �������� �� �� �̵��ϼ���.");
		}
		if (xhigh[1] < xhigh[0]) {
			gotoxy(X, Y);
			printf("�����̽� ������ ��ġ�� �˷��ݴϴ�!\n");
			printf("�ƽ��׿�. �������� �� �� �̵��ϼ���.");
		}

		gotoxy(x, y);
		printf("!");
		xhigh[1] = 990, yhigh[1] = 990;//�ٽ� ������� �ʰ� �ϱ� ���� �ٸ� ������ ��ǥ �Ű� ����
		Sleep(2000);
		gotoxy(X, Y);// ���� �ȳ��� �ȳ����� ����� ����
		printf("                                                      ");
		gotoxy(X, Y + 1);
		printf("                                                      ");
		gotoxy(x, y);
		printf("   ");
		x++;

		move_high();
	}

	if (x == xhigh[2] && y == yhigh[2]) //2�� ��� : �̵� Ƚ�� ����    
	{
		move_number += 20;
		//�� �̵�Ƚ�� �� �� ������ų��?

		xhigh[2] = 990, yhigh[2] = 990;

		gotoxy(X, Y);
		printf("Ÿ�� ������ �ߵ��߽��ϴ�! Ÿ�� ������ �ð��� ���� ������ �����־� �̵�Ƚ���� �����մϴ�.");
		gotoxy(x, y);
		printf("!");
		//�� ���ӿ����� �ް� ĳ�����ε� ���α׷����� �� �������� �ȵǱ� ������ ȭ�鿡 ��� ��Ÿ�� �ִ� ����
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                               ");

		move_high();
	}

	if (x == xhigh[3] && y == yhigh[3]) //3�� ��� : ���� ���
	{
		point += 150;
		xhigh[3] = 990, yhigh[3] = 990;

		gotoxy(36, 24);
		printf("���� : %d ��", point);

		gotoxy(X, Y);
		printf("����Ƽ ������ �ߵ��߽��ϴ�!   ����Ƽ ������ ������ ���ڸ� �����մϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                   ");

		move_high();
	}

	if (x == xhigh[4] && y == yhigh[4]) //4�� ��� : ��� �� ����� �� �ؾ���
	{
		for (i = 1; i < 16; i++) //���� ����� �� � �ִ��� ã��
		{
			if (xhigh[i] != 990) //y�� ���� ������ ���� �ʿ�X
			{
				m[l] = i; // ���� �ִ� ����� ��ȣ�� m�̶�� �迭�� ����
				flag++;
				l++;
			}
		}

		for (; l < 18; l++)
			m[l] = '\0';

		if ((flag + 1) != 2) //����� �ΰ� ���������� ����X
		{
			for (; k < ((flag + 1) / 2); k++)
			{
				j = m[rand() % 3];
				gotoxy(xhigh[j], yhigh[j]);
				printf("   ");//��ĭ ����Ʈ
				xhigh[j] = 990;// ��ǥ ġ��������
				yhigh[j] = 990;
			}
		}
		xhigh[4] = 990, yhigh[4] = 990;

		gotoxy(X, Y);
		printf(" Ÿ�뽺�� �հ����� ƨ�� ������ ������ ����� ���� ��������ϴ� !");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
	}

	if (x == xhigh[5] && y == yhigh[5]) //5�� ��� : ���� ����
	{

		point -= 50;
		xhigh[6] = 990, yhigh[6] = 990;

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

		move_high();
	}

	if (x == xhigh[6] && y == yhigh[6]) //6�� ��� : ���� ����
	{
		point -= 50;
		xhigh[6] = 990, yhigh[6] = 990;

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

		move_high();
	}

	if (x == xhigh[7] && y == yhigh[7]) //7�� ��� : ���� �ʱ�ȭ
	{
		point = 0;
		xhigh[7] = 990, yhigh[7] = 990;

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

		move_high();
	}

	if (x == xhigh[8] && y == yhigh[8]) //8�� ��� : �������� ���ư���
	{
		xhigh[8] = 990, yhigh[8] = 990;

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
		move_high();
	}

	if (x == xhigh[9] && y == yhigh[9]) //9�� ��� : �������� ���ư���
	{
		xhigh[9] = 990, yhigh[9] = 990;

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
		move_high();
	}

	if (x == xhigh[10] && y == yhigh[10])//10�� ��� : �ƹ��͵� X
	{
		xhigh[10] = 990, yhigh[10] = 990;

		gotoxy(X, Y);
		printf("������� ����� ���� �־����ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                        ");
		gotoxy(x, y);
		printf("      ");

		move_high();
	}

	if (x == xhigh[11] && y == yhigh[11])//11�� ��� : �ƹ��͵� X
	{
		xhigh[11] = 990, yhigh[11] = 990;

		gotoxy(X, Y);
		printf("������� ����� ���� �־����ϴ�.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                        ");
		gotoxy(x, y);
		printf("      ");

		move_high();
	}

	if (x == xhigh[12] && y == yhigh[12])//12�� ��� : ��� ���ġ ���ؾ���
	{
		xhigh[12] = 990, yhigh[12] = 990;

		// ���� �־���ؿ�

		gotoxy(X, Y);
		printf(" �����̽� ������ ����� �Ⱦ��մϴ�. ����� ���ġ �˴ϴ�.");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");

		move_high();
	}

	if (x == xhigh[13] && y == yhigh[13])//13�� ��� : ��ǥ ���ġ ���ؾ���(��ǥ���ٸ��ϸ� ok)
	{
		xhigh[13] = 990, yhigh[13] = 990;

		x = rand() % 46; // �� �� ���̴� x,y��ǥ ����� ����

		gotoxy(X, Y);
		printf(" ���ε� ������ �ߵ��Ͽ����ϴ�! ���ݱ��� �� ���� ��� �����̾����ϴ�. ");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                         ");

		move_high();
	}

	if (x == xhigh[14] && y == yhigh[14])//14�� ��� : �̵� Ƚ�� ����
	{
		xlow[14] = 990, yhigh[14] = 990;

		gotoxy(X, Y);
		printf("����Ƽ ������ ����� �Ⱦ��մϴ�. �̵� Ƚ���� �����մϴ�. ");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");

		move_high();
	}
}
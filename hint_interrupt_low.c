//map_low의 힌트,방해 함수
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
	printf("  %d %d 정답 x %d y %d 방향알려주기 x %d y %d 이동횟수증가 x %d y %d 점수얻기 x %d y %d \n", x, y, xlow[0], ylow[0], xlow[1], ylow[1], xlow[2], ylow[2], xlow[3], ylow[3]);
	printf("점수감소 x %d y %d 점수초기화 x %d y %d 원점으로돌아가기 x %d y %d 아무것도X 지금은 깃발 반사라짐 x %d y %d ", xlow[4], ylow[4], xlow[5], ylow[5], xlow[6], ylow[6], xlow[7], ylow[7]);

	if (x == xlow[0] && y == ylow[0]) //0번 깃발 : 정답
	{
		gotoxy(X, Y - 1);
		printf("★ 정답입니다! ★");
		Sleep(3000);
		system("cls");
		point += 200;
		gotoxy(36, 24);
		printf("점수 : %d 점", point);
		gotoxy(0, 0);
		move_number = 0;
		map_mid();
	}
	if ((x == xlow[1]) && y == ylow[1])  //1번 깃발 : 방향 알려주기
	{
		if (xlow[1] > xlow[0]) {
			gotoxy(X, Y);
			printf("스페이스 스톤이 위치를 알려줍니다!\n");
			printf("아쉽네요. 서쪽으로 좀 더 이동하세요.");
		}
		if (xlow[1] < xlow[0]) {
			gotoxy(X, Y);
			printf("스페이스 스톤이 위치를 알려줍니다!\n");
			printf("아쉽네요. 동쪽으로 좀 더 이동하세요.");
		}
		gotoxy(x, y);
		printf("!");
		xlow[1] = 990, ylow[1] = 990;//다시 실행되지 않게 하기 위해 다른 곳으로 좌표 옮겨 놓음
		Sleep(2000);
		gotoxy(X, Y);// 위에 안내한 안내문을 지우기 위해
		printf("                                                      ");
		gotoxy(X, Y + 1);
		printf("                                                      ");
		gotoxy(x, y);
		printf("   ");


		move_low();
	}
	if ((x == xlow[2]) && y == ylow[2]) //2번 깃발 : 이동 횟수 증가 
	{
		move_number += 10;
		//★ 이동횟수 몇 번 증가시킬까?

		xlow[2] = 990, ylow[2] = 990;

		gotoxy(X, Y);
		printf("타임 스톤이 발동했습니다!   타임 스톤이 시간을 조금 전으로 돌려주어 이동횟수가 증가합니다.");

		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                               ");
		gotoxy(x, y);
		printf("     ");//!표시 했던 것을 다시 없애기
		move_low();
	}
	if ((x == xlow[3]) && y == ylow[3]) //3번 깃발 : 점수 얻기
	{
		point += 50;
		xlow[3] = 990, ylow[3] = 990;

		gotoxy(36, 24);
		printf("점수 : %d 점", point);

		gotoxy(X, Y);
		printf("리얼리티 스톤이 발동했습니다!   리얼리티 스톤이 점수의 숫자를 조작하여 점수가 증가합니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                   ");
		gotoxy(x, y);
		printf("    ");

		move_low();
	}
	if ((x == xlow[4]) && y == ylow[4]) //4번 깃발 : 점수 감소
	{
		point -= 50;
		xlow[4] = 990, ylow[4] = 990;

		gotoxy(36, 24);
		printf("점수 : %d 점", point);

		gotoxy(X, Y);
		printf("소울 스톤이 그냥 당신을 싫어합니다. 점수가 감소되었습니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");
		gotoxy(x, y);
		printf("        ");

		move_low();
	}
	if ((x == xlow[5]) && y == ylow[5]) //5번 깃발 : 점수 초기화
	{
		point = 200;
		xlow[5] = 990, ylow[5] = 990;

		gotoxy(36, 24);
		printf("점수 :   %d 점", point);

		gotoxy(X, Y);
		printf("파워 스톤이 당신을 싫어합니다. 점수가 초기화 되었습니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");
		gotoxy(x, y);
		printf("     ");

		move_low();
	}
	if ((x == xlow[6]) && y == ylow[6]) //6번 깃발 : 원점으로 돌아가기
	{
		xlow[6] = 990, ylow[6] = 990;

		gotoxy(X, Y);
		printf("도르마무 거래를 하러 왔다!");
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
	if ((x == xlow[7]) && y == ylow[7])//7번 깃발 : 원래 아무것도 X  || 지금은 >> 깃발 반 사라짐
	{

		for (i = 1; i < 8; i++) //현재 깃발이 총 몇개 있는지 찾기
		{
			if (xlow[i] != 990) //y에 관한 조건은 굳이 필요X
			{
				m[l] = i; // 남아 있는 깃발의 번호를 m이라는 배열에 저장
				flag++;
				l++;
			}
		}
		for (; l < 10; l++)
			m[l] = '\0';

		if ((flag + 1) != 2) //깃발이 두개 남았을때는 실행X
		{
			for (; k < ((flag + 1) / 2); k++)
			{
				j = m[rand() % 3];
				gotoxy(xlow[j], ylow[j]);
				printf("   ");//빈칸 프린트
				xlow[j] = 990;// 좌표 치워버리기
				ylow[j] = 990;
			}
		}
		xlow[7] = 990, ylow[7] = 990;

		gotoxy(X, Y);
		printf(" 타노스가 손가락을 튕겨 정답을 제외한 깃발의 반이 사라졌습니다 !");
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
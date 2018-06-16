//map_mid의 힌트,방해 함수
#include "my.h"

void hint_interrupt_mid()
{
	int a = 0, b = 28;//나중에 지울내용

	X = 0, Y = 26;

	//나중에 지울내용
	gotoxy(a, b);
	printf("  %d %d 정답 x %d y %d 방향알려주기 x %d y %d 이동횟수증가 x %d y %d 점수얻기 x %d y %d \n", x, y, xmid[0], ymid[0], xmid[1], ymid[1], xmid[2], ymid[2], xmid[3], ymid[3]);
	printf("점수감소 x %d y %d 점수초기화 x %d y %d 원점으로돌아가기 x %d y %d\n ", xmid[4], ymid[4], xmid[5], ymid[5], xmid[6], ymid[6]);
	printf("아무것도X x %d y %d 이동횟수감소  x %d y %d 좌표재배치  x %d y %d", xmid[7], ymid[7], xmid[8], ymid[8], xmid[9], ymid[9]);

	if (x == xmid[0] && y == ymid[0]) //0번 깃발 : 정답
	{
		gotoxy(X, Y - 1);
		printf("★ 정답입니다! ★");
		Sleep(3000);
		system("cls");
		point += 200;
		gotoxy(36, 24);
		printf("점수 : %d 점", point);
		gotoxy(0, 0);
		map_high();
	}

	if ((x == xmid[1]) && y == ymid[1])  //1번 깃발 : 동,서 방향 알려주기
	{
		if (xmid[1] > xmid[0]) {
			gotoxy(X, Y);
			printf("스페이스 스톤이 위치를 알려줍니다!\n");
			printf("아쉽네요. 서쪽으로 좀 더 이동하세요.");
		}
		if (xmid[1] < xmid[0]) {
			gotoxy(X, Y);
			printf("스페이스 스톤이 위치를 알려줍니다!\n");
			printf("아쉽네요. 동쪽으로 좀 더 이동하세요.");
		}

		gotoxy(x, y);
		printf("!");
		xmid[1] = 990, ymid[1] = 990;//다시 실행되지 않게 하기 위해 다른 곳으로 좌표 옮겨 놓음
		Sleep(2000);
		gotoxy(X, Y);// 위에 안내한 안내문을 지우기 위해
		printf("                                                      ");
		gotoxy(X, Y + 1);
		printf("                                                      ");
		x++;
		move_mid();
	}

	if (x == xmid[2] && y == ymid[2]) //2번 깃발 : 이동 횟수 증가
	{
		move_number += 30;

		xmid[2] = 990, ymid[2] = 990;

		gotoxy(X, Y);
		printf("타임 스톤이 발동했습니다! 타임 스톤이 시간을 조금 전으로 돌려주어 이동횟수가 증가합니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                    ");

		move_mid();
	}

	if (x == xmid[3] && y == ymid[3]) //3번 깃발 : 점수 얻기
	{
		point += 100;
		xmid[3] = 990, ymid[3] = 990;

		gotoxy(36, 24);
		printf("점수 : %d 점", point);

		gotoxy(X, Y);
		printf("리얼리티 스톤이 발동했습니다!   리얼리티 스톤이 점수의 숫자를 조작하여 점수를 얻었습니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                   ");

		move_mid();
	}

	if (x == xmid[4] && y == ymid[4]) //4번 깃발 : 점수 감소
	{
		point -= 50;
		xmid[4] = 990, ymid[4] = 990;

		gotoxy(36, 24);
		printf("점수 : %d 점", point);

		gotoxy(X, Y);
		printf("소울 스톤이 그냥 당신을 싫어합니다. 점수가 감소되었습니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");

		move_mid();
	}

	if (x == xmid[5] && y == ymid[5]) //5번 깃발 : 점수 초기화
	{
		point = 200;
		xmid[5] = 990, ymid[5] = 990;

		gotoxy(36, 24);
		printf("점수 :   %d 점", point);

		gotoxy(X, Y);
		printf("파워 스톤이 당신을 싫어합니다. 점수가 초기화 되었습니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                 ");

		move_mid();
	}

	if (x == xmid[6] && y == ymid[6]) //6번 깃발 : 원점으로 돌아가기
	{
		xmid[6] = 990, ymid[6] = 990;

		x = 2, y = 1;

		gotoxy(X, Y);
		printf("도르마무 거래를 하러 왔다!");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                      ");

		move_mid();
	}

	if (x == xmid[7] && y == ymid[7])//7번 깃발 : 아무것도 X
	{
		xmid[7] = 990, ymid[7] = 990;

		gotoxy(X, Y);
		printf("어벤져스가 당신을 구해 주었습니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                        ");

		move_mid();
	}

	if (x == xmid[8] && y == ymid[8])//8번 깃발 : 이동횟수감소
	{
		move_number -= 50;
		xmid[8] = 990, ymid[8] = 990;

		gotoxy(X, Y);
		printf("리얼리티 스톤이 당신을 싫어합니다. 이동 횟수가 감소합니다. ");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");

		move_mid();
	}

	if (x == xmid[9] && y == ymid[9])//9번 깃발 : 좌표재배치 
	{
		xmid[9] = 990, ymid[9] = 990;

		gotoxy(X, Y);
		printf("마인드 스톤 : 지금까지 본 것은 모두 착각이었습니다.");
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
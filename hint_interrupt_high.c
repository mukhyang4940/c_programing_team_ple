//map_high의 힌트,방해 함수
#include "my.h"

void hint_interrupt_high()
{
	int a = 0, b = 28;//나중에 지울내용
	int flag = 0;
	int i;
	int j = 0;
	int l = 0;
	int k = 0;
	int m[18];

	X = 0, Y = 26;


	//나중에 지울내용
	gotoxy(a, b);
	printf("  %d %d 정답 x %d y %d 방향알려주기 x %d y %d 이동횟수증가 x %d y %d 점수얻기 x %d y %d \n", x, y, xhigh[0], yhigh[0], xhigh[1], yhigh[1], xhigh[2], yhigh[2], xhigh[3], yhigh[3]);
	printf("깃발 반사라짐 x %d y %d 점수감소1 x %d y %d 점수감소2 x %d y %d 점수초기화 x %d y %d \n ", xhigh[4], yhigh[4], xhigh[5], yhigh[5], xhigh[6], yhigh[6], xhigh[7], yhigh[7]);
	printf("원점으로1 x %d y %d 원점으로2 x %d y %d 아무것도X 1 x %d y %d 아무것도X 2 x %d y %d \n ", xhigh[8], yhigh[8], xhigh[9], yhigh[9], xhigh[10], yhigh[10], xhigh[11], yhigh[11]);
	printf("깃발재배치 x %d y %d 좌표재배치 x %d y %d 이동횟수감소 1 x %d y %d \n ", xhigh[12], yhigh[12], xhigh[13], yhigh[13], xhigh[14], yhigh[14]);


	if (x == xhigh[0] && y == yhigh[0]) //0번 깃발 : 정답
	{
		gotoxy(X, Y - 1);
		printf("★ 정답입니다! ★");
		Sleep(3000);
		system("cls");
		point += 200;
		gotoxy(36, 24);
		printf("점수 : %d 점", point);
		gotoxy(0, 0);
		main();
	}

	if (x == xhigh[1] && y == yhigh[1])  //1번 깃발 : 방향 알려주기
	{

		if (xhigh[1] > xhigh[0]) {
			gotoxy(X, Y);
			printf("스페이스 스톤이 위치를 알려줍니다!\n");
			printf("아쉽네요. 서쪽으로 좀 더 이동하세요.");
		}
		if (xhigh[1] < xhigh[0]) {
			gotoxy(X, Y);
			printf("스페이스 스톤이 위치를 알려줍니다!\n");
			printf("아쉽네요. 동쪽으로 좀 더 이동하세요.");
		}

		gotoxy(x, y);
		printf("!");
		xhigh[1] = 990, yhigh[1] = 990;//다시 실행되지 않게 하기 위해 다른 곳으로 좌표 옮겨 놓음
		Sleep(2000);
		gotoxy(X, Y);// 위에 안내한 안내문을 지우기 위해
		printf("                                                      ");
		gotoxy(X, Y + 1);
		printf("                                                      ");
		gotoxy(x, y);
		printf("   ");
		x++;

		move_high();
	}

	if (x == xhigh[2] && y == yhigh[2]) //2번 깃발 : 이동 횟수 증가    
	{
		move_number += 20;
		//★ 이동횟수 몇 번 증가시킬까?

		xhigh[2] = 990, yhigh[2] = 990;

		gotoxy(X, Y);
		printf("타임 스톤이 발동했습니다! 타임 스톤이 시간을 조금 전으로 돌려주어 이동횟수가 증가합니다.");
		gotoxy(x, y);
		printf("!");
		//이 게임에서는 ◇가 캐릭터인데 프로그램실행 중 없어지면 안되기 때문에 화면에 계속 나타내 주는 역할
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                               ");

		move_high();
	}

	if (x == xhigh[3] && y == yhigh[3]) //3번 깃발 : 점수 얻기
	{
		point += 150;
		xhigh[3] = 990, yhigh[3] = 990;

		gotoxy(36, 24);
		printf("점수 : %d 점", point);

		gotoxy(X, Y);
		printf("리얼리티 스톤이 발동했습니다!   리얼리티 스톤이 점수의 숫자를 조작합니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                                   ");

		move_high();
	}

	if (x == xhigh[4] && y == yhigh[4]) //4번 깃발 : 깃발 반 사라짐 ▶ 해야함
	{
		for (i = 1; i < 16; i++) //현재 깃발이 총 몇개 있는지 찾기
		{
			if (xhigh[i] != 990) //y에 관한 조건은 굳이 필요X
			{
				m[l] = i; // 남아 있는 깃발의 번호를 m이라는 배열에 저장
				flag++;
				l++;
			}
		}

		for (; l < 18; l++)
			m[l] = '\0';

		if ((flag + 1) != 2) //깃발이 두개 남았을때는 실행X
		{
			for (; k < ((flag + 1) / 2); k++)
			{
				j = m[rand() % 3];
				gotoxy(xhigh[j], yhigh[j]);
				printf("   ");//빈칸 프린트
				xhigh[j] = 990;// 좌표 치워버리기
				yhigh[j] = 990;
			}
		}
		xhigh[4] = 990, yhigh[4] = 990;

		gotoxy(X, Y);
		printf(" 타노스가 손가락을 튕겨 정답을 제외한 깃발의 반이 사라졌습니다 !");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
	}

	if (x == xhigh[5] && y == yhigh[5]) //5번 깃발 : 점수 감소
	{

		point -= 50;
		xhigh[6] = 990, yhigh[6] = 990;

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

		move_high();
	}

	if (x == xhigh[6] && y == yhigh[6]) //6번 깃발 : 점수 감소
	{
		point -= 50;
		xhigh[6] = 990, yhigh[6] = 990;

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

		move_high();
	}

	if (x == xhigh[7] && y == yhigh[7]) //7번 깃발 : 점수 초기화
	{
		point = 0;
		xhigh[7] = 990, yhigh[7] = 990;

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

		move_high();
	}

	if (x == xhigh[8] && y == yhigh[8]) //8번 깃발 : 원점으로 돌아가기
	{
		xhigh[8] = 990, yhigh[8] = 990;

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
		move_high();
	}

	if (x == xhigh[9] && y == yhigh[9]) //9번 깃발 : 원점으로 돌아가기
	{
		xhigh[9] = 990, yhigh[9] = 990;

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
		move_high();
	}

	if (x == xhigh[10] && y == yhigh[10])//10번 깃발 : 아무것도 X
	{
		xhigh[10] = 990, yhigh[10] = 990;

		gotoxy(X, Y);
		printf("어벤져스가 당신을 구해 주었습니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                        ");
		gotoxy(x, y);
		printf("      ");

		move_high();
	}

	if (x == xhigh[11] && y == yhigh[11])//11번 깃발 : 아무것도 X
	{
		xhigh[11] = 990, yhigh[11] = 990;

		gotoxy(X, Y);
		printf("어벤져스가 당신을 구해 주었습니다.");
		gotoxy(x, y);
		printf("!");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                        ");
		gotoxy(x, y);
		printf("      ");

		move_high();
	}

	if (x == xhigh[12] && y == yhigh[12])//12번 깃발 : 깃발 재배치 ▶해야함
	{
		xhigh[12] = 990, yhigh[12] = 990;

		// 내용 넣어야해요

		gotoxy(X, Y);
		printf(" 스페이스 스톤이 당신을 싫어합니다. 깃발이 재배치 됩니다.");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");

		move_high();
	}

	if (x == xhigh[13] && y == yhigh[13])//13번 깃발 : 좌표 재배치 ▶해야함(좌표복붙만하면 ok)
	{
		xhigh[13] = 990, yhigh[13] = 990;

		x = rand() % 46; // ★ 상에 쓰이는 x,y좌표 만들기 복붙

		gotoxy(X, Y);
		printf(" 마인드 스톤이 발동하였습니다! 지금까지 본 것은 모두 착각이었습니다. ");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                                         ");

		move_high();
	}

	if (x == xhigh[14] && y == yhigh[14])//14번 깃발 : 이동 횟수 감소
	{
		xlow[14] = 990, yhigh[14] = 990;

		gotoxy(X, Y);
		printf("리얼리티 스톤이 당신을 싫어합니다. 이동 횟수가 감소합니다. ");
		Sleep(2000);
		gotoxy(X, Y);
		printf("                                                               ");

		move_high();
	}
}
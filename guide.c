//도움말
#include"my.h"

void guide()
{
	int a;


	printf("     ───────────────────────────────────────── 도움말 ────────────────────────────────────────────\n");

	printf("\n     ───  AVENGERS : 인피니티 워\n\n\n");

	printf("        처음점수 : 200점 / 한 게임 승리시 : +100점 / 한 게임 패배시 : -50점 / -200점 이하일시 game over\n\n\n");

	printf("     ───  ☆ 도움\n\n ");
	printf("        1. 방향 알려주기 (스페이스 스톤이 위치를 알려줍니다!)\n ");
	printf("        2. 이동 횟수 증가 (타임 스톤이 시간을 조금 전으로 돌려줍니다.)\n ");
	printf("        3. 깃발이 반 사라짐 (타노스가 손가락을 튕겼습니다.)\n ");
	printf("        4. 점수 얻기 (리얼리티 스톤이 점수의 숫자를 조작합니다.)\n");

	printf("\n     ───  ☆ 방해\n\n");
	printf("        1. 깃발 재배치 (스페이스 스톤이 당신을 싫어합니다.)\n");
	printf("        2. 아무 일도 일어나지 않음 (어벤져스가 당신을 구해 주었습니다.)\n");
	printf("        3. 점수 감소(-50점) (소울 스톤이 그냥 당신을 싫어합니다.)\n");
	printf("        4. 점수 초기화 (파워 스톤이 당신을 싫어합니다.)\n");
	printf("        5. 원점으로 돌아가기 (도르마무 거래를 하러 왔다.)\n");
	printf("        6. 이동 횟수 감소 (리얼리티 스톤이 당신을 싫어합니다.)\n");
	printf("        7. 좌표 재배치 (마인드 스톤 : 지금까지 본 것은 모두 착각이었습니다.)\n\n");

	printf("     ─────────────────────────────────────────────────────────────────────────────────────────────");

	printf("\n\n      도움말 보기를 끝내려면 아무키나 누르세요 ");

	a = _getch();
	system("cls");
	main();

}

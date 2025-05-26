#include <stdio.h>

void SetCover(int F[][10]) {
	int covered[11] = { 0 };								// 1 ~ 10 U집합의 각 값을 뜻함 이미 선택 되어 포함되었는지(cover) 확인 배열
	int used[10] = { 0 };								// 각 S집합 사용 여부

	int U_count = 10;									// U 집합에서 남아있는 값 개수
	int count = 0;										// S집합에서 U배열에 겹치는 값 개수

	int max_index = 0;
	int max_count = 0;

	int round = 1;										// 출력을 위한 회차 변수

	while (U_count > 0) {
		max_index = -1;
		max_count = -1;

		for (int i = 0; i < 10; i++) {
			if (used[i])	 continue;						// 이미 사용된 집합은 Continue 
			count = 0;

			for (int j = 0; j < 10; j++) {
				int val = F[i][j];						// val S집합 값이 cover됐는지 확인하기 위해 
				if (F[i][j] != -1 && !covered[val]) {	// 중요! S집합 값이 -1이 아닌지 그리고 U집합에서 cover 안됐는지 확인 
					count++;								// 겹치는 항의 개수
				}
			}
			if (count > max_count) {
				max_count = count;						// 항의 개수
				max_index = i;							// S집합 중 어떤 집합인지
			}
		}
		used[max_index] = 1;								// 집합 사용 여부 1

		printf("====================================\n");
		printf("<%d 회차>:  선택된 집합: S%d\n", round, max_index + 1);
		printf("Coverd: { ");


		// 선택된 집합의 값을 U집합에서 cover 처리
		for (int j = 0; j < 10; j++) {
			int val = F[max_index][j];					// 선택된 S집합의 값
			if (val != -1 && !covered[val]) {
				printf("%d ", val);
				covered[val] = 1;						// 선택된 값 cover처리
				U_count--;
			}
		}
		printf("}\n");


		printf("Remain: { ");
		for (int i = 1; i <= 10; i++) {
			if (!covered[i]) {
				printf("%d ", i);						// 아직 커버되지 않은 U 원소 출력
			}
		}
		printf("}\n");

		printf("====================================\n");
		round++;
	}
}

int main() {
	int U[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };		// U 전체 집합
	int F[][10] = {										// F 부분 집합			
		{1, 2, 3, -1, -1, -1, -1, 8, -1, -1},			// S1 집합
		{1, 2, 3, 4, -1, -1, -1, 8, -1, -1},				// S2 집합
		{1, 2, 3, 4, -1, -1, -1, -1, -1, -1},			// S3 집합
		{-1, 2, 3, 4, 5, -1, 7, 8, -1, -1},				// S4 집합
		{-1, -1, -1, 4, 5, 6, 7, -1, -1, -1},			// S5 집합
		{-1, -1, -1, -1, 5, 6, 7, -1, 9, 10},			// S6 집합
		{-1, -1, -1, 4, 5, 6, 7, -1, -1, -1},			// S7 집합
		{1, 2, -1, 4, -1, -1, -1, 8, -1, -1},			// S8 집합
		{-1, -1, -1, -1, -1, 6, -1, -1, 9, -1},			// S9 집합
		{-1, -1, -1, -1, -1, 6, -1, -1, -1, 10},			// S10 집합

	};

	SetCover(F);
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ABS(x) (x > 0 ? x : -(x))
int N, Row[1000] = { 0 }; //Row[3] = 2 이면 row = 2 col = 3을 의미한다.
//기본 전제: Row엔 하나씩.
void printResult() {
	static int cnt = 1; //몇 번
	printf("%3d Result : ", cnt++);
	for (int i = 1; i <= N; ++i) //index는 1부터
		printf("(%d,%d)", i, Row[i]);
	printf("\n");
}
bool promising(int q) {//새로운 퀸을 입력 받는다. 놓을 수 없다면 false 인지
	for (int i = 1; i < q; ++i) {
		if (Row[q] == Row[i] || ABS(Row[q] - Row[i]) == ABS(q - i))
			return false;
	}
	return true;
}
void queens(int q) {
	if (!promising(q)) return;
	//-----가지 치기 ----//
	if (q == N) {
		printResult();
		return;
	}//N개의 퀸을 다 놓으면
	for (int i = 1; i <= N; ++i) {
		Row[q + 1] = i;
		queens(q + 1);
	}

}
int main() {
	scanf("%d", &N);
	queens(0);
	return 0;
}
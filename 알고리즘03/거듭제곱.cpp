#include <stdio.h>
#include <iostream>

int iterativePower(int x, int n) {
	int ret = 1;
	for (int i = 0; i < n; ++i)
		ret = ret * x;
	return ret;
}
int recursivePower(int x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	return x * recursivePower(x, n - 1);
}
//둘다 시간 복잡도가 O(n), 재귀함수를 사용하는 이익이 없다
int dcPower(int x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n % 2 == 0) {//even
		int ret = dcPower(x, n / 2);
		return ret * ret;
	}
	else {
		int ret = dcPower(x, (n - 1) / 2);
		return ret * ret * x;
	}
}
//8승을 생각해보면 함수 호출이 1번 , 1번, 1번
//트리의 높이에 비례한다.
//분할 정복 기반의 알고리즘은 O(log_2 N)
int main() {

	return 0;
}
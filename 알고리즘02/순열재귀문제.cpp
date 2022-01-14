//2개를 골라서 만들 수 있는 최대수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 10

int N, NUMS[MAX_N];
int solve(int cnt, int used, int val)//pos는 현재 나의 위치, visted는 이미 간 곳. bit
{
	if (cnt == 2)
		return val; //base case

	int ret = 0; //초기화

	for (int i = 0; i < N; ++i) {
		if (used & (1 << i)) continue; // 이미 used된 숫자라면 ++i
		int tmp = solve(cnt + 1, used | (1 << i), val * 10 + NUMS[i]);
		if (ret < tmp) ret = tmp;
	}
		return ret;
}
int main() {
	int tcCnt;
	freopen("Permutation_input.txt", "r", stdin);

	cin >> tcCnt; //test case의 수를 입력
	for (int t = 1; t <= tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> NUMS[i];

		cout << "#" << t << ' ' << solve(0, 0, 0) << endl;
	}
	return 0;
}
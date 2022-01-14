//2개를 골라서 만들 수 있는 최댓값 - Bit 부분집합
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 10

int N, NUMS[MAX_N];

int countBits(int value) //value의 Bit를 세준다.
{
	int count = 0;
	while (value > 0) {
		if ((value & 1) == 1)
			count++;
		value = value >> 1;
	}
	return count;
}
int solve()
{
	int ret = 0;
	for (int i = 0; i < (1 << N); ++i) { 
		//총 N의 길이에 해당하는 Bit
		if (countBits(i) == 2) { 
		//원소의 개수가 2개인 부분집합이면 
			int sum = 0;
			for (int j = 0; j < N; ++j) {
				if (i & (1 << j))
					sum += NUMS[j];
			}
			if (sum > ret) ret = sum;
		}
	}
	return ret;
}
int main() {
	int tcCnt;
	freopen("Combination_input.txt", "r", stdin);

	cin >> tcCnt; //test case의 수를 입력
	for (int t = 1; t <= tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> NUMS[i];

		cout << "#" << t << ' ' << solve() << endl;
	}
	return 0;
}
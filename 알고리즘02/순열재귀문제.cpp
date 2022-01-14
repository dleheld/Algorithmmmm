//2���� ��� ���� �� �ִ� �ִ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 10

int N, NUMS[MAX_N];
int solve(int cnt, int used, int val)//pos�� ���� ���� ��ġ, visted�� �̹� �� ��. bit
{
	if (cnt == 2)
		return val; //base case

	int ret = 0; //�ʱ�ȭ

	for (int i = 0; i < N; ++i) {
		if (used & (1 << i)) continue; // �̹� used�� ���ڶ�� ++i
		int tmp = solve(cnt + 1, used | (1 << i), val * 10 + NUMS[i]);
		if (ret < tmp) ret = tmp;
	}
		return ret;
}
int main() {
	int tcCnt;
	freopen("Permutation_input.txt", "r", stdin);

	cin >> tcCnt; //test case�� ���� �Է�
	for (int t = 1; t <= tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> NUMS[i];

		cout << "#" << t << ' ' << solve(0, 0, 0) << endl;
	}
	return 0;
}
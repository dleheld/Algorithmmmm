//2���� ��� ���� �� �ִ� �ִ� - Bit �κ�����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 10

int N, NUMS[MAX_N];

int countBits(int value) //value�� Bit�� ���ش�.
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
		//�� N�� ���̿� �ش��ϴ� Bit
		if (countBits(i) == 2) { 
		//������ ������ 2���� �κ������̸� 
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

	cin >> tcCnt; //test case�� ���� �Է�
	for (int t = 1; t <= tcCnt; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> NUMS[i];

		cout << "#" << t << ' ' << solve() << endl;
	}
	return 0;
}
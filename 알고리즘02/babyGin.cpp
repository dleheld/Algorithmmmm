//Brute-force
//int sequentialSearch(int arr[], int n, int x)
//{
//	for (int i = 0; i < n; ++i) {
//		if (arr[i] == x)
//			return i;
//	}
//	return -1;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

#define N 6
int CARDS[6];
int arr_1[3];
int arr_2[3];
int run(int arr[])
{
	int n = 3;
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min])
				min = j;
		}
			int tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
			}
	if (((arr[0] + 1) == arr[1]) && ((arr[1] + 1) == arr[2]))
		return 1;
	else return 0;
}
int triplet(int arr[]) 
{
	int n = 3;
	for (int i = 1; i < n; ++i) {
		if (arr[i] != arr[0])
			return 0;
	}
	return 1;
}
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
int solve(int arr[])
{
	for (int i = 1; i < (1 << N); ++i) {
		if (countBits(i) == 3) { // i는 101100 따위의 bit 근데 이러면 시간 두 배 아닌가
			for (int j = 0; j < N; ++j) {
				int front = 0, back = 0;
				if (i & (1 << j)) {
					arr_1[front] = arr[j];
					front++;
				}
				else {
					arr_2[back] = arr[j];
					back++;
				}
			}
		}
		if ((run(arr_1) || triplet(arr_1)) && (run(arr_2) || triplet(arr_2)))
			return 1;
		else
			return 0;
	}
}
int main() {
	int tcCnt;
	freopen("babyGin_input.txt", "r", stdin);

	cin >> tcCnt; //test case의 수를 입력
	for (int t = 1; t <= tcCnt; ++t) {
		for (int i = 0; i < N; ++i)
			cin >> CARDS[i];
		cout << "#" << t << ' ' << solve(CARDS) << endl;
	}
	return 0;
}
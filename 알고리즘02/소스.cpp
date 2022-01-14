#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
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

void hey(int arr[]) {
	int N = 6;
	for (int i = 1; i < (1 << N); ++i) {
		if (countBits(i) == 3) { // i는 101100 따위의 bit 근데 이러면 시간 두 배 아닌가
			int front = 0, back = 0;
			for (int j = 0; j < N; ++j) {
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
		for (int i = 0; i < 3; ++i) {
			printf("%d", arr_1[i]);
		}
		printf(" ");
		for (int i = 0; i < 3; ++i) {
			printf("%d", arr_2[i]);
		}
		printf("\n");
	}
}
int main(){

	int arr[6]; 
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	arr[5] = 6;
	hey(arr);
	return 0;
}
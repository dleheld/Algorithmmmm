#include <stdio.h>
#include <iostream>
using namespace std;

int arr[10];

int binarySearch1(int arr[], int size, int key) {
	int low = 0, high = size - 1; //첫 항과 끝 항의 index
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) { //찾으려는 key는 오른쪽 배열에 숨어있다.
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return -1; //말도 안되면 false를 반환
}
int binarySearch2(int arr[], int low, int high, int key)
{
	if (low > high) return -1;
	int mid = (high + low) / 2;
	while (low <= high) {
		if (arr[mid] == key) return mid;
		else if (arr[mid] < key) return binarySearch2(arr, mid + 1, high, key);
		else return binarySearch2(arr, low, high - 1, key);	
	}
}
int main() {
	int size = sizeof(arr) / sizeof(int);
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
	printf("binarySearch 1의 결과 4의 위치는: %d\n", binarySearch1(arr, 10, 4));
	printf("binarySearch 2의 결과 4의 위치는 %d\n", binarySearch2(arr, 0, 9, 4));

	return 0;
}
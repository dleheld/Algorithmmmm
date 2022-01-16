//MergeSort
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void mergeSort(int arr[], int size) {
	if (size == 1) return; //base case , size가 1이므로 그냥 리턴
	int mid = size / 2; //배열을 두 개로 나누어서 재귀 호출
	mergeSort(arr, mid); //왼쪽
	mergeSort(arr + mid, size - mid); //오른쪽 array의 시작은 중간부터
	//size가 1이 되면 아래로 내려온다. 
	int* buf = new int[size]; //임시 버퍼, 병합할 버퍼
	int i = 0, j = mid, k = 0; //i가 왼쪽 배열 index, j가 오른쪽 배열 index
	while (i < mid && j < size) //두 개 다 차있지 않은 경우
		buf[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	//후위 연산이다. 안의 값을 사용하고 + 해준다.
	while (i < mid)
		buf[k++] = arr[i++];
	while (j < size)
		buf[k++] = arr[j++];

	for (i = 0; i < size; ++i)
		arr[i] = buf[i];

	delete buf;
}
int main() {

	return 0;
}
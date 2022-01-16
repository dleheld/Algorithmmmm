//MergeSort
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void mergeSort(int arr[], int size) {
	if (size == 1) return; //base case , size�� 1�̹Ƿ� �׳� ����
	int mid = size / 2; //�迭�� �� ���� ����� ��� ȣ��
	mergeSort(arr, mid); //����
	mergeSort(arr + mid, size - mid); //������ array�� ������ �߰�����
	//size�� 1�� �Ǹ� �Ʒ��� �����´�. 
	int* buf = new int[size]; //�ӽ� ����, ������ ����
	int i = 0, j = mid, k = 0; //i�� ���� �迭 index, j�� ������ �迭 index
	while (i < mid && j < size) //�� �� �� ������ ���� ���
		buf[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	//���� �����̴�. ���� ���� ����ϰ� + ���ش�.
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
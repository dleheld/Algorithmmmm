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
//�Ѵ� �ð� ���⵵�� O(n), ����Լ��� ����ϴ� ������ ����
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
//8���� �����غ��� �Լ� ȣ���� 1�� , 1��, 1��
//Ʈ���� ���̿� ����Ѵ�.
//���� ���� ����� �˰����� O(log_2 N)
int main() {

	return 0;
}
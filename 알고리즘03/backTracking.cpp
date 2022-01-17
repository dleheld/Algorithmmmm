#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ABS(x) (x > 0 ? x : -(x))
int N, Row[1000] = { 0 }; //Row[3] = 2 �̸� row = 2 col = 3�� �ǹ��Ѵ�.
//�⺻ ����: Row�� �ϳ���.
void printResult() {
	static int cnt = 1; //�� ��
	printf("%3d Result : ", cnt++);
	for (int i = 1; i <= N; ++i) //index�� 1����
		printf("(%d,%d)", i, Row[i]);
	printf("\n");
}
bool promising(int q) {//���ο� ���� �Է� �޴´�. ���� �� ���ٸ� false ����
	for (int i = 1; i < q; ++i) {
		if (Row[q] == Row[i] || ABS(Row[q] - Row[i]) == ABS(q - i))
			return false;
	}
	return true;
}
void queens(int q) {
	if (!promising(q)) return;
	//-----���� ġ�� ----//
	if (q == N) {
		printResult();
		return;
	}//N���� ���� �� ������
	for (int i = 1; i <= N; ++i) {
		Row[q + 1] = i;
		queens(q + 1);
	}

}
int main() {
	scanf("%d", &N);
	queens(0);
	return 0;
}
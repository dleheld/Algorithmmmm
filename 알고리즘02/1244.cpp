//�ִ� ��� ����, �˰��� : ���� Ž��
#include <stdio.h>
#include <iostream>

using namespace std;
int N = 8271619, maxcnt;

int pow(int a, int b) {
	int ans = 1;
	if (b == 0) return ans;
	else {
		for (int i = 0; i < b; ++i) {
			ans *= a;
		}
		return ans;
	}
}
int digitLength(int n) {
	int len = 0;
	while (n) {
		n /= 10;
		len++;
	}
	return len;
}
int solve(int money, int cnt) {
	if (cnt == maxcnt) return money;
	int ret = 0;
	int len_money = digitLength(N);
	for (int i = 0; i < len_money - 1; ++i) { //i��° �ڸ���
		for (int j = i + 1; j < len_money; ++j) { //j��° �ڸ��� �ٲ۴�.
			int new_money = (money / pow(10, j + 1)) * pow(10, j + 1) + ((money / pow(10, j)) % 10) * pow(10, i) + ((money / pow(10, i)) % 10) * pow(10, j) + ((money / pow(10, i + 1)) % pow(10, j - i - 1)) * pow(10, i + 1);
			int tmp = solve( new_money , cnt + 1 );
			if (ret < tmp) ret = tmp;
		}
	}
	return ret;
}
int main(){
	int tcCnt;
	freopen("1244_input.txt", "r", stdin);
	cin >> tcCnt;

	for (int t = 1; t <= tcCnt; ++t)
	{
		cin >> N >> maxcnt;
		cout << "#" << t << ' ' << solve(N, 0) << endl;
	}
	return 0;
}

//int Digits[6];
//int N;
//int count;
//
//void makingarr(int n) {
//	for (int i = digitLength(n) - 1; i >= 0; --i) {
//		Digits[i] = n % 10;
//		n /= 10;
//	}
//}
//int solve(int money, int val, int cnt)
//{	
//	if (cnt == count) {
//		return val;
//	}
//	N = digitLength(money);
//
//}
//int solve(int arr[], int pos, int used)//�� ��° ���ڸ� ������ ����
//{
//	if (used == ) { //�� ������ �� ��� base case
//		
//		return 0;
//	}
//	for (int i = 0; i < 6; ++i) {
//		pos �� ���Ӱ� ������ ���ڿ� ( 0���� �������� ) Cards ���� ����
//		if (used & (1 << i)) continue;
//
//		arr[pos] = Cards[i];
//		if (solve(arr, pos + 1, used | (1 << i)))
//			return 1;  //baby gin���θ� �Ǵ��ϸ� �ٷ� ��!!
//	}
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int Cards[6];

int solve(int arr[], int pos, int used)//�� ��° ���ڸ� ������ ����
{	
	if(pos == 6) { //�� ������ �� ��� base case
		int tri = 0, run = 0;
		for (int i = 0; i < 2; ++i) {//�տ� ���� �ڿ� ���� üũ. 
			if (arr[i * 3 + 1] == arr[i * 3] + 1 && arr[i * 3 + 2] == arr[i * 3 + 1] + 1) 
				++run;
			else if (arr[i * 3 + 1] == arr[i * 3] && arr[i * 3 + 2] == arr[i * 3 + 1])
				++tri;
		}
		if (run + tri == 2)
			return 1;
		return 0;
	}
	for (int i = 0; i < 6; ++i) {
		//pos �� ���Ӱ� ������ ���ڿ� ( 0���� �������� ) Cards ���� ����
		if (used & (1 << i)) continue;

		arr[pos] = Cards[i];
		if (solve(arr, pos + 1, used | (1 << i)))
			return 1;  //baby gin���θ� �Ǵ��ϸ� �ٷ� ��!!
	}
}
int main() {
	int tcCnt;
	freopen("babyGin_input.txt", "r", stdin);

	cin >> tcCnt; //test case�� ���� �Է�
	for (int t = 1; t <= tcCnt; ++t)
	{
		for (int i = 0; i < 6; ++i)
			cin >> Cards[i];

		int arr[6];
		cout << "#" << t << ' ' << solve(arr, 0, 0) << endl;
	}
	return 0;
}
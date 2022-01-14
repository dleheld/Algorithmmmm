#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int Cards[6];

int solve(int arr[], int pos, int used)//몇 번째 숫자를 선택할 건지
{	
	if(pos == 6) { //다 나열은 한 경우 base case
		int tri = 0, run = 0;
		for (int i = 0; i < 2; ++i) {//앞에 세개 뒤에 세개 체크. 
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
		//pos 는 새롭게 나열할 숫자열 ( 0부터 차곡차곡 ) Cards 값을 대입
		if (used & (1 << i)) continue;

		arr[pos] = Cards[i];
		if (solve(arr, pos + 1, used | (1 << i)))
			return 1;  //baby gin여부를 판단하면 바로 끝!!
	}
}
int main() {
	int tcCnt;
	freopen("babyGin_input.txt", "r", stdin);

	cin >> tcCnt; //test case의 수를 입력
	for (int t = 1; t <= tcCnt; ++t)
	{
		for (int i = 0; i < 6; ++i)
			cin >> Cards[i];

		int arr[6];
		cout << "#" << t << ' ' << solve(arr, 0, 0) << endl;
	}
	return 0;
}
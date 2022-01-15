#include <stdio.h>
#include <iostream>

int pow(int a, int b) {
	int ans = 1;
	for (int i = 0; i < b; ++i) {
		ans *= a;
	}
	return ans;
}
int main() {
	//0 이면 바꾸면 안 되겠다잉
	int i = 0; int j = 3;
	int money = 102003;
	int tmp = (money / pow(10, j)) * pow(10, j) + ((money / pow(10, j - 1)) % 10) * pow(10, i - 1) + ((money / pow(10, i - 1)) % 10) * pow(10, j - 1) + ((money / pow(10, i)) % pow(10, j - i - 1)) * pow(10, i);
	int tmp1= (money / pow(10, j + 1)) * pow(10, j + 1) + ((money / pow(10, j)) % 10) * pow(10, i) + ((money / pow(10, i)) % 10) * pow(10, j) + ((money / pow(10, i + 1)) % pow(10, j - i - 1)) * pow(10, i + 1);

	printf("%d", tmp1);
	return 0;
}
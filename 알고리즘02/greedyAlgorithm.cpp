#include <iostream>
#include <stdio.h>
using namespace std;

struct meeting_type {
	int start;
	int end;
};
int N;
meeting_type Meetings[10];

int solve()
{
	for (int i = 0; i < N - 1; ++i) { //sorting by ending time <- 중요 ...얼마나 일찍 끝나느냐가 중요함.
		for (int j = i + 1; j < N; ++j) {
			if (Meetings[i].end > Meetings[j].end) {
				meeting_type tmp = Meetings[i];
				Meetings[i] = Meetings[j];
				Meetings[j] = tmp;
			}
		}
	}
	int lastEnd = 0, cnt = 0;
	for (int i = 0; i < N; ++i) {

		if (Meetings[i].start < lastEnd) continue; // 마지막으로 끝나는 회의 직후에 열리는 회의.

		printf("(%d,%d)\n", Meetings[i].start, Meetings[i].end);
		lastEnd = Meetings[i].end;
		++cnt;
	}
	return cnt;
}
int main() {
	freopen("meeting_input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> Meetings[i].start >> Meetings[i].end;

	cout << solve() << endl;
	return 0;
}
#include <stdio.h>

const int MOD = 1000000000;
const int MAX_N = 100;
int N;

int d[MAX_N + 3][10][1 << 10];

int solve(int index, int current_num, int state)
{
	//base-case
	if (index == N) {
		return state == (1 << 10) - 1;
	}

	int &ret = d[index][current_num][state];
	if (ret != -1)
		return ret;

	ret = 0;
	if (current_num - 1 >= 0) {
		ret += solve(index + 1, current_num - 1, state | (1 << (current_num - 1)));
		ret %= MOD;
	}

	if (current_num + 1 <= 9) {
		ret += solve(index + 1, current_num + 1, state | (1 << (current_num + 1)));
		ret %= MOD;
	}

	return ret;
}

int TC, TC_;

int main(void)
{

	scanf("%d", &TC);
	TC_ = TC;

	while (TC_--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k < (1 << 10); k++) {
					d[i][j][k] = -1;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= 9; i++) {
			ans += solve(1, i, 1 << i);
			ans %= MOD;
		}
		printf("#%d %d\n", TC - TC_, ans);

	}
}
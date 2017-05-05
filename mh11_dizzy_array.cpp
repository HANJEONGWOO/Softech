#include <stdio.h>

int tc, N, C, dp[11][56];

void solve() {

	dp[1][0] = 1;

	for (int i = 2; i <= 10; i++) {
		for (int j = 0; j <= 55; j++) {
			for (int k = 0; k <= i - 1 && k <= j; k++) {
				dp[i][j] += dp[i - 1][j - k];
			}
		}
	}
}

int main(void)
{
	solve();

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &N, &C);
		printf("%d\n", dp[N][C]);
	}

	return 0;
}
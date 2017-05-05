#include <stdio.h>

long long table[75][75] = { 0 };

int TC;
long long result;
int N, K;

int main(void)
{

	for (int i = 1; i <= 73; i++) {
		table[i][1] = 1;
		table[i][i] = 1;
	}
	for (int i = 3; i <= 73; i++) {
		for (int j = 2; j < i; j++) {
			result = 0;
			for (int k = 1; k <= j; k++) { //i-j행, k열을 더한다.
				result += table[i - j][k];
				result %= 1000000007;
			}
			table[i][j] = result;
		}
	}

	scanf("%d", &TC);

	while (TC--)
	{
		scanf("%d %d", &N, &K);
		printf("%d\n", table[N][K]);
	}

	return 0;
}
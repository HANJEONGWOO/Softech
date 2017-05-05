#include <stdio.h>

//DP 식을 추론해낼 때 손으로 써보며 식을 유추해내자
// saero : N, garo : K
// 1 2 3 4
// 1 3 6 10
// 1 4 9 16
// 1 5 12 22

int TC;
long long int DP[220][220];
int N, K;
int interval, inc;

int main(void)
{
	scanf("%d", &TC); //input TC;

	interval = 0;
	inc = -1;
	for (int i = 1; i <= 200; i++)
	{
		interval = i;
		inc++;
		for (int j = 1; j <= 200; j++)
		{
			if (j == 1)
				DP[i][j] = 1; //base condition
			else
			{
				DP[i][j] = (DP[i][j - 1] + interval) % 1000000000;
				interval += inc;
			}
		}
	}

	while (TC--)
	{
		scanf("%d %d", &N, &K);//input N, K;

		printf("%lld\n", DP[N][K]);

	}

	return 0;
}
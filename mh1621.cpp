#include <stdio.h>
#define MIN(ADD, DELETE) (ADD > DELETE ? DELETE : ADD)

char string[2010];
int cost[2010][2010];
//cost[i][j]는 입력받은 문자열에 대해 i번째 단어에서 j번째 단어까지
//팰린드롬이 되게 하기 위한 비용이다.

int L, K;
int ADD, DELETE;
int min[26];
int len, i, j;

int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &L, &K);
		scanf("%s", &string);

		for (i = 0; i < K; i++)
		{
			scanf("%d %d", &ADD, &DELETE);
			min[i] = MIN(ADD, DELETE);
		}

		for (len = 0; len < L; len++)
		{
			for (i = 0; i + len < L; i++)
			{
				j = i + len;
				if (string[i] == string[j])
					cost[i][j] = cost[i + 1][j - 1];
				else
					cost[i][j] = MIN((cost[i + 1][j] + min[string[i] - 'a']), (cost[i][j - 1] + min[string[j] - 'a']));
			}
		}

		printf("%d\n", cost[0][L - 1]);
	}

	return 0;
}

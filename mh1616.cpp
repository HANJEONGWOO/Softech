//프로그래밍 경진대회
#include <stdio.h>

const long long MOD = 1000000007;

int N;

long long Fix[100003]; //난이도가 i로 고정된 문제의 수
long long Variable[100003]; //난이도가 i나 i+1로 가변적인 문제의 수
long long D[100003][2]; //DP Table (DP Table 설명은 위에 있습니다.)

						/*
						Fix[1], Fix[2], ..., Fix[N]을 난이도가 각각 1, 2, ..., N인 문제의 수.
						Variable[1], Variable[2], ..., Variable[N]을 난이도가 각각 1이거나 2, 2이거나 3, ..., N이거나 N+1인 문제의 수

						이 문제는 동적계획법으로 해결할 수 있다.
						난이도가 가장 낮은 것부터 문제를 배정해 나가는데, 난이도가 T인 문제를 선택할 때 난이도가 T이거나 (T+1)인 문제를
						선택할 것인지 아닌지의 여부에 따라 경우의 수를 계산하면 된다.
						이 경우를 D[T][B]로 표현하면, 다음과 같은 관계식으로 문제를 해결할 수 있다.

						< B=0 : 선택안함, B=1 : 선택 >
						D[0][0] = 1
						D[0][1] = 0
						*/

int main(void)
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &Fix[i]);
		}
		for (int i = 1; i < N; i++) {
			scanf("%lld", &Variable[i]);
		} //입력 part

		  //DP Table 만들기
		D[0][0] = 1;
		D[0][1] = 0;
		for (int i = 1; i <= N; i++) {
			D[i][0] = (D[i - 1][0] * (Fix[i] + Variable[i - 1]) + D[i - 1][1] * (Fix[i] + Variable[i - 1] - 1)) % MOD;
			//D[i][0](고정된 값)은 
			//D[i-1][0](이전 고정된 값) 곱하기 (Fix[i](고정된 난이도) + Variable[i-1](가변적 난이도) 를 더한것)을 더하고,
			//D[i-1][1](이전 가변적인 값) 곱하기 (Fix[i](고정된 난이도) + Variable[i-1]-1(가변적 난이도 -1 한 것)이고
			//* -1을 하는 이유? : 저번에 Variable[i-1]값을 썼으므로 -1을 해준다.
			D[i][1] = (D[i - 1][0] * Variable[i] + D[i - 1][1] * Variable[i]) % MOD;
			//D[i][1](가변적 값)은
			//D[i-1][0](이전 고정된 값) 곱하기 Variable[i](가변적인 값) 더하기 D[i-1][1](이전 가변적 값) 곱하기 Variable[i](가변적인 값) 이다.
		}

		printf("%lld\n", D[N][0]);
	}

	return 0;
}
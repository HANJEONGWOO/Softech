#include <stdio.h>

int TC;

int N;

int input;

int arr[110000];

int max;

int main(void)
{
	scanf("%d", &TC);

	while (TC--)
	{
		max = 0;
		for (int i = 0; i <= 100000; i++)
			arr[i] = 0;

		scanf("%d", &N); //input N;

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &input); //input arr[i];

			arr[input] = arr[input - 1] + 1; //이전 배열에서 1을 더해준다.

			if (arr[input] > max)
				max = arr[input];
		} //for
		  //가장 역순으로 되어있는 수를 전체에서 빼준다.
		printf("%d\n", N - max);

	} //while


	return 0;
}
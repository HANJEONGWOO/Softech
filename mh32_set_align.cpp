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

			arr[input] = arr[input - 1] + 1; //���� �迭���� 1�� �����ش�.

			if (arr[input] > max)
				max = arr[input];
		} //for
		  //���� �������� �Ǿ��ִ� ���� ��ü���� ���ش�.
		printf("%d\n", N - max);

	} //while


	return 0;
}
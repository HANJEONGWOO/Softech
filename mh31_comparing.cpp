#include <stdio.h>

void tracking(int idx, int l, int r, int rem);
int factorial(int n);
int pow2(int n);

int TC, TC_;
int N;
int arr[10];
int is_up[10];
int result;

int sum;

int main(void)
{
	int i, j;

	scanf("%d", &TC); //�׽�Ʈ ���̽�

	TC_ = TC;

	while (TC_--)
	{
		sum = 0;
		result = 0;

		scanf("%d", &N); //input

		for (i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];

			is_up[i] = 0;
		} //for i
		tracking(0, 0, 0, sum);

		printf("%d\n", result); //print result

	} //while

	return 0;
}

void tracking(int idx, int l, int r, int rem)
{
	if (l >= r + rem) //���� ���� ���� �� �÷��� l�� �� ũ�ٸ� ������� �� �����ش�.
	{
		result += pow2(N - idx) * factorial(N - idx);
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (is_up[i] == 0)
			{
				is_up[i] = 1; //�ø� ���� ǥ����
				tracking(idx + 1, l + arr[i], r, rem - arr[i]);
				if (l >= r + arr[i])
					tracking(idx + 1, l, r + arr[i], rem - arr[i]);
				is_up[i] = 0; //�����·� �ٲ���
			} //if
		} //for i    

	} //else

} //void

int factorial(int n)
{
	int result = 1;

	for (int i = n; i > 0; i--)
		result *= i;

	return result;
}

int pow2(int n)
{
	int i;
	int result = 1;

	for (i = 1; i <= n; i++)
		result *= 2;

	return result;
}
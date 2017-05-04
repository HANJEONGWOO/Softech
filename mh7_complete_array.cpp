#include <stdio.h>

long long int DT[110000];

int n;

int TC, TC_;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	DT[1] = 0;
	DT[2] = 1;
	for (int i = 3; i <= 100000; i++) {
		DT[i] = ((i - 1) * (DT[i - 1] + DT[i - 2])) % 1000000007;
	}

	scanf("%d", &TC);
	TC_ = TC;

	while (TC_--)
	{
		scanf("%d", &n);

		printf("%lld\n", DT[n]);
	}


	return 0;
}
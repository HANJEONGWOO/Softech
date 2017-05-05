#include <stdio.h>

int TC;

int W, L, H; //input W, L, H

int arr[41][41][41];

int maximum = 40 * 40 * 40;
int result;

int min(int a, int b);

int main(void)
{
	for (int i = 1; i <= 40; i++) {
		for (int j = 1; j <= 40; j++) {
			for (int k = 1; k <= 40; k++) {
				if (i == 1 || j == 1 || k == 1)
					arr[i][j][k] = i * j * k;
				else if (i == j && j == k)
					arr[i][j][k] = 1;
				else {
					result = maximum;
					for (int l = i - 1; l >= 1; l--) //3차원배열의 인자를 하나씩 줄이며 최소값을 찾는다.
						result = min(result, arr[i - l][j][k] + arr[l][j][k]);
					for (int l = j - 1; l >= 1; l--)
						result = min(result, arr[i][j - l][k] + arr[i][l][k]);
					for (int l = k - 1; l >= 1; l--)
						result = min(result, arr[i][j][k - l] + arr[i][j][l]);

					arr[i][j][k] = result;
				}
			} //for k
		} //for j
	} //for i


	scanf("%d", &TC); //

	while (TC--)
	{
		scanf("%d %d %d", &W, &L, &H); //input w, l, h;

		printf("%d\n", arr[W][L][H]);
	} //input tc

	return 0;
}

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

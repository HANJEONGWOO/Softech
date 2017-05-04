#include <stdio.h>

bool solve(int M, int X, int Y);

int pow(int a, int k);

int main(void)
{
	int TC, TC_;
	int M, X, Y;

	setbuf(stdout, NULL);
	scanf("%d", &TC);
	TC_ = TC;

	while (TC_--)
	{
		scanf("%d %d %d", &M, &X, &Y);

		if (solve(M, X, Y))
			printf("crystal\n");
		else
			printf("empty\n");
	}

	return 0;
}

bool solve(int M, int X, int Y)
{
	int mapSize = pow(5, M);

	if (((Y < mapSize * 1 / 5) && (X >= mapSize * 1 / 5) && (X < mapSize * 4 / 5)) ||
		((Y < mapSize * 2 / 5) && (X >= mapSize * 2 / 5) && (X < mapSize * 3 / 5))) {
		//printf("1\n");
		return true;
	}
	else if (((Y >= mapSize * 1 / 5) && (Y < mapSize * 2 / 5) && X >= (mapSize * 1 / 5) && (X < mapSize * 2 / 5)) ||
		((Y >= mapSize * 2 / 5) && (Y < mapSize * 3 / 5) && (X >= mapSize * 2 / 5) && (X < mapSize * 3 / 5)) ||
		((Y >= mapSize * 1 / 5) && (Y < mapSize * 2 / 5) && (X >= mapSize * 3 / 5) && (X < mapSize * 4 / 5))) {
		// printf("2\n");
		int smallMapSize = pow(5, M - 1);
		return solve(M - 1, X % smallMapSize, Y % smallMapSize);
	}
	else {
		//printf("3\n");
		return false;
	}
}

int pow(int a, int k)
{
	int result = 1;

	for (int i = 0; i < k; i++)
		result *= 5;

	return result;
}
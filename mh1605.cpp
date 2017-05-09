#include <stdio.h>

int X, Y, Z, A, B, C, N;
long long xcount[1100];
long long ycount[1100];
long long zcount[1100];
long long xycount[1100];
long long xyzcount[1100];

int myabs(int a) {
	return a < 0 ? -a : a;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d %d %d %d %d %d", &X, &Y, &Z, &A, &B, &C, &N);

		for (int i = 0; i < 1002; i++) {
			xyzcount[i] = xycount[i] = xcount[i] = ycount[i] = zcount[i] = 0;
		}
		/*
		(x,y,z)는 |x-A|+|y-B|+|z-C|를 N으로 나눈 나머지가 중요하므로,
		먼저|x-A|,|y-B|,|z-C| 를 따로 떼어내서
		각각의 차원에 대해 이를 N으로 나눈 나머지가 같은 것들이 몇 개씩 있는지 센다.
		*/
		for (int i = 0; i < X; i++) {
			xcount[myabs(i - A) % N] += 1;
		}
		for (int i = 0; i < Y; i++) {
			ycount[myabs(i - B) % N] += 1;
		}
		for (int i = 0; i < Z; i++) {
			zcount[myabs(i - C) % N] += 1;
		}

		/*
		그 다음은 |x-A|와 |y-B|를 센 정보를 바탕으로,
		|x-A|+|y-B|를 N으로 나눈 나머지가 같은 것들이 몇 개씩 있는지 센다.
		(다항식의 곱셈과 같다.)
		*/
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				xycount[(i + j) % N] += ycount[i] * xcount[j];
			}
		}

		/*
		마지막으로 |x-A|+|y-B|와 |z-C|를 센 정보를 바탕으로,
		|x-A|+|y-B|+|z-C|를 N으로 나눈 나머지가 같은 것들로 합쳐주면 된다.
		*/
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				xyzcount[(i + j) % N] += xycount[i] * zcount[j];
			}
		}

		for (int i = 0; i < N; i++) {
			printf("%lld ", xyzcount[i]);
		}
		printf("\n");
	}

	return 0;
}
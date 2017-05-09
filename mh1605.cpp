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
		(x,y,z)�� |x-A|+|y-B|+|z-C|�� N���� ���� �������� �߿��ϹǷ�,
		����|x-A|,|y-B|,|z-C| �� ���� �����
		������ ������ ���� �̸� N���� ���� �������� ���� �͵��� �� ���� �ִ��� ����.
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
		�� ������ |x-A|�� |y-B|�� �� ������ ��������,
		|x-A|+|y-B|�� N���� ���� �������� ���� �͵��� �� ���� �ִ��� ����.
		(���׽��� ������ ����.)
		*/
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				xycount[(i + j) % N] += ycount[i] * xcount[j];
			}
		}

		/*
		���������� |x-A|+|y-B|�� |z-C|�� �� ������ ��������,
		|x-A|+|y-B|+|z-C|�� N���� ���� �������� ���� �͵�� �����ָ� �ȴ�.
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
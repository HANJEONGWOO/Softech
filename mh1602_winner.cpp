#include <stdio.h>

long long pow(int i, int j) {
	long long  n = 1;
	int k;
	for (k = 1; k <= j; k++) {
		n *= i;
	} //for

	return n;
}

int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	//여러 개의 테스트 케이스를 처리하기 위한 부분입니다.

	for (test_case = 1; test_case <= T; test_case++)
	{
		int i, j = 0;
		long long N = 0;
		long long start = 1;

		scanf("%lld", &N);

		if (N == 1) {
			printf("Bob\n");
		}
		else {

			for (i = 1; i <= 40; i++) {
				//A가 4의 N승 만큼 반복되고
				start += pow(4, i);
				if (N <= start) {
					printf("Alice\n");
					break;
				}

				//B가 4의 N승 만큼 반복되고
				start += pow(4, i);
				if (N <= start) {
					printf("Bob\n");
					break;
				}
			}
		}
	}

	return 0;
}
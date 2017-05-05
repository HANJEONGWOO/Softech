#include <stdio.h>

int main(void)
{
	int TC, TC_;
	int N;
	int room[2200]; //room

	int next;

	scanf("%d", &TC);
	TC_ = TC;

	while (TC_--)
	{
		for (int i = 0; i < 2200; i++)
			room[i] = 0;

		scanf("%d", &N); //input N

		room[0] = N;

		for (int i = 0; i < N; i++) {
			next = 1;
			room[next - 1]--; //[0] minus
			room[next]++; //arr[1] plus

			while (1)
			{
				if (room[next] > next) {
					room[next + 1] += (next + 1); //plus next room
					room[next] -= (next + 1); //set zero
					next++; //next plus
				}
				else {
					break; //break, out;;;
				}
			}
		}

		for (int i = 1; i < 2200; i++) {
			printf("%d ", room[i]); //print room[i];
			N -= room[i];
			if (N <= 0)
				break;
		}
		printf("\n");
	}


	return 0;
}
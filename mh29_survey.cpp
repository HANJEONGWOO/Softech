#include <stdio.h>

unsigned long long int TC, TC_;

unsigned long long int N, M;

unsigned long long int each[1100000];

unsigned long long int first = 1;
unsigned long long int last = 1000000000; //십억
unsigned long long int mid;

unsigned long long int person; //사람의 수를 카운팅한다.

int main(void)
{
	int i, j;

	scanf("%lld", &TC);
	TC_ = TC;

	while (TC_--)
	{
		scanf("%lld %lld", &N, &M);

		for (i = 0; i < N; i++)
			scanf("%lld", &each[i]);

		first = 0;
		last = 0xffffffffffffffff;

		while (first <= last)
		{
			person = 0;//init person;
			mid = (first + last) / 2; //init mid;

			for (i = 0; i < N; i++)
			{
				//정해진 mid라는 시간안에 얼마나 많은 사람을 처리할 수 있는지 조사함.
				person += (int)(mid / each[i]);
				//plus each person
			}

			if (person >= M)
			{
				last = mid - 1;
				//더 줄여야함
			}
			else
			{
				first = mid + 1; //첫번째 것을 바꿈
			}
			//printf("! %d\n", person);
		} //만약 while을 통과한다면, 이것은 시간의 최솟값이다.
		  //printf("!! %d %d\n", first, last);

		printf("%lld\n", first); //값 출력

	} //while(TC_--)


	return 0;
}
#include <stdio.h>

unsigned long long int TC, TC_;

unsigned long long int N, M;

unsigned long long int each[1100000];

unsigned long long int first = 1;
unsigned long long int last = 1000000000; //�ʾ�
unsigned long long int mid;

unsigned long long int person; //����� ���� ī�����Ѵ�.

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
				//������ mid��� �ð��ȿ� �󸶳� ���� ����� ó���� �� �ִ��� ������.
				person += (int)(mid / each[i]);
				//plus each person
			}

			if (person >= M)
			{
				last = mid - 1;
				//�� �ٿ�����
			}
			else
			{
				first = mid + 1; //ù��° ���� �ٲ�
			}
			//printf("! %d\n", person);
		} //���� while�� ����Ѵٸ�, �̰��� �ð��� �ּڰ��̴�.
		  //printf("!! %d %d\n", first, last);

		printf("%lld\n", first); //�� ���

	} //while(TC_--)


	return 0;
}
#include <stdio.h>
#include <string.h>

char sign[32768];
int prime[3512];
int num;

void findprime()
{
int i , k;

	memset(sign , 0 , sizeof(sign));
	sign[1] = 1;
	for (i = 2; i < 182; i ++)
		if (sign[i] == 0)
		{
			k = i + i;
			while (k < 32768)
			{
				sign[k] = 1;
				k += i;
			}
		}
	num = 0;
	for (i = 2; i < 32768; i ++) if (sign[i] == 0) prime[num ++] = i;
}

int main()
{
int n , i , tot , temp;

	findprime();
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		tot = 0; temp = n / 2;
		for (i = 0; i < 3512; i ++)
			if (prime[i] > temp) break;
			else if (sign[n - prime[i]] == 0) tot ++;
		printf("%d\n" , tot);
	}
	return 0;
}
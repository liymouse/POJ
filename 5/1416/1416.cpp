#include <stdio.h>

int target , card , a[6];
int cut[6] , max , tot , L;
int num[6] , best[6] , bestn;

void find(int x)
{
int i , s , n;

	if (x == L - 1)
	{
		s = 0; n = 0;
		for (i = 0; i < L; i ++)
		{
			s = s * 10 + a[i];
			if (cut[i] == 1)
			{
				num[n ++] = s;
				s = 0;
			}
		}
		num[n ++] = s;
		s = 0;
		for (i = 0; i < n; i ++) s += num[i];
		if (s <= target)
		{
			if (s == max) tot ++;
			else if (s > max) 
			{
				max = s; tot = 1; bestn = n;
				for (i = 0; i < n; i ++) best[i] = num[i];
			}
		}
		return;
	}
	cut[x] = 0;
	find(x + 1);
	cut[x] = 1;
	find(x + 1);
}

int main()
{
int x , s , i , j;

	while (scanf("%d %d" , &target , &card) == 2)
	{
		if ((target == 0) && (card == 0)) break;
		s = 0; x = card; L = 0;
		while (x > 0) {a[L] = x % 10; s += a[L]; x /= 10; L ++;}
		for (i = 0; i < L/2; i ++) {x = a[i]; a[i] = a[L-1-i]; a[L-1-i] = x;}
		if (s > target) printf("error\n");
		else if (card == target) printf("%d %d\n" , target , card);
		else
		{
			max = -1; tot = 1;
			for (i = 0; i < 6; i ++) cut[i] = 0;
			find(0);
			if (tot > 1) printf("rejected\n");
			else
			{
				printf("%d" , max);
				for (i = 0; i < bestn; i ++) printf(" %d" , best[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
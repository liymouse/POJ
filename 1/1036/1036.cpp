#include <stdio.h>

int n , s , t;
int tt[110];
int pp[110];
int ss[110];
int f[110] = {0};

int abs(int x)
{
	if (x < 0) return -x;
	else return x;
}

void qu(int s , int t)
{
int i , j , x;

	i = s; j = t; x = tt[(i+j)/2];
	while (i < j)
	{
		while (tt[i] < x) i ++;
		while (tt[j] > x) j --;
		if (i <= j)
		{
			int y = tt[i];
			tt[i] = tt[j];
			tt[j] = y;
			y = pp[i];
			pp[i] = pp[j];
			pp[j] = y;
			y = ss[i];
			ss[i] = ss[j];
			ss[j] = y;
			i ++; j --;
		}
	}
	if (i < t) qu(i , t);
	if (s < j) qu(s , j);
}

int main()
{
	while (scanf("%d %d %d" , &n , &s , &t) == 3)
	{
		for (int i = 1; i <= n; i ++) scanf("%d" , &tt[i]);
		for (int i = 1; i <= n; i ++) scanf("%d" , &pp[i]);
		for (int i = 1; i <= n; i ++) scanf("%d" , &ss[i]);
		qu(1 , n);
		f[0] = 0;
		for (int i = 1; i <= n; i ++) f[i] = -1;
		for (int i = 1; i <= n; i ++)
		{
			int max = -1;
			for (int j = 0; j < i; j ++)
				if (f[j] >= 0 && abs(ss[i] - ss[j]) <= tt[i] - tt[j] && f[j] > max)
					max = f[j];
			if (max != -1) f[i] = max + pp[i];
		}
		int max = 0;
		for (int i = 0; i <= n; i ++)
			if (f[i] > max) max = f[i];
		printf("%d\n" , max);
	}
	return 0;
}
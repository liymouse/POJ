#include <stdio.h>
#include <string.h>

int n , a[100] , b[100] , L;

int searchone(int , int);

int find(int x)
{
int i , suc = 1;

	if (x > 0)
	{
		for (i = 0; i < n; i ++) if (b[i] == 0) break;
		b[i] = 1;
		suc = searchone(a[i] , x);
		if (suc == 0) b[i] = 0;
	}
	return suc;
}

int searchone(int nowL , int num)
{
int i , suc = 1;

	if (nowL == L) suc = find(num - 1);
	else
	{
		suc = 0;
		for (i = 0; i < n; i ++)
			if ((b[i] == 0) && (nowL + a[i] <= L))
			{
				b[i] = 1;
				suc = searchone(nowL + a[i] , num);
				if (!suc)
				{
					b[i] = 0;
					while ((i < n) && (a[i+1] == a[i])) i ++;
				}
			}
	}
	return suc;
}

int main()
{
int i , j , x , totL , done;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		totL = 0;
		for (i = 0; i < n; i ++) {scanf("%d" , &a[i]); totL += a[i];}
		memset(b , 0 , sizeof(b));
		for (i = 0; i < n; i ++) for (j = 1; j < n-i; j ++) if (a[j-1]<a[j]) {x = a[j-1]; a[j-1] = a[j]; a[j] = x;}
		x = 0; done = 0;
		for (L = a[0]; L <= totL / 2; L ++)
			if (totL % L == 0)
			{
				done = find(totL / L);
				if (done) break;
			}
		if (done) printf("%d\n" , L); else printf("%d\n" , totL);
	}
	return 0;
}
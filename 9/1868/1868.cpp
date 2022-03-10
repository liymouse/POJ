#include <stdio.h>
#include <string.h>

int main()
{
int n;
int a[10001];
struct
{
	int biao , num;
}big[10001] , small[10001];
int i , b , k;
char c;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) return 0;
		scanf("%c" , &c);
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		b = 0;
		for (k = 1; k < n - 1; k ++)
		{
		memset(big , 0 , sizeof(big));
		memset(small , 0 , sizeof(small));
		for (i = k; i < n; i ++) 
			if (a[i] - a[k-1] > 0) {big[a[i] - a[k-1]].biao = 1; big[a[i]-a[k-1]].num = i;}
			else {small[a[k-1] - a[i]].biao = 1; small[a[k-1]-a[i]].num = i;}
		for (i = 1; i < 5000; i ++) 
		{
			if ((big[i].biao == 1) && (big[i*2].biao == 1) && (big[i].num < big[i*2].num)) {b = 1; k = i; break;}
			if ((small[i].biao == 1) && (small[i * 2].biao == 1) && (small[i].num < small[i*2].num)) {b = 1; k= i;break;}
		}
		if (b == 1) break;
		}
		if (b == 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}


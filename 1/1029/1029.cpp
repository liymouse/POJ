#include <stdio.h>

int main()
{
struct {
	int n , bo;
	int L[500] , R[500];
}a[100];
int w[1001];
int n , k , i , j , tot , index , t , sumL , sumR , ok , p;
char s[5];

	scanf("%d %d" , &n , &k);
	for (i = 0; i < k; i ++)
	{
		scanf("%d" , &a[i].n);
		for (j = 0; j < a[i].n; j ++) scanf("%d" , &a[i].L[j]);
		for (j = 0; j < a[i].n; j ++) scanf("%d" , &a[i].R[j]);
		scanf("%s" , s);
		if (s[0] == '<') a[i].bo = -1; else if (s[0] == '>') a[i].bo = 1; else a[i].bo = 0;
	}
	for (i = 1; i <= n; i ++) w[i] = 1;
	tot = 0; index = 0;
	for (t = 1; t <= n; t ++)
	{
		for (p = 0; p <= 1; p ++)
		{
			if (p == 0) w[t] = 0; else w[t] = 2;
			ok = 1;
			for (i = 0; i < k; i ++)
			{
				sumL = 0; sumR = 0;
				for (j = 0; j < a[i].n; j ++) sumL += w[a[i].L[j]];
				for (j = 0; j < a[i].n; j ++) sumR += w[a[i].R[j]];
				if (a[i].bo != sumL - sumR) {ok = 0; break;}
			}
			if (ok) {if (index != t) tot ++; index = t;}
		}
		w[t] = 1;
	}
	if (tot == 1) printf("%d\n" , index); else printf("0\n");
	return 0;
}
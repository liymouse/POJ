#include <stdio.h>

int main()
{
int n , a[3000] , next[3000];
int i , t;
	
	scanf("%d" , &n);
	t = 0;
	for (i = 0; i < n; i ++) {scanf("%d" , &a[i]); if (a[i] == 0) next[t ++] = i;}
	for (i = 0; i < n; i ++) if (a[i] == 1) next[t ++] = i;
	t = 0;
	for (i = 0; i < n - 1; i ++)
	{
		printf("%d " , a[next[t]]);
		t = next[t];
	}
	printf("%d\n" , a[next[t]]);
	return 0;
}
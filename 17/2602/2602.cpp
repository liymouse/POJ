#include <stdio.h>

char a[1000001];

int main()
{
int n , i , x , y;

	scanf("%d" , &n);
	for (i = n - 1; i >= 0; i --)
	{
		scanf("%d %d" , &x , &y);
		a[i] = x + y;
	}
	for (i = 0; i < n; i ++) if (a[i] > 9) {a[i+1] += a[i]/10; a[i] %= 10;}
	for (i = n-1; i >= 0; i --) printf("%d" , a[i]);
	printf("\n");
	return 0;
}
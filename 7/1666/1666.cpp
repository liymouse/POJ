#include <stdio.h>
#define MAX 100

int main()
{
int n , i , bb , x , tot;
int a[MAX] , b[MAX];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++) scanf("%d" , a[i]);
		tot = 0;
		while (1)
		{
			x = a[0]; bb = 0;
			for (i = 1; i < n; i ++) if (x != a[i]) {bb = 1; break;}
			if (bb == 0) break;
			tot ++;
			for (i = 0; i < n; i ++) a[i] /= 2;
			b[0] = a[n-1];
			for (i = 1; i < n; i ++) b[i] = a[i-1];
			for (i = 0; i < n; i ++) {a[i] += b[i]; if (a[i] % 2 == 1) a[i] ++;}
		}
		printf("%d %d\n" , tot , a[0]);
	}
	return 0;
}
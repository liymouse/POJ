#include <stdio.h>
#include <string.h>

int main()
{
int b1[100] , b2[100] , a[10000];
int n , k;
int i , j , x;
int *p , *q , *s;

	scanf("%d %d" , &n , &k);
	for (i = 0; i < n; i ++) {scanf("%d" , &a[i]); a[i] %= k;}
	memset(b1 , 0 , sizeof(b1));
	if (a[0] < 0) a[0] = - a[0];
	b1[a[0]] = 1; b1[k - a[0]] = 1;
	p = b1; q = b2; 
	for (i = 1; i < n; i ++)
	{
		for (j = 0; j < k; j ++) q[j] = 0;
		for (j = 0; j < k; j ++)
			if (p[j])
			{
				x = (j + a[i]) % k;
				if (x >= 0) q[x] = 1; else q[k + x] = 1;
				x = (j - a[i]) % k;
				if (x >= 0) q[x] = 1; else q[k + x] = 1;
			}
		s = p; p = q; q = s;
	}
	if (p[0] == 1) printf("Divisible\n");
	else printf("Not divisible\n");
		
}
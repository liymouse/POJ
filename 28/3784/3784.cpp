#include <stdio.h>
#include <string.h>
int main() 
{
	int cas;
	scanf("%d" , &cas);
	int a[10010];
	while (cas --)
	{
		int t , n , s = 0;
		scanf("%d %d" , &t , &n);
		printf("%d %d\n" , t , n/2 + 1);
		memset(a , 0 , sizeof(a));
		for (int i = 0; i < n; i ++)
		{
			int x;
			scanf("%d" , &x);
			int k = -1;
			for (int j = 0; j < i; j ++)
				if (x < a[j]) {k = j; break;}
			if (k == -1) k = i;
			
			for (int j = i-1; j >= k; j --)
				a[j + 1] = a[j];
			a[k] = x;

			if (i % 2 == 0)
			{
				printf("%d" , a[i/2]);
				s ++;
				if (s == 10) {printf("\n"); s = 0;}
				else printf(" ");
			}
		}
		if (s > 0) printf("\n");
	}
	return 0;
}

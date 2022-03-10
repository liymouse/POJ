#include <stdio.h>

int main()
{
int n , a[1000] , b , i , j , x;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		while (scanf("%d" , &a[0]) == 1)
		{
			if (a[0] == 0) {printf("\n"); break;}
			for (i = 1; i < n; i ++) scanf("%d" , &a[i]);
			b = 0;
			for (i = 0; i < n; i ++)
				if (a[i] > 2)
				{
					x = a[i];
					for (j = i + 1; j < n; j ++)
						if (a[j] < a[i])
						{
							if (a[j] < x) x = a[j];
							else {b = 1; break;}
						}
					if (b == 1) break;
				}
			if (b == 0) printf("Yes\n"); else printf("No\n");
		}
	}
	return 0;
}
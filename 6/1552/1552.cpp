#include <stdio.h>

int main()
{
int a[15] , n , i , j , tot;

	while (scanf("%d" , &a[0]) == 1)
	{
		if (a[0] == -1) break; n = 1;
		while (scanf("%d" , &a[n]) == 1)
		{
			if (a[n] == 0) break;
			n ++;
		}
		tot = 0;
		for (i = 0; i < n; i ++)
			for (j = 0; j < i; j ++)
				if ((a[i] == 2 * a[j]) || (a[j] == 2 * a[i])) tot ++;
		printf("%d\n" , tot);
	}
	return 0;
}
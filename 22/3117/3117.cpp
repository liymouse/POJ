#include <stdio.h>

int main()
{
int t , n;
char s[13];
int tot , i , k;

	while (scanf("%d %d" , &t, &n) == 2)
	{
		if (t == 0) break;
		tot = 0;
		for (i = 0; i < t; i ++)
		{
			scanf("%s %d" , s , &k);
			tot += k;
		}
		printf("%d\n" , 3 * n - tot);
	}
	return 0;
}

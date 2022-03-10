#include <stdio.h>

int main()
{
char s1[8][26] , s2[7][26] , i , n , h;

	h = 0;
	while (scanf("%d" , &n) == 1)
	{
		h ++;
		if (n == 0) return 0;
		for (i = 0; i < n / 2; i ++)
		{
			scanf("%s" , s1[i]); scanf("%s" , s2[i]);
		}
		printf("SET %d\n" , h);
		if (n % 2 == 1) 
		{
			scanf("%s" , s1[n/2]);
			for (i = 0; i <= n/2; i ++) printf("%s\n" , s1[i]);
		}
		else for (i = 0; i < n/2; i ++) printf("%s\n" , s1[i]);
		for (i = n/2-1; i >= 0; i --) printf("%s\n" , s2[i]);
	}
	return 0;
}
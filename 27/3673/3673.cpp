#include <stdio.h>
#include <string.h>
int main()
{
int i , j , res;
char s1[11] , s2[15];

	while (scanf("%s %s" , s1, s2) == 2)
	{
		res = 0;
		for (i = 0; i < strlen(s1); i ++)
			for (j = 0; j < strlen(s2); j ++)
				res += (s1[i] - '0') * (s2[j] - '0');
		printf("%d\n" , res);
	}
	return 0;
}

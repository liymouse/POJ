#include <stdio.h>
#include <string.h>

int main()
{
int n , L , i;
char s[10] , s1[10];

	scanf("%d" , &n);
	while (n --)
	{
		scanf("%s" , s);
		if (s[1] == 0) printf("%s\n" , s);
		else
		{
			L = strlen(s);
			s1[0] = s[0];
			for (i = 1; i < L; i ++) s1[i] = '4';
			s[L] = 0;
			if (strcmp(s , s1) > 0)
			{
				printf("%d" , s[0] - '0' + 1);
				for (i = 1; i < L; i ++) printf("0");
				printf("\n");
			}
			else {printf("%d" , s[0] - '0'); for (i = 1; i < L; i ++) printf("0"); printf("\n");}
		}
	}
	return 0;
}

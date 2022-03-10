#include <stdio.h>
#include <string.h>

int main()
{
char str[300];
char s[50];
int sL , L;

	while (scanf("%s\n",str) == 1)
	{
		//gets(str);	
		sL = strlen(str);
		while (1)
		{
			gets(s);
			if (strcmp(s , "END") == 0) break;
			if (strcmp(s , "NULL") == 0)
			{
				printf("0 NULL\n");
				continue;
			}
			L = strlen(s);
			int ok;
			for (int i = 0; i <= sL - L; i ++)
			{
				ok = 1;
				for (int j = i; j < i + L; j ++)
					if (str[j] != s[j-i]) {ok = 0; break;}
				if (ok)
				{
					printf("%d " , i);
					if (i == 0)
						printf("NULL");
					else
						for (int j = 0; j < i; j ++)
							printf("%c" , str[j]);
					printf("\n");
					break;
				}
			}
			if (ok == 0)
			{
				printf("%d %s\n" , sL , str);
			}
		}
	}
	return 0;
}

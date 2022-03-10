#include <stdio.h>
#include <string.h>

int main()
{
char s[210];
int i;

	while (1)
	{
		gets(s);
		if (strcmp(s , "ENDOFINPUT") == 0) break;
		if ((strcmp(s , "START") != 0) && (strcmp(s , "END") != 0))
		{
			i = 0;
			while (s[i] > 0) 
			{
				if ((s[i] >= 'A') && (s[i] <= 'Z')) printf("%c" , (s[i]-'A' + 21) % 26 + 'A'); 
				else printf("%c" , s[i]);
				i ++;
			}
			printf("\n");
		}
	}
	return 0;
}
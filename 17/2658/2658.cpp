#include <stdio.h>
#include <string.h>

int yuan(char c)
{
	if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) return 1;
	else return 0;
}

int main()
{
int t , i , j , L , b;
char s[4][50] , st[51] , word[51];

	scanf("%d\n" , &t);
	while (t --)
	{
		for (i = 0; i < 4; i ++)
		{
			gets(st);
			L = strlen(st);
			for (j = L-1; j >= 0; j --)
				if (((st[j] >= 'A') && (st[j] <= 'Z')) || ((st[j] >= 'a') && (st[j] <= 'z')))
				{
					word[L-1-j] = st[j];
				}
				else break;
			word[L-1-j] = 0;
			strlwr(word);
			L = L - 1 - j; b = 0;
			for (j = 0; j < L; j ++) if (yuan(word[j])) {s[i][0] = word[j]; s[i][1] = 0; b = 1; break;}
			if (b == 0)
			{
				strrev(word);
				strcpy(s[i] , word);
			}
		}
		if ((strcmp(s[0] , s[1]) == 0) && (strcmp(s[1] , s[2]) == 0) && (strcmp(s[2] , s[3]) == 0))
			printf("perfect\n");
		else if ((strcmp(s[0] , s[1]) == 0) && (strcmp(s[2] , s[3]) == 0)) printf("even\n");
		else if ((strcmp(s[0] , s[2]) == 0) && (strcmp(s[1] , s[3]) == 0)) printf("cross\n");
		else if ((strcmp(s[0] , s[3]) == 0) && (strcmp(s[1] , s[2]) == 0)) printf("shell\n");
		else printf("free\n");
	}
	return 0;
}
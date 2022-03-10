#include <stdio.h>
#include <string.h>

char p[35] = {'A',0,0,0,'3',0,0,'H','I','L','0','J',
			  'M',0,'O',0,0,0,'2','T','U','V','W','X',
			  'Y','Z','1','S','E',0,'Z',0,0,'8',0};

int hui(char s[])
{
int i , L;
	
	L = strlen(s);
	for (i = 0; i < L / 2; i ++) if (s[i] != s[L-i-1]) return 0;
	return 1;
}

int mir(char s[])
{
int i , L , b;
char s1[21];

	L = strlen(s);
	for (i = 0; i < L; i ++)
	{
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			if (p[s[i]-'A'] != 0) s1[i] = p[s[i]-'A'];
			else return 0;
		}
		else
		{
			if (p[25 + s[i] - '0'] != 0) s1[i] = p[25 + s[i] - '0'];
			else return 0;
		}
	}
	for (i = 0; i < L; i ++)
		if (s1[i] != s[L-i-1]) return 0;
	return 1;
}

int main()
{

char s[21];
int a , b;

	while (scanf("%s" , s) == 1)
	{
		printf("%s -- " , s);
		a = hui(s); b = mir(s);
		if ((a == 0) && (b == 0)) printf("is not a palindrome.\n");
		else if ((a == 1) && (b == 0)) printf("is a regular palindrome.\n");
			else if ((a == 0) && (b == 1)) printf("is a mirrored string.\n");
				else printf("is a mirrored palindrome.\n");
		printf("\n");
	}
	return 0;
}
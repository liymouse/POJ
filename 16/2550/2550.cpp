#include <stdio.h>
#include <string.h>

char s[10010][1000];
char st[1000];
int tot , n;

void qu(int ss, int tt)
{
int i , j;
char x[1000] , y[1000];

	i = ss; j = tt; strcpy(x , s[(ss+tt)/2]);
	while (i <= j)
	{
		while (strcmp(x , s[i]) > 0) i ++;
		while (strcmp(x , s[j]) < 0) j --;
		if (i <= j)
		{
			strcpy(y , s[i]); strcpy(s[i] , s[j]); strcpy(s[j] , y);
			i ++; j --;
		}
	}
	if (i < tt) qu(i , tt);
	if (ss < j) qu(ss , j);
}

int main()
{
int i , L , t;
char word[1000];
int num;

	while (scanf("%d" , &n) == 1)
	{
		tot = 0;
		while(scanf("%s" , st) == 1)
		{
			if (strcmp(st , "EndOfText") == 0) break;
			i = 0; L = strlen(st);
			t = 0; strlwr(st);
			while (i < L)
			{
				while ((st[i] >= 'a') && (st[i] <= 'z')) word[t++] = st[i++];
				word[t] = 0;
				if (word[0] != 0) strcpy(s[tot++] , word);
				t = 0;
				while ((i < L) && ((st[i] < 'a') || (st[i] > 'z'))) i ++;
			}
		}
		qu(0 , tot-1);
		num = 1; t = 0;
		for (i = 1; i < tot; i ++)
		{
			if (strcmp(s[i-1] , s[i]) == 0) num ++;
			else
			{
				if (num == n) {t ++; printf("%s\n" , s[i-1]);}
				num = 1;
			}
		}
		if (num == n) {t ++; printf("%s\n" , s[tot-1]);}
		if (t == 0) printf("There is no such word.\n");
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n , ans;
char word[105][50];
bool be[105][26];
char st[90];
bool ok1 , ok2 , ok3;

void work()
{
int i , j , l, la , lb , lc , p;
char a[100] , b[100] , c[100];

	while (1)
	{
		scanf("%s" , st);
		if (st[0] == '*') break;
		l = strlen(st);
		i = -1; ans = 0;
		while (i < l-1)
		{
			la = 0; lb = 0; lc = 0;
			while (i < l-1)
			{
				i ++;
				if (st[i] == '|') break;
				if (st[i] == '+')
				{
					i++;
					b[lb ++] = st[i];
				}
				else if (st[i] == '-')
				{
					i++;
					c[lc ++] = st[i];
				}
				else a[la ++] = st[i];
			}
			for (j = 1; j <= n; j ++)
			{
				ok1 = false;
				if (la == 0) ok1 = true;
				for (p = 0; p < la; p ++) if (be[j][a[p] - 'a']) { ok1 = true; break; }
				ok2 = true;
				for (p = 0; p < lb; p ++) if (!be[j][b[p] - 'a']) { ok2 = false; break; } 
				ok3 = true;
				for (p = 0; p < lc; p ++) if (be[j][c[p] - 'a']) { ok3 = false; break; }
				if (ok1 && ok2 && ok3)
				{
					if (ans == 0){ans = j;}
					else
					{
						if (strcmp(word[j] , word[ans]) < 0)
						{
							ans = j;
						}
					}
				}
			}
		}
		if (ans)
		{
			printf("%s\n",word[ans]);
		}
		else
		{
			printf("NONE\n");
		}
	}
}

int main()
{
int i , l;

	while (1)
	{
		n = 0;
		memset(be , 0 , sizeof(be));
		while (1)
		{
			n ++;
			scanf("%s" , st);
			if (st[0] == '#') return 0;
			if (st[0] == '*') break;
			strcpy(word[n] , st);
			l = strlen(st);
			for (i = 0; i < l; i ++) be[n][st[i] - 'a'] = 1;
		}
		n --;
		work();
		printf("$\n");
	}
}

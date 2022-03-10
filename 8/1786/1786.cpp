#include <stdio.h>
#include <algorithm>
using namespace std;

struct kk{char hua , zhi;}x , a[4][13];

int change2(char c)
{
	if ((c >= '0') && (c <= '9')) return c - '0';
	if (c == 'T') return 10;
	if (c == 'J') return 11;
	if (c == 'Q') return 12;
	if (c == 'K') return 13;
	return 14;
}
int change1(char c)
{
	if (c == 'C') return 0;
	if (c == 'D') return 1;
	if (c == 'S') return 2;
	if (c == 'H') return 3;
}

bool cmp(kk x , kk y)
{
int a , b;

	a = change1(x.hua); b = change1(y.hua);
	if (a != b) return a < b;
	else
	{
		a = change2(x.zhi); b = change2(y.zhi);
		return a < b;
	}
}

int main()
{
char s[55];
int i , k , j;

	while (scanf("%s" , s) == 1)
	{
		if (s[0] == '#') break;
		else if (s[0] == 'N') k = 3;
			else if (s[0] == 'E') k = 0;
				else if (s[0] == 'S') k = 1;
					else if (s[0] == 'W') k = 2;
		scanf("%s" , s);
		j = 0;
		for (i = 0; i < 52; i += 2)
		{
			a[k][j/4].hua = s[i];
			a[k][j/4].zhi = s[i+1];
			j ++;
			k ++; if (k == 4) k = 0;
		}
		scanf("%s" , s);
		for (i = 0; i < 52; i += 2)
		{
			a[k][j/4].hua = s[i];
			a[k][j/4].zhi = s[i+1];
			j ++;
			k ++; if (k == 4) k = 0;
		}
		for (k = 0; k < 4; k ++)
		{
			sort(a[k] , a[k] + 13 , cmp);
			switch (k)
			{
				case 0 : printf("South player:\n"); break;
				case 1 : printf("West player:\n"); break;
				case 2 : printf("North player:\n"); break;
				case 3 : printf("East player:\n"); break;
			}
			for (i = 0; i < 13; i ++) printf("+---");
			printf("+\n");
			for (i = 0; i < 13; i ++) printf("|%c %c" , a[k][i].zhi , a[k][i].zhi);
			printf("|\n");
			for (i = 0; i < 13; i ++) printf("| %c " , a[k][i].hua);
			printf("|\n");
			for (i = 0; i < 13; i ++) printf("|%c %c" , a[k][i].zhi , a[k][i].zhi);
			printf("|\n");
			for (i = 0; i < 13; i ++) printf("+---");
			printf("+\n");
		}
		printf("\n");
	}
	return 0;
}
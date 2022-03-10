#include <stdio.h>
#include <string.h>

char fore[100000][11];
char eng[100000][11];

void qu(int s , int t)
{
int i , j;
char x[11] , y[11];

	i = s; j = t; strcpy(x , fore[(i+j)/2]);
	while (i <= j)
	{
		while (strcmp(fore[i] , x) < 0) i ++;
		while (strcmp(fore[j] , x) > 0) j --;
		if (i <= j)
		{
			strcpy(y , fore[i]); strcpy(fore[i] , fore[j]); strcpy(fore[j] , y);
			strcpy(y , eng[i]); strcpy(eng[i] , eng[j]); strcpy(eng[j] , y);
			i ++; j --;
		}
	}
	if (s < j) qu(s , j);
	if (i < t) qu(i , t);
}

int main()
{
char s[100];
int n , t , x , y , z , i;

	gets(s); n = 0; 
	while (s[0] >= 'a' && s[0] <= 'z')
	{
		i = 0; t = 0;
		while (s[i] != ' ') eng[n][t ++] = s[i ++];
		eng[n][t] = 0;
		while (s[i] == ' ') i ++;
		t = 0;
		while ((s[i] >= 'a') && (s[i] <= 'z')) fore[n][t ++] = s[i ++];
		fore[n][t] = 0;
		n ++;
		gets(s);
	}
	qu(0 , n - 1);
	while (scanf("%s" , s) == 1)
	{
		x = 0; y = n - 1;
		while (1)
		{
			z = (x + y) / 2;
			if (x > y) break;
			if (strcmp(s , fore[z]) < 0) y = z - 1;
			else if (strcmp(s , fore[z]) > 0) x = z + 1;
			else break;
		}
		if (strcmp(s , fore[z]) == 0) printf("%s\n" , eng[z]);
		else printf("eh\n");
	}
	return 0;
}

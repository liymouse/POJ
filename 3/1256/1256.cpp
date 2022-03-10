#include <stdio.h>
#include <string.h>

int b[20] , L;
char s[20] , st[20];

int cmp(char x , char y)
{
int p , q;

	p = 0; q = 0;
	if (('A' <= x) && (x <= 'Z')) {x = x - 'A' + 'a'; p = 1;}
	if (('A' <= y) && (y <= 'Z')) {y = y - 'A' + 'a'; q = 1;}
	if (x > y) return 1;
	else if (x < y) return -1;
	else
	{
		if (p == q) return 0;
		else if (p == 0) return 1;
			else return -1;
	}
}

int main()
{
int t , i , j , b[60] , k;
char c;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%s" , s);
		L = strlen(s);
		for (i = 0; i < L; i ++)
			for (j = 1; j < L - i; j ++)
				if (cmp(s[j-1] , s[j]) > 0) {c = s[j-1]; s[j-1] = s[j]; s[j] = c;}
		s[L] = 0; 
		printf("%s\n" , s);
		for (i = 0; i < L; i ++) b[i] = 0;
		while (1)
		{
			for (i = 0; i < 60; i ++) b[i] = 0;
			i = L-1;
			while ((i > 0) && (cmp(s[i-1] , s[i]) >= 0))
			{
				if (('a' <= s[i]) && (s[i] <= 'z')) b[2 * (s[i] - 'a') + 1] ++;
				else b[2 * (s[i] - 'A')] ++; 
				i --;
			}
			if ((i == 0) && (cmp(s[0] , s[1]) >= 0)) break;
			else
			{
				if (('a' <= s[i]) && (s[i] <= 'z')) b[2 * (s[i] - 'a') + 1] ++;
				else b[2 * (s[i] - 'A')] ++; 
				i --;
				if (('a' <= s[i]) && (s[i] <= 'z')) 
				{
					b[2 * (s[i] - 'a') + 1] ++; 
					k = 2 * (s[i]-'a') + 1;
				}
				else 
				{
					b[2 * (s[i] - 'A')] ++; 
					k = 2 * (s[i] - 'A');
				}
				for (j = k+1; j <= 51; j ++) if (b[j] > 0) break;
				if (j % 2 == 0) s[i] = j / 2 + 'A';
				else s[i] = j / 2 + 'a';
				b[j] --; i ++;
				for (j = 0; j <= 51; j ++)
					while (b[j] > 0) 
					{
						if (j % 2 == 0) s[i ++] = j / 2 + 'A';
						else s[i ++] = j / 2 + 'a';
						b[j] --;
					}
				s[L] = 0;
				printf("%s\n" , s);
			}
		}
	}
	return 0;
}
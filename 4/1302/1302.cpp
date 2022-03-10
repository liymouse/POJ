#include <stdio.h>
#include <string.h>

char res[30];
int n;

int sum(int x)
{
int s;
	if (x >= n) return 0;
	if (res[x] == '0') return 0;
	if (res[x] >= '1' && res[x] <= '9')
	{
		res[x] --;
		if (x + res[x] - '0' + 1 < n)
			return 1 + sum(x + res[x] - '0' + 1);
		else 
			return 1 + sum(x + 1);
	}
	s = sum(x+1);
	res[x] = (s % 10) + '0';
	return 1 + s;
}

int main()
{
char s[30];

	while (scanf("%s" , s) == 1)
	{
		if (s[0] == 'E') break;
		scanf("%d" , &n);
		scanf("%s" , res);
		scanf("%s" , s);
		sum(0);
		printf("%s\n" , res);
	}
	return 0;
}

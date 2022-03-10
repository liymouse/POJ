#include <stdio.h>
#include <string.h>

int main()
{
int k , L , i , x , y;
char s[71] , st[71];

	while (scanf("%d" , &k) == 1)
	{
		if (k == 0) break;
		scanf("%s" , s);
		L = strlen(s);
		for (i = 0; i < L; i ++)
		{
			if (s[i] == '_') x = 0;
			else if (s[i] == '.') x = 27;
			else x = s[i] - 'a' + 1;
			while (x + i >= 28) x -= 28;
			y = (k * i) % L;
			st[y] = x + i;
			if (st[y] == 0) st[y] = '_';
			else if (st[y] == 27) st[y] = '.';
				else st[y] = st[y] - 1 + 'a';
		}
		st[L] = 0;
		printf("%s\n" , st);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int min(int x , int y)
{
	return x < y ? x : y;
}

int main()
{
int f[30][12] , p[30][12];
int a[30];
int t , n , i , j , k , x , m , b;
char s[31];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		memset(a , 0 , sizeof(a));
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			j = 0;
			while (s[j] != 0)
			{
				if ((s[j] >= 'a') && (s[j] <= 'z')) a[s[j] - 'a'] ++;
				else if (s[j] == '+') a[26] ++;
					else if (s[j] == '*') a[27] ++;
						else if (s[j] == '/') a[28] ++;
							else a[29] ++;
				j ++;
			}
		}
		memset(f , 0 , sizeof(f));
		memset(p , 0 , sizeof(p));
		for (i = 0; i < 30; i ++)
		{
			f[i][0] = 0;
			for (j = 0; j <= i; j ++)
				f[i][0] += a[j] * (j + 1);
			for (j = 1; j <= min(11 , i); j ++)
			{
				f[i][j] = 999999999;
				for (k = j - 1; k < i; k ++)
				{
					m = f[k][j - 1];
					for (x = k + 1; x <= i; x ++)
						m += a[x] * (x - k);
					if (m < f[i][j])
					{
						f[i][j] = m;
						p[i][j] = k + 1;
					}
				}
			}
		}
		s[11] = 0;
		i = 11; j = 29;
		while (i > 0)
		{
			s[i-1] = p[j][i];
			if (s[i-1] < 26) s[i-1] += 'a';
			else if (s[i-1] == 26) s[i-1] = '+';
				else if (s[i-1] == 27) s[i-1] = '*';
					else if (s[i-1] == 28) s[i-1] = '/';
						else s[i-1] = '?';
			j = p[j][i] - 1;
			i --;
		}
		printf("%s\n" , s);
	}
	return 0;
}
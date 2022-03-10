#include <stdio.h>
#include <math.h>
#include <string.h>

int map[20][20] = {0};
int chk[20];
int match[20];
int m , n;
int id[20];

int Dfs(int p)
{
	int i , t;
	for (i = 0; i < m; i ++)
		if (map[i][p] && !chk[i])
		{
			chk[i] = 1;
			t = match[i];
			match[i] = p;
			if(t == n || Dfs(t))return 1;
			match[i] = t;
		}
		return 0;
}

int maxmatch()
{
	int i , res = 0;

	for (i = 0; i < m; i ++) match[i] = n;
	for (i = 0; i < n; i ++)
	{
		memset(chk , 0 , sizeof(chk));
		if (Dfs(i))
			res ++;
	}
	return res;
}

void find()
{
	for (int i = 0; i < m; i ++)
	{
		id[i] = -1;
		for (int j = 0; j < n; j ++)
			if (map[i][j] == 1)
			{
				map[i][j] = 0;
				int res = maxmatch();
				map[i][j] = 1;
				if (res != n)
				{
					id[i] = j;
					break;
				}
			}
	}
}

int main()
{
	char s2[30][30];
	char s1[100][30];
	char ss[30] , s[30];
	int c[100] = {0};

	scanf("%d" , &n);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			map[i][j] = 1;
	for (int i = 0; i < n; i ++)
		scanf("%s" , s2[i]);
	for (int i = 0; i < n; i ++)
		for (int j = 1; j < n - i; j ++)
			if (strcmp(s2[j-1] , s2[j]) > 0)
			{
				char temp[30];
				strcpy(temp , s2[j-1]);
				strcpy(s2[j-1] , s2[j]);
				strcpy(s2[j] , temp);
			}
	m = 0;
	while (scanf("%s" , s) == 1)
	{
		if (s[0] == 'Q') break;
		scanf("%s" , ss);
		if (s[0] == 'E')
		{
			int i;
			for (i = 0; i < m; i ++)
				if (strcmp(s1[i] , ss) == 0)
					break;
			if (i == m)
			{
				strcpy(s1[m] , ss);
				m ++;
			}
			c[i] = 1;
		}
		else if (s[0] == 'L')
		{
			for (int i = 0; i < m; i ++)
				if (strcmp(s1[i] , ss) == 0)
				{
					c[i] = 0;
					break;
				}
		}
		else
		{
			int k;
			for (int i = 0; i < n; i ++)
				if (strcmp(s2[i] , ss) == 0)
				{
					k = i;
					break;
				}
				for (int i = 0; i < m; i ++)
					if (c[i] == 0) map[i][k] = 0;
				for (int i = m; i < n; i ++)
					map[i][k] = 0;
		}
	}
	for (int i = 0; i < m; i ++)
		for (int j = 1; j < m - i; j ++)
			if (strcmp(s1[j-1] , s1[j]) < 0)
			{
				char temp[30];
				strcpy(temp , s1[j-1]);
				strcpy(s1[j-1] , s1[j]);
				strcpy(s1[j] , temp);
				for (int k = 0; k < n; k ++)
				{
					int t = map[j-1][k];
					map[j-1][k] = map[j][k];
					map[j][k] = t;
				}
			}
	find();

	for (int i = m-1; i >= 0; i --)
	{
		printf("%s:" , s1[i]);
		if (id[i] != -1)
			printf("%s\n" , s2[id[i]]);
		else
			printf("???\n");
	}

	return 0;
}

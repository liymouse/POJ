#include <stdio.h>
#include <map>
#include <string>
using namespace std;
#define MAX 105
#define MMM 405
int n , m , fn;
int used[MAX] , link[MAX] , a[MAX][MAX];
int b[MMM][MMM];
map<string , int> plug;

bool can(int t)
{
int i;
	
	for (i = 0; i < m; i ++)
		if (used[i] == 0 && a[t][i] == 1)
		{
			used[i] = 1;
			if (link[i] == -1 || can(link[i]))
			{
				link[i] = t; return true;
			}
		}
	return false;
}

int maxMatch()
{
int i , num = 0;

	for (i = 0; i < m; i ++) link[i] = -1;
	for (i = 0; i < n; i ++)
	{
		memset(used , 0 , sizeof(used));
		if (can(i)) num ++;
	}
	return num;
}

int getnum(char *s)
{
	if (plug.find(s) == plug.end())
	{
		plug.insert(pair<string , int>(s , fn));
		fn ++;
	}
	return plug[s];
}

int main()
{
char s[30] , st[30];
int dev[MAX] , pl[MAX];
int k , i , j , t , res;

	while (scanf("%d" , &n) == 1)
	{
		plug.clear();
		memset(dev , 0 , sizeof(dev));
		memset(pl , 0 , sizeof(pl));
		memset(b , 0 , sizeof(b));
		fn = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			pl[i] = getnum(s);
		}
		scanf("%d" , &m);
		for (i = 0; i < m; i ++)
		{
			scanf("%s %s" , st , s);
			dev[i] = getnum(s);
		}
		scanf("%d" , &k);
		for (i = 0; i < k; i ++)
		{
			scanf("%s %s" , s , st);
			b[getnum(st)][getnum(s)] = 1;
		}
		for (i = 0; i < fn; i ++) b[i][i] = 1;
		for (t = 0; t < fn; t ++)
			for (i = 0; i < fn; i ++)
				if (b[i][t] == 1)
					for (j = 0; j < fn; j ++)
						if (b[t][j] == 1)
							b[i][j] = 1;
		for (i = 0; i < m; i ++)
		{
			for (j = 0; j < n; j ++)
				if (b[pl[j]][dev[i]] == 1) a[j][i] = 1;
		}
		res = maxMatch();
		res = m - res;
		printf("%d\n" , res);
	}
	return 0;
}

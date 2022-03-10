#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int main()
{
int i , n , j , k;
char s[10];
int a[105][105];
int dist[105];
int have[105];
queue<int> qu;
	while (scanf("%d" , &n) == 1)
	{
		memset(a , 0 , sizeof(a));
		for (i = 0; i < n; i ++)
			for (j = 0; j < i; j ++)
			{
				scanf("%s" , s);
				if (s[0] == 'x') a[i][j] = 999999999;
				for (k = 0; k < strlen(s); k ++)
				{
					a[i][j] = a[i][j] * 10 + s[k] - '0';
				}
				a[j][i] = a[i][j];
			}
		for (i = 0; i < n; i ++) dist[i] = 999999999;
		dist[0] = 0;
		qu.push(0);
		memset(have , 0 , sizeof(have));
		have[0] = 1;
		while (!qu.empty())
		{
			k = qu.front();
			qu.pop();
			have[k] = 0;
			for (i = 0; i < n; i ++)
				if (i != k && dist[k] + a[k][i] < dist[i])
				{
					dist[i] = dist[k] + a[k][i];
					if (have[i] == 0)
					{
						qu.push(i);
						have[i] = 1;
					}
				}
		}
		k = 0;
		for (i = 1; i < n; i ++) if (dist[i] > k) k = dist[i];
		printf("%d\n" , k);
	}
	return 0;
}
